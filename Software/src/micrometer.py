import serial


ser = serial.Serial(port = '/dev/ttyUSB1',
                    baudrate = 9600,
                    bytesize = serial.EIGHTBITS,
                    parity = serial.PARITY_NONE,
                    stopbits = serial.STOPBITS_ONE,
                    timeout = 10)

ser.flush()
x = ser.read(200)          # read one byte

print(x)

ser.close()             # close port
