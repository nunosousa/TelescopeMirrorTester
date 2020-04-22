EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 6000 5400 3    50   Input ~ 0
GND
Text HLabel 6500 1750 2    50   Output ~ 0
V3_3_MCU
Text HLabel 8750 4800 2    50   Output ~ 0
V5_0_MOTOR
$Comp
L Regulator_Linear:TLV70033_SOT23-5 U7
U 1 1 5E59F3DE
P 5400 1850
F 0 "U7" H 5400 2192 50  0000 C CNN
F 1 "TLV70033_SOT23-5" H 5400 2101 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 5400 2175 50  0001 C CIN
F 3 "http://www.ti.com/lit/ds/symlink/tlv700.pdf" H 5400 1900 50  0001 C CNN
F 4 "TLV70033DDCT" H 5400 1850 50  0001 C CNN "Manufacturer Part Number"
	1    5400 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 1750 5100 1850
Connection ~ 5100 1750
Wire Wire Line
	5700 1750 6000 1750
$Comp
L Device:C C30
U 1 1 5E5ACBC2
P 6000 1950
F 0 "C30" H 6115 1996 50  0000 L CNN
F 1 "1uC" H 6115 1905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6038 1800 50  0001 C CNN
F 3 "~" H 6000 1950 50  0001 C CNN
F 4 "CC0805MKX7R7BB105" H 6000 1950 50  0001 C CNN "Manufacturer Part Number"
	1    6000 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C29
U 1 1 5E5AD351
P 4700 1950
F 0 "C29" H 4815 1996 50  0000 L CNN
F 1 "1uC" H 4815 1905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4738 1800 50  0001 C CNN
F 3 "~" H 4700 1950 50  0001 C CNN
F 4 "CC0805MKX7R7BB105" H 4700 1950 50  0001 C CNN "Manufacturer Part Number"
	1    4700 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 1800 6000 1750
Wire Wire Line
	4700 1800 4700 1750
Wire Wire Line
	4700 1750 5100 1750
Text HLabel 6700 4250 1    50   Input ~ 0
V5_USB
Wire Wire Line
	6500 4600 6700 4600
$Comp
L Device:C C8
U 1 1 5E61FCAC
P 6700 5150
F 0 "C8" H 6815 5196 50  0000 L CNN
F 1 "0.1uC" H 6815 5105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6738 5000 50  0001 C CNN
F 3 "~" H 6700 5150 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 6700 5150 50  0001 C CNN "Manufacturer Part Number"
	1    6700 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C9
U 1 1 5E6221E4
P 7200 5150
F 0 "C9" H 7315 5196 50  0000 L CNN
F 1 "0.1uC" H 7315 5105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7238 5000 50  0001 C CNN
F 3 "~" H 7200 5150 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 7200 5150 50  0001 C CNN "Manufacturer Part Number"
	1    7200 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 4800 7200 4800
Wire Wire Line
	7200 4800 7200 5000
Text HLabel 3350 5000 0    50   Input ~ 0
~POWER_SWITCH_ANALOGUE_LOADS
$Comp
L Device:R R6
U 1 1 5E62500B
P 4850 4300
F 0 "R6" H 4920 4346 50  0000 L CNN
F 1 "10kR" H 4920 4255 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4780 4300 50  0001 C CNN
F 3 "~" H 4850 4300 50  0001 C CNN
F 4 "RC0805FR-0710KL" H 4850 4300 50  0001 C CNN "Manufacturer Part Number"
	1    4850 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 4600 4850 4450
Text Notes 4500 5450 0    50   ~ 0
Power switch and current limiter
Text HLabel 3350 4600 0    50   Output ~ 0
LOAD_OVERCURRENT_MOTOR
Text HLabel 3350 5100 0    50   Input ~ 0
~POWER_SWITCH_DIGITAL_LOGIC
$Comp
L Device:R R23
U 1 1 5E61DACA
P 5200 4300
F 0 "R23" H 5270 4346 50  0000 L CNN
F 1 "10kR" H 5270 4255 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5130 4300 50  0001 C CNN
F 3 "~" H 5200 4300 50  0001 C CNN
F 4 "RC0805FR-0710KL" H 5200 4300 50  0001 C CNN "Manufacturer Part Number"
	1    5200 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 4700 5200 4700
Wire Wire Line
	5200 4700 5200 4450
Connection ~ 5200 4700
Text HLabel 3350 4700 0    50   Output ~ 0
LOAD_OVERCURRENT_DIGITAL_LOGIC
Connection ~ 7200 4800
$Comp
L Device:C C10
U 1 1 5E629047
P 8250 5150
F 0 "C10" H 8365 5196 50  0000 L CNN
F 1 "0.1uC" H 8365 5105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8288 5000 50  0001 C CNN
F 3 "~" H 8250 5150 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 8250 5150 50  0001 C CNN "Manufacturer Part Number"
	1    8250 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 4800 7750 4800
Connection ~ 4850 4600
Wire Wire Line
	4850 4600 5500 4600
$Comp
L Power_Management_Custom:TPS2046B U6
U 1 1 5E64DFDB
P 6000 4800
F 0 "U6" H 6000 5267 50  0000 C CNN
F 1 "TPS2046B" H 6000 5176 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 6000 5300 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tps2046b.pdf" H 5950 5100 50  0001 C CNN
F 4 "TPS2046BDR" H 6000 4800 50  0001 C CNN "Manufacturer Part Number"
	1    6000 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C11
U 1 1 5E651B36
P 7750 5150
F 0 "C11" H 7868 5196 50  0000 L CNN
F 1 "150uCP" H 7868 5105 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-7343-31_Kemet-D_Pad2.25x2.55mm_HandSolder" H 7788 5000 50  0001 C CNN
F 3 "~" H 7750 5150 50  0001 C CNN
F 4 "T495D157K010ATE100" H 7750 5150 50  0001 C CNN "Manufacturer Part Number"
	1    7750 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 5000 8250 4900
Wire Wire Line
	6500 4900 8250 4900
Wire Wire Line
	7750 5000 7750 4800
Wire Wire Line
	6700 5000 6700 4600
Wire Wire Line
	4850 3800 4850 4150
Wire Wire Line
	5200 4150 5200 3800
$Comp
L Device:R R31
U 1 1 5E6464A0
P 4050 4300
F 0 "R31" H 4120 4346 50  0000 L CNN
F 1 "10kR" H 4120 4255 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3980 4300 50  0001 C CNN
F 3 "~" H 4050 4300 50  0001 C CNN
F 4 "RC0805FR-0710KL" H 4050 4300 50  0001 C CNN "Manufacturer Part Number"
	1    4050 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R32
U 1 1 5E64669F
P 4450 4300
F 0 "R32" H 4520 4346 50  0000 L CNN
F 1 "10kR" H 4520 4255 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4380 4300 50  0001 C CNN
F 3 "~" H 4450 4300 50  0001 C CNN
F 4 "RC0805FR-0710KL" H 4450 4300 50  0001 C CNN "Manufacturer Part Number"
	1    4450 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 4600 4850 4600
Wire Wire Line
	3350 4700 5200 4700
Wire Wire Line
	5500 5000 4050 5000
Wire Wire Line
	5500 5100 4450 5100
Wire Wire Line
	4450 4450 4450 5100
Connection ~ 4450 5100
Wire Wire Line
	4450 5100 3350 5100
Wire Wire Line
	4050 4450 4050 5000
Connection ~ 4050 5000
Wire Wire Line
	4050 5000 3350 5000
Wire Wire Line
	4050 4150 4050 3800
Wire Wire Line
	4450 4150 4450 3800
Text HLabel 8750 4900 2    50   Output ~ 0
V5_0
Text HLabel 4700 2100 3    50   Input ~ 0
GND
Text HLabel 5400 2150 3    50   Input ~ 0
GND
Text HLabel 6000 2100 3    50   Input ~ 0
GND
Text HLabel 6700 5300 3    50   Input ~ 0
GND
Text HLabel 7200 5300 3    50   Input ~ 0
GND
Text HLabel 7750 5300 3    50   Input ~ 0
GND
Text HLabel 8250 5300 3    50   Input ~ 0
GND
Wire Wire Line
	8750 4800 7750 4800
Connection ~ 7750 4800
Wire Wire Line
	8250 4900 8750 4900
Connection ~ 8250 4900
Text HLabel 4350 1750 0    50   Input ~ 0
V5_USB
Wire Wire Line
	4700 1750 4350 1750
Connection ~ 4700 1750
Wire Wire Line
	6700 4450 6700 4600
Connection ~ 6700 4600
Text HLabel 4650 3700 1    50   Output ~ 0
V3_3_MCU
Wire Wire Line
	5200 3800 4850 3800
Connection ~ 4450 3800
Wire Wire Line
	4450 3800 4050 3800
Connection ~ 4850 3800
Wire Wire Line
	4850 3800 4650 3800
Wire Wire Line
	4650 3700 4650 3800
Connection ~ 4650 3800
Wire Wire Line
	4650 3800 4450 3800
$Comp
L Device:Net-Tie_2 NT5
U 1 1 5EA48D93
P 6700 4350
F 0 "NT5" V 6654 4394 50  0000 L CNN
F 1 "Net-Tie_2" V 6745 4394 50  0000 L CNN
F 2 "" H 6700 4350 50  0001 C CNN
F 3 "~" H 6700 4350 50  0001 C CNN
	1    6700 4350
	0    1    1    0   
$EndComp
Wire Wire Line
	6500 1750 6000 1750
Connection ~ 6000 1750
$EndSCHEMATC
