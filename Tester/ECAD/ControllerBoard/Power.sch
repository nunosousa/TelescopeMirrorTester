EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 5
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
	1400 850  2050 850 
Wire Wire Line
	1700 7500 850  7500
Wire Wire Line
	4900 1950 3950 1950
Connection ~ 3500 1950
Wire Wire Line
	1700 1950 3500 1950
Wire Wire Line
	1700 1950 1700 3850
Text HLabel 8300 4850 2    50   Output ~ 0
V3_3
Text HLabel 8300 2750 2    50   Output ~ 0
V5_0
$Comp
L Regulator_Switching:TPS562200 U?
U 1 1 5E6B255B
P 4900 2850
AR Path="/5E507163/5E6B255B" Ref="U?"  Part="1" 
AR Path="/5E55CCDC/5E6B255B" Ref="U6"  Part="1" 
F 0 "U6" H 4900 3217 50  0000 C CNN
F 1 "TPS562200" H 4900 3126 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 4950 2600 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/tps563200.pdf" H 4900 2850 50  0001 C CNN
F 4 "TPS562200DDCR" H 4900 2850 50  0001 C CNN "Manufacturer Part Number"
	1    4900 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 2950 4300 2950
Wire Wire Line
	4300 2950 4300 2750
Connection ~ 4300 2750
Wire Wire Line
	4300 2750 4500 2750
$Comp
L Device:C C?
U 1 1 5E6B2566
P 3950 3150
AR Path="/5E507163/5E6B2566" Ref="C?"  Part="1" 
AR Path="/5E55CCDC/5E6B2566" Ref="C25"  Part="1" 
F 0 "C25" H 4065 3196 50  0000 L CNN
F 1 "10uC" H 4065 3105 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 3988 3000 50  0001 C CNN
F 3 "~" H 3950 3150 50  0001 C CNN
F 4 "C3216X5R1E106K085AC" H 3950 3150 50  0001 C CNN "Manufacturer Part Number"
	1    3950 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5E6B256D
P 5900 2900
AR Path="/5E507163/5E6B256D" Ref="C?"  Part="1" 
AR Path="/5E55CCDC/5E6B256D" Ref="C26"  Part="1" 
F 0 "C26" H 6015 2946 50  0000 L CNN
F 1 "0.1uC" H 6015 2855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5938 2750 50  0001 C CNN
F 3 "~" H 5900 2900 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 5900 2900 50  0001 C CNN "Manufacturer Part Number"
	1    5900 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:L L?
U 1 1 5E6B2574
P 6350 2750
AR Path="/5E507163/5E6B2574" Ref="L?"  Part="1" 
AR Path="/5E55CCDC/5E6B2574" Ref="L3"  Part="1" 
F 0 "L3" V 6540 2750 50  0000 C CNN
F 1 "4.7uL" V 6449 2750 50  0000 C CNN
F 2 "" H 6350 2750 50  0001 C CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/SRN6045.pdf" H 6350 2750 50  0001 C CNN
F 4 "SRN6045-4R7Y" H 6350 2750 50  0001 C CNN "Manufacturer Part Number"
	1    6350 2750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5300 2750 5900 2750
Connection ~ 5900 2750
Wire Wire Line
	5900 2750 6200 2750
Wire Wire Line
	5900 3050 5900 3200
Wire Wire Line
	5900 3200 5600 3200
Wire Wire Line
	5600 3200 5600 2850
Wire Wire Line
	5600 2850 5300 2850
$Comp
L Device:R R?
U 1 1 5E6B2582
P 6850 2950
AR Path="/5E507163/5E6B2582" Ref="R?"  Part="1" 
AR Path="/5E55CCDC/5E6B2582" Ref="R23"  Part="1" 
F 0 "R23" H 6920 2996 50  0000 L CNN
F 1 "56.2kR" H 6920 2905 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6780 2950 50  0001 C CNN
F 3 "~" H 6850 2950 50  0001 C CNN
F 4 "RC0805FR-0756K2L" H 6850 2950 50  0001 C CNN "Manufacturer Part Number"
	1    6850 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E6B2589
P 6850 3450
AR Path="/5E507163/5E6B2589" Ref="R?"  Part="1" 
AR Path="/5E55CCDC/5E6B2589" Ref="R24"  Part="1" 
F 0 "R24" H 6920 3496 50  0000 L CNN
F 1 "10kR" H 6920 3405 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6780 3450 50  0001 C CNN
F 3 "~" H 6850 3450 50  0001 C CNN
F 4 "RC0805FR-0710KL" H 6850 3450 50  0001 C CNN "Manufacturer Part Number"
	1    6850 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 2750 6850 2750
Wire Wire Line
	6850 2750 6850 2800
Wire Wire Line
	6850 3100 6850 3200
Wire Wire Line
	6850 3600 6850 3850
Wire Wire Line
	6850 3850 4900 3850
Wire Wire Line
	6850 3200 6600 3200
Wire Wire Line
	6600 3200 6600 3350
Wire Wire Line
	6600 3350 5450 3350
Wire Wire Line
	5450 3350 5450 2950
Wire Wire Line
	5450 2950 5300 2950
Connection ~ 6850 3200
Wire Wire Line
	6850 3200 6850 3300
$Comp
L Device:C C?
U 1 1 5E6B259C
P 7250 3200
AR Path="/5E507163/5E6B259C" Ref="C?"  Part="1" 
AR Path="/5E55CCDC/5E6B259C" Ref="C27"  Part="1" 
F 0 "C27" H 7365 3246 50  0000 L CNN
F 1 "22uC" H 7365 3155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7288 3050 50  0001 C CNN
F 3 "~" H 7250 3200 50  0001 C CNN
F 4 "LMK212BJ226MG-T" H 7250 3200 50  0001 C CNN "Manufacturer Part Number"
	1    7250 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 3050 7250 2750
Wire Wire Line
	7250 2750 6850 2750
Connection ~ 6850 2750
Wire Wire Line
	7250 3350 7250 3850
Wire Wire Line
	7250 3850 6850 3850
Connection ~ 6850 3850
Wire Wire Line
	7250 2750 7700 2750
Connection ~ 7250 2750
$Comp
L Device:C C?
U 1 1 5E6B25AB
P 3500 3150
AR Path="/5E507163/5E6B25AB" Ref="C?"  Part="1" 
AR Path="/5E55CCDC/5E6B25AB" Ref="C24"  Part="1" 
F 0 "C24" H 3615 3196 50  0000 L CNN
F 1 "10uC" H 3615 3105 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 3538 3000 50  0001 C CNN
F 3 "~" H 3500 3150 50  0001 C CNN
F 4 "C3216X5R1E106K085AC" H 3500 3150 50  0001 C CNN "Manufacturer Part Number"
	1    3500 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 3000 3950 2750
Connection ~ 3950 2750
Wire Wire Line
	3950 2750 4300 2750
Wire Wire Line
	3500 3000 3500 2750
Wire Wire Line
	3500 2750 3950 2750
$Comp
L Device:C C?
U 1 1 5E6B25B8
P 7700 3200
AR Path="/5E507163/5E6B25B8" Ref="C?"  Part="1" 
AR Path="/5E55CCDC/5E6B25B8" Ref="C28"  Part="1" 
F 0 "C28" H 7815 3246 50  0000 L CNN
F 1 "22uC" H 7815 3155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7738 3050 50  0001 C CNN
F 3 "~" H 7700 3200 50  0001 C CNN
F 4 "LMK212BJ226MG-T" H 7700 3200 50  0001 C CNN "Manufacturer Part Number"
	1    7700 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 3050 7700 2750
Wire Wire Line
	7700 3350 7700 3850
Wire Wire Line
	7700 3850 7250 3850
Connection ~ 7250 3850
Wire Wire Line
	4900 3150 4900 3850
Wire Wire Line
	3500 3850 3500 3300
Connection ~ 4900 3850
Wire Wire Line
	3950 3300 3950 3850
Connection ~ 3950 3850
Wire Wire Line
	3950 3850 3500 3850
Wire Wire Line
	7700 2750 8100 2750
Connection ~ 7700 2750
Wire Wire Line
	4900 3850 3950 3850
Wire Wire Line
	3500 2750 2050 2750
Wire Wire Line
	2050 2750 2050 850 
Connection ~ 3500 2750
Connection ~ 2050 850 
Wire Wire Line
	2050 850  3500 850 
Wire Wire Line
	3500 3850 1700 3850
Connection ~ 3500 3850
Connection ~ 1700 3850
Wire Wire Line
	1700 3850 1700 5350
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
	8100 2750 8100 4450
Wire Wire Line
	8100 4450 3850 4450
Wire Wire Line
	3850 4450 3850 4850
Wire Wire Line
	3850 4850 4200 4850
Connection ~ 8100 2750
Wire Wire Line
	8100 2750 8300 2750
Wire Wire Line
	4600 4850 4600 4950
Connection ~ 4600 4850
Wire Wire Line
	4900 5250 4900 5350
Wire Wire Line
	4900 5350 4200 5350
Connection ~ 1700 5350
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
$EndSCHEMATC
