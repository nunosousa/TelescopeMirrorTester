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
P 4250 3200
F 0 "R3" H 4320 3246 50  0000 L CNN
F 1 "1R" H 4320 3155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4180 3200 50  0001 C CNN
F 3 "~" H 4250 3200 50  0001 C CNN
F 4 "RC0805FR-071RL" H 4250 3200 50  0001 C CNN "Manufacturer Part Number"
	1    4250 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 3050 4250 2250
Wire Wire Line
	3900 3050 3900 2150
Text Notes 3100 3250 0    50   ~ 0
Rated for 200mA
Text HLabel 5050 2450 0    50   Input ~ 0
MOTOR_CTRL_1A
Text HLabel 5050 2550 0    50   Input ~ 0
MOTOR_CTRL_1B
Text HLabel 5050 2650 0    50   Input ~ 0
MOTOR_CTRL_2A
Text HLabel 5050 2750 0    50   Input ~ 0
MOTOR_CTRL_2B
Wire Wire Line
	3900 2150 5050 2150
Wire Wire Line
	4250 2250 5050 2250
Text Notes 7250 1500 0    50   ~ 0
Low-ESR (ceramic)\nbypass capacitor
$Comp
L Device:C C1
U 1 1 5E554940
P 4250 1550
F 0 "C1" H 4365 1596 50  0000 L CNN
F 1 "0.01uC" H 4365 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4288 1400 50  0001 C CNN
F 3 "~" H 4250 1550 50  0001 C CNN
F 4 "CC0805KRX7R9BB103" H 4250 1550 50  0001 C CNN "Manufacturer Part Number"
	1    4250 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 1250 4250 1400
Text Notes 3100 1600 0    50   ~ 0
Low-ESR ceramic\ncapacitor rated for 16 V.
$Comp
L Device:C C3
U 1 1 5E5579B2
P 6300 1700
F 0 "C3" H 6415 1746 50  0000 L CNN
F 1 "2.2uC" H 6415 1655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6338 1550 50  0001 C CNN
F 3 "~" H 6300 1700 50  0001 C CNN
F 4 "CC0805KRX5R7BB225" H 6300 1700 50  0001 C CNN "Manufacturer Part Number"
	1    6300 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 1650 5850 1350
Text Notes 6350 1500 0    50   ~ 0
Ceramic capacitor\nrated 6.3 V.
Text HLabel 8450 2250 2    50   Output ~ 0
MOTOR_FAULT_12
Text HLabel 5050 1950 0    50   Input ~ 0
MOTOR_SLEEP_12
$Comp
L Device:C C5
U 1 1 5E5466EF
P 7200 1700
F 0 "C5" H 7315 1746 50  0000 L CNN
F 1 "10uC" H 7315 1655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7238 1550 50  0001 C CNN
F 3 "~" H 7200 1700 50  0001 C CNN
F 4 "CC0805MRX5R6BB106" H 7200 1700 50  0001 C CNN "Manufacturer Part Number"
	1    7200 1700
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:DRV8833PW U3
U 1 1 5E51B362
P 5650 2350
F 0 "U3" H 5900 1750 50  0000 C CNN
F 1 "DRV8833PW" H 6000 1650 50  0000 C CNN
F 2 "Package_SO:TSSOP-16_4.4x5mm_P0.65mm" H 6100 2800 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/drv8833.pdf" H 5500 2900 50  0001 C CNN
F 4 "DRV8833PWR" H 5650 2350 50  0001 C CNN "Manufacturer Part Number"
	1    5650 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 1550 7200 1250
Wire Wire Line
	7200 1250 5950 1250
Wire Wire Line
	5950 1250 5950 1650
Connection ~ 5950 1250
Wire Wire Line
	6300 1350 5850 1350
Wire Wire Line
	6300 1350 6300 1550
Text HLabel 4000 1250 0    50   Input ~ 0
V5_0
$Comp
L Device:R R24
U 1 1 5E6297EE
P 8150 2000
F 0 "R24" H 8220 2046 50  0000 L CNN
F 1 "10kR" H 8220 1955 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 8080 2000 50  0001 C CNN
F 3 "~" H 8150 2000 50  0001 C CNN
F 4 "RC0805FR-0710KL" H 8150 2000 50  0001 C CNN "Manufacturer Part Number"
	1    8150 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 2250 8150 2250
Wire Wire Line
	8150 2150 8150 2250
Connection ~ 8150 2250
Wire Wire Line
	8150 2250 8450 2250
Text HLabel 8150 1850 1    50   Input ~ 0
V3_3
Text HLabel 4250 3350 3    50   Input ~ 0
GND
Text HLabel 5650 3050 3    50   Input ~ 0
GND
Text HLabel 6300 1850 3    50   Input ~ 0
GND
Text HLabel 7200 1850 3    50   Input ~ 0
GND
Connection ~ 4250 1250
Wire Wire Line
	4250 1250 5950 1250
Wire Wire Line
	4250 2050 4250 1700
Wire Wire Line
	4250 2050 5050 2050
Wire Wire Line
	4000 1250 4250 1250
Text HLabel 3900 3350 3    50   Input ~ 0
GND
$Comp
L Device:R R1
U 1 1 5E529A2C
P 3900 3200
F 0 "R1" H 3970 3246 50  0000 L CNN
F 1 "1R" H 3970 3155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3830 3200 50  0001 C CNN
F 3 "~" H 3900 3200 50  0001 C CNN
F 4 "RC0805FR-071RL" H 3900 3200 50  0001 C CNN "Manufacturer Part Number"
	1    3900 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R13
U 1 1 5EA9157C
P 4250 6200
F 0 "R13" H 4320 6246 50  0000 L CNN
F 1 "1R" H 4320 6155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4180 6200 50  0001 C CNN
F 3 "~" H 4250 6200 50  0001 C CNN
F 4 "RC0805FR-071RL" H 4250 6200 50  0001 C CNN "Manufacturer Part Number"
	1    4250 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 6050 4250 5250
Wire Wire Line
	3900 6050 3900 5150
Text Notes 3100 6250 0    50   ~ 0
Rated for 200mA
Text HLabel 5050 5450 0    50   Input ~ 0
MOTOR_CTRL_3A
Text HLabel 5050 5550 0    50   Input ~ 0
MOTOR_CTRL_3B
Text HLabel 5050 5650 0    50   Input ~ 0
MOTOR_CTRL_4A
Text HLabel 5050 5750 0    50   Input ~ 0
MOTOR_CTRL_4B
Wire Wire Line
	3900 5150 5050 5150
Wire Wire Line
	4250 5250 5050 5250
Text Notes 7250 4500 0    50   ~ 0
Low-ESR (ceramic)\nbypass capacitor
$Comp
L Device:C C35
U 1 1 5EA9158D
P 4250 4550
F 0 "C35" H 4365 4596 50  0000 L CNN
F 1 "0.01uC" H 4365 4505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4288 4400 50  0001 C CNN
F 3 "~" H 4250 4550 50  0001 C CNN
F 4 "CC0805KRX7R9BB103" H 4250 4550 50  0001 C CNN "Manufacturer Part Number"
	1    4250 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 4250 4250 4400
Text Notes 3100 4600 0    50   ~ 0
Low-ESR ceramic\ncapacitor rated for 16 V.
$Comp
L Device:C C36
U 1 1 5EA91596
P 6300 4700
F 0 "C36" H 6415 4746 50  0000 L CNN
F 1 "2.2uC" H 6415 4655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6338 4550 50  0001 C CNN
F 3 "~" H 6300 4700 50  0001 C CNN
F 4 "CC0805KRX5R7BB225" H 6300 4700 50  0001 C CNN "Manufacturer Part Number"
	1    6300 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 4650 5850 4350
Text Notes 6350 4500 0    50   ~ 0
Ceramic capacitor\nrated 6.3 V.
Text HLabel 8450 5250 2    50   Output ~ 0
MOTOR_FAULT_34
Text HLabel 5050 4950 0    50   Input ~ 0
MOTOR_SLEEP_34
$Comp
L Device:C C37
U 1 1 5EA915A1
P 7200 4700
F 0 "C37" H 7315 4746 50  0000 L CNN
F 1 "10uC" H 7315 4655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7238 4550 50  0001 C CNN
F 3 "~" H 7200 4700 50  0001 C CNN
F 4 "CC0805MRX5R6BB106" H 7200 4700 50  0001 C CNN "Manufacturer Part Number"
	1    7200 4700
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:DRV8833PW U14
U 1 1 5EA915A8
P 5650 5350
F 0 "U14" H 5900 4750 50  0000 C CNN
F 1 "DRV8833PW" H 6000 4650 50  0000 C CNN
F 2 "Package_SO:TSSOP-16_4.4x5mm_P0.65mm" H 6100 5800 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/drv8833.pdf" H 5500 5900 50  0001 C CNN
F 4 "DRV8833PWR" H 5650 5350 50  0001 C CNN "Manufacturer Part Number"
	1    5650 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 4550 7200 4250
Wire Wire Line
	7200 4250 5950 4250
Wire Wire Line
	5950 4250 5950 4650
Connection ~ 5950 4250
Wire Wire Line
	6300 4350 5850 4350
Wire Wire Line
	6300 4350 6300 4550
Text HLabel 4000 4250 0    50   Input ~ 0
V5_0
$Comp
L Device:R R17
U 1 1 5EA915C4
P 8150 5000
F 0 "R17" H 8220 5046 50  0000 L CNN
F 1 "10kR" H 8220 4955 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 8080 5000 50  0001 C CNN
F 3 "~" H 8150 5000 50  0001 C CNN
F 4 "RC0805FR-0710KL" H 8150 5000 50  0001 C CNN "Manufacturer Part Number"
	1    8150 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 5250 8150 5250
Wire Wire Line
	8150 5150 8150 5250
Connection ~ 8150 5250
Wire Wire Line
	8150 5250 8450 5250
Text HLabel 8150 4850 1    50   Input ~ 0
V3_3
Text HLabel 4250 6350 3    50   Input ~ 0
GND
Text HLabel 5650 6050 3    50   Input ~ 0
GND
Text HLabel 6300 4850 3    50   Input ~ 0
GND
Text HLabel 7200 4850 3    50   Input ~ 0
GND
Connection ~ 4250 4250
Wire Wire Line
	4250 4250 5950 4250
Wire Wire Line
	4250 5050 4250 4700
Wire Wire Line
	4250 5050 5050 5050
Wire Wire Line
	4000 4250 4250 4250
Text HLabel 3900 6350 3    50   Input ~ 0
GND
$Comp
L Device:R R12
U 1 1 5EA915E2
P 3900 6200
F 0 "R12" H 3970 6246 50  0000 L CNN
F 1 "1R" H 3970 6155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3830 6200 50  0001 C CNN
F 3 "~" H 3900 6200 50  0001 C CNN
F 4 "RC0805FR-071RL" H 3900 6200 50  0001 C CNN "Manufacturer Part Number"
	1    3900 6200
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5EA639A2
P 6450 2450
AR Path="/5E55806E/5EA639A2" Ref="J?"  Part="1" 
AR Path="/5E507163/5EA639A2" Ref="J2"  Part="1" 
F 0 "J2" H 6600 2350 50  0000 C CNN
F 1 "Conn_01x02" H 6750 2450 50  0000 C CNN
F 2 "Connector_JST:JST_PH_S2B-PH-K_1x02_P2.00mm_Horizontal" H 6450 2450 50  0001 C CNN
F 3 "http://www.jst-mfg.com/product/pdf/eng/ePH.pdf" H 6450 2450 50  0001 C CNN
F 4 "S2B-PH-K-S(LF)(SN)" H 6450 2450 50  0001 C CNN "Manufacturer Part Number"
	1    6450 2450
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5EA650C3
P 6450 2650
AR Path="/5E55806E/5EA650C3" Ref="J?"  Part="1" 
AR Path="/5E507163/5EA650C3" Ref="J3"  Part="1" 
F 0 "J3" H 6600 2550 50  0000 C CNN
F 1 "Conn_01x02" H 6750 2650 50  0000 C CNN
F 2 "Connector_JST:JST_PH_S2B-PH-K_1x02_P2.00mm_Horizontal" H 6450 2650 50  0001 C CNN
F 3 "http://www.jst-mfg.com/product/pdf/eng/ePH.pdf" H 6450 2650 50  0001 C CNN
F 4 "S2B-PH-K-S(LF)(SN)" H 6450 2650 50  0001 C CNN "Manufacturer Part Number"
	1    6450 2650
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5EA66B65
P 6450 5450
AR Path="/5E55806E/5EA66B65" Ref="J?"  Part="1" 
AR Path="/5E507163/5EA66B65" Ref="J4"  Part="1" 
F 0 "J4" H 6600 5350 50  0000 C CNN
F 1 "Conn_01x02" H 6750 5450 50  0000 C CNN
F 2 "Connector_JST:JST_PH_S2B-PH-K_1x02_P2.00mm_Horizontal" H 6450 5450 50  0001 C CNN
F 3 "http://www.jst-mfg.com/product/pdf/eng/ePH.pdf" H 6450 5450 50  0001 C CNN
F 4 "S2B-PH-K-S(LF)(SN)" H 6450 5450 50  0001 C CNN "Manufacturer Part Number"
	1    6450 5450
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5EA66B6B
P 6450 5650
AR Path="/5E55806E/5EA66B6B" Ref="J?"  Part="1" 
AR Path="/5E507163/5EA66B6B" Ref="J5"  Part="1" 
F 0 "J5" H 6600 5550 50  0000 C CNN
F 1 "Conn_01x02" H 6750 5650 50  0000 C CNN
F 2 "Connector_JST:JST_PH_S2B-PH-K_1x02_P2.00mm_Horizontal" H 6450 5650 50  0001 C CNN
F 3 "http://www.jst-mfg.com/product/pdf/eng/ePH.pdf" H 6450 5650 50  0001 C CNN
F 4 "S2B-PH-K-S(LF)(SN)" H 6450 5650 50  0001 C CNN "Manufacturer Part Number"
	1    6450 5650
	1    0    0    -1  
$EndComp
$EndSCHEMATC
