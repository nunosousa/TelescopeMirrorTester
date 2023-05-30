import serial.tools.list_ports

VID = 1234
PID = 5678

device_list = serial.tools.list_ports.comports()

for device in device_list:

    print("------")
    print(device.pid)
    print(device.vid)
    print(device.serial_number)
    print(device.device)
    print(device.description)
    print(device.manufacturer)

    #if (device.vid != None or device.pid != None):
    #    if ('{:04X}'.format(device.vid) == VID and
    #        '{:04X}'.format(device.pid) == PID):
    #        port = device.device
    #        break
    #    port = None