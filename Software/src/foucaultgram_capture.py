import tkinter
import cv2
import threading
import queue
import numpy


# constants - Visual interface
GUI_REFRESH_PERIOD = 120 # milliseconds


class VisualInterface(tkinter.Tk):
    def __init__(self):
        super().__init__()

        self.title("Shadowgram capture")

        # create widgets
        self.frm_mtr = tkinter.Frame(master=self)
        
        # Original camera widgets
        self.frm_unp = tkinter.LabelFrame(master=self.frm_mtr,
                                          text="Unprocessed image")
        self.cns_unp = tkinter.Canvas(master=self.frm_unp)
        self.cns_unp.pack()

        # Processed camera widgets
        self.frm_pro = tkinter.LabelFrame(master=self.frm_mtr,
                                          text="Processed image")
        self.cns_pro = tkinter.Canvas(master=self.frm_pro)
        self.cns_pro.pack()

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
    
    def set_frame_size(self, width, height):
        self.cns_unp.configure(width=width)
        self.cns_unp.configure(height=height)
        self.cns_unp.create_image(0, 0, anchor="nw")

        self.cns_pro.configure(width=width)
        self.cns_pro.configure(height=height)
        self.cns_pro.create_image(0, 0, anchor="nw")

    def show_unprocessed_image(self, frame):
        height, width = frame.shape # expect only one channel/gray image
        data = f'P5 {width} {height} 255 '.encode() + frame.astype(numpy.uint8).tobytes()
        frame_view = tkinter.PhotoImage(width=width, height=height, data=data, format='PPM')
        self.cns_unp.create_image(image=frame_view)

    def show_processed_image(self, frame):
        pass
    
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

        self.original_frame_data = queue.Queue()
        self.processed_frame_data = queue.Queue()
        self.shadowgram_radius_data = queue.Queue()
        self.new_shadowgram_data = threading.Event()

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
            frame = cv2.cvtColor(frame, cv2.COLOR_RGB2GRAY)
            self.original_frame_data.put(frame)
            self.processed_frame_data.put(frame)
            self.shadowgram_radius_data.put(shadowgram_radius)
            self.new_shadowgram_data.set()


class Controller:
    def __init__(self, view, camera_processor):
        # set internal state variables
        self.view = view
        self.camera_processor = camera_processor

        # set visual interface initial configuration
        view.set_frame_size(self.camera_processor.frame_width,
                            self.camera_processor.frame_height)

        # start camera processor
        self.camera_processor.run_capture()
    
    def update_shadowgram_data(self):
        if self.camera_processor.new_shadowgram_data.is_set():
            self.camera_processor.new_shadowgram_data.clear()

            all_good = True
            
            try:
                self.original_frame_data = self.camera_processor.original_frame_data.get(block=False)
            except queue.Empty:
                all_good = False
            else:
                pass

            try:
                self.processed_frame_data = self.camera_processor.processed_frame_data.get(block=False)
            except queue.Empty:
                all_good = False
            else:
                pass

            try:
                self.shadowgram_radius_data = self.camera_processor.shadowgram_radius_data.get(block=False)
            except queue.Empty:
                all_good = False
            else:
                pass

            if all_good:
                view.show_unprocessed_image(self.original_frame_data)
                view.show_processed_image(self.processed_frame_data)


if __name__ == '__main__':
    # create the visual interface
    view = VisualInterface()

    # setup the camera image processor 
    camera_processor = ShadowgramProcessor(1)

    # create a controller
    controller = Controller(view, camera_processor)
    
    # set the controller to view
    view.set_controller(controller)

    view.mainloop()
