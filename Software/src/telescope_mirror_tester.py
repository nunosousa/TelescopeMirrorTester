import tkinter
import serial
import serial.tools.list_ports
import threading
import queue
import time
import simple_pid


#sudo chmod 666 /dev/ttyUSB0
#sudo chmod 666 /dev/ttyUSB1


class VisualInterface(tkinter.Tk):
    def __init__(self):
        super().__init__()

        self.title("Measurement Platform Controler")

        # create widgets
        self.frm_mtr = tkinter.Frame(master=self)

        # update function calling period
        self.readings_update_period = 15

        # Manual motor controls
        self.spd_fine_adjst= 1
        self.spd_coarse_adjst = 5
        inc_spd_fine_text = ">"
        inc_spd_coarse_text = ">>"
        dec_spd_fine_text = "<"
        dec_spd_coarse_text = "<<"
        
        # A Axis controls
        frm_a = tkinter.LabelFrame(master=self.frm_mtr,
                                   text="A axis")
        
        self.lbl_a_spd_text = tkinter.StringVar()
        
        self.rd_a_select = tkinter.StringVar()
        self.rd_a_select.set("Man")
        
        self.rd_a_man = tkinter.Radiobutton(master=frm_a,
                                            text="Manual Speed control",
                                            variable=self.rd_a_select,
                                            value="Man",
                                            command=lambda:self.select_a_axis_mode('Man'))
        self.btn_a_mm = tkinter.Button(master=frm_a,
                                       text=dec_spd_coarse_text,
                                       width=5,
                                       command=lambda:self.set_speed_on_axis('A', -self.spd_coarse_adjst))
        self.btn_a_m = tkinter.Button(master=frm_a,
                                      text=dec_spd_fine_text,
                                      width=5,
                                      command=lambda:self.set_speed_on_axis('A', -self.spd_fine_adjst))
        lbl_a_spd = tkinter.Label(master=frm_a,
                                  width=7,
                                  textvariable=self.lbl_a_spd_text,
                                  relief=tkinter.SUNKEN)
        self.btn_a_p = tkinter.Button(master=frm_a,
                                      text=inc_spd_fine_text,
                                      width=5,
                                      command=lambda:self.set_speed_on_axis('A', self.spd_fine_adjst))
        self.btn_a_pp = tkinter.Button(master=frm_a,
                                       text=inc_spd_coarse_text,
                                       width=5,
                                       command=lambda:self.set_speed_on_axis('A', self.spd_coarse_adjst))
        self.btn_a_stop = tkinter.Button(master=frm_a,
                                         text="STOP",
                                         width=5,
                                         command=lambda:self.set_speed_on_axis('A', 0),
                                         bg="red",
                                         activebackground="red")
        
        self.rd_a_man.grid(row=0, column=0, columnspan = 6, padx=4, pady=4, sticky = tkinter.W)
        self.btn_a_mm.grid(row=1, column=0, padx=4, pady=4)
        self.btn_a_m.grid(row=1, column=1, padx=4, pady=4)
        lbl_a_spd.grid(row=1, column=2, padx=4, pady=4)
        self.btn_a_p.grid(row=1, column=3, padx=4, pady=4)
        self.btn_a_pp.grid(row=1, column=4, padx=4, pady=4)
        self.btn_a_stop.grid(row=1, column=5, padx=4, pady=4)

        self.spn_a_stp_text = tkinter.StringVar()
        self.spn_a_stp_text.set("0.0")

        self.rd_a_aut = tkinter.Radiobutton(master=frm_a,
                                            text="Automatic Position control",
                                            variable=self.rd_a_select,
                                            value="Aut",
                                            command=lambda:self.select_a_axis_mode('Aut'))
        lbl_a_stp = tkinter.Label(master=frm_a,
                                  text="Step:",
                                  width=5,
                                  anchor="e")
        self.spn_a_stp = tkinter.Spinbox(master=frm_a,
                                         from_=-25.4,
                                         to=25.4,
                                         increment=0.01,
                                         state='readonly',
                                         width=5,
                                         textvariable=self.spn_a_stp_text)
        lbl_a_stp_mm = tkinter.Label(master=frm_a,
                                     text="mm",
                                     width=3,
                                     anchor="w")
        self.btn_a_go = tkinter.Button(master=frm_a,
                                       text="GO",
                                       width=5,
                                       bg="green",
                                       activebackground="green",
                                       command=self.start_a_automatic_mode)
        self.btn_a_stop_aut = tkinter.Button(master=frm_a,
                                             text="STOP",
                                             width=5,
                                             command=lambda:self.set_speed_on_axis('A', 0),
                                             bg="red",
                                             activebackground="red")
        
        self.rd_a_aut.grid(row=2, column=0, columnspan=6, padx=4, pady=4, sticky = tkinter.W)
        lbl_a_stp.grid(row=3, column=0, columnspan=2, padx=4, pady=4, sticky=tkinter.E)
        self.spn_a_stp.grid(row=3, column=2, padx=4, pady=4)
        lbl_a_stp_mm.grid(row=3, column=3, padx=4, pady=4, sticky = tkinter.W)
        self.btn_a_go.grid(row=3, column=4, padx=4, pady=4)
        self.btn_a_stop_aut.grid(row=3, column=5, padx=4, pady=4)

        self.lbl_a_new_pos_text = tkinter.StringVar()
        
        lbl_a_new_pos = tkinter.Label(master=frm_a,
                                      text="New position:",
                                      width=14,
                                      anchor="e")
        lbl_a_new_pos_mm = tkinter.Label(master=frm_a,
                                         width=7,
                                         textvariable=self.lbl_a_new_pos_text,
                                         relief=tkinter.SUNKEN)
        lbl_a_new_mm = tkinter.Label(master=frm_a,
                                     text="mm",
                                     width=3,
                                     anchor="w")
        
        lbl_a_new_pos.grid(row=4, column=0, columnspan=2, padx=4, pady=4, sticky=tkinter.E)
        lbl_a_new_pos_mm.grid(row=4, column=2, padx=4, pady=4)
        lbl_a_new_mm.grid(row=4, column=3, padx=4, pady=4, sticky = tkinter.W)

        self.lbl_a_pos_text = tkinter.StringVar()
        
        lbl_a_pos = tkinter.Label(master=frm_a,
                                  text="Current position:",
                                  width=18,
                                  anchor="e")
        lbl_a_pos_mm = tkinter.Label(master=frm_a,
                                     width=7,
                                     textvariable=self.lbl_a_pos_text,
                                     relief=tkinter.SUNKEN)
        lbl_a_mm = tkinter.Label(master=frm_a,
                                 text="mm",
                                 width=3,
                                 anchor="w")
        self.btn_a_copy = tkinter.Button(master=frm_a,
                                         text="COPY",
                                         width=5,
                                         bg="purple",
                                         activebackground="purple",
                                         command=self.copy_a_position)
        
        lbl_a_pos.grid(row=5, column=0, columnspan=2, padx=4, pady=4, sticky=tkinter.E)
        lbl_a_pos_mm.grid(row=5, column=2, padx=4, pady=4)
        lbl_a_mm.grid(row=5, column=3, padx=4, pady=4, sticky = tkinter.W)
        self.btn_a_copy.grid(row=5, column=4, padx=4, pady=4)
        
        frm_a.grid(row=0, column=0, padx=4, pady=4)
        
        # B Axis controls
        frm_b = tkinter.LabelFrame(master=self.frm_mtr,
                                   text="B axis")
        
        self.lbl_b_spd_text = tkinter.StringVar()
        
        rd_b_aut = tkinter.Radiobutton(master=frm_b,
                                       text="Manual Speed control",
                                       state=tkinter.DISABLED)
        self.btn_b_mm = tkinter.Button(master=frm_b,
                                       text=dec_spd_coarse_text,
                                       width=5,
                                       command=lambda:self.set_speed_on_axis('B', -self.spd_coarse_adjst))
        self.btn_b_m = tkinter.Button(master=frm_b,
                                      text=dec_spd_fine_text,
                                      width=5,
                                      command=lambda:self.set_speed_on_axis('B', -self.spd_fine_adjst))
        lbl_b_spd = tkinter.Label(master=frm_b,
                                  width=7,
                                  textvariable=self.lbl_b_spd_text,
                                  relief=tkinter.SUNKEN)
        self.btn_b_p = tkinter.Button(master=frm_b,
                                      text=inc_spd_fine_text,
                                      width=5,
                                      command=lambda:self.set_speed_on_axis('B', self.spd_fine_adjst))
        self.btn_b_pp = tkinter.Button(master=frm_b,
                                       text=inc_spd_coarse_text,
                                       width=5,
                                       command=lambda:self.set_speed_on_axis('B', self.spd_coarse_adjst))
        self.btn_b_stop = tkinter.Button(master=frm_b,
                                         text="STOP",
                                         width=5,
                                         bg="red",
                                         activebackground="red",
                                         command=lambda:self.set_speed_on_axis('B', 0))
        
        rd_b_aut.grid(row=0, column=0, columnspan = 5, padx=4, pady=4, sticky = tkinter.W)
        self.btn_b_mm.grid(row=1, column=0, padx=4, pady=4)
        self.btn_b_m.grid(row=1, column=1, padx=4, pady=4)
        lbl_b_spd.grid(row=1, column=2, padx=4, pady=4)
        self.btn_b_p.grid(row=1, column=3, padx=4, pady=4)
        self.btn_b_pp.grid(row=1, column=4, padx=4, pady=4)
        self.btn_b_stop.grid(row=1, column=5, padx=4, pady=4)
        
        frm_b.grid(row=1, column=0, padx=4, pady=4)
        
        # C Axis controls
        frm_c = tkinter.LabelFrame(master=self.frm_mtr,
                                   text="C axis")
        
        self.lbl_c_spd_text = tkinter.StringVar()
        
        rd_c_aut = tkinter.Radiobutton(master=frm_c,
                                       text="Manual Speed control",
                                       state=tkinter.DISABLED)
        self.btn_c_mm = tkinter.Button(master=frm_c,
                                       text=dec_spd_coarse_text,
                                       width=5,
                                       command=lambda:self.set_speed_on_axis('C', -self.spd_coarse_adjst))
        self.btn_c_m = tkinter.Button(master=frm_c,
                                      text=dec_spd_fine_text,
                                      width=5,
                                      command=lambda:self.set_speed_on_axis('C', -self.spd_fine_adjst))
        lbl_c_spd = tkinter.Label(master=frm_c,
                                  width=7,
                                  textvariable=self.lbl_c_spd_text,
                                  relief=tkinter.SUNKEN)
        self.btn_c_p = tkinter.Button(master=frm_c,
                                      text=inc_spd_fine_text,
                                      width=5,
                                      command=lambda:self.set_speed_on_axis('C', self.spd_fine_adjst))
        self.btn_c_pp = tkinter.Button(master=frm_c,
                                       text=inc_spd_coarse_text,
                                       width=5,
                                       command=lambda:self.set_speed_on_axis('C', self.spd_coarse_adjst))
        self.btn_c_stop = tkinter.Button(master=frm_c,
                                         text="STOP",
                                         width=5,
                                         bg="red",
                                         activebackground="red",
                                         command=lambda:self.set_speed_on_axis('C', 0))
        
        rd_c_aut.grid(row=0, column=0, columnspan = 5, padx=4, pady=4, sticky = tkinter.W)
        self.btn_c_mm.grid(row=1, column=0, padx=4, pady=4)
        self.btn_c_m.grid(row=1, column=1, padx=4, pady=4)
        lbl_c_spd.grid(row=1, column=2, padx=4, pady=4)
        self.btn_c_p.grid(row=1, column=3, padx=4, pady=4)
        self.btn_c_pp.grid(row=1, column=4, padx=4, pady=4)
        self.btn_c_stop.grid(row=1, column=5, padx=4, pady=4)
        
        frm_c.grid(row=2, column=0, padx=4, pady=4)
        
        self.frm_mtr.pack()
        
        self.resizable(width=False, height=False)

        # Choose manual mode for axis at startup
        self.select_a_axis_mode('Man')

        # set the controller
        self.controller = None

        # set window closing callback
        self.protocol("WM_DELETE_WINDOW", self.on_closing)

        # create a periodic event
        self.after(100, self.after_callback)

    def select_a_axis_mode(self, mode):
        if mode == 'Man':
            # Enable manual mode widgets
            self.spn_a_stp.configure(state='disabled')
            self.btn_a_go.configure(state='disabled')

            # Disable automatic mode widgets
            self.btn_a_mm.configure(state='normal')
            self.btn_a_m.configure(state='normal')
            self.btn_a_p.configure(state='normal')
            self.btn_a_pp.configure(state='normal')
            self.btn_a_stop.configure(state='normal')

        else:
            # Enable automatic mode widgets
            self.btn_a_mm.configure(state='disabled')
            self.btn_a_m.configure(state='disabled')
            self.btn_a_p.configure(state='disabled')
            self.btn_a_pp.configure(state='disabled')
            self.btn_a_stop.configure(state='disabled')

            # Disable manual mode widgets
            self.spn_a_stp.configure(state='normal')
            self.btn_a_go.configure(state='normal')

    def set_controller(self, controller):
        self.controller = controller

    def after_callback(self):
        if self.controller:
            self.controller.update_readings()

        self.after(self.readings_update_period, self.after_callback)

    def set_speed_on_axis(self, axis, spd_step):
        if self.controller:
            self.controller.set_speed_on_axis(axis, spd_step)

    def start_a_automatic_mode(self):
        if self.controller:
            self.controller.start_a_automatic_mode(self.spn_a_stp_text.get())

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
            time.sleep(0.2)

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
                speed = int(string[0]) # get speed value in integer format
            except ValueError:
                pass
            else:
                try:
                    direction = self.motor_direction[string[1]] # get direction value as a signed 1 or a 0 if stopped
                except KeyError:
                    pass
                else:
                    speed = speed * direction
                    self.speed_data.put(speed) # put speed data on queue

    def set_speed_on_axis(self, axis, speed):
        # Call work function
        self.monitor=threading.Thread(target=lambda:self.set_motor_speed(axis, speed),
                                      daemon=True)
        self.monitor.start()

    def set_motor_speed(self, axis, speed):
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
            time.sleep(0.01)

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


class Controller:
    def __init__(self, view, motor_controller, micrometer_readings):
        # setup PID controler
        self.pid_controler = simple_pid.PID()
        self.pid_controler.Kp = 400
        self.pid_controler.Ki = 0
        self.pid_controler.Kd = 0
        self.pid_controler.proportional_on_measurement = False
        self.pid_controler.differential_on_measurement = False
        self.pid_controler.sample_time = 0.015
        self.pid_controler.output_limits = (0, 25)
        #self.pid_controler.starting_output = 16.0

        self.auto_position_control_enabled = False

        self.current_speed = 0
        self.current_position = 0.0

        self.ts_micrometer_prev = time.time()
        self.ts_motor_speed_prev = time.time()

        view.update_speed_reading_on_axis("A", "---%")
        view.update_speed_reading_on_axis("B", "---%")
        view.update_speed_reading_on_axis("C", "---%")
        view.update_position_reading_on_axis("A", "--.--")

        motor_controller.run_monitor()
        micrometer_readings.run_monitor()

    def update_readings(self):
        # get current timestamp
        time_stamp = time.time()

        # update micrometer reading
        try:
            self.current_position = micrometer_readings.position_data.get(block=False)
        except queue.Empty:
            if time_stamp - self.ts_micrometer_prev > 0.5:
                # tbd: position gone stale, assume it is zero and stop control loop if applicable
                view.update_position_reading_on_axis("A", "--.--")
        else:
            view.update_position_reading_on_axis("A", str(self.current_position))
            self.ts_micrometer_prev = time_stamp

            # Compute new output from the PID according to the systems current value
            speed_control = self.pid_controler(self.current_position)
            if self.auto_position_control_enabled == True:
                motor_controller.set_speed_on_axis('A', speed_control)
                print(f"command: {speed_control:.2f}, position: {self.current_position:.2f}, setpoint: {self.pid_controler.setpoint:.2f}, p: {self.pid_controler.components[0]:.2f}, i: {self.pid_controler.components[1]:.2f}, d: {self.pid_controler.components[2]:.2f}")
                #print(self.pid_controler.components)

        # update motor speed readings
        try:
            self.current_speed = motor_controller.speed_data.get(block=False)
        except queue.Empty:
            if time_stamp - self.ts_motor_speed_prev > 0.5:
                self.current_speed = 0 # speed gone stale, assume it is zero
                view.update_speed_reading_on_axis("A", "---%")
                view.update_speed_reading_on_axis("B", "---%")
                view.update_speed_reading_on_axis("C", "---%")
        else:
            if motor_controller.motor_a_active.is_set():
                view.update_speed_reading_on_axis("A", str(self.current_speed) + "%")
                view.update_speed_reading_on_axis("B", "---%")
                view.update_speed_reading_on_axis("C", "---%")
                self.ts_motor_speed_prev = time_stamp
            elif motor_controller.motor_b_active.is_set():
                view.update_speed_reading_on_axis("A", "---%")
                view.update_speed_reading_on_axis("B", str(self.current_speed) + "%")
                view.update_speed_reading_on_axis("C", "---%")
                self.ts_motor_speed_prev = time_stamp
            elif motor_controller.motor_c_active.is_set():
                view.update_speed_reading_on_axis("A", "---%")
                view.update_speed_reading_on_axis("B", "---%")
                view.update_speed_reading_on_axis("C", str(self.current_speed) + "%")
                self.ts_motor_speed_prev = time_stamp
            else:
                pass

    def set_speed_on_axis(self, axis, speed_step):
        if speed_step == 0: # stop command
            motor_controller.set_speed_on_axis(axis, 0)
        else: # update current speed
            motor_controller.set_speed_on_axis(axis, self.current_speed + speed_step)

    def start_a_automatic_mode(self, position_step):
        # tbd: tell gui to disable controls before staring control loop

        # set PID setpoint
        self.pid_controler.setpoint = self.current_position + float(position_step)
        self.auto_position_control_enabled = True

        print(f"start_a_automatic_mode with step {position_step}")

        # tbd: tell gui to enable controls after ending control loop


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

    view.mainloop()
