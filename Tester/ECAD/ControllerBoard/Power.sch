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
Text HLabel 1400 850  0    50   Input ~ 0
12V_POWER_IN
Text HLabel 850  7500 0    50   Input ~ 0
GND
$Comp
L Regulator_Switching:TPS562200 U?
U 1 1 5E56C6D7
P 4900 950
AR Path="/5E507163/5E56C6D7" Ref="U?"  Part="1" 
AR Path="/5E55CCDC/5E56C6D7" Ref="U2"  Part="1" 
F 0 "U2" H 4900 1317 50  0000 C CNN
F 1 "TPS562200" H 4900 1226 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 4950 700 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/tps563200.pdf" H 4900 950 50  0001 C CNN
F 4 "TPS562200DDCR" H 4900 950 50  0001 C CNN "Manufacturer Part Number"
	1    4900 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 1050 4300 1050
Wire Wire Line
	4300 1050 4300 850 
Connection ~ 4300 850 
Wire Wire Line
	4300 850  4500 850 
$Comp
L Device:C C?
U 1 1 5E56C6E2
P 3950 1250
AR Path="/5E507163/5E56C6E2" Ref="C?"  Part="1" 
AR Path="/5E55CCDC/5E56C6E2" Ref="C8"  Part="1" 
F 0 "C8" H 4065 1296 50  0000 L CNN
F 1 "10uC" H 4065 1205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 3988 1100 50  0001 C CNN
F 3 "~" H 3950 1250 50  0001 C CNN
F 4 "C3216X5R1E106K085AC" H 3950 1250 50  0001 C CNN "Manufacturer Part Number"
	1    3950 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5E56C6E9
P 5900 1000
AR Path="/5E507163/5E56C6E9" Ref="C?"  Part="1" 
AR Path="/5E55CCDC/5E56C6E9" Ref="C9"  Part="1" 
F 0 "C9" H 6015 1046 50  0000 L CNN
F 1 "0.1uC" H 6015 955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5938 850 50  0001 C CNN
F 3 "~" H 5900 1000 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 5900 1000 50  0001 C CNN "Manufacturer Part Number"
	1    5900 1000
	1    0    0    -1  
$EndComp
$Comp
L Device:L L?
U 1 1 5E56C6F0
P 6350 850
AR Path="/5E507163/5E56C6F0" Ref="L?"  Part="1" 
AR Path="/5E55CCDC/5E56C6F0" Ref="L1"  Part="1" 
F 0 "L1" V 6540 850 50  0000 C CNN
F 1 "4.7uL" V 6449 850 50  0000 C CNN
F 2 "" H 6350 850 50  0001 C CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/SRN6045.pdf" H 6350 850 50  0001 C CNN
F 4 "SRN6045-4R7Y" H 6350 850 50  0001 C CNN "Manufacturer Part Number"
	1    6350 850 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5300 850  5900 850 
Connection ~ 5900 850 
Wire Wire Line
	5900 850  6200 850 
Wire Wire Line
	5900 1150 5900 1300
Wire Wire Line
	5900 1300 5600 1300
Wire Wire Line
	5600 1300 5600 950 
Wire Wire Line
	5600 950  5300 950 
$Comp
L Device:R R?
U 1 1 5E56C6FE
P 6850 1050
AR Path="/5E507163/5E56C6FE" Ref="R?"  Part="1" 
AR Path="/5E55CCDC/5E56C6FE" Ref="R5"  Part="1" 
F 0 "R5" H 6920 1096 50  0000 L CNN
F 1 "68.1kR" H 6920 1005 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6780 1050 50  0001 C CNN
F 3 "~" H 6850 1050 50  0001 C CNN
F 4 "RC0805FR-0768R1L" H 6850 1050 50  0001 C CNN "Manufacturer Part Number"
	1    6850 1050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E56C705
P 6850 1550
AR Path="/5E507163/5E56C705" Ref="R?"  Part="1" 
AR Path="/5E55CCDC/5E56C705" Ref="R6"  Part="1" 
F 0 "R6" H 6920 1596 50  0000 L CNN
F 1 "10kR" H 6920 1505 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6780 1550 50  0001 C CNN
F 3 "~" H 6850 1550 50  0001 C CNN
F 4 "RC0805FR-0710KL" H 6850 1550 50  0001 C CNN "Manufacturer Part Number"
	1    6850 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 850  6850 850 
Wire Wire Line
	6850 850  6850 900 
Wire Wire Line
	6850 1200 6850 1300
Wire Wire Line
	6850 1700 6850 1950
Wire Wire Line
	6850 1950 4900 1950
Wire Wire Line
	6850 1300 6600 1300
Wire Wire Line
	6600 1300 6600 1450
Wire Wire Line
	6600 1450 5450 1450
Wire Wire Line
	5450 1450 5450 1050
Wire Wire Line
	5450 1050 5300 1050
Connection ~ 6850 1300
Wire Wire Line
	6850 1300 6850 1400
$Comp
L Device:C C?
U 1 1 5E56C718
P 7250 1300
AR Path="/5E507163/5E56C718" Ref="C?"  Part="1" 
AR Path="/5E55CCDC/5E56C718" Ref="C10"  Part="1" 
F 0 "C10" H 7365 1346 50  0000 L CNN
F 1 "22uC" H 7365 1255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7288 1150 50  0001 C CNN
F 3 "~" H 7250 1300 50  0001 C CNN
F 4 "LMK212BJ226MG-T" H 7250 1300 50  0001 C CNN "Manufacturer Part Number"
	1    7250 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 1150 7250 850 
Wire Wire Line
	7250 850  6850 850 
Connection ~ 6850 850 
Wire Wire Line
	7250 1450 7250 1950
Wire Wire Line
	7250 1950 6850 1950
Connection ~ 6850 1950
Wire Wire Line
	7250 850  7700 850 
Connection ~ 7250 850 
$Comp
L Device:C C?
U 1 1 5E56C727
P 3500 1250
AR Path="/5E507163/5E56C727" Ref="C?"  Part="1" 
AR Path="/5E55CCDC/5E56C727" Ref="C7"  Part="1" 
F 0 "C7" H 3615 1296 50  0000 L CNN
F 1 "10uC" H 3615 1205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 3538 1100 50  0001 C CNN
F 3 "~" H 3500 1250 50  0001 C CNN
F 4 "C3216X5R1E106K085AC" H 3500 1250 50  0001 C CNN "Manufacturer Part Number"
	1    3500 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 1100 3950 850 
Connection ~ 3950 850 
Wire Wire Line
	3950 850  4300 850 
Wire Wire Line
	3500 1100 3500 850 
Connection ~ 3500 850 
Wire Wire Line
	3500 850  3950 850 
$Comp
L Device:C C?
U 1 1 5E56C735
P 7700 1300
AR Path="/5E507163/5E56C735" Ref="C?"  Part="1" 
AR Path="/5E55CCDC/5E56C735" Ref="C11"  Part="1" 
F 0 "C11" H 7815 1346 50  0000 L CNN
F 1 "22uC" H 7815 1255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7738 1150 50  0001 C CNN
F 3 "~" H 7700 1300 50  0001 C CNN
F 4 "LMK212BJ226MG-T" H 7700 1300 50  0001 C CNN "Manufacturer Part Number"
	1    7700 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 1150 7700 850 
Wire Wire Line
	7700 1450 7700 1950
Wire Wire Line
	7700 1950 7250 1950
Connection ~ 7250 1950
Wire Wire Line
	4900 1250 4900 1950
Wire Wire Line
	3500 1950 3500 1400
Connection ~ 4900 1950
Wire Wire Line
	3950 1400 3950 1950
Connection ~ 3950 1950
Wire Wire Line
	3950 1950 3500 1950
Text HLabel 8300 850  2    50   Output ~ 0
VMOTOR
Wire Wire Line
	7700 850  8300 850 
Connection ~ 7700 850 
Wire Wire Line
	1400 850  3500 850 
Wire Wire Line
	1700 7500 850  7500
Wire Wire Line
	4900 1950 3950 1950
Connection ~ 3500 1950
Wire Wire Line
	1700 1950 3500 1950
Wire Wire Line
	1700 1950 1700 7500
Text HLabel 8350 3800 2    50   Output ~ 0
VMCU
$EndSCHEMATC
