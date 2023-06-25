import tkinter
import cv2
import threading
import PIL.Image
import PIL.ImageTk
import time


# constants - Frame grabber
CAMERA_FRAME_GRAB_PERIOD = 0.025 # seconds
CAMERA_FRAME_PROCESS_PERIOD = CAMERA_FRAME_GRAB_PERIOD

# constants - Visual interface
GUI_REFRESH_PERIOD = int(CAMERA_FRAME_GRAB_PERIOD*1000) # milliseconds
LABEL_A_TEXT = "Unprocessed image"
LABEL_B_TEXT = "Processed image"


class VisualInterface(tkinter.Tk):
    def __init__(self):
        super().__init__()

        self.title("Shadowgram capture")

        # create widgets
        self.frm_mtr = tkinter.Frame(master=self)
        
        # Original camera widgets
        self.frm_a = tkinter.LabelFrame(master=self.frm_mtr,
                                        text=LABEL_A_TEXT)
        self.lbl_a = tkinter.Label(master=self.frm_a)
        self.lbl_a.pack()

        # Processed camera widgets
        self.frm_b = tkinter.LabelFrame(master=self.frm_mtr,
                                        text=LABEL_B_TEXT)
        self.lbl_b = tkinter.Label(master=self.frm_b)
        self.lbl_b.pack()

        # Capture command button
        self.btn_cap = tkinter.Button(master=self.frm_mtr,
                                      text="Capture and save",
                                      command=self.save_frame)
        
        self.frm_a.grid(row=0, column=0, padx=4, pady=4)
        self.frm_b.grid(row=0, column=1, padx=4, pady=4)
        self.btn_cap.grid(row=1, column=0, columnspan=2, padx=4, pady=4)
        
        self.frm_mtr.pack()
        
        self.resizable(width=False, height=False)

        # set window closing callback
        self.protocol("WM_DELETE_WINDOW", self.on_closing)

        # create a periodic event
        self.after(GUI_REFRESH_PERIOD, self.after_callback)

        # timestamps to calculate fps
        self.ts_frame_a_prev = time.time()
        self.ts_frame_b_prev = time.time()

    def show_image_a(self, frame):
        # update image
        captured_image = PIL.Image.fromarray(frame)
        photo_image = PIL.ImageTk.PhotoImage(image=captured_image)
        self.lbl_a.configure(image=photo_image)
        self.lbl_a.image = photo_image

        # update text
        fps = 1/(time.time() - self.ts_frame_a_prev)
        self.frm_a.configure(text=f"{LABEL_A_TEXT}, {fps:.0f} fps")
        self.ts_frame_a_prev = time.time()

    def show_image_b(self, frame):
        # update image
        captured_image = PIL.Image.fromarray(frame)
        photo_image = PIL.ImageTk.PhotoImage(image=captured_image)
        self.lbl_b.configure(image=photo_image)
        self.lbl_b.image = photo_image

        # update text
        fps = 1/(time.time() - self.ts_frame_b_prev)
        self.frm_b.configure(text=f"{LABEL_B_TEXT}, {fps:.0f} fps")
        self.ts_frame_b_prev = time.time()

    def set_controller(self, controller):
        self.controller = controller
    
    def save_frame(self):
        pass

    def after_callback(self):
        if self.controller:
            self.controller.update_shadowgram_data()

        self.after(GUI_REFRESH_PERIOD, self.after_callback)
    
    def on_closing(self):
        if self.controller:
            self.controller.close_camera()

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

        self.frame_data = []
        self.frame_lock = threading.Lock()
        self.frame_event = threading.Event()
        self.frame_to_process_event = threading.Event()

        self.shadowgram_data = []
        self.shadowgram_radius_data = []
        self.shadowgram_lock = threading.Lock()
        self.shadowgram_event = threading.Event()

    def close_camera(self):
        self.capture_cam.release()

    def run_capture(self):
        # Call work function
        self.capture_monitor = threading.Thread(target=self.capture_frame,
                                                daemon=True)
        self.capture_monitor.start()

        self.process_monitor = threading.Thread(target=self.process_frame,
                                                daemon=True)
        self.process_monitor.start()

    def capture_frame(self):
        while True:
            # check if there is a new frame
            while self.capture_cam.grab() == False:
                time.sleep(CAMERA_FRAME_GRAB_PERIOD)
            
            # capture frame
            ret, frame = self.capture_cam.retrieve()
            
            # if frame is read correctly ret is True
            if not ret:
                print("Can't receive frame.")
                continue

            # set and release data
            self.frame_lock.acquire(blocking=True)
            self.frame_data = frame
            self.frame_lock.release()
            self.frame_event.set()
            self.frame_to_process_event.set()

    def process_frame(self):
        while True:
            # get newest camera capture
            if not self.frame_to_process_event.is_set():
                time.sleep(CAMERA_FRAME_PROCESS_PERIOD)
                continue

            self.frame_to_process_event.clear()

            self.frame_lock.acquire(blocking=True)
            frame_data = self.frame_data
            self.frame_lock.release()

            # process frame
            shadowgram_radius, shadowgram = self.find_shadowgram(frame_data)

            # set and release data
            self.shadowgram_lock.acquire(blocking=True)
            self.shadowgram_data = shadowgram
            self.shadowgram_radius_data = shadowgram_radius
            self.shadowgram_lock.release()
            self.shadowgram_event.set()

    def find_shadowgram(self, frame):
        shadowgram_radius = 0.0
        shadowgram = cv2.cvtColor(frame, cv2.COLOR_RGB2GRAY)

        return shadowgram_radius, shadowgram


class Controller:
    def __init__(self, view, camera_processor):
        # set internal state variables
        self.view = view
        self.camera_processor = camera_processor

        # start camera processor
        self.camera_processor.run_capture()
    
    def update_shadowgram_data(self):
        if self.camera_processor.frame_event.is_set():
            self.camera_processor.frame_event.clear()

            self.camera_processor.frame_lock.acquire(blocking=True)
            frame = cv2.cvtColor(self.camera_processor.frame_data, cv2.COLOR_BGR2RGBA)
            view.show_image_a(frame)
            self.camera_processor.frame_lock.release()

        if self.camera_processor.shadowgram_event.is_set():
            self.camera_processor.shadowgram_event.clear()

            self.camera_processor.shadowgram_lock.acquire(blocking=True)
            view.show_image_b(self.camera_processor.shadowgram_data)
            self.camera_processor.shadowgram_lock.release()

    def close_camera(self):
        self.camera_processor.close_camera()


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
