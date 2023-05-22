import tkinter as tk

class View(tk.Frame):
    def __init__(self, parent):
        super().__init__(parent)

        # create widgets
        # Manual motor controls
        
        spd_fine_adjst= 5
        spd_coarse_adjst = 20
        inc_spd_fine_text = "+5%"
        inc_spd_coarse_text = "+20%"
        dec_spd_fine_text = "-5%"
        dec_spd_coarse_text = "-20%"
        
        # A Axis controls
        frm_a = tk.LabelFrame(master=self, text="A axis")
        
        self.lbl_a_spd_text = tk.StringVar()
        self.lbl_a_spd_text.set("+100%")
        
        self.rd_a_select = tk.StringVar()
        self.rd_a_select.set("Man")
        
        rd_a_man = tk.Radiobutton(master=frm_a, text="Manual Speed control", variable=self.rd_a_select, value="Man")
        btn_a_mm = tk.Button(master=frm_a, text=dec_spd_coarse_text, width=5)
        btn_a_m = tk.Button(master=frm_a, text=dec_spd_fine_text, width=5)
        lbl_a_spd = tk.Label(master=frm_a, text="+100%", width=7, textvariable=self.lbl_a_spd_text, relief=tk.SUNKEN)
        btn_a_p = tk.Button(master=frm_a, text=inc_spd_fine_text, width=5)
        btn_a_pp = tk.Button(master=frm_a, text=inc_spd_coarse_text, width=5)
        btn_a_stop = tk.Button(master=frm_a, text="STOP", width=5, bg="red", activebackground="red")
        
        rd_a_man.grid(row=0, column=0, columnspan = 6, padx=4, pady=4, sticky = tk.W)
        btn_a_mm.grid(row=1, column=0, padx=4, pady=4)
        btn_a_m.grid(row=1, column=1, padx=4, pady=4)
        lbl_a_spd.grid(row=1, column=2, padx=4, pady=4)
        btn_a_p.grid(row=1, column=3, padx=4, pady=4)
        btn_a_pp.grid(row=1, column=4, padx=4, pady=4)
        btn_a_stop.grid(row=1, column=5, padx=4, pady=4)
        
        rd_a_aut = tk.Radiobutton(master=frm_a, text="Automatic Position control", variable=self.rd_a_select, value="Aut")
        lbl_a_stp = tk.Label(master=frm_a, text="Position step:", width=14)
        spn_a_stp = tk.Spinbox(master=frm_a, from_= -25.00, to = 25.00, width=5)
        lbl_a_stp_mm = tk.Label(master=frm_a, text="mm", width=3)
        btn_a_go = tk.Button(master=frm_a, text="GO", width=5, bg="green", activebackground="green")
        
        rd_a_aut.grid(row=2, column=0, columnspan = 6, padx=4, pady=4, sticky = tk.W)
        lbl_a_stp.grid(row=3, column=0, columnspan = 2, padx=0, pady=4, sticky = tk.E)
        spn_a_stp.grid(row=3, column=2, padx=4, pady=4)
        lbl_a_stp_mm.grid(row=3, column=3, padx=0, pady=4, sticky = tk.W)
        btn_a_go.grid(row=3, column=5, padx=4, pady=4)
        
        self.lbl_a_pos_text = tk.StringVar()
        self.lbl_a_pos_text.set("-20.25")
        
        lbl_a_pos = tk.Label(master=frm_a, text="Position:", width=10)
        lbl_a_pos_mm = tk.Label(master=frm_a, width=7, textvariable=self.lbl_a_pos_text, relief=tk.SUNKEN)
        lbl_a_mm = tk.Label(master=frm_a, text="mm", width=3)
        btn_a_copy = tk.Button(master=frm_a, text="COPY", width=5, bg="purple", activebackground="purple")
        btn_a_go = tk.Button(master=frm_a, text="ZERO", width=5, bg="yellow", activebackground="yellow")
        
        lbl_a_pos.grid(row=4, column=0, columnspan = 2, padx=0, pady=4, sticky = tk.E)
        lbl_a_pos_mm.grid(row=4, column=2, padx=4, pady=4)
        lbl_a_mm.grid(row=4, column=3, padx=0, pady=4, sticky = tk.W)
        btn_a_copy.grid(row=4, column=4, padx=4, pady=4)
        btn_a_go.grid(row=4, column=5, padx=4, pady=4)
        
        frm_a.grid(row=0, column=0, padx=4, pady=4)
        
        # B Axis controls
        frm_b = tk.LabelFrame(master=self, text="B axis")
        
        self.lbl_b_spd_text = tk.StringVar()
        self.lbl_b_spd_text.set("+100%")
        
        rd_b_aut = tk.Radiobutton(master=frm_b, text="Manual Speed control", state=tk.DISABLED)
        btn_b_mm = tk.Button(master=frm_b, text=dec_spd_coarse_text, width=5)
        btn_b_m = tk.Button(master=frm_b, text=dec_spd_fine_text, width=5)
        lbl_b_spd = tk.Label(master=frm_b, text="+100%", width=7, textvariable=self.lbl_b_spd_text, relief=tk.SUNKEN)
        btn_b_p = tk.Button(master=frm_b, text=inc_spd_fine_text, width=5)
        btn_b_pp = tk.Button(master=frm_b, text=inc_spd_coarse_text, width=5)
        btn_b_stop = tk.Button(master=frm_b, text="STOP", width=5, bg="red", activebackground="red")
        
        rd_b_aut.grid(row=0, column=0, columnspan = 5, padx=4, pady=4, sticky = tk.W)
        btn_b_mm.grid(row=1, column=0, padx=4, pady=4)
        btn_b_m.grid(row=1, column=1, padx=4, pady=4)
        lbl_b_spd.grid(row=1, column=2, padx=4, pady=4)
        btn_b_p.grid(row=1, column=3, padx=4, pady=4)
        btn_b_pp.grid(row=1, column=4, padx=4, pady=4)
        btn_b_stop.grid(row=1, column=5, padx=4, pady=4)
        
        frm_b.grid(row=1, column=0, padx=4, pady=4)
        
        # C Axis controls
        frm_c = tk.LabelFrame(master=self, text="C axis")
        
        self.lbl_c_spd_text = tk.StringVar()
        self.lbl_c_spd_text.set("+100%")
        
        rd_c_aut = tk.Radiobutton(master=frm_c, text="Manual Speed control", state=tk.DISABLED)
        btn_c_mm = tk.Button(master=frm_c, text=dec_spd_coarse_text, width=5)
        btn_c_m = tk.Button(master=frm_c, text=dec_spd_fine_text, width=5)
        lbl_c_spd = tk.Label(master=frm_c, text="+100%", width=7, textvariable=self.lbl_c_spd_text, relief=tk.SUNKEN)
        btn_c_p = tk.Button(master=frm_c, text=inc_spd_fine_text, width=5)
        btn_c_pp = tk.Button(master=frm_c, text=inc_spd_coarse_text, width=5)
        btn_c_stop = tk.Button(master=frm_c, text="STOP", width=5, bg="red", activebackground="red")
        
        rd_c_aut.grid(row=0, column=0, columnspan = 5, padx=4, pady=4, sticky = tk.W)
        btn_c_mm.grid(row=1, column=0, padx=4, pady=4)
        btn_c_m.grid(row=1, column=1, padx=4, pady=4)
        lbl_c_spd.grid(row=1, column=2, padx=4, pady=4)
        btn_c_p.grid(row=1, column=3, padx=4, pady=4)
        btn_c_pp.grid(row=1, column=4, padx=4, pady=4)
        btn_c_stop.grid(row=1, column=5, padx=4, pady=4)
        
        frm_c.grid(row=2, column=0, padx=4, pady=4)
        
        self.pack()

class Model:
    pass        

class Controller:
    pass      

class App(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Measurement Platform Controler")

        # create a view and place it on the root window
        view = View(self)
        view.grid(row=0, column=0)


if __name__ == '__main__':
    app = App()
    app.mainloop()
