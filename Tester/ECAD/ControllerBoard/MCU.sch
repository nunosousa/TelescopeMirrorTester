EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 5
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
L MCU_Microchip_SAMD:ATSAMD21G18A-AUT U1
U 1 1 5E507201
P 5450 3800
F 0 "U1" H 5450 1811 50  0000 C CNN
F 1 "ATSAMD21G18A-AUT" H 5450 1720 50  0000 C CNN
F 2 "Package_QFP:TQFP-48_7x7mm_P0.5mm" H 4500 2050 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/SAMD21-Family-DataSheet-DS40001882D.pdf" H 5450 4800 50  0001 C CNN
F 4 "ATSAMD21G18A-AUT" H 5450 3800 50  0001 C CNN "Manufacturer Part Number"
	1    5450 3800
	1    0    0    -1  
$EndComp
Text HLabel 9900 1400 2    50   Output ~ 0
MOTOR_CTRL_1A
Text HLabel 9900 1500 2    50   Output ~ 0
MOTOR_CTRL_1B
Text HLabel 9900 1650 2    50   Output ~ 0
MOTOR_CTRL_2A
Text HLabel 9900 1750 2    50   Output ~ 0
MOTOR_CTRL_2B
Text HLabel 9900 1900 2    50   Output ~ 0
MOTOR_CTRL_3A
Text HLabel 9900 2000 2    50   Output ~ 0
MOTOR_CTRL_3B
Text HLabel 9900 2150 2    50   Output ~ 0
MOTOR_CTRL_4A
Text HLabel 9900 2250 2    50   Output ~ 0
MOTOR_CTRL_4B
Text HLabel 8650 4850 2    50   Input ~ 0
MOTOR_FAULT_12
Text HLabel 8650 4950 2    50   Input ~ 0
MOTOR_FAULT_34
Text HLabel 9850 4650 2    50   Output ~ 0
MOTOR_SLEEP_12
Text HLabel 9850 4750 2    50   Output ~ 0
MOTOR_SLEEP_34
Text HLabel 1000 7150 0    50   Input ~ 0
GND
Wire Wire Line
	5350 5700 5350 6150
Wire Wire Line
	5350 7150 4100 7150
Text HLabel 1100 900  0    50   Input ~ 0
V3_3
Wire Wire Line
	5550 5700 5350 5700
Connection ~ 5350 5700
$Comp
L Device:C C15
U 1 1 5E5846F6
P 7250 1700
F 0 "C15" H 7365 1746 50  0000 L CNN
F 1 "1uC" H 7365 1655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7288 1550 50  0001 C CNN
F 3 "~" H 7250 1700 50  0001 C CNN
F 4 "CC0805MKX7R7BB105" H 7250 1700 50  0001 C CNN "Manufacturer Part Number"
	1    7250 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 1900 5650 1300
Wire Wire Line
	5650 1300 7250 1300
Wire Wire Line
	7250 1300 7250 1550
Wire Wire Line
	7250 1850 7250 6150
Wire Wire Line
	7250 6150 5350 6150
Connection ~ 5350 6150
Wire Wire Line
	5350 6150 5350 7150
$Comp
L Device:C C12
U 1 1 5E58564D
P 1700 3600
F 0 "C12" H 1815 3646 50  0000 L CNN
F 1 "10uC" H 1815 3555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1738 3450 50  0001 C CNN
F 3 "~" H 1700 3600 50  0001 C CNN
F 4 "CC0805MRX5R6BB106" H 1700 3600 50  0001 C CNN "Manufacturer Part Number"
	1    1700 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 900  1700 900 
Wire Wire Line
	1700 900  1700 3450
Wire Wire Line
	1700 3750 1700 7150
Connection ~ 1700 7150
Wire Wire Line
	1700 7150 1000 7150
$Comp
L Device:C C14
U 1 1 5E586DB7
P 4100 1700
F 0 "C14" H 4215 1746 50  0000 L CNN
F 1 "0.1uC" H 4215 1655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4138 1550 50  0001 C CNN
F 3 "~" H 4100 1700 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 4100 1700 50  0001 C CNN "Manufacturer Part Number"
	1    4100 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 1900 5350 1300
Wire Wire Line
	5350 1300 4100 1300
Wire Wire Line
	4100 1300 4100 1550
Wire Wire Line
	4100 1850 4100 7150
Connection ~ 4100 7150
Wire Wire Line
	4100 7150 3550 7150
Wire Wire Line
	4100 1300 4100 900 
Wire Wire Line
	4100 900  3550 900 
Connection ~ 4100 1300
Connection ~ 1700 900 
$Comp
L Device:C C13
U 1 1 5E588280
P 3550 1700
F 0 "C13" H 3665 1746 50  0000 L CNN
F 1 "0.1uC" H 3665 1655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3588 1550 50  0001 C CNN
F 3 "~" H 3550 1700 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 3550 1700 50  0001 C CNN "Manufacturer Part Number"
	1    3550 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 1900 5250 1400
Wire Wire Line
	5250 1400 3550 1400
Wire Wire Line
	3550 1400 3550 1550
Wire Wire Line
	3550 1850 3550 7150
Connection ~ 3550 7150
Wire Wire Line
	3550 7150 1700 7150
Wire Wire Line
	3550 1400 3550 900 
Connection ~ 3550 1400
Connection ~ 3550 900 
Wire Wire Line
	3550 900  1700 900 
Wire Wire Line
	5550 1900 5550 1400
Wire Wire Line
	5550 1400 7700 1400
Wire Wire Line
	7700 1550 7700 1400
Connection ~ 7700 1400
Wire Wire Line
	7700 1850 7700 6150
Wire Wire Line
	7700 6150 7250 6150
Connection ~ 7250 6150
Connection ~ 7700 6150
$Comp
L Device:C C16
U 1 1 5E58C2F2
P 7700 1700
F 0 "C16" H 7815 1746 50  0000 L CNN
F 1 "0.1uC" H 7815 1655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7738 1550 50  0001 C CNN
F 3 "~" H 7700 1700 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 7700 1700 50  0001 C CNN "Manufacturer Part Number"
	1    7700 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C17
U 1 1 5E58C960
P 8200 1700
F 0 "C17" H 8315 1746 50  0000 L CNN
F 1 "10uC" H 8315 1655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8238 1550 50  0001 C CNN
F 3 "~" H 8200 1700 50  0001 C CNN
F 4 "CC0805MRX5R6BB106" H 8200 1700 50  0001 C CNN "Manufacturer Part Number"
	1    8200 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 1550 8200 1400
Wire Wire Line
	7700 1400 8200 1400
Wire Wire Line
	8200 1850 8200 6150
Wire Wire Line
	7700 6150 8200 6150
$Comp
L Device:L L2
U 1 1 5E58F693
P 4800 900
F 0 "L2" V 4990 900 50  0000 C CNN
F 1 "L" V 4899 900 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4800 900 50  0001 C CNN
F 3 "~" H 4800 900 50  0001 C CNN
F 4 "BLM21SP471SH1D" H 4800 900 50  0001 C CNN "Manufacturer Part Number"
	1    4800 900 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4650 900  4100 900 
Connection ~ 4100 900 
Wire Wire Line
	4950 900  5550 900 
Wire Wire Line
	5550 900  5550 1400
Connection ~ 5550 1400
Text HLabel 8900 1350 2    50   Input ~ 0
POSX_MISO
Text HLabel 8900 1450 2    50   Output ~ 0
POSX_MOSI
Text HLabel 8900 1550 2    50   Output ~ 0
POSX_SCLK
Text HLabel 8900 2700 2    50   Output ~ 0
~POSX_NCS
Text HLabel 8900 2800 2    50   Output ~ 0
~POSY_NCS
Text HLabel 8900 2900 2    50   Output ~ 0
~POSZ_NCS
Text HLabel 8700 4500 2    50   Input ~ 0
POSX_MOTION
Text HLabel 8700 4600 2    50   Input ~ 0
POSY_MOTION
Text HLabel 8700 4700 2    50   Input ~ 0
POSZ_MOTION
Text HLabel 8850 3150 2    50   Output ~ 0
~POSX_NRESET
Text HLabel 8850 3250 2    50   Output ~ 0
~POSY_NRESET
Text HLabel 8850 3350 2    50   Output ~ 0
~POSZ_NRESET
Text HLabel 8800 5150 2    50   Input ~ 0
END_STOP_X+
Text HLabel 8800 5300 2    50   Input ~ 0
END_STOP_Y+
Text HLabel 8800 5500 2    50   Input ~ 0
END_STOP_Z+
Text HLabel 8800 5700 2    50   Input ~ 0
END_STOP_X-
Text HLabel 8800 5850 2    50   Input ~ 0
END_STOP_Y-
Text HLabel 8800 6050 2    50   Input ~ 0
END_STOP_Z-
Text HLabel 9850 2550 2    50   BiDi ~ 0
LASER_SDA
Text HLabel 9900 2750 2    50   Output ~ 0
LASER_SCL
Text HLabel 8900 1750 2    50   Input ~ 0
POSY_MISO
Text HLabel 8900 1850 2    50   Output ~ 0
POSY_MOSI
Text HLabel 8900 1950 2    50   Output ~ 0
POSY_SCLK
Text HLabel 8900 2200 2    50   Input ~ 0
POSZ_MISO
Text HLabel 8900 2300 2    50   Output ~ 0
POSZ_MOSI
Text HLabel 8900 2400 2    50   Output ~ 0
POSZ_SCLK
$EndSCHEMATC
