import serial

#sudo chmod 666 /dev/ttyUSB0
#sudo chmod 666 /dev/ttyUSB1

ser = serial.Serial()

ser.port = '/dev/ttyUSB0'
ser.baudrate = 9600
ser.bytesize = serial.EIGHTBITS
ser.parity = serial.PARITY_ODD
ser.stopbits = serial.STOPBITS_ONE
ser.timeout = 1
ser.xonxoff = False #disable software flow control
ser.rtscts = False  #disable hardware (RTS/CTS) flow control
ser.dsrdtr = False  #disable hardware (DSR/DTR) flow control

ser.open()


line = ser.readline(100)   # read a '\n' terminated line
print(line)


# version command
ser.write(b'version\r\n')     # write a string

line = ser.readline(1000)   # read a '\n' terminated line
print(line)

line = ser.readline(1000)   # read a '\n' terminated line
print(line)


# setSpeed command
ser.write(b'setSpeed A -100\r\n')     # write a string

line = ser.readline(1000)   # read a '\n' terminated line
print(line)

line = ser.readline(1000)   # read a '\n' terminated line
print(line)


# getSpeed command
ser.write(b'getSpeed A\r\n')     # write a string

line = ser.readline(1000)   # read a '\n' terminated line
print(line)

line = ser.readline(1000)   # read a '\n' terminated line
print(line)


# setSpeed command
ser.write(b'setSpeed A 0\r\n')     # write a string

line = ser.readline(1000)   # read a '\n' terminated line
print(line)

line = ser.readline(1000)   # read a '\n' terminated line
print(line)


ser.close()             # close port
