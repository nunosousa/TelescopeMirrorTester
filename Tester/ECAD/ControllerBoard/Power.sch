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
Text HLabel 8300 850  2    50   Output ~ 0
VMOTOR
Wire Wire Line
	1700 7500 850  7500
Text HLabel 8300 4850 2    50   Output ~ 0
V3_3_MCU
Text HLabel 8300 2750 2    50   Output ~ 0
V5_0
$Comp
L Regulator_Linear:TLV70033_SOT23-5 U7
U 1 1 5E59F3DE
P 4900 4950
F 0 "U7" H 4900 5292 50  0000 C CNN
F 1 "TLV70033_SOT23-5" H 4900 5201 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 4900 5275 50  0001 C CIN
F 3 "http://www.ti.com/lit/ds/symlink/tlv700.pdf" H 4900 5000 50  0001 C CNN
F 4 "TLV70033DDCT" H 4900 4950 50  0001 C CNN "Manufacturer Part Number"
	1    4900 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 4850 4200 4850
Wire Wire Line
	4600 4850 4600 4950
Connection ~ 4600 4850
Wire Wire Line
	4900 5250 4900 5350
Wire Wire Line
	4900 5350 4200 5350
Wire Wire Line
	1700 5350 1700 7500
Wire Wire Line
	5200 4850 5500 4850
$Comp
L Device:C C30
U 1 1 5E5ACBC2
P 5500 5050
F 0 "C30" H 5615 5096 50  0000 L CNN
F 1 "1uC" H 5615 5005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5538 4900 50  0001 C CNN
F 3 "~" H 5500 5050 50  0001 C CNN
F 4 "CC0805MKX7R7BB105" H 5500 5050 50  0001 C CNN "Manufacturer Part Number"
	1    5500 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C29
U 1 1 5E5AD351
P 4200 5050
F 0 "C29" H 4315 5096 50  0000 L CNN
F 1 "1uC" H 4315 5005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4238 4900 50  0001 C CNN
F 3 "~" H 4200 5050 50  0001 C CNN
F 4 "CC0805MKX7R7BB105" H 4200 5050 50  0001 C CNN "Manufacturer Part Number"
	1    4200 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 4900 5500 4850
Connection ~ 5500 4850
Wire Wire Line
	5500 4850 8300 4850
Wire Wire Line
	5500 5200 5500 5350
Wire Wire Line
	5500 5350 4900 5350
Connection ~ 4900 5350
Wire Wire Line
	4200 4900 4200 4850
Connection ~ 4200 4850
Wire Wire Line
	4200 4850 4600 4850
Wire Wire Line
	4200 5200 4200 5350
Connection ~ 4200 5350
Wire Wire Line
	4200 5350 1700 5350
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
Wire Wire Line
	3850 4850 3850 6150
Text HLabel 8300 6150 2    50   Output ~ 0
V3_3_SENS
Text HLabel 1300 1000 0    50   Input ~ 0
V5_USB
$EndSCHEMATC
