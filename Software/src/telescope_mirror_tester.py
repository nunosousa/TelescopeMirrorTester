import tkinter
import serial
import serial.tools.list_ports
import threading
import queue
import time
import simple_pid
import logging

#sudo chmod 666 /dev/ttyUSB0
#sudo chmod 666 /dev/ttyUSB1

# constants - Visual interface
GUI_REFRESH_PERIOD = 120 # milliseconds

# constants - Serial interface
MOTOR_SPEED_UPDATE_PERIOD = GUI_REFRESH_PERIOD/1000 # seconds

# constants - Stale data threshold
STALE_TIME_TRHESHOLD = 0.5 # seconds

# constants - PID
KP_CONSTANT = 700
KD_CONSTANT = 2
KI_CONSTANT = 2


class VisualInterface(tkinter.Tk):
    def __init__(self):
        super().__init__()

        self.title("Measurement Platform Controler")

        # create widgets
        self.frm_mtr = tkinter.Frame(master=self)

        # Manual motor controls
        self.spd_fine_adjst= 1
        self.spd_coarse_adjst = 5
        inc_spd_fine_text = ">"
        inc_spd_coarse_text = ">>"
        dec_spd_fine_text = "<"
        dec_spd_coarse_text = "<<"
        
        # A Axis controls
        self.frm_a = tkinter.LabelFrame(master=self.frm_mtr,
                                        text="A axis")
        
        self.lbl_a_spd_text = tkinter.StringVar()
        
        self.rd_a_select = tkinter.StringVar()
        self.rd_a_select.set("Man")
        
        self.rd_a_man = tkinter.Radiobutton(master=self.frm_a,
                                            text="Manual Speed control",
                                            variable=self.rd_a_select,
                                            value="Man",
                                            command=lambda:self.select_a_axis_mode('Man'))
        self.btn_a_mm = tkinter.Button(master=self.frm_a,
                                       text=dec_spd_coarse_text,
                                       width=5,
                                       command=lambda:self.set_speed_step_on_axis('A', -self.spd_coarse_adjst))
        self.btn_a_m = tkinter.Button(master=self.frm_a,
                                      text=dec_spd_fine_text,
                                      width=5,
                                      command=lambda:self.set_speed_step_on_axis('A', -self.spd_fine_adjst))
        self.lbl_a_spd = tkinter.Label(master=self.frm_a,
                                  width=7,
                                  textvariable=self.lbl_a_spd_text,
                                  relief=tkinter.SUNKEN)
        self.btn_a_p = tkinter.Button(master=self.frm_a,
                                      text=inc_spd_fine_text,
                                      width=5,
                                      command=lambda:self.set_speed_step_on_axis('A', self.spd_fine_adjst))
        self.btn_a_pp = tkinter.Button(master=self.frm_a,
                                       text=inc_spd_coarse_text,
                                       width=5,
                                       command=lambda:self.set_speed_step_on_axis('A', self.spd_coarse_adjst))
        self.btn_a_stop = tkinter.Button(master=self.frm_a,
                                         text="STOP",
                                         width=5,
                                         command=lambda:self.set_speed_step_on_axis('A', 0),
                                         bg="red",
                                         activebackground="red")
        
        self.rd_a_man.grid(row=0, column=0, columnspan = 6, padx=4, pady=4, sticky=tkinter.W)
        self.btn_a_mm.grid(row=1, column=0, padx=4, pady=4)
        self.btn_a_m.grid(row=1, column=1, padx=4, pady=4)
        self.lbl_a_spd.grid(row=1, column=2, padx=4, pady=4)
        self.btn_a_p.grid(row=1, column=3, padx=4, pady=4)
        self.btn_a_pp.grid(row=1, column=4, padx=4, pady=4)
        self.btn_a_stop.grid(row=1, column=5, padx=4, pady=4)

        self.spn_a_stp_text = tkinter.StringVar()
        self.spn_a_stp_text.set("0.0")

        self.rd_a_aut = tkinter.Radiobutton(master=self.frm_a,
                                            text="Automatic Position control",
                                            variable=self.rd_a_select,
                                            value="Aut",
                                            command=lambda:self.select_a_axis_mode('Aut'))
        lbl_a_stp = tkinter.Label(master=self.frm_a,
                                  text="Step:",
                                  width=5,
                                  anchor="e")
        self.spn_a_stp = tkinter.Spinbox(master=self.frm_a,
                                         from_=-25.4,
                                         to=25.4,
                                         increment=0.01,
                                         state='readonly',
                                         width=5,
                                         textvariable=self.spn_a_stp_text)
        lbl_a_stp_mm = tkinter.Label(master=self.frm_a,
                                     text="mm",
                                     width=3,
                                     anchor="w")
        self.btn_a_go = tkinter.Button(master=self.frm_a,
                                       text="GO",
                                       width=5,
                                       bg="green",
                                       activebackground="green",
                                       command=lambda:self.start_automatic_mode('A'))
        self.btn_a_stop_aut = tkinter.Button(master=self.frm_a,
                                             text="STOP",
                                             width=5,
                                             command=lambda:self.set_speed_step_on_axis('A', 0),
                                             bg="red",
                                             activebackground="red")
        
        self.rd_a_aut.grid(row=2, column=0, columnspan=6, padx=4, pady=4, sticky=tkinter.W)
        lbl_a_stp.grid(row=3, column=0, columnspan=2, padx=4, pady=4, sticky=tkinter.E)
        self.spn_a_stp.grid(row=3, column=2, padx=4, pady=4)
        lbl_a_stp_mm.grid(row=3, column=3, padx=4, pady=4, sticky=tkinter.W)
        self.btn_a_go.grid(row=3, column=4, padx=4, pady=4)
        self.btn_a_stop_aut.grid(row=3, column=5, padx=4, pady=4)

        self.lbl_a_new_pos_text = tkinter.StringVar()
        
        lbl_a_new_pos = tkinter.Label(master=self.frm_a,
                                      text="New position:",
                                      width=14,
                                      anchor="e")
        self.lbl_a_new_pos_mm = tkinter.Label(master=self.frm_a,
                                              width=7,
                                              textvariable=self.lbl_a_new_pos_text,
                                              relief=tkinter.SUNKEN)
        lbl_a_new_mm = tkinter.Label(master=self.frm_a,
                                     text="mm",
                                     width=3,
                                     anchor="w")
        
        lbl_a_new_pos.grid(row=4, column=0, columnspan=2, padx=4, pady=4, sticky=tkinter.E)
        self.lbl_a_new_pos_mm.grid(row=4, column=2, padx=4, pady=4)
        lbl_a_new_mm.grid(row=4, column=3, padx=4, pady=4, sticky=tkinter.W)

        frm_a_sep = tkinter.Frame(master=self.frm_a,
                                  borderwidth=1,
                                  relief=tkinter.SUNKEN,
                                  height=2,
                                  width=400)
        frm_a_sep.grid(row=5, column=0, columnspan=6, padx=0, pady=4)

        self.lbl_a_pos_text = tkinter.StringVar()
        
        lbl_a_pos = tkinter.Label(master=self.frm_a,
                                  text="Current position:",
                                  width=18,
                                  anchor="e")
        lbl_a_pos_mm = tkinter.Label(master=self.frm_a,
                                     width=7,
                                     textvariable=self.lbl_a_pos_text,
                                     relief=tkinter.SUNKEN)
        lbl_a_mm = tkinter.Label(master=self.frm_a,
                                 text="mm",
                                 width=3,
                                 anchor="w")
        self.btn_a_copy = tkinter.Button(master=self.frm_a,
                                         text="COPY",
                                         width=5,
                                         bg="purple",
                                         activebackground="purple",
                                         command=self.copy_a_position)
        
        lbl_a_pos.grid(row=6, column=0, columnspan=2, padx=4, pady=4, sticky=tkinter.E)
        lbl_a_pos_mm.grid(row=6, column=2, padx=4, pady=4)
        lbl_a_mm.grid(row=6, column=3, padx=4, pady=4, sticky=tkinter.W)
        self.btn_a_copy.grid(row=6, column=4, padx=4, pady=4)
        
        self.frm_a.grid(row=0, column=0, padx=4, pady=4)
        
        # B Axis controls
        self.frm_b = tkinter.LabelFrame(master=self.frm_mtr,
                                        text="B axis")
        
        self.lbl_b_spd_text = tkinter.StringVar()
        
        rd_b_aut = tkinter.Radiobutton(master=self.frm_b,
                                       text="Manual Speed control",
                                       state=tkinter.DISABLED)
        self.btn_b_mm = tkinter.Button(master=self.frm_b,
                                       text=dec_spd_coarse_text,
                                       width=5,
                                       command=lambda:self.set_speed_step_on_axis('B', -self.spd_coarse_adjst))
        self.btn_b_m = tkinter.Button(master=self.frm_b,
                                      text=dec_spd_fine_text,
                                      width=5,
                                      command=lambda:self.set_speed_step_on_axis('B', -self.spd_fine_adjst))
        self.lbl_b_spd = tkinter.Label(master=self.frm_b,
                                       width=7,
                                       textvariable=self.lbl_b_spd_text,
                                       relief=tkinter.SUNKEN)
        self.btn_b_p = tkinter.Button(master=self.frm_b,
                                      text=inc_spd_fine_text,
                                      width=5,
                                      command=lambda:self.set_speed_step_on_axis('B', self.spd_fine_adjst))
        self.btn_b_pp = tkinter.Button(master=self.frm_b,
                                       text=inc_spd_coarse_text,
                                       width=5,
                                       command=lambda:self.set_speed_step_on_axis('B', self.spd_coarse_adjst))
        self.btn_b_stop = tkinter.Button(master=self.frm_b,
                                         text="STOP",
                                         width=5,
                                         bg="red",
                                         activebackground="red",
                                         command=lambda:self.set_speed_step_on_axis('B', 0))
        
        rd_b_aut.grid(row=0, column=0, columnspan=5, padx=4, pady=4, sticky=tkinter.W)
        self.btn_b_mm.grid(row=1, column=0, padx=4, pady=4)
        self.btn_b_m.grid(row=1, column=1, padx=4, pady=4)
        self.lbl_b_spd.grid(row=1, column=2, padx=4, pady=4)
        self.btn_b_p.grid(row=1, column=3, padx=4, pady=4)
        self.btn_b_pp.grid(row=1, column=4, padx=4, pady=4)
        self.btn_b_stop.grid(row=1, column=5, padx=4, pady=4)
        
        self.frm_b.grid(row=1, column=0, padx=4, pady=4)
        
        # C Axis controls
        self.frm_c = tkinter.LabelFrame(master=self.frm_mtr,
                                        text="C axis")
        
        self.lbl_c_spd_text = tkinter.StringVar()
        
        rd_c_aut = tkinter.Radiobutton(master=self.frm_c,
                                       text="Manual Speed control",
                                       state=tkinter.DISABLED)
        self.btn_c_mm = tkinter.Button(master=self.frm_c,
                                       text=dec_spd_coarse_text,
                                       width=5,
                                       command=lambda:self.set_speed_step_on_axis('C', -self.spd_coarse_adjst))
        self.btn_c_m = tkinter.Button(master=self.frm_c,
                                      text=dec_spd_fine_text,
                                      width=5,
                                      command=lambda:self.set_speed_step_on_axis('C', -self.spd_fine_adjst))
        self.lbl_c_spd = tkinter.Label(master=self.frm_c,
                                       width=7,
                                       textvariable=self.lbl_c_spd_text,
                                       relief=tkinter.SUNKEN)
        self.btn_c_p = tkinter.Button(master=self.frm_c,
                                      text=inc_spd_fine_text,
                                      width=5,
                                      command=lambda:self.set_speed_step_on_axis('C', self.spd_fine_adjst))
        self.btn_c_pp = tkinter.Button(master=self.frm_c,
                                       text=inc_spd_coarse_text,
                                       width=5,
                                       command=lambda:self.set_speed_step_on_axis('C', self.spd_coarse_adjst))
        self.btn_c_stop = tkinter.Button(master=self.frm_c,
                                         text="STOP",
                                         width=5,
                                         bg="red",
                                         activebackground="red",
                                         command=lambda:self.set_speed_step_on_axis('C', 0))
        
        rd_c_aut.grid(row=0, column=0, columnspan=5, padx=4, pady=4, sticky=tkinter.W)
        self.btn_c_mm.grid(row=1, column=0, padx=4, pady=4)
        self.btn_c_m.grid(row=1, column=1, padx=4, pady=4)
        self.lbl_c_spd.grid(row=1, column=2, padx=4, pady=4)
        self.btn_c_p.grid(row=1, column=3, padx=4, pady=4)
        self.btn_c_pp.grid(row=1, column=4, padx=4, pady=4)
        self.btn_c_stop.grid(row=1, column=5, padx=4, pady=4)
        
        self.frm_c.grid(row=2, column=0, padx=4, pady=4)
        
        self.frm_mtr.pack()
        
        self.resizable(width=False, height=False)

        # Choose manual mode for axis at startup
        self.select_a_axis_mode('Man')

        # set the controller
        self.controller = None

        # set window closing callback
        self.protocol("WM_DELETE_WINDOW", self.on_closing)

        # create a periodic event
        self.after(GUI_REFRESH_PERIOD, self.after_callback)

    def select_a_axis_mode(self, mode):
        if mode == 'Man':
            # Disable automatic mode widgets
            self.spn_a_stp.configure(state='disabled')
            self.btn_a_go.configure(state='disabled',
                                    bg="gray")
            self.btn_a_stop_aut.configure(state='disabled',
                                          bg="gray")
            self.lbl_a_new_pos_mm.configure(state='disabled')

            # Enable manual mode widgets
            self.btn_a_mm.configure(state='normal')
            self.btn_a_m.configure(state='normal')
            self.lbl_a_spd.configure(state='normal')
            self.btn_a_p.configure(state='normal')
            self.btn_a_pp.configure(state='normal')
            self.btn_a_stop.configure(state='normal',
                                      bg="red")

        else:
            # Disable manual mode widgets
            self.btn_a_mm.configure(state='disabled')
            self.btn_a_m.configure(state='disabled')
            self.lbl_a_spd.configure(state='disabled')
            self.btn_a_p.configure(state='disabled')
            self.btn_a_pp.configure(state='disabled')
            self.btn_a_stop.configure(state='disabled',
                                      bg="gray")

            # Enable automatic mode widgets
            self.spn_a_stp.configure(state='normal')
            self.btn_a_go.configure(state='normal',
                                    bg="green")
            self.btn_a_stop_aut.configure(state='normal',
                                          bg="red")
            self.lbl_a_new_pos_mm.configure(state='normal')

    def set_controller(self, controller):
        self.controller = controller

    def after_callback(self):
        if self.controller:
            self.controller.update_readings()

        self.after(GUI_REFRESH_PERIOD, self.after_callback)

    def set_speed_step_on_axis(self, axis, spd_step):
        if self.controller:
            self.controller.set_speed_step_on_axis(axis, spd_step)

    def start_automatic_mode(self, axis):
        if self.controller:
            self.controller.start_automatic_mode(axis, self.spn_a_stp_text.get())

    def copy_a_position(self):
        self.clipboard_clear()
        self.clipboard_append(self.lbl_a_pos_text.get())

    def update_speed_reading_on_axis(self, axis, spd_value):
        if axis == "A":
            self.lbl_a_spd_text.set(spd_value)
        elif axis == "B":
            self.lbl_b_spd_text.set(spd_value)
        elif axis == "C":
            self.lbl_c_spd_text.set(spd_value)
        else:
            pass

    def update_position_reading_on_axis(self, axis, pos_value):
        if axis == "A":
            self.lbl_a_pos_text.set(pos_value)
        else:
            pass

    def update_new_position_reading_on_axis(self, axis, pos_value):
        if axis == "A":
            self.lbl_a_new_pos_text.set(pos_value)
        else:
            pass

    def set_interface_mode(self, mode):
        if mode == "A active":
            # enable A widgets
            if self.rd_a_select.get() == 'Aut':
                self.select_a_axis_mode('Aut')
                self.rd_a_man.configure(state='disabled')
                self.rd_a_aut.configure(state='normal')
            elif self.rd_a_select.get() == 'Man':
                self.select_a_axis_mode('Man')
                self.rd_a_man.configure(state='normal')
                self.rd_a_aut.configure(state='disabled')

            # disable B widgets
            self.btn_b_mm.configure(state='disabled')
            self.btn_b_m.configure(state='disabled')
            self.lbl_b_spd.configure(state='disabled')
            self.btn_b_p.configure(state='disabled')
            self.btn_b_pp.configure(state='disabled')
            self.btn_b_stop.configure(state='disabled',
                                      bg="gray")

            # disable C widgets
            self.btn_c_mm.configure(state='disabled')
            self.btn_c_m.configure(state='disabled')
            self.lbl_c_spd.configure(state='disabled')
            self.btn_c_p.configure(state='disabled')
            self.btn_c_pp.configure(state='disabled')
            self.btn_c_stop.configure(state='disabled',
                                      bg="gray")

        elif mode == "B active":
            # disable A widgets
            self.rd_a_man.configure(state='disabled')
            self.rd_a_aut.configure(state='disabled')
            self.spn_a_stp.configure(state='disabled')
            self.btn_a_go.configure(state='disabled',
                                    bg="gray")
            self.btn_a_stop_aut.configure(state='disabled',
                                          bg="gray")
            self.lbl_a_new_pos_mm.configure(state='disabled')
            self.btn_a_mm.configure(state='disabled')
            self.btn_a_m.configure(state='disabled')
            self.lbl_a_spd.configure(state='disabled')
            self.btn_a_p.configure(state='disabled')
            self.btn_a_pp.configure(state='disabled')
            self.btn_a_stop.configure(state='disabled',
                                      bg="gray")
            
            # enable B widgets
            self.btn_b_mm.configure(state='normal')
            self.btn_b_m.configure(state='normal')
            self.lbl_b_spd.configure(state='normal')
            self.btn_b_p.configure(state='normal')
            self.btn_b_pp.configure(state='normal')
            self.btn_b_stop.configure(state='normal',
                                      bg="red")

            # disable C widgets
            self.btn_c_mm.configure(state='disabled')
            self.btn_c_m.configure(state='disabled')
            self.lbl_c_spd.configure(state='disabled')
            self.btn_c_p.configure(state='disabled')
            self.btn_c_pp.configure(state='disabled')
            self.btn_c_stop.configure(state='disabled',
                                      bg="gray")
            
        elif mode == "C active":
            # disable A widgets
            self.rd_a_man.configure(state='disabled')
            self.rd_a_aut.configure(state='disabled')
            self.spn_a_stp.configure(state='disabled')
            self.btn_a_go.configure(state='disabled',
                                    bg="gray")
            self.btn_a_stop_aut.configure(state='disabled',
                                          bg="gray")
            self.lbl_a_new_pos_mm.configure(state='disabled')
            self.btn_a_mm.configure(state='disabled')
            self.btn_a_m.configure(state='disabled')
            self.lbl_a_spd.configure(state='disabled')
            self.btn_a_p.configure(state='disabled')
            self.btn_a_pp.configure(state='disabled')
            self.btn_a_stop.configure(state='disabled',
                                      bg="gray")
            
            # disable B widgets
            self.btn_b_mm.configure(state='disabled')
            self.btn_b_m.configure(state='disabled')
            self.lbl_b_spd.configure(state='disabled')
            self.btn_b_p.configure(state='disabled')
            self.btn_b_pp.configure(state='disabled')
            self.btn_b_stop.configure(state='disabled',
                                      bg="gray")

            # enable C widgets
            self.btn_c_mm.configure(state='normal')
            self.btn_c_m.configure(state='normal')
            self.lbl_c_spd.configure(state='normal')
            self.btn_c_p.configure(state='normal')
            self.btn_c_pp.configure(state='normal')
            self.btn_c_stop.configure(state='normal',
                                      bg="red")
            
        elif mode == "none active":
            # enable A widgets
            self.rd_a_man.configure(state='normal')
            self.rd_a_aut.configure(state='normal')
            if self.rd_a_select.get() == 'Aut':
                self.select_a_axis_mode('Aut')
            elif self.rd_a_select.get() == 'Man':
                self.select_a_axis_mode('Man')
            
            # enable B widgets
            self.btn_b_mm.configure(state='normal')
            self.btn_b_m.configure(state='normal')
            self.lbl_b_spd.configure(state='normal')
            self.btn_b_p.configure(state='normal')
            self.btn_b_pp.configure(state='normal')
            self.btn_b_stop.configure(state='normal',
                                      bg="red")

            # enable C widgets
            self.btn_c_mm.configure(state='normal')
            self.btn_c_m.configure(state='normal')
            self.lbl_c_spd.configure(state='normal')
            self.btn_c_p.configure(state='normal')
            self.btn_c_pp.configure(state='normal')
            self.btn_c_stop.configure(state='normal',
                                      bg="red")
        else:
            pass
    
    def on_closing(self):
        print("terminating")
        self.destroy()


class MotorControllerInterface(serial.Serial):
    def __init__(self, serial_port):
        super().__init__()

        # serial port setup
        self.port = serial_port
        self.baudrate = 9600
        self.bytesize = serial.EIGHTBITS
        self.parity = serial.PARITY_ODD
        self.stopbits = serial.STOPBITS_ONE
        self.timeout = 1
        self.xonxoff = False #disable software flow control
        self.rtscts = False  #disable hardware (RTS/CTS) flow control
        self.dsrdtr = False  #disable hardware (DSR/DTR) flow control

        self.speed_data = queue.Queue()
        self.motor_a_active = threading.Event()
        self.motor_b_active = threading.Event()
        self.motor_c_active = threading.Event()
        self.serial_port_lock = threading.Lock()
        
        # is dictionary is used to decode received serial messages
        self.motor_direction = {
            "coast": 0,
            "brake": 0,
            "reverse drive": -1,
            "forward drive": 1
            }

    def run_monitor(self):
        self.open()

        self.monitor=threading.Thread(target=self.get_motor_speed,
                                      daemon=True)
        self.monitor.start()

    def stop_monitor(self):
        self.close()

    def get_motor_speed(self):
        # monitor active motor speed
        while True:
            time.sleep(MOTOR_SPEED_UPDATE_PERIOD)

            if self.motor_a_active.is_set():
                command = b'getSpeed A\r\n'
            elif self.motor_b_active.is_set():
                command = b'getSpeed B\r\n'
            elif self.motor_c_active.is_set():
                command = b'getSpeed C\r\n'
            else:
                continue
            
            self.serial_port_lock.acquire()
            self.write(command)
            line = self.readline(100) # consume command echo: >> getSpeed A\n
            line = self.readline(100) # get axis A speed value
            self.serial_port_lock.release()
            
            # parse command response and extract speed value
            string = line.decode('ascii')
            string = string.strip('\r\n')
            string = string.split('%, ')

            try:
                # get speed value (first token of response string) in integer format
                speed = int(string[0])
            except ValueError:
                pass
            else:
                try:
                    # get direction value (second token) as a signed 1 or a 0 if stopped
                    direction = self.motor_direction[string[1]]
                except KeyError:
                    pass
                else:
                    speed = speed * direction
                    self.speed_data.put(speed) # put speed data on queue

                    #logging.info(f'Time: {time.time():.4f}, Motor speed actual: {speed}')
                    
                    # update motor activity
                    if speed == 0:
                        self.motor_a_active.clear()
                        self.motor_b_active.clear()
                        self.motor_c_active.clear()

    def set_speed_on_axis(self, axis, speed):
        # Call work function
        self.monitor=threading.Thread(target=lambda:self.set_motor_speed(axis, speed),
                                      daemon=True)
        self.monitor.start()

    def set_motor_speed(self, axis, speed):
        # get an integer representation of speed
        speed = int(round(speed))

        # validate inputs
        if axis != 'A' and axis != 'B' and axis != 'C':
            return
        
        if speed < -100 or speed > 100:
            return
        
        # build serial command
        command = f'setSpeed {axis} {speed}\r\n'

        # send serial command
        self.serial_port_lock.acquire()
        self.write(command.encode('ascii'))
        self.readline(100) # consume command echo: >> setSpeed C 99\n
        self.serial_port_lock.release()

        # flag motor activity
        if speed != 0:
            if axis == 'A':
                self.motor_a_active.set()
                self.motor_b_active.clear()
                self.motor_c_active.clear()
            elif axis == 'B':
                self.motor_a_active.clear()
                self.motor_b_active.set()
                self.motor_c_active.clear()
            elif axis == 'C':
                self.motor_a_active.clear()
                self.motor_b_active.clear()
                self.motor_c_active.set()
        else:
            self.motor_a_active.clear()
            self.motor_b_active.clear()
            self.motor_c_active.clear()
        
        #logging.info(f'Time: {time.time():.4f}, Motor speed command: {speed}')


class MicrometerInterface(serial.Serial):
    def __init__(self, serial_port):
        super().__init__()

        # serial port setup
        self.port = serial_port
        self.baudrate = 9600
        self.bytesize = serial.EIGHTBITS
        self.parity = serial.PARITY_NONE
        self.stopbits = serial.STOPBITS_ONE
        self.timeout = 1
        self.xonxoff = False #disable software flow control
        self.rtscts = False  #disable hardware (RTS/CTS) flow control
        self.dsrdtr = False  #disable hardware (DSR/DTR) flow control

        self.position_data = queue.Queue()

    def run_monitor(self):
        self.open()
        
        # Call work function
        self.monitor=threading.Thread(target=self.process_micrometer_readings,
                                      daemon=True)
        self.monitor.start()

    def stop_monitor(self):
        self.close()

    def process_micrometer_readings(self):
        while True:
            # the expected messages end in \r\x12
            value = self.read_until(b'\r\x12')
            
            if not value:
                continue
            
            if len(value) != 10:
                continue

            # if message delimiters are as expected, process it
            if (value[0] == ord(b'+') or value[0] == ord(b'-')) and value[8] == ord(b'\r') and value[9] == ord(b'\x12'):
                # remove unwanted bytes and convert to a float number
                value=value.translate(None, b'\x00\r\x12')
                decoded_str = value.decode('ascii')
                decoded_float = float(decoded_str)/100.0

                # put received data on queue
                self.position_data.put(decoded_float)
                
                #logging.info(f'Time: {time.time():.4f}, Position {decoded_float}')


class Controller:
    def __init__(self, view, motor_controller, micrometer_readings):
        # set internal state variables
        self.motor_controller = motor_controller
        self.micrometer_readings = micrometer_readings
        self.automatic_control_mode_enabled = False
        self.current_speed = 0
        self.current_position = 0.0
        self.new_position = 0.0
        self.ts_micrometer_prev = time.time()
        self.ts_motor_speed_prev = time.time()

        # setup PID controler
        self.pid_controler = simple_pid.PID()
        self.pid_controler.Kp = KP_CONSTANT
        self.pid_controler.Ki = KI_CONSTANT
        self.pid_controler.Kd = KD_CONSTANT
        self.pid_controler.proportional_on_measurement = False
        self.pid_controler.differential_on_measurement = False
        self.pid_controler.sample_time = None
        self.max_abs_output = 100#25
        #self.pid_controler.starting_output = 16.0

        # set visual interface initial configuration
        view.update_speed_reading_on_axis("A", "---%")
        view.update_speed_reading_on_axis("B", "---%")
        view.update_speed_reading_on_axis("C", "---%")
        view.update_position_reading_on_axis("A", "--.--")
        view.update_new_position_reading_on_axis("A", "--.--")

        # start serial interfaces
        self.motor_controller.run_monitor()
        self.micrometer_readings.run_monitor()

    def update_readings(self):
        # get current timestamp
        time_stamp = time.time()

        # update axis A micrometer reading
        try:
            self.current_position = self.micrometer_readings.position_data.get(block=False)
        except queue.Empty:
            if time_stamp - self.ts_micrometer_prev > STALE_TIME_TRHESHOLD:
                # position gone stale, assume it is zero and stop control loop if applicable
                self.automatic_control_mode_enabled = False
                view.update_position_reading_on_axis("A", "--.--")
                view.update_new_position_reading_on_axis("A", "--.--")
        else:
            view.update_position_reading_on_axis("A", str(self.current_position))
            self.ts_micrometer_prev = time_stamp
            # Compute new output from the PID according to the systems current value
            if self.automatic_control_mode_enabled == True:
                speed_control = self.pid_controler(self.current_position)
                self.motor_controller.set_speed_on_axis('A', speed_control)
                
                logging.debug(f"command: {speed_control:.2f}, position: {self.current_position:.2f}, setpoint: {self.pid_controler.setpoint:.2f}, p: {self.pid_controler.components[0]:.2f}, i: {self.pid_controler.components[1]:.2f}, d: {self.pid_controler.components[2]:.2f}")

        # update motor speed readings
        try:
            self.current_speed = self.motor_controller.speed_data.get(block=False)
        except queue.Empty:
            if time_stamp - self.ts_motor_speed_prev > STALE_TIME_TRHESHOLD:
                self.current_speed = 0 # speed gone stale, assume it is zero
                view.update_speed_reading_on_axis("A", "---%")
                view.update_speed_reading_on_axis("B", "---%")
                view.update_speed_reading_on_axis("C", "---%")
                view.set_interface_mode("none active")
        else:
            if self.motor_controller.motor_a_active.is_set():
                view.update_speed_reading_on_axis("A", str(self.current_speed) + "%")
                view.update_speed_reading_on_axis("B", "---%")
                view.update_speed_reading_on_axis("C", "---%")
                view.set_interface_mode("A active")
                self.ts_motor_speed_prev = time_stamp
            elif self.motor_controller.motor_b_active.is_set():
                view.update_speed_reading_on_axis("A", "---%")
                view.update_speed_reading_on_axis("B", str(self.current_speed) + "%")
                view.update_speed_reading_on_axis("C", "---%")
                view.set_interface_mode("B active")
                self.ts_motor_speed_prev = time_stamp
            elif self.motor_controller.motor_c_active.is_set():
                view.update_speed_reading_on_axis("A", "---%")
                view.update_speed_reading_on_axis("B", "---%")
                view.update_speed_reading_on_axis("C", str(self.current_speed) + "%")
                view.set_interface_mode("C active")
                self.ts_motor_speed_prev = time_stamp
            else:
                view.set_interface_mode("none active")
                self.automatic_control_mode_enabled = False

    def set_speed_step_on_axis(self, axis, speed_step):
        if speed_step == 0: # stop command
            self.motor_controller.set_speed_on_axis(axis, 0)
            self.automatic_control_mode_enabled = False
        else: # update current speed
            speed = self.current_speed + speed_step
            self.motor_controller.set_speed_on_axis(axis, speed)

    def start_automatic_mode(self, axis, position_step):
        position_step = float(position_step)

        # adjust control output boundaries
        if position_step > 0:
            self.pid_controler.output_limits = (0, self.max_abs_output)
        else:
            self.pid_controler.output_limits = (-self.max_abs_output, 0)
        self.pid_controler.output_limits = (-self.max_abs_output, self.max_abs_output) # remove

        # set PID setpoint
        self.pid_controler.setpoint = self.current_position + position_step
        self.automatic_control_mode_enabled = True
        if axis == 'A': # stop controll loop
            view.update_new_position_reading_on_axis("A", f"{self.pid_controler.setpoint:.2f}")
        elif axis == 'B':
            pass
        elif axis == 'C':
            pass
        else:
            pass


def find_serial_device(vid, pid, serial_number):
    """Return the device path based on vender & product ID.
    
    The device is something like (like COM4, /dev/ttyUSB0 or /dev/cu.usbserial-1430)
    """
    device_list = serial.tools.list_ports.comports()
    
    for device in device_list:
        if (device.vid == vid and device.pid == pid and device.serial_number == serial_number):
            return device.device
        
    return None


if __name__ == '__main__':
    # find serial ports
    micrometer_port = find_serial_device(1027, 24577, 'A602FCS9')
    motor_controller_port = find_serial_device(6790, 29987, None)

    if micrometer_port == None or motor_controller_port == None:
        raise Exception("The expected serial ports are not available!")

    # tbd
    micrometer_readings = MicrometerInterface(micrometer_port)

    # tbd
    motor_controller = MotorControllerInterface(motor_controller_port)

    # create a view
    view = VisualInterface()

    # create a controller
    controller = Controller(view, motor_controller, micrometer_readings)
    
    # set the controller to view
    view.set_controller(controller)

    #logging.getLogger().setLevel(logging.INFO)
    logging.getLogger().setLevel(logging.DEBUG)

    view.mainloop()
