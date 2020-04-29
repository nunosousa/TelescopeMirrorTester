EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 7
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
U 1 1 5E621F8B
P 4000 4200
F 0 "R5" H 4070 4246 50  0000 L CNN
F 1 "1MR" H 4070 4155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3930 4200 50  0001 C CNN
F 3 "~" H 4000 4200 50  0001 C CNN
F 4 "RC0805FR-071ML" H 4000 4200 50  0001 C CNN "Manufacturer Part Number"
	1    4000 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 5E623AF4
P 3550 4200
F 0 "C7" H 3665 4246 50  0000 L CNN
F 1 "4.7nC" H 3665 4155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3588 4050 50  0001 C CNN
F 3 "~" H 3550 4200 50  0001 C CNN
F 4 "C0805C472K3RAC7800" H 3550 4200 50  0001 C CNN "Manufacturer Part Number"
	1    3550 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 4350 3550 4500
Wire Wire Line
	3550 4500 3700 4500
Wire Wire Line
	4000 4500 4000 4350
Wire Wire Line
	4000 4050 4000 3900
Wire Wire Line
	4000 3900 3700 3900
Wire Wire Line
	3550 3900 3550 4050
Wire Wire Line
	3700 3200 3700 3900
Connection ~ 3700 3900
Wire Wire Line
	3700 3900 3550 3900
Wire Wire Line
	3800 3200 3800 3650
Wire Wire Line
	3800 3650 4550 3650
Wire Wire Line
	4550 3650 4550 4800
Wire Wire Line
	3700 4800 3700 4500
Connection ~ 4550 4800
Connection ~ 3700 4500
Wire Wire Line
	3700 4500 4000 4500
Text HLabel 3600 4800 0    50   Output ~ 0
GND
Text HLabel 8150 2600 2    50   Output ~ 0
V_USB
Text HLabel 8150 2800 2    50   BiDi ~ 0
USB_D+
Text HLabel 8150 2900 2    50   BiDi ~ 0
USB_D-
$Comp
L Device:Ferrite_Bead FB1
U 1 1 5E60ECFA
P 5050 2600
F 0 "FB1" V 4776 2600 50  0000 C CNN
F 1 "Ferrite_Bead" V 4867 2600 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4980 2600 50  0001 C CNN
F 3 "~" H 5050 2600 50  0001 C CNN
F 4 "BLM21PG221SN1D" H 5050 2600 50  0001 C CNN "Manufacturer Part Number"
	1    5050 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	4900 2600 4100 2600
Wire Wire Line
	5200 2600 5750 2600
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5E65E293
P 5750 2600
F 0 "#FLG0101" H 5750 2675 50  0001 C CNN
F 1 "PWR_FLAG" H 5750 2773 50  0000 C CNN
F 2 "" H 5750 2600 50  0001 C CNN
F 3 "~" H 5750 2600 50  0001 C CNN
	1    5750 2600
	1    0    0    -1  
$EndComp
Connection ~ 5750 2600
Text Label 4450 2800 0    50   ~ 0
D+
Text Label 4450 2900 0    50   ~ 0
D-
Text Label 3700 3650 1    50   ~ 0
SHIELD
Text Label 4300 2600 0    50   ~ 0
VBUS
$Comp
L Power_Protection:USBLC6-2SC6 U2
U 1 1 5E62B9EB
P 6050 3600
F 0 "U2" H 6450 3150 50  0000 C CNN
F 1 "USBLC6-2SC6" H 6650 3250 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 5300 4000 50  0001 C CNN
F 3 "http://www2.st.com/resource/en/datasheet/CD00050750.pdf" H 6250 3950 50  0001 C CNN
F 4 "USBLC6-2SC6" H 6050 3600 50  0001 C CNN "Manufacturer Part Number"
	1    6050 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 2600 6050 2600
Wire Wire Line
	6050 3100 6050 2600
Connection ~ 6050 2600
Wire Wire Line
	6050 2600 8150 2600
Wire Wire Line
	6050 4100 6050 4800
Wire Wire Line
	6800 2800 6800 3700
Wire Wire Line
	6800 3700 6550 3700
Wire Wire Line
	4100 2800 6800 2800
Wire Wire Line
	6550 3500 6950 3500
Wire Wire Line
	6950 3500 6950 2800
Wire Wire Line
	6950 2800 8150 2800
Wire Wire Line
	4100 2900 5150 2900
Wire Wire Line
	5150 2900 5150 3700
Wire Wire Line
	5150 3700 5550 3700
Wire Wire Line
	5550 3500 5350 3500
Wire Wire Line
	5350 3500 5350 2900
Wire Wire Line
	5350 2900 8150 2900
Wire Wire Line
	3700 4800 4550 4800
$Comp
L Connector:USB_B_Micro J9
U 1 1 5EAE8B91
P 3800 2800
F 0 "J9" H 3857 3267 50  0000 C CNN
F 1 "USB_B_Micro" H 3857 3176 50  0000 C CNN
F 2 "Connector_USB:USB_Micro-B_Wuerth_629105150521" H 3950 2750 50  0001 C CNN
F 3 "https://www.we-online.de/katalog/datasheet/629105150521.pdf" H 3950 2750 50  0001 C CNN
F 4 "629105150521" H 3800 2800 50  0001 C CNN "Manufacturer Part Number"
	1    3800 2800
	1    0    0    -1  
$EndComp
NoConn ~ 4100 3000
Wire Wire Line
	4550 4800 6050 4800
Wire Wire Line
	3700 4800 3600 4800
Connection ~ 3700 4800
$EndSCHEMATC
