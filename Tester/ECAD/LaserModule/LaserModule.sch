EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Diode_Laser_Custom:SLD3134VL LD?
U 1 1 5E456480
P 6800 3100
F 0 "LD?" H 6850 3507 50  0000 C CNN
F 1 "SLD3134VL" H 6850 3416 50  0000 C CNN
F 2 "OptoDevice:LaserDiode_TO18-D5.6-3" H 6800 2800 50  0001 C CNN
F 3 "" H 6830 2900 50  0001 C CNN
	1    6800 3100
	1    0    0    -1  
$EndComp
$Comp
L Diode_Laser_Custom:Generic_650nm-5mW LD?
U 1 1 5E457FDF
P 7850 3100
F 0 "LD?" H 7900 3507 50  0000 C CNN
F 1 "Generic_650nm-5mW" H 7900 3416 50  0000 C CNN
F 2 "OptoDevice:LaserDiode_TO18-D5.6-3" H 7850 2800 50  0001 C CNN
F 3 "" H 7880 2900 50  0001 C CNN
	1    7850 3100
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:ZXMP4A16G Q?
U 1 1 5E46C00F
P 5650 3800
F 0 "Q?" H 5854 3846 50  0000 L CNN
F 1 "ZXMP4A16G" H 5854 3755 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 5850 3725 50  0001 L CIN
F 3 "https://www.diodes.com/assets/Datasheets/ZXMP4A16G.pdf" H 5650 3800 50  0001 L CNN
	1    5650 3800
	1    0    0    -1  
$EndComp
$Comp
L Analog_DAC:MCP4728 U?
U 1 1 5E46C78E
P 5500 2600
F 0 "U?" H 5500 3081 50  0000 C CNN
F 1 "MCP4728" H 5500 2990 50  0000 C CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 5500 2000 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22187E.pdf" H 5500 2850 50  0001 C CNN
	1    5500 2600
	1    0    0    -1  
$EndComp
$EndSCHEMATC
