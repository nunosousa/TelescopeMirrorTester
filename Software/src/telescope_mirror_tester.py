import tkinter as tk

class VisualInterface(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Measurement Platform Controler")

        # create widgets
        frm_mtr = tk.Frame(master=self)

        # Manual motor controls
        self.spd_fine_adjst= 5
        self.spd_coarse_adjst = 20
        inc_spd_fine_text = "+5%"
        inc_spd_coarse_text = "+20%"
        dec_spd_fine_text = "-5%"
        dec_spd_coarse_text = "-20%"
        
        # A Axis controls
        frm_a = tk.LabelFrame(master=frm_mtr, text="A axis")
        
        self.lbl_a_spd_text = tk.StringVar()
        self.lbl_a_spd_text.set("+100%")
        
        self.rd_a_select = tk.StringVar()
        self.rd_a_select.set("Man")
        
        self.rd_a_man = tk.Radiobutton(master=frm_a, text="Manual Speed control", variable=self.rd_a_select, value="Man", command=lambda:self.select_a_axis_mode('Man'))
        self.btn_a_mm = tk.Button(master=frm_a, text=dec_spd_coarse_text, width=5, command=lambda:self.set_speed_on_axis('A', -self.spd_coarse_adjst))
        self.btn_a_m = tk.Button(master=frm_a, text=dec_spd_fine_text, width=5, command=lambda:self.set_speed_on_axis('A', -self.spd_fine_adjst))
        lbl_a_spd = tk.Label(master=frm_a, text="+100%", width=7, textvariable=self.lbl_a_spd_text, relief=tk.SUNKEN)
        self.btn_a_p = tk.Button(master=frm_a, text=inc_spd_fine_text, width=5, command=lambda:self.set_speed_on_axis('A', self.spd_fine_adjst))
        self.btn_a_pp = tk.Button(master=frm_a, text=inc_spd_coarse_text, width=5, command=lambda:self.set_speed_on_axis('A', self.spd_coarse_adjst))
        self.btn_a_stop = tk.Button(master=frm_a, text="STOP", width=5, bg="red", activebackground="red", command=lambda:self.set_speed_on_axis('A', 0))
        
        self.rd_a_man.grid(row=0, column=0, columnspan = 6, padx=4, pady=4, sticky = tk.W)
        self.btn_a_mm.grid(row=1, column=0, padx=4, pady=4)
        self.btn_a_m.grid(row=1, column=1, padx=4, pady=4)
        lbl_a_spd.grid(row=1, column=2, padx=4, pady=4)
        self.btn_a_p.grid(row=1, column=3, padx=4, pady=4)
        self.btn_a_pp.grid(row=1, column=4, padx=4, pady=4)
        self.btn_a_stop.grid(row=1, column=5, padx=4, pady=4)

        self.spn_a_stp_text = tk.StringVar()
        self.spn_a_stp_text.set(0) #Initial value

        self.rd_a_aut = tk.Radiobutton(master=frm_a, text="Automatic Position control", variable=self.rd_a_select, value="Aut", command=lambda:self.select_a_axis_mode('Aut'))
        lbl_a_stp = tk.Label(master=frm_a, text="Position step:", width=14)
        self.spn_a_stp = tk.Spinbox(master=frm_a, from_=-25.4, to=25.4, increment=0.01, state = 'readonly', width=5, textvariable=self.spn_a_stp_text, command=lambda:self.select_a_position_step(self.spn_a_stp_text.get()))
        lbl_a_stp_mm = tk.Label(master=frm_a, text="mm", width=3)
        self.btn_a_go = tk.Button(master=frm_a, text="GO", width=5, bg="green", activebackground="green", command=self.start_a_automatic_mode)
        
        self.rd_a_aut.grid(row=2, column=0, columnspan = 6, padx=4, pady=4, sticky = tk.W)
        lbl_a_stp.grid(row=3, column=0, columnspan = 2, padx=0, pady=4, sticky = tk.E)
        self.spn_a_stp.grid(row=3, column=2, padx=4, pady=4)
        lbl_a_stp_mm.grid(row=3, column=3, padx=0, pady=4, sticky = tk.W)
        self.btn_a_go.grid(row=3, column=5, padx=4, pady=4)

        self.lbl_a_pos_text = tk.StringVar()
        self.lbl_a_pos_text.set("-20.25")
        
        lbl_a_pos = tk.Label(master=frm_a, text="Position:", width=10)
        lbl_a_pos_mm = tk.Label(master=frm_a, width=7, textvariable=self.lbl_a_pos_text, relief=tk.SUNKEN)
        lbl_a_mm = tk.Label(master=frm_a, text="mm", width=3)
        self.btn_a_copy = tk.Button(master=frm_a, text="COPY", width=5, bg="purple", activebackground="purple", command=self.copy_a_position)
        self.btn_a_zero = tk.Button(master=frm_a, text="ZERO", width=5, bg="yellow", activebackground="yellow", command=self.clear_a_position)
        
        lbl_a_pos.grid(row=4, column=0, columnspan = 2, padx=0, pady=4, sticky = tk.E)
        lbl_a_pos_mm.grid(row=4, column=2, padx=4, pady=4)
        lbl_a_mm.grid(row=4, column=3, padx=0, pady=4, sticky = tk.W)
        self.btn_a_copy.grid(row=4, column=4, padx=4, pady=4)
        self.btn_a_zero.grid(row=4, column=5, padx=4, pady=4)
        
        frm_a.grid(row=0, column=0, padx=4, pady=4)
        
        # B Axis controls
        frm_b = tk.LabelFrame(master=frm_mtr, text="B axis")
        
        self.lbl_b_spd_text = tk.StringVar()
        self.lbl_b_spd_text.set("+100%")
        
        rd_b_aut = tk.Radiobutton(master=frm_b, text="Manual Speed control", state=tk.DISABLED)
        self.btn_b_mm = tk.Button(master=frm_b, text=dec_spd_coarse_text, width=5, command=lambda:self.set_speed_on_axis('B', -self.spd_coarse_adjst))
        self.btn_b_m = tk.Button(master=frm_b, text=dec_spd_fine_text, width=5, command=lambda:self.set_speed_on_axis('B', -self.spd_fine_adjst))
        lbl_b_spd = tk.Label(master=frm_b, text="+100%", width=7, textvariable=self.lbl_b_spd_text, relief=tk.SUNKEN)
        self.btn_b_p = tk.Button(master=frm_b, text=inc_spd_fine_text, width=5, command=lambda:self.set_speed_on_axis('B', self.spd_fine_adjst))
        self.btn_b_pp = tk.Button(master=frm_b, text=inc_spd_coarse_text, width=5, command=lambda:self.set_speed_on_axis('B', self.spd_coarse_adjst))
        self.btn_b_stop = tk.Button(master=frm_b, text="STOP", width=5, bg="red", activebackground="red", command=lambda:self.set_speed_on_axis('B', 0))
        
        rd_b_aut.grid(row=0, column=0, columnspan = 5, padx=4, pady=4, sticky = tk.W)
        self.btn_b_mm.grid(row=1, column=0, padx=4, pady=4)
        self.btn_b_m.grid(row=1, column=1, padx=4, pady=4)
        lbl_b_spd.grid(row=1, column=2, padx=4, pady=4)
        self.btn_b_p.grid(row=1, column=3, padx=4, pady=4)
        self.btn_b_pp.grid(row=1, column=4, padx=4, pady=4)
        self.btn_b_stop.grid(row=1, column=5, padx=4, pady=4)
        
        frm_b.grid(row=1, column=0, padx=4, pady=4)
        
        # C Axis controls
        frm_c = tk.LabelFrame(master=frm_mtr, text="C axis")
        
        self.lbl_c_spd_text = tk.StringVar()
        self.lbl_c_spd_text.set("+100%")
        
        rd_c_aut = tk.Radiobutton(master=frm_c, text="Manual Speed control", state=tk.DISABLED)
        self.btn_c_mm = tk.Button(master=frm_c, text=dec_spd_coarse_text, width=5, command=lambda:self.set_speed_on_axis('C', -self.spd_coarse_adjst))
        self.btn_c_m = tk.Button(master=frm_c, text=dec_spd_fine_text, width=5, command=lambda:self.set_speed_on_axis('C', -self.spd_fine_adjst))
        lbl_c_spd = tk.Label(master=frm_c, text="+100%", width=7, textvariable=self.lbl_c_spd_text, relief=tk.SUNKEN)
        self.btn_c_p = tk.Button(master=frm_c, text=inc_spd_fine_text, width=5, command=lambda:self.set_speed_on_axis('C', self.spd_fine_adjst))
        self.btn_c_pp = tk.Button(master=frm_c, text=inc_spd_coarse_text, width=5, command=lambda:self.set_speed_on_axis('C', self.spd_coarse_adjst))
        self.btn_c_stop = tk.Button(master=frm_c, text="STOP", width=5, bg="red", activebackground="red", command=lambda:self.set_speed_on_axis('C', 0))
        
        rd_c_aut.grid(row=0, column=0, columnspan = 5, padx=4, pady=4, sticky = tk.W)
        self.btn_c_mm.grid(row=1, column=0, padx=4, pady=4)
        self.btn_c_m.grid(row=1, column=1, padx=4, pady=4)
        lbl_c_spd.grid(row=1, column=2, padx=4, pady=4)
        self.btn_c_p.grid(row=1, column=3, padx=4, pady=4)
        self.btn_c_pp.grid(row=1, column=4, padx=4, pady=4)
        self.btn_c_stop.grid(row=1, column=5, padx=4, pady=4)
        
        frm_c.grid(row=2, column=0, padx=4, pady=4)
        
        frm_mtr.pack()
        
        self.resizable(width=False, height=False)

        # Choose manual mode for axis at startup
        self.select_a_axis_mode('Man')

    def select_a_axis_mode(self, mode):
        if mode == 'Man':
            self.spn_a_stp.configure(state='disabled')
            self.btn_a_go.configure(state='disabled')
            self.btn_a_copy.configure(state='disabled')
            self.btn_a_zero.configure(state='disabled')

            self.btn_a_mm.configure(state='normal')
            self.btn_a_m.configure(state='normal')
            self.btn_a_p.configure(state='normal')
            self.btn_a_pp.configure(state='normal')
            self.btn_a_stop.configure(state='normal')
        else:
            self.btn_a_mm.configure(state='disabled')
            self.btn_a_m.configure(state='disabled')
            self.btn_a_p.configure(state='disabled')
            self.btn_a_pp.configure(state='disabled')
            self.btn_a_stop.configure(state='disabled')

            self.spn_a_stp.configure(state='normal')
            self.btn_a_go.configure(state='normal')
            self.btn_a_copy.configure(state='normal')
            self.btn_a_zero.configure(state='normal')

    def set_speed_on_axis(self, axis, spd_step):
        print(axis + ' ' + str(spd_step))

    def start_a_automatic_mode(self):
        print("A automatic mode start")

    def copy_a_position(self):
        print("send to clipboard")

    def clear_a_position(self):
        print("clear a position")

    def select_a_position_step(self, pos_step):
        print(pos_step)

if __name__ == '__main__':
    gui = VisualInterface()
    gui.mainloop()
