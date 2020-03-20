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
L PixArt:PMW3360DM-T2QU U2
U 1 1 5E3F46B3
P 2150 4200
F 0 "U2" H 1850 4800 50  0000 C CNN
F 1 "PMW3360DM-T2QU" H 2150 3850 50  0000 C CNN
F 2 "PixArt:PMW3360DM-T2QU" H 2150 4200 50  0001 C CNN
F 3 "" H 2150 4200 50  0001 C CNN
F 4 "" H 2150 4200 50  0001 C CNN "Manufacturer Part Number"
	1    2150 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5E3F5785
P 1200 6150
F 0 "C1" H 1315 6196 50  0000 L CNN
F 1 "4.7uC" H 1315 6105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1238 6000 50  0001 C CNN
F 3 "~" H 1200 6150 50  0001 C CNN
F 4 "C0805C475K9PACTU" H 1200 6150 50  0001 C CNN "Manufacturer Part Number"
	1    1200 6150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5E3F5E11
P 1650 6150
F 0 "C3" H 1765 6196 50  0000 L CNN
F 1 "100nC" H 1765 6105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1688 6000 50  0001 C CNN
F 3 "~" H 1650 6150 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 1650 6150 50  0001 C CNN "Manufacturer Part Number"
	1    1650 6150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5E3F78DD
P 3850 7400
F 0 "#PWR01" H 3850 7150 50  0001 C CNN
F 1 "GND" H 3855 7227 50  0000 C CNN
F 2 "" H 3850 7400 50  0001 C CNN
F 3 "" H 3850 7400 50  0001 C CNN
	1    3850 7400
	1    0    0    -1  
$EndComp
$Comp
L Logic_LevelTranslator:SN74LVC1T45DBV U4
U 1 1 5E3FADD1
P 4750 2550
F 0 "U4" H 5050 2900 50  0000 L CNN
F 1 "SN74LVC1T45DBV" H 5050 2200 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 4750 2100 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1t45.pdf" H 3850 1900 50  0001 C CNN
F 4 "SN74LVC1T45DBVR" H 4750 2550 50  0001 C CNN "Manufacturer Part Number"
	1    4750 2550
	1    0    0    -1  
$EndComp
$Comp
L Logic_LevelTranslator:SN74LVC1T45DBV U5
U 1 1 5E3FB68D
P 4750 3600
F 0 "U5" H 5050 3950 50  0000 L CNN
F 1 "SN74LVC1T45DBV" H 5050 3250 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 4750 3150 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1t45.pdf" H 3850 2950 50  0001 C CNN
F 4 "SN74LVC1T45DBVR" H 4750 3600 50  0001 C CNN "Manufacturer Part Number"
	1    4750 3600
	1    0    0    -1  
$EndComp
$Comp
L Logic_LevelTranslator:SN74LVC1T45DBV U8
U 1 1 5E3FBBCA
P 4750 6700
F 0 "U8" H 5050 7050 50  0000 L CNN
F 1 "SN74LVC1T45DBV" H 5050 6350 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 4750 6250 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1t45.pdf" H 3850 6050 50  0001 C CNN
F 4 "SN74LVC1T45DBVR" H 4750 6700 50  0001 C CNN "Manufacturer Part Number"
	1    4750 6700
	1    0    0    -1  
$EndComp
$Comp
L Logic_LevelTranslator:SN74LVC1T45DBV U7
U 1 1 5E3FC3D2
P 4750 5600
F 0 "U7" H 5050 5950 50  0000 L CNN
F 1 "SN74LVC1T45DBV" H 5050 5250 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 4750 5150 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1t45.pdf" H 3850 4950 50  0001 C CNN
F 4 "SN74LVC1T45DBVR" H 4750 5600 50  0001 C CNN "Manufacturer Part Number"
	1    4750 5600
	1    0    0    -1  
$EndComp
$Comp
L Logic_LevelTranslator:SN74LVC1T45DBV U6
U 1 1 5E3FC5FB
P 4750 4600
F 0 "U6" H 5050 4950 50  0000 L CNN
F 1 "SN74LVC1T45DBV" H 5050 4250 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 4750 4150 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1t45.pdf" H 3850 3950 50  0001 C CNN
F 4 "SN74LVC1T45DBVR" H 4750 4600 50  0001 C CNN "Manufacturer Part Number"
	1    4750 4600
	1    0    0    -1  
$EndComp
$Comp
L Logic_LevelTranslator:SN74LVC1T45DBV U3
U 1 1 5E3F6A5F
P 4750 1400
F 0 "U3" H 5050 1750 50  0000 L CNN
F 1 "SN74LVC1T45DBV" H 5050 1050 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 4750 950 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1t45.pdf" H 3850 750 50  0001 C CNN
F 4 "SN74LVC1T45DBVR" H 4750 1400 50  0001 C CNN "Manufacturer Part Number"
	1    4750 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 4050 3250 4050
Wire Wire Line
	3250 4050 3250 1400
Wire Wire Line
	3250 1400 4350 1400
Wire Wire Line
	2600 4150 3550 4150
Wire Wire Line
	3550 4150 3550 2550
Wire Wire Line
	3550 2550 4350 2550
Wire Wire Line
	2600 4250 3700 4250
Wire Wire Line
	3700 4250 3700 3600
Wire Wire Line
	3700 3600 4350 3600
Wire Wire Line
	2600 4350 3700 4350
Wire Wire Line
	3700 4350 3700 4600
Wire Wire Line
	3700 4600 4350 4600
Wire Wire Line
	2600 4450 3550 4450
Wire Wire Line
	3550 4450 3550 5600
Wire Wire Line
	3550 5600 4350 5600
Text Label 2850 4050 0    50   ~ 0
~NCS
Text Label 2850 4150 0    50   ~ 0
MISO
Text Label 2850 4250 0    50   ~ 0
MOSI
Text Label 2850 4350 0    50   ~ 0
SCLK
Text Label 2850 4450 0    50   ~ 0
MOTION
Wire Wire Line
	1700 4350 1600 4350
Wire Wire Line
	1600 4350 1600 4850
Wire Wire Line
	1600 4850 3300 4850
Wire Wire Line
	3300 4850 3300 6700
Wire Wire Line
	3300 6700 4350 6700
Text Label 2850 4850 0    50   ~ 0
~NRESET
Wire Wire Line
	3850 1950 4300 1950
Wire Wire Line
	4750 1950 4750 1800
Wire Wire Line
	4750 2950 4750 3000
Wire Wire Line
	4750 3000 3850 3000
Connection ~ 3850 3000
Wire Wire Line
	4750 4000 4750 4050
Wire Wire Line
	4750 4050 4250 4050
Connection ~ 3850 4050
Wire Wire Line
	3850 4050 3850 3000
Wire Wire Line
	4750 5000 4750 5050
Wire Wire Line
	4750 5050 4250 5050
Connection ~ 3850 5050
Wire Wire Line
	3850 5050 3850 4050
Wire Wire Line
	4750 6000 4750 6050
Wire Wire Line
	4750 6050 3850 6050
Connection ~ 3850 6050
Wire Wire Line
	3850 6050 3850 5050
Wire Wire Line
	4750 7100 4750 7200
Wire Wire Line
	4750 7200 4300 7200
Connection ~ 3850 7200
Wire Wire Line
	3850 7200 3850 7050
Wire Wire Line
	1700 4450 1700 5250
Wire Wire Line
	1700 5250 3100 5250
Wire Wire Line
	3100 5250 3100 7050
Wire Wire Line
	3100 7050 3850 7050
Connection ~ 3850 7050
Wire Wire Line
	3850 7050 3850 6050
Text Label 2250 5250 0    50   ~ 0
GND
Wire Wire Line
	1650 6000 1650 5850
Wire Wire Line
	1650 5850 1450 5850
Wire Wire Line
	1200 5850 1200 6000
Wire Wire Line
	1700 3950 1450 3950
Wire Wire Line
	1450 3950 1450 5850
Connection ~ 1450 5850
Wire Wire Line
	1450 5850 1200 5850
Wire Wire Line
	1700 4050 1600 4050
Wire Wire Line
	1600 4050 1600 4150
Wire Wire Line
	1600 4150 1700 4150
$Comp
L Regulator_Linear:TLV70019_SOT23-5 U1
U 1 1 5E421D87
P 2050 1700
F 0 "U1" H 2300 1450 50  0000 C CNN
F 1 "TLV70019_SOT23-5" H 2200 1950 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5_HandSoldering" H 2050 2025 50  0001 C CIN
F 3 "http://www.ti.com/lit/ds/symlink/tlv700.pdf" H 2050 1750 50  0001 C CNN
F 4 "TLV70019DDCT" H 2050 1700 50  0001 C CNN "Manufacturer Part Number"
	1    2050 1700
	1    0    0    -1  
$EndComp
Connection ~ 3850 2200
Wire Wire Line
	3850 2200 3850 1950
Wire Wire Line
	2350 1600 2550 1600
Wire Wire Line
	3000 1600 3000 2850
Wire Wire Line
	3000 2850 2900 2850
Wire Wire Line
	1050 2850 1050 4050
Wire Wire Line
	1050 4050 1600 4050
Connection ~ 1600 4050
Wire Wire Line
	3000 1600 4050 1600
Wire Wire Line
	4050 1600 4050 900 
Wire Wire Line
	4050 900  4650 900 
Wire Wire Line
	4650 900  4650 1000
Connection ~ 3000 1600
Wire Wire Line
	4050 1600 4050 2050
Wire Wire Line
	4050 2050 4650 2050
Wire Wire Line
	4650 2050 4650 2150
Connection ~ 4050 1600
Wire Wire Line
	4050 2050 4050 2750
Wire Wire Line
	4050 3100 4650 3100
Wire Wire Line
	4650 3100 4650 3200
Connection ~ 4050 2050
Wire Wire Line
	4050 4150 4650 4150
Wire Wire Line
	4650 4150 4650 4200
Connection ~ 4050 3100
Wire Wire Line
	4050 5150 4650 5150
Wire Wire Line
	4650 5150 4650 5200
Connection ~ 4050 4150
Wire Wire Line
	4050 5150 4050 5800
Wire Wire Line
	4050 6200 4650 6200
Wire Wire Line
	4650 6200 4650 6300
Connection ~ 4050 5150
Wire Wire Line
	4350 1600 4300 1600
Wire Wire Line
	4300 1600 4300 1950
Connection ~ 4300 1950
Wire Wire Line
	4300 1950 4750 1950
Wire Wire Line
	4350 5800 4050 5800
Connection ~ 4050 5800
Wire Wire Line
	4050 5800 4050 6200
Wire Wire Line
	4350 6900 4300 6900
Wire Wire Line
	4300 6900 4300 7200
Connection ~ 4300 7200
Wire Wire Line
	4300 7200 3850 7200
Wire Wire Line
	3850 2200 3850 3000
Wire Wire Line
	4350 2750 4050 2750
Connection ~ 4050 2750
Wire Wire Line
	4050 2750 4050 3100
Wire Wire Line
	4050 3100 4050 4150
Wire Wire Line
	4350 3800 4250 3800
Wire Wire Line
	4250 3800 4250 4050
Connection ~ 4250 4050
Wire Wire Line
	4250 4050 3850 4050
Wire Wire Line
	4050 4150 4050 5150
Wire Wire Line
	4350 4800 4250 4800
Wire Wire Line
	4250 4800 4250 5050
Connection ~ 4250 5050
Wire Wire Line
	4250 5050 3850 5050
$Comp
L Device:C C4
U 1 1 5E453DF9
P 2550 1850
F 0 "C4" H 2665 1896 50  0000 L CNN
F 1 "1uC" H 2665 1805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2588 1700 50  0001 C CNN
F 3 "~" H 2550 1850 50  0001 C CNN
F 4 "CC0805MKX7R7BB105" H 2550 1850 50  0001 C CNN "Manufacturer Part Number"
	1    2550 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5E45460A
P 1300 1850
F 0 "C2" H 1415 1896 50  0000 L CNN
F 1 "1uC" H 1415 1805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1338 1700 50  0001 C CNN
F 3 "~" H 1300 1850 50  0001 C CNN
F 4 "CC0805MKX7R7BB105" H 1300 1850 50  0001 C CNN "Manufacturer Part Number"
	1    1300 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 1700 2550 1600
Connection ~ 2550 1600
Wire Wire Line
	2550 1600 3000 1600
Wire Wire Line
	2550 2000 2550 2200
Connection ~ 2550 2200
Wire Wire Line
	2550 2200 3850 2200
Wire Wire Line
	1750 1600 1650 1600
Wire Wire Line
	1300 1600 1300 1700
Wire Wire Line
	1300 2200 1300 2000
Wire Wire Line
	1750 1700 1650 1700
Wire Wire Line
	1650 1700 1650 1600
Connection ~ 1650 1600
Wire Wire Line
	1650 1600 1300 1600
$Comp
L Device:R R1
U 1 1 5E485812
P 2900 3400
F 0 "R1" H 2970 3446 50  0000 L CNN
F 1 "39R" H 2970 3355 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2830 3400 50  0001 C CNN
F 3 "~" H 2900 3400 50  0001 C CNN
F 4 "RC0805FR-0739RL" H 2900 3400 50  0001 C CNN "Manufacturer Part Number"
	1    2900 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 3550 2900 3850
Wire Wire Line
	2900 3850 2600 3850
Wire Wire Line
	2900 3250 2900 2850
Connection ~ 2900 2850
Wire Wire Line
	2900 2850 1050 2850
Text Label 2900 3750 0    50   ~ 0
LED_P
Text Label 2700 1600 0    50   ~ 0
VCC_1.9V
Text Label 1350 1600 0    50   ~ 0
V_IN
Text Label 1450 5500 0    50   ~ 0
VDDPIX
Wire Wire Line
	4850 6300 5950 6300
Wire Wire Line
	5950 6300 5950 5150
Wire Wire Line
	5950 900  4850 900 
Wire Wire Line
	4850 900  4850 1000
Wire Wire Line
	4850 2150 4850 2050
Wire Wire Line
	4850 2050 5950 2050
Connection ~ 5950 2050
Wire Wire Line
	5950 2050 5950 900 
Wire Wire Line
	4850 3200 4850 3100
Wire Wire Line
	4850 3100 5950 3100
Connection ~ 5950 3100
Wire Wire Line
	5950 3100 5950 2050
Wire Wire Line
	4850 4200 4850 4150
Wire Wire Line
	4850 4150 5950 4150
Connection ~ 5950 4150
Wire Wire Line
	5950 4150 5950 3100
Wire Wire Line
	4850 5200 4850 5150
Wire Wire Line
	4850 5150 5950 5150
Connection ~ 5950 5150
Wire Wire Line
	5950 5150 5950 4150
Wire Wire Line
	1300 1600 1300 650 
Wire Wire Line
	1300 650  5950 650 
Wire Wire Line
	5950 650  5950 900 
Connection ~ 1300 1600
Connection ~ 5950 900 
Wire Wire Line
	7650 4000 7650 6300
Wire Wire Line
	7650 6300 6500 6300
Wire Wire Line
	6500 6300 6500 7200
Wire Wire Line
	6500 7200 4750 7200
Connection ~ 4750 7200
Wire Wire Line
	7650 3300 7650 650 
Wire Wire Line
	7650 650  5950 650 
Connection ~ 5950 650 
Wire Wire Line
	5150 6700 6350 6700
Wire Wire Line
	6350 6700 6350 6150
Wire Wire Line
	6350 6150 7500 6150
Wire Wire Line
	7500 6150 7500 3900
Wire Wire Line
	5150 5600 7350 5600
Wire Wire Line
	7350 5600 7350 3800
Wire Wire Line
	7350 3800 8300 3800
Wire Wire Line
	5150 4600 7200 4600
Wire Wire Line
	7200 4600 7200 3700
Wire Wire Line
	7200 3700 8300 3700
Wire Wire Line
	5150 1400 7500 1400
Wire Wire Line
	7500 1400 7500 3400
Wire Wire Line
	7500 3400 8300 3400
Wire Wire Line
	5150 2550 7350 2550
Wire Wire Line
	7350 2550 7350 3500
Wire Wire Line
	7350 3500 8300 3500
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5E50D827
P 7850 3300
F 0 "#FLG0101" H 7850 3375 50  0001 C CNN
F 1 "PWR_FLAG" H 7850 3473 50  0000 C CNN
F 2 "" H 7850 3300 50  0001 C CNN
F 3 "~" H 7850 3300 50  0001 C CNN
	1    7850 3300
	1    0    0    -1  
$EndComp
Connection ~ 7850 3300
Wire Wire Line
	7850 3300 7650 3300
Wire Wire Line
	1300 2200 2050 2200
Wire Wire Line
	2050 2000 2050 2200
Connection ~ 2050 2200
Wire Wire Line
	2050 2200 2550 2200
Wire Wire Line
	3850 7200 3850 7300
Wire Wire Line
	1200 6300 1200 7300
Wire Wire Line
	1200 7300 1650 7300
Connection ~ 3850 7300
Wire Wire Line
	3850 7300 3850 7400
Wire Wire Line
	1650 6300 1650 7300
Connection ~ 1650 7300
Wire Wire Line
	1650 7300 3850 7300
Text Notes 8100 7650 0    50   ~ 0
08/02/2020
Text Notes 7350 7500 0    50   ~ 0
Optic Position sensor schematic
$Comp
L Mechanical:MountingHole H1
U 1 1 5E417948
P 9700 1650
F 0 "H1" H 9800 1696 50  0000 L CNN
F 1 "MountingHole" H 9800 1605 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad" H 9700 1650 50  0001 C CNN
F 3 "~" H 9700 1650 50  0001 C CNN
F 4 "" H 9700 1650 50  0001 C CNN "Manufacturer Part Number"
	1    9700 1650
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5E417FD8
P 9700 1950
F 0 "H2" H 9800 1996 50  0000 L CNN
F 1 "MountingHole" H 9800 1905 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad" H 9700 1950 50  0001 C CNN
F 3 "~" H 9700 1950 50  0001 C CNN
F 4 "" H 9700 1950 50  0001 C CNN "Manufacturer Part Number"
	1    9700 1950
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 5E4186E0
P 9700 2250
F 0 "H3" H 9800 2296 50  0000 L CNN
F 1 "MountingHole" H 9800 2205 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad" H 9700 2250 50  0001 C CNN
F 3 "~" H 9700 2250 50  0001 C CNN
F 4 "" H 9700 2250 50  0001 C CNN "Manufacturer Part Number"
	1    9700 2250
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 5E4188C7
P 9700 2500
F 0 "H4" H 9800 2546 50  0000 L CNN
F 1 "MountingHole" H 9800 2455 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad" H 9700 2500 50  0001 C CNN
F 3 "~" H 9700 2500 50  0001 C CNN
F 4 "" H 9700 2500 50  0001 C CNN "Manufacturer Part Number"
	1    9700 2500
	1    0    0    -1  
$EndComp
Text Label 6400 1400 0    50   ~ 0
~NCS_HEADER
Text Label 6400 2550 0    50   ~ 0
MISO_HEADER
Text Label 6450 3600 0    50   ~ 0
MOSI_HEADER
Text Label 6500 4600 0    50   ~ 0
SCLK_HEADER
Text Label 6550 5600 0    50   ~ 0
MOTION_HEADER
Text Label 6550 6150 0    50   ~ 0
~NRESET_HEADER
$Comp
L Connector:Conn_01x08_Male J1
U 1 1 5E497C0D
P 8500 3700
F 0 "J1" H 8472 3582 50  0000 R CNN
F 1 "Conn_01x08_Male" H 8472 3673 50  0000 R CNN
F 2 "Connector_Molex:Molex_PicoBlade_53048-0810_1x08_P1.25mm_Horizontal" H 8500 3700 50  0001 C CNN
F 3 "~" H 8500 3700 50  0001 C CNN
F 4 "0530480810" H 8500 3700 50  0001 C CNN "Manufacturer Part Number"
	1    8500 3700
	-1   0    0    1   
$EndComp
Wire Wire Line
	7850 3300 8300 3300
Wire Wire Line
	7500 3900 8300 3900
Wire Wire Line
	7650 4000 8300 4000
Wire Wire Line
	5150 3600 8300 3600
$EndSCHEMATC
