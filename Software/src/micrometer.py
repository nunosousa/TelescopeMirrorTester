import serial

#sudo chmod 666 /dev/ttyUSB0
#sudo chmod 666 /dev/ttyUSB1

ser = serial.Serial()

ser.port = '/dev/ttyUSB1'
ser.baudrate = 9600
ser.bytesize = serial.EIGHTBITS
ser.parity = serial.PARITY_NONE
ser.stopbits = serial.STOPBITS_ONE
ser.timeout = 1
ser.xonxoff = False #disable software flow control
ser.rtscts = True  #disable hardware (RTS/CTS) flow control
ser.dsrdtr = True  #disable hardware (DSR/DTR) flow control

ser.open()

for n in range(200):
    value = ser.read_until(b'\r\x12')
    #value = ser.read(ser.inWaiting)

    print(value)

    if not value:
        continue

    if (value[0] == ord(b'+') or value[0] == ord(b'-')) and value[8] == ord(b'\r') and value[9] == ord(b'\x12'):
        value=value.translate(None, b'\x00\r\x12') # remove unwanted bytes

        decoded_str = value.decode('ascii')
        decoded_int = float(decoded_str)/100.0
        print(decoded_int)

ser.close()             # close port
