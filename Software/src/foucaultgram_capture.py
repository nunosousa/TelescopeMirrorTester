import tkinter
import cv2


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
                                       command=self.capture_and_save_processed_image)
        
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

    def capture_and_save_processed_image(self):
        pass

    def after_callback(self):
        if self.controller:
            self.controller.update_readings()

        self.after(GUI_REFRESH_PERIOD, self.after_callback)
    
    def on_closing(self):
        print("terminating")
        self.destroy()


class CameraInterface():
    def __init__(self, camera):
        super().__init__()

        # camera setup

    def run_monitor(self):
        pass

if __name__ == '__main__':
    # create a view
    view = VisualInterface()

    view.mainloop()
