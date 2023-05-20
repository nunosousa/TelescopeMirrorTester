import tkinter as tk
import tkinter.ttk as ttk

# https://realpython.com/python-gui-tkinter/

root = tk.Tk()

root.title("Telescope Mirror Tester")

# Manual motor controls
frm_mtr = tk.LabelFrame(master=root, text="Axis Control")

spd_fine_adjst= 5
spd_coarse_adjst = 20
inc_spd_fine_text = "+5%"
inc_spd_coarse_text = "+20%"
dec_spd_fine_text = "-5%"
dec_spd_coarse_text = "-20%"

# A Axis controls
frm_a = tk.LabelFrame(master=frm_mtr, text="A axis")

lbl_a_spd_text = tk.StringVar()
lbl_a_spd_text.set("+100%")

rd_a_select = tk.StringVar()
rd_a_select.set("Man")

rd_a_man = tk.Radiobutton(master=frm_a, text="Manual Speed control", variable=rd_a_select, value="Man")
btn_a_mm = tk.Button(master=frm_a, text=dec_spd_coarse_text, width=4)
btn_a_m = tk.Button(master=frm_a, text=dec_spd_fine_text, width=4)
lbl_a_spd = tk.Label(master=frm_a, text="+100%", width=7, textvariable=lbl_a_spd_text, relief=tk.SUNKEN)
btn_a_p = tk.Button(master=frm_a, text=inc_spd_fine_text, width=4)
btn_a_pp = tk.Button(master=frm_a, text=inc_spd_coarse_text, width=4)
btn_a_stop = tk.Button(master=frm_a, text="STOP", width=5, bg="red", activebackground="red")

rd_a_man.grid(row=0, column=0, columnspan = 6, padx=4, pady=4, sticky = tk.W)
btn_a_mm.grid(row=1, column=0, padx=4, pady=4)
btn_a_m.grid(row=1, column=1, padx=4, pady=4)
lbl_a_spd.grid(row=1, column=2, padx=4, pady=4)
btn_a_p.grid(row=1, column=3, padx=4, pady=4)
btn_a_pp.grid(row=1, column=4, padx=4, pady=4)
btn_a_stop.grid(row=1, column=5, padx=4, pady=4)

rd_a_aut = tk.Radiobutton(master=frm_a, text="Automatic Position control", variable=rd_a_select, value="Aut")
lbl_a_stp = tk.Label(master=frm_a, text="Position step:", width=14)
spn_a_stp = tk.Spinbox(master=frm_a, from_= -25.00, to = 25.00, width=5)
lbl_a_stp_mm = tk.Label(master=frm_a, text="mm", width=3)
btn_a_go = tk.Button(master=frm_a, text="GO", width=5, bg="green", activebackground="green")

rd_a_aut.grid(row=2, column=0, columnspan = 6, padx=4, pady=4, sticky = tk.W)
lbl_a_stp.grid(row=3, column=0, columnspan = 2, padx=4, pady=4, sticky = tk.E)
spn_a_stp.grid(row=3, column=2, padx=4, pady=4)
lbl_a_stp_mm.grid(row=3, column=3, padx=4, pady=4)
btn_a_go.grid(row=3, column=5, padx=4, pady=4)

lbl_a_pos_text = tk.StringVar()
lbl_a_pos_text.set("-20.25")

lbl_a_pos = tk.Label(master=frm_a, text="Position:", width=10)
lbl_a_pos_mm = tk.Label(master=frm_a, width=7, textvariable=lbl_a_pos_text, relief=tk.SUNKEN)
lbl_a_mm = tk.Label(master=frm_a, text="mm", width=3)
btn_a_go = tk.Button(master=frm_a, text="ZERO", width=5, bg="yellow", activebackground="yellow")

lbl_a_pos.grid(row=4, column=0, columnspan = 2, padx=4, pady=4, sticky = tk.E)
lbl_a_pos_mm.grid(row=4, column=2, padx=4, pady=4)
lbl_a_mm.grid(row=4, column=3, padx=4, pady=4)
btn_a_go.grid(row=4, column=5, padx=4, pady=4)

frm_a.grid(row=0, column=0, padx=4, pady=4)

# B Axis controls
frm_b = tk.LabelFrame(master=frm_mtr, text="B axis")

lbl_b_spd_text = tk.StringVar()
lbl_b_spd_text.set("+100%")

rd_b_aut = tk.Radiobutton(master=frm_b, text="Manual Speed control", state=tk.DISABLED)
btn_b_mm = tk.Button(master=frm_b, text=dec_spd_coarse_text, width=4)
btn_b_m = tk.Button(master=frm_b, text=dec_spd_fine_text, width=4)
lbl_b_spd = tk.Label(master=frm_b, text="+100%", width=7, textvariable=lbl_b_spd_text, relief=tk.SUNKEN)
btn_b_p = tk.Button(master=frm_b, text=inc_spd_fine_text, width=4)
btn_b_pp = tk.Button(master=frm_b, text=inc_spd_coarse_text, width=4)
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
frm_c = tk.LabelFrame(master=frm_mtr, text="C axis")

lbl_c_spd_text = tk.StringVar()
lbl_c_spd_text.set("+100%")

rd_c_aut = tk.Radiobutton(master=frm_c, text="Manual Speed control", state=tk.DISABLED)
btn_c_mm = tk.Button(master=frm_c, text=dec_spd_coarse_text, width=4)
btn_c_m = tk.Button(master=frm_c, text=dec_spd_fine_text, width=4)
lbl_c_spd = tk.Label(master=frm_c, text="+100%", width=7, textvariable=lbl_c_spd_text, relief=tk.SUNKEN)
btn_c_p = tk.Button(master=frm_c, text=inc_spd_fine_text, width=4)
btn_c_pp = tk.Button(master=frm_c, text=inc_spd_coarse_text, width=4)
btn_c_stop = tk.Button(master=frm_c, text="STOP", width=5, bg="red", activebackground="red")

rd_c_aut.grid(row=0, column=0, columnspan = 5, padx=4, pady=4, sticky = tk.W)
btn_c_mm.grid(row=1, column=0, padx=4, pady=4)
btn_c_m.grid(row=1, column=1, padx=4, pady=4)
lbl_c_spd.grid(row=1, column=2, padx=4, pady=4)
btn_c_p.grid(row=1, column=3, padx=4, pady=4)
btn_c_pp.grid(row=1, column=4, padx=4, pady=4)
btn_c_stop.grid(row=1, column=5, padx=4, pady=4)

frm_c.grid(row=2, column=0, padx=4, pady=4)

frm_mtr.pack()

root.mainloop()
