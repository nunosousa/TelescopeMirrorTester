EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 7
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
L Device:R R3
U 1 1 5E52A923
P 4750 4850
F 0 "R3" H 4820 4896 50  0000 L CNN
F 1 "1R" H 4820 4805 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4680 4850 50  0001 C CNN
F 3 "~" H 4750 4850 50  0001 C CNN
F 4 "RC0805FR-071RL" H 4750 4850 50  0001 C CNN "Manufacturer Part Number"
	1    4750 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5E529A2C
P 4400 4850
F 0 "R1" H 4470 4896 50  0000 L CNN
F 1 "1R" H 4470 4805 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4330 4850 50  0001 C CNN
F 3 "~" H 4400 4850 50  0001 C CNN
F 4 "RC0805FR-071RL" H 4400 4850 50  0001 C CNN "Manufacturer Part Number"
	1    4400 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 4700 4750 3900
Wire Wire Line
	4400 4700 4400 3800
Text Notes 3600 4900 0    50   ~ 0
Rated for 200mA
Text HLabel 5550 4100 0    50   Input ~ 0
MOTOR_CTRL_1A
Text HLabel 5550 4200 0    50   Input ~ 0
MOTOR_CTRL_1B
Text HLabel 5550 4300 0    50   Input ~ 0
MOTOR_CTRL_2A
Text HLabel 5550 4400 0    50   Input ~ 0
MOTOR_CTRL_2B
Wire Wire Line
	4400 3800 5550 3800
Wire Wire Line
	4750 3900 5550 3900
Text Notes 7750 3150 0    50   ~ 0
Low-ESR (ceramic)\nbypass capacitor
$Comp
L Device:C C1
U 1 1 5E554940
P 4850 3200
F 0 "C1" H 4965 3246 50  0000 L CNN
F 1 "0.01uC" H 4965 3155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4888 3050 50  0001 C CNN
F 3 "~" H 4850 3200 50  0001 C CNN
F 4 "CC0805KRX7R9BB103" H 4850 3200 50  0001 C CNN "Manufacturer Part Number"
	1    4850 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 2900 4850 3050
Wire Wire Line
	4850 3350 4850 3700
Wire Wire Line
	4850 3700 5550 3700
Text Notes 3700 3250 0    50   ~ 0
Low-ESR ceramic\ncapacitor rated for 16 V.
$Comp
L Device:C C3
U 1 1 5E5579B2
P 6800 3350
F 0 "C3" H 6915 3396 50  0000 L CNN
F 1 "2.2uC" H 6915 3305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6838 3200 50  0001 C CNN
F 3 "~" H 6800 3350 50  0001 C CNN
F 4 "CC0805KRX5R7BB225" H 6800 3350 50  0001 C CNN "Manufacturer Part Number"
	1    6800 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 3300 6350 3000
Text Notes 6850 3150 0    50   ~ 0
Ceramic capacitor\nrated 6.3 V.
Text HLabel 8950 3900 2    50   Output ~ 0
MOTOR_FAULT_12
Text HLabel 5550 3600 0    50   Input ~ 0
MOTOR_SLEEP_12
$Comp
L Device:C C5
U 1 1 5E5466EF
P 7700 3350
F 0 "C5" H 7815 3396 50  0000 L CNN
F 1 "10uC" H 7815 3305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7738 3200 50  0001 C CNN
F 3 "~" H 7700 3350 50  0001 C CNN
F 4 "CC0805MRX5R6BB106" H 7700 3350 50  0001 C CNN "Manufacturer Part Number"
	1    7700 3350
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:DRV8833PW U3
U 1 1 5E51B362
P 6150 4000
F 0 "U3" H 6400 3400 50  0000 C CNN
F 1 "DRV8833PW" H 6500 3300 50  0000 C CNN
F 2 "Package_SO:TSSOP-16_4.4x5mm_P0.65mm" H 6600 4450 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/drv8833.pdf" H 6000 4550 50  0001 C CNN
F 4 "DRV8833PWR" H 6150 4000 50  0001 C CNN "Manufacturer Part Number"
	1    6150 4000
	1    0    0    -1  
$EndComp
Connection ~ 4850 2900
Wire Wire Line
	7700 3200 7700 2900
Wire Wire Line
	7700 2900 6450 2900
Wire Wire Line
	6450 2900 6450 3300
Connection ~ 6450 2900
Wire Wire Line
	4850 2900 6450 2900
Wire Wire Line
	6800 3000 6350 3000
Wire Wire Line
	6800 3000 6800 3200
Text HLabel 2350 2900 0    50   Input ~ 0
V5_0
Text HLabel 4400 5000 3    50   Input ~ 0
GND
$Comp
L Connector:Conn_01x02_Male J2
U 1 1 5E623A42
P 9400 4200
AR Path="/5E507163/5E623A42" Ref="J2"  Part="1" 
AR Path="/5E623A42" Ref="J?"  Part="1" 
F 0 "J2" H 9372 4082 50  0000 R CNN
F 1 "Conn_01x02_Male" H 9372 4173 50  0000 R CNN
F 2 "Connector_JST:JST_XH_B2B-XH-A_1x02_P2.50mm_Vertical" H 9400 4200 50  0001 C CNN
F 3 "http://www.jst-mfg.com/product/pdf/eng/eXH.pdf" H 9400 4200 50  0001 C CNN
F 4 "B2B-XH-A(LF)(SN)" H 9400 4200 50  0001 C CNN "Manufacturer Part Number"
	1    9400 4200
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x02_Male J3
U 1 1 5E623A49
P 9400 4400
AR Path="/5E507163/5E623A49" Ref="J3"  Part="1" 
AR Path="/5E623A49" Ref="J?"  Part="1" 
F 0 "J3" H 9372 4282 50  0000 R CNN
F 1 "Conn_01x02_Male" H 9372 4373 50  0000 R CNN
F 2 "Connector_JST:JST_XH_B2B-XH-A_1x02_P2.50mm_Vertical" H 9400 4400 50  0001 C CNN
F 3 "http://www.jst-mfg.com/product/pdf/eng/eXH.pdf" H 9400 4400 50  0001 C CNN
F 4 "B2B-XH-A(LF)(SN)" H 9400 4400 50  0001 C CNN "Manufacturer Part Number"
	1    9400 4400
	-1   0    0    1   
$EndComp
Wire Wire Line
	6750 4100 9200 4100
Wire Wire Line
	6750 4200 9200 4200
Wire Wire Line
	6750 4300 9200 4300
Wire Wire Line
	6750 4400 9200 4400
$Comp
L Device:R R24
U 1 1 5E6297EE
P 8650 3650
F 0 "R24" H 8720 3696 50  0000 L CNN
F 1 "10kR" H 8720 3605 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 8580 3650 50  0001 C CNN
F 3 "~" H 8650 3650 50  0001 C CNN
F 4 "RC0805FR-0710KL" H 8650 3650 50  0001 C CNN "Manufacturer Part Number"
	1    8650 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 3900 8650 3900
Wire Wire Line
	8650 3800 8650 3900
Connection ~ 8650 3900
Wire Wire Line
	8650 3900 8950 3900
Text HLabel 8650 3500 1    50   Input ~ 0
V3_3
Text Label 6950 4100 0    50   ~ 0
MOTOR_1A
Text Label 6950 4200 0    50   ~ 0
MOTOR_1B
Text Label 6950 4300 0    50   ~ 0
MOTOR_2A
Text Label 6950 4400 0    50   ~ 0
MOTOR_2B
Text Label 4400 4650 1    50   ~ 0
MOTOR_1_CUR_SENS
Text Label 4750 4650 1    50   ~ 0
MOTOR_2_CUR_SENS
Text Label 6350 3250 1    50   ~ 0
VINT_1
Text Label 4850 3450 0    50   ~ 0
VCP_1
Wire Wire Line
	2350 2900 3300 2900
$Comp
L Device:Net-Tie_2 NT3
U 1 1 5EA0FF05
P 3400 2900
F 0 "NT3" H 3400 3081 50  0000 C CNN
F 1 "Net-Tie_2" H 3400 2990 50  0000 C CNN
F 2 "NetTie:NetTie-2_SMD_Pad0.5mm" H 3400 2900 50  0001 C CNN
F 3 "~" H 3400 2900 50  0001 C CNN
	1    3400 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 2900 4850 2900
Text HLabel 4750 5000 3    50   Input ~ 0
GND
Text HLabel 6150 4700 3    50   Input ~ 0
GND
Text HLabel 6800 3500 3    50   Input ~ 0
GND
Text HLabel 7700 3500 3    50   Input ~ 0
GND
$EndSCHEMATC
