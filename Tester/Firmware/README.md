Install the following packages:

sudo apt-get install gcc-avr
sudo apt-get install gdb-avr
sudo apt-get install avr-libc
sudo apt-get install binutils-avr
sudo apt-get install uisp
sudo apt-get install avrdude


Compile the code (generate a HEX file)
avr-gcc -w -Os -DF_CPU=16000000UL -mmcu=atmega328 -c -o main.o main.c
avr-gcc -w -mmcu=atmega328 main.o -o main
avr-objcopy -O ihex -R .eeprom main main.hex


Program the HEX firmware onto the AVR
sudo avrdude -F -V -c avrispmkII -p ATmega328 -P usb -U flash:w:main.hex
