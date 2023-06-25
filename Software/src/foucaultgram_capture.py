import tkinter
import cv2
import threading
import queue
import numpy
import PIL.Image
import PIL.ImageTk


# constants - Visual interface
GUI_REFRESH_PERIOD = 12 # milliseconds


class VisualInterface(tkinter.Tk):
    def __init__(self):
        super().__init__()

        self.title("Shadowgram capture")

        # create widgets
        self.frm_mtr = tkinter.Frame(master=self)
        
        # Original camera widgets
        self.frm_unp = tkinter.LabelFrame(master=self.frm_mtr,
                                          text="Unprocessed image")
        self.lbl_unp = tkinter.Label(master=self.frm_unp)
        self.lbl_unp.pack()

        # Processed camera widgets
        self.frm_pro = tkinter.LabelFrame(master=self.frm_mtr,
                                          text="Processed image")
        self.lbl_pro = tkinter.Label(master=self.frm_pro)
        self.lbl_pro.pack()

        # Capture command button
        self.btn_cap = tkinter.Button(master=self.frm_mtr,
                                       text="Capture and save",
                                       command=self.save_processed_frame)
        
        self.frm_unp.grid(row=0, column=0, padx=4, pady=4)
        self.frm_pro.grid(row=0, column=1, padx=4, pady=4)
        self.btn_cap.grid(row=1, column=0, columnspan=2, padx=4, pady=4)
        
        self.frm_mtr.pack()
        
        self.resizable(width=False, height=False)

        # set window closing callback
        self.protocol("WM_DELETE_WINDOW", self.on_closing)

        # create a periodic event
        self.after(GUI_REFRESH_PERIOD, self.after_callback)

    def set_controller(self, controller):
        self.controller = controller

    def show_unprocessed_image(self, frame):
        captured_image = PIL.Image.fromarray(frame)
        photo_image = PIL.ImageTk.PhotoImage(image=captured_image)
        self.lbl_unp.configure(image=photo_image)
        self.lbl_unp.image = photo_image

    def show_processed_image(self, frame):
        captured_image = PIL.Image.fromarray(frame)
        photo_image = PIL.ImageTk.PhotoImage(image=captured_image)
        self.lbl_pro.configure(image=photo_image)
        self.lbl_pro.image = photo_image
    
    def save_processed_frame(self):
        pass

    def after_callback(self):
        if self.controller:
            self.controller.update_shadowgram_data()

        self.after(GUI_REFRESH_PERIOD, self.after_callback)
    
    def on_closing(self):
        print("terminating")
        self.destroy()


class ShadowgramProcessor:
    def __init__(self, camera):

        # camera setup
        self.capture_cam = cv2.VideoCapture(camera)

        if not self.capture_cam.isOpened(): 
            raise Exception("Unable to open video input!")
        
        self.frame_width = int(self.capture_cam.get(cv2.CAP_PROP_FRAME_WIDTH))
        self.frame_height = int(self.capture_cam.get(cv2.CAP_PROP_FRAME_HEIGHT))
        self.frame_fps = int(self.capture_cam.get(cv2.CAP_PROP_FPS))

        self.original_frame_data = []
        self.original_frame_lock = threading.Lock()

        self.processed_frame_data = []
        self.shadowgram_radius_data = []
        self.processed_frame_lock = threading.Lock()

        self.new_shadowgram_data_event = threading.Event()

    def run_capture(self):
        # Call work function
        self.monitor = threading.Thread(target=self.process_frame,
                                        daemon=True)
        self.monitor.start()

    def process_frame(self):
        while True:
            # Capture frame-by-frame
            ret, frame = self.capture_cam.read()
            
            # if frame is read correctly ret is True
            if not ret:
                print("Can't receive frame.")
                continue

            # process captured frame
            shadowgram_radius = 0.0

            # put received data on queue
            self.original_frame_lock.acquire(blocking=True)
            self.original_frame_data = cv2.cvtColor(frame, cv2.COLOR_BGR2RGBA)
            self.original_frame_lock.release()

            self.processed_frame_lock.acquire(blocking=True)
            self.processed_frame_data = cv2.cvtColor(frame, cv2.COLOR_RGB2GRAY)
            self.shadowgram_radius_data = shadowgram_radius
            self.processed_frame_lock.release()

            self.new_shadowgram_data_event.set()


class Controller:
    def __init__(self, view, camera_processor):
        # set internal state variables
        self.view = view
        self.camera_processor = camera_processor

        # start camera processor
        self.camera_processor.run_capture()
    
    def update_shadowgram_data(self):
        if self.camera_processor.new_shadowgram_data_event.is_set():
            self.camera_processor.new_shadowgram_data_event.clear()

            self.camera_processor.original_frame_lock.acquire(blocking=True)
            view.show_unprocessed_image(self.camera_processor.original_frame_data)
            self.camera_processor.original_frame_lock.release()

            self.camera_processor.processed_frame_lock.acquire(blocking=True)
            view.show_processed_image(self.camera_processor.processed_frame_data)
            self.camera_processor.processed_frame_lock.release()


if __name__ == '__main__':
    # create the visual interface
    view = VisualInterface()

    # setup the camera image processor 
    camera_processor = ShadowgramProcessor(3)

    # create a controller
    controller = Controller(view, camera_processor)
    
    # set the controller to view
    view.set_controller(controller)

    view.mainloop()
