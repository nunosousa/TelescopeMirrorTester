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
L Device:R R5
U 1 1 5E479FC2
P 10600 2900
F 0 "R5" H 10670 2946 50  0000 L CNN
F 1 "4kR" H 10670 2855 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 10530 2900 50  0001 C CNN
F 3 "~" H 10600 2900 50  0001 C CNN
F 4 "tbd" H 10600 2900 50  0001 C CNN "Manufacturer Part Number"
	1    10600 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5E47A4F4
P 7300 2550
F 0 "R4" V 7093 2550 50  0000 C CNN
F 1 "10kR" V 7184 2550 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7230 2550 50  0001 C CNN
F 3 "~" H 7300 2550 50  0001 C CNN
F 4 "RC0805FR-0710KL" H 7300 2550 50  0001 C CNN "Manufacturer Part Number"
	1    7300 2550
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5E47A91E
P 4550 2950
F 0 "R2" V 4757 2950 50  0000 C CNN
F 1 "20kR" V 4666 2950 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4480 2950 50  0001 C CNN
F 3 "~" H 4550 2950 50  0001 C CNN
F 4 "tbd" H 4550 2950 50  0001 C CNN "Manufacturer Part Number"
	1    4550 2950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 5E47AA27
P 5000 2300
F 0 "R3" H 5070 2346 50  0000 L CNN
F 1 "30kR" H 5070 2255 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4930 2300 50  0001 C CNN
F 3 "~" H 5000 2300 50  0001 C CNN
F 4 "tbd" H 5000 2300 50  0001 C CNN "Manufacturer Part Number"
	1    5000 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5E47AB6E
P 9050 2050
F 0 "R1" H 9120 2096 50  0000 L CNN
F 1 "12R" H 9120 2005 50  0000 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" V 8980 2050 50  0001 C CNN
F 3 "~" H 9050 2050 50  0001 C CNN
F 4 "tbd" H 9050 2050 50  0001 C CNN "Manufacturer Part Number"
	1    9050 2050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5E47AED4
P 5000 3550
F 0 "C2" H 5115 3596 50  0000 L CNN
F 1 "1nC" H 5115 3505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5038 3400 50  0001 C CNN
F 3 "~" H 5000 3550 50  0001 C CNN
F 4 "tbd" H 5000 3550 50  0001 C CNN "Manufacturer Part Number"
	1    5000 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5E47B442
P 6850 2800
F 0 "C1" H 6965 2846 50  0000 L CNN
F 1 "100pC" H 6965 2755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6888 2650 50  0001 C CNN
F 3 "~" H 6850 2800 50  0001 C CNN
F 4 "tbd" H 6850 2800 50  0001 C CNN "Manufacturer Part Number"
	1    6850 2800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5E47BBB2
P 6750 6050
F 0 "#PWR01" H 6750 5800 50  0001 C CNN
F 1 "GND" H 6755 5877 50  0000 C CNN
F 2 "" H 6750 6050 50  0001 C CNN
F 3 "" H 6750 6050 50  0001 C CNN
	1    6750 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 2950 4400 2950
Wire Wire Line
	5700 2950 5000 2950
Wire Wire Line
	5000 2450 5000 2950
Connection ~ 5000 2950
Wire Wire Line
	5000 2950 4700 2950
Wire Wire Line
	5000 2950 5000 3400
Wire Wire Line
	3650 5400 3650 3450
Wire Wire Line
	5000 3700 5000 5400
Connection ~ 5000 5400
Wire Wire Line
	5000 5400 3650 5400
Wire Wire Line
	6750 6050 6750 5400
Connection ~ 6750 5400
Wire Wire Line
	6750 5400 5900 5400
Wire Wire Line
	10600 3050 10600 5400
Wire Wire Line
	10600 2750 10600 2400
Wire Wire Line
	10600 2400 9050 2400
Wire Wire Line
	9050 2400 9050 2200
Connection ~ 9050 2400
Wire Wire Line
	9050 1900 9050 1500
Wire Wire Line
	9050 1500 7100 1500
Wire Wire Line
	5000 1500 5000 2150
Wire Wire Line
	3650 2750 3650 1500
Wire Wire Line
	3650 1500 5000 1500
Connection ~ 5000 1500
Wire Wire Line
	5900 2750 5900 1500
Connection ~ 5900 1500
Wire Wire Line
	5900 1500 5000 1500
Wire Wire Line
	5900 3350 5900 5400
Connection ~ 5900 5400
Wire Wire Line
	5900 5400 5000 5400
$Comp
L power:+5C #PWR02
U 1 1 5E48B4EC
P 7100 1500
F 0 "#PWR02" H 7100 1350 50  0001 C CNN
F 1 "+5C" H 7115 1673 50  0000 C CNN
F 2 "" H 7100 1500 50  0001 C CNN
F 3 "" H 7100 1500 50  0001 C CNN
	1    7100 1500
	1    0    0    -1  
$EndComp
Connection ~ 7100 1500
Wire Wire Line
	7100 1500 5900 1500
Wire Wire Line
	3050 3150 2400 3150
Wire Wire Line
	2400 1500 3650 1500
Wire Wire Line
	2400 1500 2400 3150
Connection ~ 3650 1500
Wire Wire Line
	1400 3150 1900 3150
Wire Wire Line
	1900 3150 1900 1500
Wire Wire Line
	1900 1500 2400 1500
Connection ~ 2400 1500
Wire Wire Line
	3050 2950 2100 2950
Wire Wire Line
	2100 2950 2100 3250
Wire Wire Line
	2100 3250 1400 3250
Wire Wire Line
	3050 3050 2200 3050
Wire Wire Line
	2200 3050 2200 3350
Wire Wire Line
	2200 3350 1400 3350
Wire Wire Line
	3650 5400 2350 5400
Wire Wire Line
	2350 5400 2350 3450
Wire Wire Line
	2350 3450 1400 3450
Connection ~ 3650 5400
$Comp
L Mechanical:MountingHole H1
U 1 1 5E4A9DE3
P 1550 6450
F 0 "H1" H 1650 6496 50  0000 L CNN
F 1 "MountingHole" H 1650 6405 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad" H 1550 6450 50  0001 C CNN
F 3 "~" H 1550 6450 50  0001 C CNN
F 4 "" H 1550 6450 50  0001 C CNN "Manufacturer Part Number"
	1    1550 6450
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5E4A9F61
P 1550 6700
F 0 "H2" H 1650 6746 50  0000 L CNN
F 1 "MountingHole" H 1650 6655 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad" H 1550 6700 50  0001 C CNN
F 3 "~" H 1550 6700 50  0001 C CNN
F 4 "" H 1550 6700 50  0001 C CNN "Manufacturer Part Number"
	1    1550 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 3050 6850 3050
$Comp
L Amplifier_Operational_Custom:AD8601 U2
U 1 1 5E4799F9
P 6000 3050
F 0 "U2" H 6344 3096 50  0000 L CNN
F 1 "AD8601" H 6344 3005 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23-5" H 6000 3050 50  0001 C CNN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/AD8601_8602_8604.pdf" H 6000 3250 50  0001 C CNN
F 4 "AD8601WDRTZ-REEL7" H 6000 3050 50  0001 C CNN "Manufacturer Part Number"
	1    6000 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 2400 9050 2550
Wire Wire Line
	7450 2550 9050 2550
Connection ~ 9050 2550
Wire Wire Line
	7150 2550 6850 2550
Wire Wire Line
	5600 2550 5600 3150
Wire Wire Line
	5600 3150 5700 3150
Wire Wire Line
	6850 2650 6850 2550
Connection ~ 6850 2550
Wire Wire Line
	6850 2550 5600 2550
Wire Wire Line
	6850 2950 6850 3050
Connection ~ 6850 3050
Wire Wire Line
	6850 3050 8750 3050
Wire Wire Line
	9050 2550 9050 2850
$Comp
L Diode_Laser_Custom:SLD3134VL LD1
U 1 1 5E4E7513
P 9950 4350
F 0 "LD1" V 10046 4150 50  0000 R CNN
F 1 "SLD3134VL" V 9955 4150 50  0000 R CNN
F 2 "OptoDevice_Custom:LaserDiode_TO18-D5.6-3" H 9950 4050 50  0001 C CNN
F 3 "" H 9980 4150 50  0001 C CNN
F 4 "" H 9950 4350 50  0001 C CNN "Manufacturer Part Number"
	1    9950 4350
	0    -1   -1   0   
$EndComp
Text Label 5600 3150 0    50   ~ 0
V-
Text Label 5650 2950 0    50   ~ 0
V+
Text Label 8700 3050 0    50   ~ 0
G
Text Label 9050 2850 0    50   ~ 0
S
Text Label 9050 3300 0    50   ~ 0
D
Text Label 4250 2950 0    50   ~ 0
VOUT
Text Label 2700 2950 0    50   ~ 0
SCL
Text Label 2700 3050 0    50   ~ 0
SDA
$Comp
L Analog_DAC_Custom:MCP4716 U1
U 1 1 5E4F9088
P 3650 3050
F 0 "U1" H 4294 3046 50  0000 L CNN
F 1 "MCP4716" H 4294 2955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 3650 2450 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22272C.pdf" H 3650 3300 50  0001 C CNN
F 4 "MCP4716A3T-E/CH" H 3650 3050 50  0001 C CNN "Manufacturer Part Number"
	1    3650 3050
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP1
U 1 1 5E737829
P 8750 3550
F 0 "JP1" V 8750 3462 50  0000 R CNN
F 1 "SolderJumper_2_Open" H 8750 3664 50  0001 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 8750 3550 50  0001 C CNN
F 3 "~" H 8750 3550 50  0001 C CNN
	1    8750 3550
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_FET_Custom:ZXMP6A17G Q1
U 1 1 5E4DF28A
P 8950 3050
F 0 "Q1" H 9154 3096 50  0000 L CNN
F 1 "ZXMP6A17G" H 9154 3005 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 9150 2975 50  0001 L CIN
F 3 "https://www.diodes.com/assets/Datasheets/ZXMP6A17G.pdf" H 8950 3050 50  0001 L CNN
F 4 "ZXMP6A17GTA" H 8950 3050 50  0001 C CNN "Manufacturer Part Number"
	1    8950 3050
	1    0    0    1   
$EndComp
Wire Wire Line
	6750 5400 8750 5400
$Comp
L Jumper:SolderJumper_2_Open JP2
U 1 1 5E7419CA
P 9050 3550
F 0 "JP2" V 9050 3462 50  0000 R CNN
F 1 "SolderJumper_2_Open" H 9050 3664 50  0001 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 9050 3550 50  0001 C CNN
F 3 "~" H 9050 3550 50  0001 C CNN
	1    9050 3550
	0    -1   -1   0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP3
U 1 1 5E741ED9
P 9350 3550
F 0 "JP3" V 9350 3462 50  0000 R CNN
F 1 "SolderJumper_2_Open" H 9350 3664 50  0001 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 9350 3550 50  0001 C CNN
F 3 "~" H 9350 3550 50  0001 C CNN
	1    9350 3550
	0    -1   -1   0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP4
U 1 1 5E74AD77
P 8750 5050
F 0 "JP4" V 8750 4962 50  0000 R CNN
F 1 "SolderJumper_2_Open" H 8750 5164 50  0001 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 8750 5050 50  0001 C CNN
F 3 "~" H 8750 5050 50  0001 C CNN
	1    8750 5050
	0    -1   -1   0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP5
U 1 1 5E74B32C
P 9050 5050
F 0 "JP5" V 9050 4962 50  0000 R CNN
F 1 "SolderJumper_2_Open" H 9050 5164 50  0001 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 9050 5050 50  0001 C CNN
F 3 "~" H 9050 5050 50  0001 C CNN
	1    9050 5050
	0    -1   -1   0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP6
U 1 1 5E74B585
P 9350 5050
F 0 "JP6" V 9350 4962 50  0000 R CNN
F 1 "SolderJumper_2_Open" H 9350 5164 50  0001 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 9350 5050 50  0001 C CNN
F 3 "~" H 9350 5050 50  0001 C CNN
	1    9350 5050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8750 3400 8750 3350
Wire Wire Line
	8750 3350 9050 3350
Wire Wire Line
	9050 3350 9050 3300
Wire Wire Line
	9050 3400 9050 3350
Connection ~ 9050 3350
Wire Wire Line
	9350 3400 9350 3300
Wire Wire Line
	9350 3300 9050 3300
Connection ~ 9050 3300
Wire Wire Line
	9050 3300 9050 3250
Wire Wire Line
	8750 5200 8750 5400
Connection ~ 8750 5400
Wire Wire Line
	8750 5400 9050 5400
Wire Wire Line
	9050 5200 9050 5400
Connection ~ 9050 5400
Wire Wire Line
	9050 5400 9350 5400
Wire Wire Line
	9350 5200 9350 5400
Connection ~ 9350 5400
Wire Wire Line
	9350 5400 10600 5400
Wire Wire Line
	8750 4900 8750 3900
Wire Wire Line
	9050 4900 9050 4000
Wire Wire Line
	9350 4900 9350 4750
Wire Wire Line
	9950 4550 9950 4750
Wire Wire Line
	9950 4750 9350 4750
Connection ~ 9350 4750
Wire Wire Line
	9350 4750 9350 3700
Wire Wire Line
	9850 4050 9850 4000
Wire Wire Line
	9850 4000 9050 4000
Connection ~ 9050 4000
Wire Wire Line
	9050 4000 9050 3700
Wire Wire Line
	10050 4050 10050 3900
Wire Wire Line
	10050 3900 8750 3900
Connection ~ 8750 3900
Wire Wire Line
	8750 3900 8750 3700
$Comp
L Connector_Generic:Conn_01x04 J1
U 1 1 5EB3CF54
P 1200 3350
F 0 "J1" H 1280 3342 50  0000 L CNN
F 1 "Conn_01x04" H 1280 3251 50  0000 L CNN
F 2 "Connector_JST:JST_PH_S4B-PH-K_1x04_P2.00mm_Horizontal" H 1200 3350 50  0001 C CNN
F 3 "http://www.jst-mfg.com/product/pdf/eng/ePH.pdf" H 1200 3350 50  0001 C CNN
F 4 "S4B-PH-K-S(LF)(SN)" H 1200 3350 50  0001 C CNN "Manufacturer Part Number"
	1    1200 3350
	-1   0    0    1   
$EndComp
$EndSCHEMATC
