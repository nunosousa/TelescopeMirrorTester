import serial


ser = serial.Serial(port = '/dev/ttyUSB0',
                    baudrate = 9600,
                    bytesize = serial.EIGHTBITS,
                    parity = serial.PARITY_ODD,
                    stopbits = serial.STOPBITS_ONE,
                    timeout = 10)

ser.writelines(b'version\r\n')     # write a string
line = ser.readline()   # read a '\n' terminated line

print(line)

ser.close()             # close port