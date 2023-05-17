import tkinter as tk
import tkinter.ttk as ttk

# https://realpython.com/python-gui-tkinter/

root = tk.Tk()

root.title("Telescope Mirror Tester")

# Position controls
frm_pos = tk.LabelFrame(master=root, text="Axis Motor Speed Controls")

# X Axis controls
frm_x = tk.LabelFrame(master=frm_pos, text="X axis, Speed: ")

btn_x_mm = ttk.Button(master=frm_x, text="<<", width=3)
btn_x_m = ttk.Button(master=frm_x, text="<", width=3)
btn_x_stop = ttk.Button(master=frm_x, text="STOP", width=5)
btn_x_p = ttk.Button(master=frm_x, text=">", width=3)
btn_x_pp = ttk.Button(master=frm_x, text=">>", width=3)

btn_x_mm.grid(row=0, column=0, padx=4, pady=4)
btn_x_m.grid(row=0, column=1, padx=4, pady=4)
btn_x_stop.grid(row=0, column=2, padx=4, pady=4)
btn_x_p.grid(row=0, column=3, padx=4, pady=4)
btn_x_pp.grid(row=0, column=4, padx=4, pady=4)

frm_x.grid(row=0, column=0, padx=4, pady=4)

# Y Axis controls
frm_y = tk.LabelFrame(master=frm_pos, text="Y axis, Speed: ")

btn_y_mm = ttk.Button(master=frm_y, text="<<", width=3)
btn_y_m = ttk.Button(master=frm_y, text="<", width=3)
btn_y_stop = ttk.Button(master=frm_y, text="STOP", width=5)
btn_y_p = ttk.Button(master=frm_y, text=">", width=3)
btn_y_pp = ttk.Button(master=frm_y, text=">>", width=3)

btn_y_mm.grid(row=0, column=0, padx=4, pady=4)
btn_y_m.grid(row=0, column=1, padx=4, pady=4)
btn_y_stop.grid(row=0, column=2, padx=4, pady=4)
btn_y_p.grid(row=0, column=3, padx=4, pady=4)
btn_y_pp.grid(row=0, column=4, padx=4, pady=4)

frm_y.grid(row=1, column=0, padx=4, pady=4)

# Z Axis controls
frm_z = tk.LabelFrame(master=frm_pos, text="Z axis, Speed: ")

btn_z_mm = ttk.Button(master=frm_z, text="<<", width=3)
btn_z_m = ttk.Button(master=frm_z, text="<", width=3)
btn_z_stop = ttk.Button(master=frm_z, text="STOP", width=5)
btn_z_p = ttk.Button(master=frm_z, text=">", width=3)
btn_z_pp = ttk.Button(master=frm_z, text=">>", width=3)

btn_z_mm.grid(row=0, column=0, padx=4, pady=4)
btn_z_m.grid(row=0, column=1, padx=4, pady=4)
btn_z_stop.grid(row=0, column=2, padx=4, pady=4)
btn_z_p.grid(row=0, column=3, padx=4, pady=4)
btn_z_pp.grid(row=0, column=4, padx=4, pady=4)

frm_z.grid(row=2, column=0, padx=4, pady=4)

frm_pos.pack()

root.mainloop()
