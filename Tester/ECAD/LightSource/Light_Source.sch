EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
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
L Device:LED D1
U 1 1 6167978F
P 7000 3700
F 0 "D1" V 7039 3582 50  0000 R CNN
F 1 "LED" V 6948 3582 50  0000 R CNN
F 2 "LED_THT:LED_Rectangular_W5.0mm_H2.0mm" H 7000 3700 50  0001 C CNN
F 3 "~" H 7000 3700 50  0001 C CNN
F 4 "Varies" H 7000 3700 50  0001 C CNN "Manufacturer Part Number"
	1    7000 3700
	0    -1   -1   0   
$EndComp
$Comp
L Device:Laserdiode_M_TYPE LD1
U 1 1 6167A069
P 4500 3800
F 0 "LD1" V 4596 3600 50  0000 R CNN
F 1 "LD" V 4505 3600 50  0000 R CNN
F 2 "OptoDevice:LaserDiode_TO18-D5.6-3" H 4540 3875 50  0001 C CNN
F 3 "" H 4590 3700 50  0001 C CNN
F 4 "Varies" H 4500 3800 50  0001 C CNN "Manufacturer Part Number"
	1    4500 3800
	0    -1   -1   0   
$EndComp
$Comp
L Jumper:SolderJumper_3_Open JP1
U 1 1 6167C555
P 3900 4300
F 0 "JP1" V 3854 4368 50  0000 L CNN
F 1 "JP" V 3945 4368 50  0000 L CNN
F 2 "Jumper:SolderJumper-3_P2.0mm_Open_TrianglePad1.0x1.5mm" H 3900 4300 50  0001 C CNN
F 3 "~" H 3900 4300 50  0001 C CNN
F 4 "N/A" H 3900 4300 50  0001 C CNN "Manufacturer Part Number"
	1    3900 4300
	0    -1   1    0   
$EndComp
$Comp
L Jumper:SolderJumper_3_Open JP2
U 1 1 6167DB7E
P 4050 3200
F 0 "JP2" V 4004 3267 50  0000 L CNN
F 1 "JP" V 4095 3267 50  0000 L CNN
F 2 "Jumper:SolderJumper-3_P2.0mm_Open_TrianglePad1.0x1.5mm" H 4050 3200 50  0001 C CNN
F 3 "~" H 4050 3200 50  0001 C CNN
F 4 "N/A" H 4050 3200 50  0001 C CNN "Manufacturer Part Number"
	1    4050 3200
	0    -1   1    0   
$EndComp
$Comp
L Jumper:SolderJumper_3_Open JP3
U 1 1 6167E457
P 5000 3200
F 0 "JP3" V 4954 3268 50  0000 L CNN
F 1 "JP" V 5045 3268 50  0000 L CNN
F 2 "Jumper:SolderJumper-3_P2.0mm_Open_TrianglePad1.0x1.5mm" H 5000 3200 50  0001 C CNN
F 3 "~" H 5000 3200 50  0001 C CNN
F 4 "N/A" H 5000 3200 50  0001 C CNN "Manufacturer Part Number"
	1    5000 3200
	0    1    1    0   
$EndComp
Text HLabel 7000 3550 1    50   UnSpc ~ 0
Anode
Text HLabel 7000 3850 3    50   UnSpc ~ 0
Cathode
Wire Wire Line
	4400 3500 4400 3200
Wire Wire Line
	4400 3200 4200 3200
Wire Wire Line
	4600 3200 4600 3500
Wire Wire Line
	4500 4300 4500 4000
Text HLabel 4050 3000 1    50   UnSpc ~ 0
Anode
Text HLabel 5000 3000 1    50   UnSpc ~ 0
Anode
Text HLabel 3900 4100 1    50   UnSpc ~ 0
Anode
Text HLabel 4050 3400 3    50   UnSpc ~ 0
Cathode
Text HLabel 5000 3400 3    50   UnSpc ~ 0
Cathode
Text HLabel 3900 4500 3    50   UnSpc ~ 0
Cathode
Wire Wire Line
	4050 4300 4500 4300
Wire Wire Line
	4600 3200 4850 3200
$EndSCHEMATC
