EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 850  7500 0    50   Input ~ 0
GND
Text HLabel 9500 2800 2    50   Output ~ 0
VMOTOR
Text HLabel 9400 1050 2    50   Output ~ 0
V3_3_MCU
Text HLabel 9500 5600 2    50   Output ~ 0
V5_0
$Comp
L Regulator_Linear:TLV70033_SOT23-5 U7
U 1 1 5E59F3DE
P 6000 1150
F 0 "U7" H 6000 1492 50  0000 C CNN
F 1 "TLV70033_SOT23-5" H 6000 1401 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 6000 1475 50  0001 C CIN
F 3 "http://www.ti.com/lit/ds/symlink/tlv700.pdf" H 6000 1200 50  0001 C CNN
F 4 "TLV70033DDCT" H 6000 1150 50  0001 C CNN "Manufacturer Part Number"
	1    6000 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 1050 5700 1150
Connection ~ 5700 1050
Wire Wire Line
	6000 1450 6000 1550
Wire Wire Line
	6000 1550 5300 1550
Wire Wire Line
	6300 1050 6600 1050
$Comp
L Device:C C30
U 1 1 5E5ACBC2
P 6600 1250
F 0 "C30" H 6715 1296 50  0000 L CNN
F 1 "1uC" H 6715 1205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6638 1100 50  0001 C CNN
F 3 "~" H 6600 1250 50  0001 C CNN
F 4 "CC0805MKX7R7BB105" H 6600 1250 50  0001 C CNN "Manufacturer Part Number"
	1    6600 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C29
U 1 1 5E5AD351
P 5300 1250
F 0 "C29" H 5415 1296 50  0000 L CNN
F 1 "1uC" H 5415 1205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5338 1100 50  0001 C CNN
F 3 "~" H 5300 1250 50  0001 C CNN
F 4 "CC0805MKX7R7BB105" H 5300 1250 50  0001 C CNN "Manufacturer Part Number"
	1    5300 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 1100 6600 1050
Connection ~ 6600 1050
Wire Wire Line
	6600 1050 9400 1050
Wire Wire Line
	6600 1400 6600 1550
Wire Wire Line
	6600 1550 6000 1550
Connection ~ 6000 1550
Wire Wire Line
	5300 1100 5300 1050
Connection ~ 5300 1050
Wire Wire Line
	5300 1050 5700 1050
Wire Wire Line
	5300 1400 5300 1550
$Comp
L Regulator_Linear:TLV70033_SOT23-5 U8
U 1 1 5E5D3E36
P 4900 6250
F 0 "U8" H 4900 6592 50  0000 C CNN
F 1 "TLV70033_SOT23-5" H 4900 6501 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 4900 6575 50  0001 C CIN
F 3 "http://www.ti.com/lit/ds/symlink/tlv700.pdf" H 4900 6300 50  0001 C CNN
F 4 "TLV70033DDCT" H 4900 6250 50  0001 C CNN "Manufacturer Part Number"
	1    4900 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 6150 4200 6150
Wire Wire Line
	4600 6150 4600 6250
Connection ~ 4600 6150
Wire Wire Line
	4900 6550 4900 6650
Wire Wire Line
	4900 6650 4200 6650
Wire Wire Line
	5200 6150 5500 6150
$Comp
L Device:C C32
U 1 1 5E5D3E45
P 5500 6350
F 0 "C32" H 5615 6396 50  0000 L CNN
F 1 "1uC" H 5615 6305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5538 6200 50  0001 C CNN
F 3 "~" H 5500 6350 50  0001 C CNN
F 4 "CC0805MKX7R7BB105" H 5500 6350 50  0001 C CNN "Manufacturer Part Number"
	1    5500 6350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C31
U 1 1 5E5D3E4C
P 4200 6350
F 0 "C31" H 4315 6396 50  0000 L CNN
F 1 "1uC" H 4315 6305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4238 6200 50  0001 C CNN
F 3 "~" H 4200 6350 50  0001 C CNN
F 4 "CC0805MKX7R7BB105" H 4200 6350 50  0001 C CNN "Manufacturer Part Number"
	1    4200 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 6200 5500 6150
Connection ~ 5500 6150
Wire Wire Line
	5500 6150 8300 6150
Wire Wire Line
	5500 6500 5500 6650
Wire Wire Line
	5500 6650 4900 6650
Connection ~ 4900 6650
Wire Wire Line
	4200 6200 4200 6150
Connection ~ 4200 6150
Wire Wire Line
	4200 6150 4600 6150
Wire Wire Line
	4200 6500 4200 6650
Connection ~ 4200 6650
Wire Wire Line
	4200 6650 1700 6650
Text HLabel 8300 6150 2    50   Output ~ 0
V3_3_SENS
Text HLabel 1300 1050 0    50   Input ~ 0
V5_USB
Wire Wire Line
	1300 1050 3350 1050
Wire Wire Line
	5300 1550 1300 1550
Wire Wire Line
	1300 1550 1300 3650
Connection ~ 5300 1550
Wire Wire Line
	1300 7500 850  7500
$Comp
L Power_Management:TPS2041B U6
U 1 1 5E61B45E
P 6000 2800
F 0 "U6" H 6000 3267 50  0000 C CNN
F 1 "TPS2041B" H 6000 3176 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 6000 3300 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tps2041.pdf" H 5950 3100 50  0001 C CNN
	1    6000 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 2600 6700 2600
Wire Wire Line
	6700 2000 4900 2000
Wire Wire Line
	3350 2000 3350 1050
Connection ~ 3350 1050
Wire Wire Line
	3350 1050 5300 1050
Wire Wire Line
	6000 3400 6000 3650
Wire Wire Line
	6000 3650 1300 3650
Connection ~ 1300 3650
Wire Wire Line
	1300 3650 1300 7500
Wire Wire Line
	6700 2600 6700 2000
$Comp
L Device:C C8
U 1 1 5E61FCAC
P 7200 2250
F 0 "C8" H 7315 2296 50  0000 L CNN
F 1 "0.1uC" H 7315 2205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7238 2100 50  0001 C CNN
F 3 "~" H 7200 2250 50  0001 C CNN
F 4 "" H 7200 2250 50  0001 C CNN "Manufacturer Part Number"
	1    7200 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 2000 7200 2000
Wire Wire Line
	7200 2000 7200 2100
Connection ~ 6700 2000
Wire Wire Line
	7200 2400 7200 3650
Wire Wire Line
	7200 3650 6000 3650
Connection ~ 6000 3650
$Comp
L Device:C C9
U 1 1 5E6221E4
P 7500 3150
F 0 "C9" H 7615 3196 50  0000 L CNN
F 1 "0.1uC" H 7615 3105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7538 3000 50  0001 C CNN
F 3 "~" H 7500 3150 50  0001 C CNN
F 4 "" H 7500 3150 50  0001 C CNN "Manufacturer Part Number"
	1    7500 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 2800 7500 2800
Wire Wire Line
	7500 2800 7500 3000
Wire Wire Line
	7500 3300 7500 3650
Wire Wire Line
	7500 3650 7200 3650
Connection ~ 7200 3650
Text HLabel 5500 3000 0    50   Input ~ 0
~POWER_SWITCH
$Comp
L Device:R R6
U 1 1 5E62500B
P 4900 2300
F 0 "R6" H 4970 2346 50  0000 L CNN
F 1 "R" H 4970 2255 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4830 2300 50  0001 C CNN
F 3 "~" H 4900 2300 50  0001 C CNN
	1    4900 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 2600 4900 2600
Wire Wire Line
	4900 2600 4900 2450
Wire Wire Line
	4900 2150 4900 2000
Connection ~ 4900 2000
Wire Wire Line
	4900 2000 3350 2000
Text Notes 5350 2200 0    50   ~ 0
Power switch and current limiter
Wire Wire Line
	7500 2800 9500 2800
Connection ~ 7500 2800
$EndSCHEMATC
