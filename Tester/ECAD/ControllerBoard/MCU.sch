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
Text HLabel 1100 900  0    50   Input ~ 0
V3_3
$Comp
L Device:C C15
U 1 1 5E5846F6
P 6700 1900
F 0 "C15" H 6815 1946 50  0000 L CNN
F 1 "1uC" H 6815 1855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6738 1750 50  0001 C CNN
F 3 "~" H 6700 1900 50  0001 C CNN
F 4 "CC0805MKX7R7BB105" H 6700 1900 50  0001 C CNN "Manufacturer Part Number"
	1    6700 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 5E58564D
P 4650 1900
F 0 "C12" H 4765 1946 50  0000 L CNN
F 1 "10uC" H 4765 1855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4688 1750 50  0001 C CNN
F 3 "~" H 4650 1900 50  0001 C CNN
F 4 "CC0805MRX5R6BB106" H 4650 1900 50  0001 C CNN "Manufacturer Part Number"
	1    4650 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C14
U 1 1 5E586DB7
P 8200 1900
F 0 "C14" H 8315 1946 50  0000 L CNN
F 1 "0.1uC" H 8315 1855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8238 1750 50  0001 C CNN
F 3 "~" H 8200 1900 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 8200 1900 50  0001 C CNN "Manufacturer Part Number"
	1    8200 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 5E588280
P 8700 1900
F 0 "C13" H 8815 1946 50  0000 L CNN
F 1 "0.1uC" H 8815 1855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8738 1750 50  0001 C CNN
F 3 "~" H 8700 1900 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 8700 1900 50  0001 C CNN "Manufacturer Part Number"
	1    8700 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C16
U 1 1 5E58C2F2
P 7200 1900
F 0 "C16" H 7315 1946 50  0000 L CNN
F 1 "0.1uC" H 7315 1855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7238 1750 50  0001 C CNN
F 3 "~" H 7200 1900 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 7200 1900 50  0001 C CNN "Manufacturer Part Number"
	1    7200 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C17
U 1 1 5E58C960
P 7700 1900
F 0 "C17" H 7815 1946 50  0000 L CNN
F 1 "10uC" H 7815 1855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7738 1750 50  0001 C CNN
F 3 "~" H 7700 1900 50  0001 C CNN
F 4 "CC0805MRX5R6BB106" H 7700 1900 50  0001 C CNN "Manufacturer Part Number"
	1    7700 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:L L2
U 1 1 5E58F693
P 5200 900
F 0 "L2" V 5390 900 50  0000 C CNN
F 1 "L" V 5299 900 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5200 900 50  0001 C CNN
F 3 "~" H 5200 900 50  0001 C CNN
F 4 "BLM21SP471SH1D" H 5200 900 50  0001 C CNN "Manufacturer Part Number"
	1    5200 900 
	0    -1   -1   0   
$EndComp
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
Text HLabel 9200 1800 2    50   Input ~ 0
POSY_MISO
Text HLabel 9200 1900 2    50   Output ~ 0
POSY_MOSI
Text HLabel 9200 2000 2    50   Output ~ 0
POSY_SCLK
Text HLabel 8900 2200 2    50   Input ~ 0
POSZ_MISO
Text HLabel 8900 2300 2    50   Output ~ 0
POSZ_MOSI
Text HLabel 8900 2400 2    50   Output ~ 0
POSZ_SCLK
$Comp
L MCU_Microchip_SAMD_Custom:ATSAMD21J18A-AU U1
U 1 1 5E5C7565
P 5550 4200
F 0 "U1" H 5550 2011 50  0000 C CNN
F 1 "ATSAMD21J18A-AU" H 5550 1920 50  0000 C CNN
F 2 "Package_QFP:TQFP-64_10x10mm_P0.5mm" H 5100 1550 50  0001 L BNN
F 3 "" H 5550 4200 50  0001 L BNN
	1    5550 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 6300 5400 6300
Connection ~ 5400 6300
Wire Wire Line
	5400 6300 5500 6300
Connection ~ 5500 6300
Wire Wire Line
	5500 6300 5600 6300
Connection ~ 5600 6300
Wire Wire Line
	5600 6300 5750 6300
Wire Wire Line
	5300 6300 5100 6300
Wire Wire Line
	5100 6300 5100 7150
Connection ~ 5300 6300
Wire Wire Line
	5850 2200 5850 1750
Wire Wire Line
	5850 1750 6700 1750
Wire Wire Line
	5700 2200 5700 1650
Wire Wire Line
	5700 900  5350 900 
Wire Wire Line
	7200 1750 7200 1650
Wire Wire Line
	7200 1650 7700 1650
Wire Wire Line
	7700 1650 7700 1750
Wire Wire Line
	7200 1650 5700 1650
Connection ~ 7200 1650
Connection ~ 5700 1650
Wire Wire Line
	5700 1650 5700 900 
Wire Wire Line
	7700 2050 7450 2050
Connection ~ 7200 2050
Wire Wire Line
	7200 2050 6700 2050
Wire Wire Line
	5200 2200 5300 2200
Connection ~ 5300 2200
Wire Wire Line
	5300 2200 5400 2200
Wire Wire Line
	5400 2200 5400 1550
Wire Wire Line
	5400 1550 8200 1550
Wire Wire Line
	8200 1550 8200 1750
Connection ~ 5400 2200
Wire Wire Line
	8200 2050 7700 2050
Connection ~ 7700 2050
Wire Wire Line
	8700 2050 8200 2050
Connection ~ 8200 2050
Wire Wire Line
	8700 1750 8700 1450
Wire Wire Line
	8700 1450 5550 1450
Wire Wire Line
	5550 1450 5550 2200
Wire Wire Line
	5750 6300 7450 6300
Wire Wire Line
	7450 6300 7450 2050
Connection ~ 5750 6300
Connection ~ 7450 2050
Wire Wire Line
	7450 2050 7200 2050
Connection ~ 6700 2050
Wire Wire Line
	4650 1750 4650 900 
Connection ~ 4650 900 
Wire Wire Line
	4650 2050 6700 2050
Wire Wire Line
	1100 900  4650 900 
Wire Wire Line
	1000 7150 5100 7150
Wire Wire Line
	4650 900  5050 900 
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J16
U 1 1 5E5DF00C
P 2600 2150
F 0 "J16" H 2650 2567 50  0000 C CNN
F 1 "Conn_02x05_Odd_Even" H 2650 2476 50  0000 C CNN
F 2 "" H 2600 2150 50  0001 C CNN
F 3 "~" H 2600 2150 50  0001 C CNN
	1    2600 2150
	1    0    0    -1  
$EndComp
$EndSCHEMATC
