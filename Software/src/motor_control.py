import serial


ser = serial.Serial()

ser.port = '/dev/ttyUSB1'
ser.baudrate = 9600
ser.bytesize = serial.EIGHTBITS
ser.parity = serial.PARITY_ODD
ser.stopbits = serial.STOPBITS_ONE
ser.timeout = 1

ser.open()

line = ser.read(100)   # read a '\n' terminated line
print(line)

ser.write(b'version\r\n')     # write a string

line = ser.readline(1000)   # read a '\n' terminated line
print(line)

line = ser.readline(1000)   # read a '\n' terminated line
print(line)

ser.close()             # close port
