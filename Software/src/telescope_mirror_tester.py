import tkinter as tk
import tkinter.ttk as ttk

# https://realpython.com/python-gui-tkinter/

root = tk.Tk()

root.title("Telescope Mirror Tester")

# Manual motor controls
frm_mtr = tk.LabelFrame(master=root, text="Motor Control")

# A Axis controls
frm_a = tk.LabelFrame(master=frm_mtr, text="A axis")

rd_a_man = ttk.Radiobutton(master=frm_a, text="Manual Speed control")
btn_a_mm = ttk.Button(master=frm_a, text="<<", width=3)
btn_a_m = ttk.Button(master=frm_a, text="<", width=3)
lbl_a_spd = ttk.Label(master=frm_a, text="+100%", width=6)
btn_a_p = ttk.Button(master=frm_a, text=">", width=3)
btn_a_pp = ttk.Button(master=frm_a, text=">>", width=3)
btn_a_stop = ttk.Button(master=frm_a, text="STOP", width=5)

rd_a_man.grid(row=0, column=0, columnspan = 6, sticky = tk.W)
btn_a_mm.grid(row=1, column=0, padx=4, pady=4)
btn_a_m.grid(row=1, column=1, padx=4, pady=4)
lbl_a_spd.grid(row=1, column=2, padx=4, pady=4)
btn_a_p.grid(row=1, column=3, padx=4, pady=4)
btn_a_pp.grid(row=1, column=4, padx=4, pady=4)
btn_a_stop.grid(row=1, column=5, padx=4, pady=4)

rd_a_aut = ttk.Radiobutton(master=frm_a, text="Automatic Position control")
lbl_a_pos = ttk.Label(master=frm_a, text="Position movement [mm]:", width=24)
spn_a_pos = ttk.Spinbox(master=frm_a, from_= -25.00, to = 25.00, width=5)

rd_a_aut.grid(row=2, column=0, columnspan = 6, sticky = tk.W)
lbl_a_pos.grid(row=3, column=0, columnspan = 4, padx=4, pady=4, sticky = tk.W)
spn_a_pos.grid(row=3, column=4, columnspan = 2, padx=4, pady=4, sticky = tk.W)

frm_a.grid(row=0, column=0, padx=4, pady=4)

# B Axis controls
frm_b = tk.LabelFrame(master=frm_mtr, text="B axis")

lbl_b = ttk.Label(master=frm_b, text="Manual Speed control")
btn_b_mm = ttk.Button(master=frm_b, text="<<", width=3)
btn_b_m = ttk.Button(master=frm_b, text="<", width=3)
lbl_b_spd = ttk.Label(master=frm_b, text="+100%", width=6)
btn_b_p = ttk.Button(master=frm_b, text=">", width=3)
btn_b_pp = ttk.Button(master=frm_b, text=">>", width=3)
btn_b_stop = ttk.Button(master=frm_b, text="STOP", width=5)

lbl_b.grid(row=0, column=0, columnspan = 5, sticky = tk.W)
btn_b_mm.grid(row=1, column=0, padx=4, pady=4)
btn_b_m.grid(row=1, column=1, padx=4, pady=4)
lbl_b_spd.grid(row=1, column=2, padx=4, pady=4)
btn_b_p.grid(row=1, column=3, padx=4, pady=4)
btn_b_pp.grid(row=1, column=4, padx=4, pady=4)
btn_b_stop.grid(row=1, column=5, padx=4, pady=4)

frm_b.grid(row=1, column=0, padx=4, pady=4)

# C Axis controls
frm_c = tk.LabelFrame(master=frm_mtr, text="Z axis")

lbl_c = ttk.Label(master=frm_c, text="Manual Speed control")
btn_c_mm = ttk.Button(master=frm_c, text="<<", width=3)
btn_c_m = ttk.Button(master=frm_c, text="<", width=3)
lbl_c_spd = ttk.Label(master=frm_c, text="+100%", width=6)
btn_c_p = ttk.Button(master=frm_c, text=">", width=3)
btn_c_pp = ttk.Button(master=frm_c, text=">>", width=3)
btn_c_stop = ttk.Button(master=frm_c, text="STOP", width=5)

lbl_c.grid(row=0, column=0, columnspan = 5, sticky = tk.W)
btn_c_mm.grid(row=1, column=0, padx=4, pady=4)
btn_c_m.grid(row=1, column=1, padx=4, pady=4)
lbl_c_spd.grid(row=1, column=2, padx=4, pady=4)
btn_c_p.grid(row=1, column=3, padx=4, pady=4)
btn_c_pp.grid(row=1, column=4, padx=4, pady=4)
btn_c_stop.grid(row=1, column=5, padx=4, pady=4)

frm_c.grid(row=2, column=0, padx=4, pady=4)

frm_mtr.pack()

root.mainloop()
