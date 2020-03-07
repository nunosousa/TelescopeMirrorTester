EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 3500 3300 2    50   Output ~ 0
MOTOR_CTRL_1A
Text HLabel 3500 3400 2    50   Output ~ 0
MOTOR_CTRL_1B
Text HLabel 3500 3550 2    50   Output ~ 0
MOTOR_CTRL_2A
Text HLabel 3500 3650 2    50   Output ~ 0
MOTOR_CTRL_2B
Text HLabel 3500 3800 2    50   Output ~ 0
MOTOR_CTRL_3A
Text HLabel 3500 3900 2    50   Output ~ 0
MOTOR_CTRL_3B
Text HLabel 3500 4050 2    50   Output ~ 0
MOTOR_CTRL_4A
Text HLabel 3500 4150 2    50   Output ~ 0
MOTOR_CTRL_4B
Text HLabel 1800 5750 2    50   Input ~ 0
MOTOR_FAULT_12
Text HLabel 1800 5850 2    50   Input ~ 0
MOTOR_FAULT_34
Text HLabel 3000 5550 2    50   Output ~ 0
MOTOR_SLEEP_12
Text HLabel 3000 5650 2    50   Output ~ 0
MOTOR_SLEEP_34
Text HLabel 1000 7150 0    50   Input ~ 0
GND
Text HLabel 1100 900  0    50   Input ~ 0
V3_3
$Comp
L Device:C C15
U 1 1 5E5846F6
P 6600 2550
F 0 "C15" H 6715 2596 50  0000 L CNN
F 1 "1uC" H 6715 2505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6638 2400 50  0001 C CNN
F 3 "~" H 6600 2550 50  0001 C CNN
F 4 "CC0805MKX7R7BB105" H 6600 2550 50  0001 C CNN "Manufacturer Part Number"
	1    6600 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 5E58564D
P 3600 1300
F 0 "C12" H 3715 1346 50  0000 L CNN
F 1 "10uC" H 3715 1255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3638 1150 50  0001 C CNN
F 3 "~" H 3600 1300 50  0001 C CNN
F 4 "CC0805MRX5R6BB106" H 3600 1300 50  0001 C CNN "Manufacturer Part Number"
	1    3600 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C14
U 1 1 5E586DB7
P 4800 1550
F 0 "C14" H 4915 1596 50  0000 L CNN
F 1 "0.1uC" H 4915 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4838 1400 50  0001 C CNN
F 3 "~" H 4800 1550 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 4800 1550 50  0001 C CNN "Manufacturer Part Number"
	1    4800 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 5E588280
P 4200 1550
F 0 "C13" H 4315 1596 50  0000 L CNN
F 1 "0.1uC" H 4315 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4238 1400 50  0001 C CNN
F 3 "~" H 4200 1550 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 4200 1550 50  0001 C CNN "Manufacturer Part Number"
	1    4200 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C16
U 1 1 5E58C2F2
P 5950 1550
F 0 "C16" H 6065 1596 50  0000 L CNN
F 1 "0.1uC" H 6065 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5988 1400 50  0001 C CNN
F 3 "~" H 5950 1550 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 5950 1550 50  0001 C CNN "Manufacturer Part Number"
	1    5950 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C17
U 1 1 5E58C960
P 6400 1550
F 0 "C17" H 6515 1596 50  0000 L CNN
F 1 "10uC" H 6515 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6438 1400 50  0001 C CNN
F 3 "~" H 6400 1550 50  0001 C CNN
F 4 "CC0805MRX5R6BB106" H 6400 1550 50  0001 C CNN "Manufacturer Part Number"
	1    6400 1550
	1    0    0    -1  
$EndComp
Text HLabel 2500 3250 2    50   Input ~ 0
POSX_MISO
Text HLabel 2500 3350 2    50   Output ~ 0
POSX_MOSI
Text HLabel 2500 3450 2    50   Output ~ 0
POSX_SCLK
Text HLabel 2500 4600 2    50   Output ~ 0
~POSX_NCS
Text HLabel 2500 4700 2    50   Output ~ 0
~POSY_NCS
Text HLabel 2500 4800 2    50   Output ~ 0
~POSZ_NCS
Text HLabel 1850 5400 2    50   Input ~ 0
POSX_MOTION
Text HLabel 1850 5500 2    50   Input ~ 0
POSY_MOTION
Text HLabel 1850 5600 2    50   Input ~ 0
POSZ_MOTION
Text HLabel 2450 5050 2    50   Output ~ 0
~POSX_NRESET
Text HLabel 2450 5150 2    50   Output ~ 0
~POSY_NRESET
Text HLabel 2450 5250 2    50   Output ~ 0
~POSZ_NRESET
Text HLabel 1950 6050 2    50   Input ~ 0
END_STOP_X+
Text HLabel 1950 6200 2    50   Input ~ 0
END_STOP_Y+
Text HLabel 3200 6100 2    50   Input ~ 0
END_STOP_Z+
Text HLabel 3200 6300 2    50   Input ~ 0
END_STOP_X-
Text HLabel 3200 6450 2    50   Input ~ 0
END_STOP_Y-
Text HLabel 3200 6650 2    50   Input ~ 0
END_STOP_Z-
Text HLabel 3450 4450 2    50   BiDi ~ 0
LASER_SDA
Text HLabel 3500 4650 2    50   Output ~ 0
LASER_SCL
Text HLabel 2800 3700 2    50   Input ~ 0
POSY_MISO
Text HLabel 2800 3800 2    50   Output ~ 0
POSY_MOSI
Text HLabel 2800 3900 2    50   Output ~ 0
POSY_SCLK
Text HLabel 2500 4100 2    50   Input ~ 0
POSZ_MISO
Text HLabel 2500 4200 2    50   Output ~ 0
POSZ_MOSI
Text HLabel 2500 4300 2    50   Output ~ 0
POSZ_SCLK
Wire Wire Line
	5100 6300 5100 7150
Wire Wire Line
	5600 6300 5750 6300
Connection ~ 5600 6300
Wire Wire Line
	5500 6300 5600 6300
Connection ~ 5500 6300
Wire Wire Line
	5400 6300 5500 6300
Connection ~ 5400 6300
Wire Wire Line
	5300 6300 5100 6300
Wire Wire Line
	5300 6300 5400 6300
Connection ~ 5300 6300
Wire Wire Line
	5300 2200 5400 2200
Wire Wire Line
	5200 2200 5300 2200
Connection ~ 5300 2200
$Comp
L MCU_Microchip_SAMD_Custom:ATSAMD21J18A-AU U1
U 1 1 5E5C7565
P 5550 4200
F 0 "U1" H 5550 2011 50  0000 C CNN
F 1 "ATSAMD21J18A-AU" H 5550 1920 50  0000 C CNN
F 2 "Package_QFP:TQFP-64_10x10mm_P0.5mm" H 5100 1550 50  0001 L BNN
F 3 "" H 5550 4200 50  0001 L BNN
F 4 "ATSAMD21J18A-AUT" H 5550 4200 50  0001 C CNN "Manufacturer Part Number"
	1    5550 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R25
U 1 1 5E5EDE05
P 8950 3650
F 0 "R25" H 9020 3696 50  0000 L CNN
F 1 "10kR" H 9020 3605 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 8880 3650 50  0001 C CNN
F 3 "~" H 8950 3650 50  0001 C CNN
F 4 "RC0805FR-0710KL" H 8950 3650 50  0001 C CNN "Manufacturer Part Number"
	1    8950 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R27
U 1 1 5E5F27BD
P 1650 1800
F 0 "R27" H 1720 1846 50  0000 L CNN
F 1 "330R" H 1720 1755 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1580 1800 50  0001 C CNN
F 3 "~" H 1650 1800 50  0001 C CNN
F 4 "RC0805FR-07330RL" H 1650 1800 50  0001 C CNN "Manufacturer Part Number"
	1    1650 1800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R28
U 1 1 5E5F34E6
P 1650 1250
F 0 "R28" H 1720 1296 50  0000 L CNN
F 1 "10kR" H 1720 1205 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1580 1250 50  0001 C CNN
F 3 "~" H 1650 1250 50  0001 C CNN
F 4 "RC0805FR-0710KL" H 1650 1250 50  0001 C CNN "Manufacturer Part Number"
	1    1650 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C33
U 1 1 5E5F699E
P 1050 2000
F 0 "C33" H 1165 2046 50  0000 L CNN
F 1 "0.1uC" H 1165 1955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1088 1850 50  0001 C CNN
F 3 "~" H 1050 2000 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 1050 2000 50  0001 C CNN "Manufacturer Part Number"
	1    1050 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 3000 4650 3000
Text HLabel 2250 3700 0    50   BiDi ~ 0
USB_D+
Text HLabel 2250 3950 0    50   BiDi ~ 0
USB_D-
Text HLabel 1400 3650 0    50   Input ~ 0
OC_ALOADS
Text HLabel 1400 3950 0    50   Input ~ 0
OC_DLOADS
Text HLabel 1350 4200 0    50   Output ~ 0
~PS_ALOADS
Text HLabel 1350 4450 0    50   Output ~ 0
~PS_DLOADS
$Comp
L Connector:Conn_ARM_JTAG_SWD_20 J16
U 1 1 5E63A4FC
P 10050 4100
F 0 "J16" H 10550 4900 50  0000 R CNN
F 1 "Conn_ARM_JTAG_SWD_20" H 11050 3250 50  0000 R CNN
F 2 "Connector_IDC:IDC-Header_2x10_P2.54mm_Vertical" H 10500 3050 50  0001 L TNN
F 3 "http://infocenter.arm.com/help/topic/com.arm.doc.dui0499b/DUI0499B_system_design_reference.pdf" V 9700 2850 50  0001 C CNN
F 4 "5103308-5" H 10050 4100 50  0001 C CNN "Manufacturer Part Number"
	1    10050 4100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5750 6300 10150 6300
Connection ~ 5750 6300
NoConn ~ 9450 4500
Wire Wire Line
	5700 900  10150 900 
Wire Wire Line
	5700 1000 5700 900 
Connection ~ 5700 900 
NoConn ~ 10050 3300
NoConn ~ 9450 3600
NoConn ~ 9450 4300
NoConn ~ 9450 3900
NoConn ~ 9450 4200
NoConn ~ 9450 4600
Wire Wire Line
	8150 4000 8150 5200
Wire Wire Line
	8150 5200 6350 5200
Wire Wire Line
	9450 4100 8550 4100
Wire Wire Line
	8250 4100 8250 5300
Wire Wire Line
	8250 5300 7400 5300
Wire Wire Line
	8950 2950 10150 2950
Wire Wire Line
	10150 900  10150 2950
Wire Wire Line
	10150 2950 10150 3300
Connection ~ 10150 2950
Wire Wire Line
	4650 3000 4650 2100
Wire Wire Line
	4650 2100 9300 2100
Wire Wire Line
	9300 2100 9300 3700
Wire Wire Line
	9300 3700 9450 3700
Wire Wire Line
	1100 900  1650 900 
Wire Wire Line
	8950 3500 8950 2950
Wire Wire Line
	8150 4000 8950 4000
Wire Wire Line
	8950 3800 8950 4000
Connection ~ 8950 4000
Wire Wire Line
	8950 4000 9450 4000
$Comp
L Device:R R26
U 1 1 5E68B768
P 8550 3650
F 0 "R26" H 8620 3696 50  0000 L CNN
F 1 "10kR" H 8620 3605 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 8480 3650 50  0001 C CNN
F 3 "~" H 8550 3650 50  0001 C CNN
F 4 "RC0805FR-0710KL" H 8550 3650 50  0001 C CNN "Manufacturer Part Number"
	1    8550 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 3800 8550 4100
Connection ~ 8550 4100
Wire Wire Line
	8550 4100 8250 4100
Wire Wire Line
	8550 3500 8550 2950
Wire Wire Line
	8550 2950 8950 2950
Connection ~ 8950 2950
$Comp
L Device:R R30
U 1 1 5E68E598
P 7250 5300
F 0 "R30" V 7050 5200 50  0000 L CNN
F 1 "22R" V 7150 5200 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7180 5300 50  0001 C CNN
F 3 "~" H 7250 5300 50  0001 C CNN
F 4 "" H 7250 5300 50  0001 C CNN "Manufacturer Part Number"
	1    7250 5300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7100 5300 6350 5300
$Comp
L Switch:SW_SPST SW1
U 1 1 5E5F8021
P 1650 2200
F 0 "SW1" V 1604 2298 50  0000 L CNN
F 1 "SW_SPST" V 1695 2298 50  0000 L CNN
F 2 "Button_Switch_THT:SW_Tactile_Straight_KSA0Axx1LFTR" H 1650 2200 50  0001 C CNN
F 3 "~" H 1650 2200 50  0001 C CNN
F 4 "KSA0A311 LFTR" H 1650 2200 50  0001 C CNN "Manufacturer Part Number"
	1    1650 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	1650 1400 1650 1500
Connection ~ 1650 1550
Wire Wire Line
	1650 1100 1650 900 
Connection ~ 1650 900 
Wire Wire Line
	4650 2100 2150 2100
Wire Wire Line
	2150 2100 2150 1550
Connection ~ 4650 2100
Wire Wire Line
	1650 2500 1650 2750
Wire Wire Line
	1000 7150 1650 7150
Wire Wire Line
	1650 7150 5100 7150
Connection ~ 1650 7150
$Comp
L Device:L L2
U 1 1 5E58F693
P 5700 1150
F 0 "L2" H 5800 1050 50  0000 C CNN
F 1 "L" H 5800 1150 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5700 1150 50  0001 C CNN
F 3 "~" H 5700 1150 50  0001 C CNN
F 4 "BLM21SP471SH1D" H 5700 1150 50  0001 C CNN "Manufacturer Part Number"
	1    5700 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 6300 10150 4900
Wire Wire Line
	6400 1400 5950 1400
Wire Wire Line
	5950 1400 5700 1400
Connection ~ 5950 1400
Connection ~ 5700 1400
Wire Wire Line
	5700 1400 5700 1300
Wire Wire Line
	6400 1700 5950 1700
Wire Wire Line
	5700 2200 5700 1400
Wire Wire Line
	1650 900  3600 900 
Connection ~ 5950 1700
Wire Wire Line
	5850 2200 6350 2200
Wire Wire Line
	6350 2200 6350 2800
Wire Wire Line
	6350 2800 6600 2800
Wire Wire Line
	6600 2800 6600 2700
Wire Wire Line
	6600 2400 6600 1700
Wire Wire Line
	6600 1700 6400 1700
Connection ~ 6400 1700
Connection ~ 4800 1700
Connection ~ 4200 1700
Wire Wire Line
	4200 1700 4800 1700
Wire Wire Line
	4800 1700 5950 1700
Wire Wire Line
	5200 2200 5200 1350
Wire Wire Line
	5200 1350 4800 1350
Wire Wire Line
	4800 1350 4800 1400
Connection ~ 5200 2200
Wire Wire Line
	5550 2200 5550 1250
Wire Wire Line
	5550 1250 4200 1250
Wire Wire Line
	4200 1250 4200 1400
Wire Wire Line
	3600 1150 3600 900 
Connection ~ 3600 900 
Wire Wire Line
	3600 900  5700 900 
Wire Wire Line
	3600 1450 3600 1700
Wire Wire Line
	3600 1700 4200 1700
Wire Wire Line
	3600 1700 3600 2750
Wire Wire Line
	3600 2750 1650 2750
Connection ~ 3600 1700
Connection ~ 1650 2750
Wire Wire Line
	1650 2750 1650 7150
Wire Wire Line
	1650 1550 2150 1550
Wire Wire Line
	1650 2000 1650 1950
Wire Wire Line
	1650 2400 1650 2500
Connection ~ 1650 2500
Wire Wire Line
	1650 1650 1650 1550
Wire Wire Line
	1050 2500 1050 2150
Wire Wire Line
	1050 2500 1650 2500
Wire Wire Line
	1050 1500 1650 1500
Wire Wire Line
	1050 1500 1050 1850
Connection ~ 1650 1500
Wire Wire Line
	1650 1500 1650 1550
$EndSCHEMATC
