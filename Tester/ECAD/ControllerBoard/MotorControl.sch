EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 6
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
L Device:R R4
U 1 1 5E52ACD2
P 4500 5900
F 0 "R4" H 4430 5854 50  0000 R CNN
F 1 "1R" H 4430 5945 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4430 5900 50  0001 C CNN
F 3 "~" H 4500 5900 50  0001 C CNN
F 4 "RC0805FR-071RL" H 4500 5900 50  0001 C CNN "Manufacturer Part Number"
	1    4500 5900
	-1   0    0    1   
$EndComp
$Comp
L Device:R R2
U 1 1 5E52B98B
P 4150 5900
F 0 "R2" H 4220 5946 50  0000 L CNN
F 1 "1R" H 4220 5855 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4080 5900 50  0001 C CNN
F 3 "~" H 4150 5900 50  0001 C CNN
F 4 "RC0805FR-071RL" H 4150 5900 50  0001 C CNN "Manufacturer Part Number"
	1    4150 5900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5E52A923
P 4450 3150
F 0 "R3" H 4520 3196 50  0000 L CNN
F 1 "1R" H 4520 3105 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4380 3150 50  0001 C CNN
F 3 "~" H 4450 3150 50  0001 C CNN
F 4 "RC0805FR-071RL" H 4450 3150 50  0001 C CNN "Manufacturer Part Number"
	1    4450 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5E529A2C
P 4100 3150
F 0 "R1" H 4170 3196 50  0000 L CNN
F 1 "1R" H 4170 3105 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4030 3150 50  0001 C CNN
F 3 "~" H 4100 3150 50  0001 C CNN
F 4 "RC0805FR-071RL" H 4100 3150 50  0001 C CNN "Manufacturer Part Number"
	1    4100 3150
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:DRV8833PW U4
U 1 1 5E51A8F9
P 5850 5050
F 0 "U4" H 5850 4261 50  0000 C CNN
F 1 "DRV8833PW" H 5850 4170 50  0000 C CNN
F 2 "Package_SO:TSSOP-16_4.4x5mm_P0.65mm" H 6300 5500 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/drv8833.pdf" H 5700 5600 50  0001 C CNN
F 4 "DRV8833PWR" H 5850 5050 50  0001 C CNN "Manufacturer Part Number"
	1    5850 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3000 5850 3300
Wire Wire Line
	4450 3300 4100 3300
Wire Wire Line
	4050 6050 4150 6050
Connection ~ 4450 3300
Connection ~ 4500 6050
Wire Wire Line
	5850 6050 5850 5750
Wire Wire Line
	4500 5750 4500 4950
Wire Wire Line
	4150 4850 4150 5750
Wire Wire Line
	4450 3000 4450 2200
Wire Wire Line
	4100 3000 4100 2100
Text Notes 4400 3450 0    50   ~ 0
Rated for 200mA
Text Notes 4400 6200 0    50   ~ 0
Rated for 200mA
Text HLabel 5250 2400 0    50   Input ~ 0
MOTOR_CTRL_1A
Text HLabel 5250 2500 0    50   Input ~ 0
MOTOR_CTRL_1B
Text HLabel 5250 2600 0    50   Input ~ 0
MOTOR_CTRL_2A
Text HLabel 5250 2700 0    50   Input ~ 0
MOTOR_CTRL_2B
Text HLabel 5250 5150 0    50   Input ~ 0
MOTOR_CTRL_3A
Text HLabel 5250 5250 0    50   Input ~ 0
MOTOR_CTRL_3B
Text HLabel 5250 5350 0    50   Input ~ 0
MOTOR_CTRL_4A
Text HLabel 5250 5450 0    50   Input ~ 0
MOTOR_CTRL_4B
Wire Wire Line
	7400 4500 7400 4750
Wire Wire Line
	7400 6050 5850 6050
Connection ~ 5850 6050
Wire Wire Line
	5850 3300 7400 3300
Wire Wire Line
	7400 3300 7400 2050
Connection ~ 5850 3300
Connection ~ 4100 3300
Wire Wire Line
	4100 3300 4050 3300
Wire Wire Line
	4450 3300 5850 3300
Wire Wire Line
	4100 2100 5250 2100
Wire Wire Line
	4450 2200 5250 2200
Connection ~ 4150 6050
Wire Wire Line
	4150 6050 4500 6050
Wire Wire Line
	4500 6050 5850 6050
Wire Wire Line
	4150 4850 5250 4850
Wire Wire Line
	4500 4950 5250 4950
Text Notes 7150 1900 0    50   ~ 0
Low-ESR (ceramic)\nbypass capacitor
Text Notes 7250 4650 0    50   ~ 0
Low-ESR (ceramic)\nbypass capacitor
$Comp
L Device:C C1
U 1 1 5E554940
P 4550 1500
F 0 "C1" H 4665 1546 50  0000 L CNN
F 1 "0.01uC" H 4665 1455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4588 1350 50  0001 C CNN
F 3 "~" H 4550 1500 50  0001 C CNN
F 4 "CC0805KRX7R9BB103" H 4550 1500 50  0001 C CNN "Manufacturer Part Number"
	1    4550 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 1200 4550 1350
Wire Wire Line
	4550 1650 4550 2000
Wire Wire Line
	4550 2000 5250 2000
$Comp
L Device:C C2
U 1 1 5E556072
P 4600 4300
F 0 "C2" H 4715 4346 50  0000 L CNN
F 1 "0.01uC" H 4715 4255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4638 4150 50  0001 C CNN
F 3 "~" H 4600 4300 50  0001 C CNN
F 4 "CC0805KRX7R9BB103" H 4600 4300 50  0001 C CNN "Manufacturer Part Number"
	1    4600 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 4450 4600 4750
Wire Wire Line
	4600 4750 5250 4750
Text Notes 4200 1350 0    50   ~ 0
Low-ESR ceramic\ncapacitor rated for 16 V.
Text Notes 4350 4150 0    50   ~ 0
Low-ESR ceramic\ncapacitor rated for 16 V.
$Comp
L Device:C C3
U 1 1 5E5579B2
P 6500 1650
F 0 "C3" H 6615 1696 50  0000 L CNN
F 1 "2.2uC" H 6615 1605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6538 1500 50  0001 C CNN
F 3 "~" H 6500 1650 50  0001 C CNN
F 4 "CC0805KRX5R7BB225" H 6500 1650 50  0001 C CNN "Manufacturer Part Number"
	1    6500 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 1600 6050 1300
Wire Wire Line
	6500 1800 6500 2050
Wire Wire Line
	6500 2050 7400 2050
Connection ~ 7400 2050
Wire Wire Line
	7400 2050 7400 1800
$Comp
L Device:C C4
U 1 1 5E5593EC
P 6500 4350
F 0 "C4" H 6615 4396 50  0000 L CNN
F 1 "2.2uC" H 6615 4305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6538 4200 50  0001 C CNN
F 3 "~" H 6500 4350 50  0001 C CNN
F 4 "CC0805KRX5R7BB225" H 6500 4350 50  0001 C CNN "Manufacturer Part Number"
	1    6500 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 4350 6050 3850
Wire Wire Line
	6050 3850 6500 3850
Wire Wire Line
	6500 3850 6500 4200
Wire Wire Line
	6500 4500 6500 4750
Wire Wire Line
	6500 4750 7400 4750
Connection ~ 7400 4750
Wire Wire Line
	7400 4750 7400 6050
Text Notes 6450 1500 0    50   ~ 0
Ceramic capacitor\nrated 6.3 V.
Text Notes 6400 4200 0    50   ~ 0
Ceramic capacitor\nrated 6.3 V.
Text HLabel 8650 2200 2    50   Output ~ 0
MOTOR_FAULT_12
Text HLabel 8650 4950 2    50   Output ~ 0
MOTOR_FAULT_34
Text HLabel 5250 1900 0    50   Input ~ 0
MOTOR_SLEEP_12
Text HLabel 5250 4650 0    50   Input ~ 0
MOTOR_SLEEP_34
$Comp
L Device:C C5
U 1 1 5E5466EF
P 7400 1650
F 0 "C5" H 7515 1696 50  0000 L CNN
F 1 "10uC" H 7515 1605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7438 1500 50  0001 C CNN
F 3 "~" H 7400 1650 50  0001 C CNN
F 4 "CC0805MRX5R6BB106" H 7400 1650 50  0001 C CNN "Manufacturer Part Number"
	1    7400 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 5E5419EC
P 7400 4350
F 0 "C6" H 7515 4396 50  0000 L CNN
F 1 "10uC" H 7515 4305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7438 4200 50  0001 C CNN
F 3 "~" H 7400 4350 50  0001 C CNN
F 4 "CC0805MRX5R6BB106" H 7400 4350 50  0001 C CNN "Manufacturer Part Number"
	1    7400 4350
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:DRV8833PW U3
U 1 1 5E51B362
P 5850 2300
F 0 "U3" H 5850 1511 50  0000 C CNN
F 1 "DRV8833PW" H 5850 1420 50  0000 C CNN
F 2 "Package_SO:TSSOP-16_4.4x5mm_P0.65mm" H 6300 2750 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/drv8833.pdf" H 5700 2850 50  0001 C CNN
F 4 "DRV8833PWR" H 5850 2300 50  0001 C CNN "Manufacturer Part Number"
	1    5850 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 1200 4550 1200
Wire Wire Line
	3550 1200 3550 1950
Connection ~ 4550 1200
Wire Wire Line
	7400 1500 7400 1200
Wire Wire Line
	7400 1200 6150 1200
Wire Wire Line
	6150 1200 6150 1600
Connection ~ 6150 1200
Wire Wire Line
	4550 1200 6150 1200
Wire Wire Line
	6500 1300 6050 1300
Wire Wire Line
	6500 1300 6500 1500
Wire Wire Line
	7400 3650 7400 4200
Wire Wire Line
	6150 3650 6150 4350
Connection ~ 6150 3650
Wire Wire Line
	6150 3650 7400 3650
Wire Wire Line
	4600 3650 4600 4150
Wire Wire Line
	3550 3650 4600 3650
Connection ~ 4600 3650
Wire Wire Line
	4600 3650 6150 3650
Wire Wire Line
	4050 3300 4050 5050
Text HLabel 2100 1950 0    50   Input ~ 0
VMOTOR
Text HLabel 2050 5050 0    50   Input ~ 0
GND
Wire Wire Line
	2100 1950 3550 1950
Connection ~ 3550 1950
Wire Wire Line
	3550 1950 3550 3650
Wire Wire Line
	2050 5050 4050 5050
Connection ~ 4050 5050
Wire Wire Line
	4050 5050 4050 6050
$Comp
L Connector:Conn_01x02_Male J2
U 1 1 5E623A42
P 9100 2500
AR Path="/5E507163/5E623A42" Ref="J2"  Part="1" 
AR Path="/5E623A42" Ref="J?"  Part="1" 
F 0 "J2" H 9072 2382 50  0000 R CNN
F 1 "Conn_01x02_Male" H 9072 2473 50  0000 R CNN
F 2 "Connector_Molex_Custom:Molex_PicoBlade_53048-0210_1x02_P1.25mm_Horizontal" H 9100 2500 50  0001 C CNN
F 3 "~" H 9100 2500 50  0001 C CNN
F 4 "0530480210" H 9100 2500 50  0001 C CNN "Manufacturer Part Number"
	1    9100 2500
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x02_Male J3
U 1 1 5E623A49
P 9100 2700
AR Path="/5E507163/5E623A49" Ref="J3"  Part="1" 
AR Path="/5E623A49" Ref="J?"  Part="1" 
F 0 "J3" H 9072 2582 50  0000 R CNN
F 1 "Conn_01x02_Male" H 9072 2673 50  0000 R CNN
F 2 "Connector_Molex_Custom:Molex_PicoBlade_53048-0210_1x02_P1.25mm_Horizontal" H 9100 2700 50  0001 C CNN
F 3 "~" H 9100 2700 50  0001 C CNN
F 4 "0530480210" H 9100 2700 50  0001 C CNN "Manufacturer Part Number"
	1    9100 2700
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x02_Male J4
U 1 1 5E623A50
P 9150 5250
AR Path="/5E507163/5E623A50" Ref="J4"  Part="1" 
AR Path="/5E623A50" Ref="J?"  Part="1" 
F 0 "J4" H 9122 5132 50  0000 R CNN
F 1 "Conn_01x02_Male" H 9122 5223 50  0000 R CNN
F 2 "Connector_Molex_Custom:Molex_PicoBlade_53048-0210_1x02_P1.25mm_Horizontal" H 9150 5250 50  0001 C CNN
F 3 "~" H 9150 5250 50  0001 C CNN
F 4 "0530480210" H 9150 5250 50  0001 C CNN "Manufacturer Part Number"
	1    9150 5250
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x02_Male J5
U 1 1 5E623A57
P 9150 5450
AR Path="/5E507163/5E623A57" Ref="J5"  Part="1" 
AR Path="/5E623A57" Ref="J?"  Part="1" 
F 0 "J5" H 9122 5332 50  0000 R CNN
F 1 "Conn_01x02_Male" H 9122 5423 50  0000 R CNN
F 2 "Connector_Molex_Custom:Molex_PicoBlade_53048-0210_1x02_P1.25mm_Horizontal" H 9150 5450 50  0001 C CNN
F 3 "~" H 9150 5450 50  0001 C CNN
F 4 "0530480210" H 9150 5450 50  0001 C CNN "Manufacturer Part Number"
	1    9150 5450
	-1   0    0    1   
$EndComp
Wire Wire Line
	6450 2400 8900 2400
Wire Wire Line
	6450 2500 8900 2500
Wire Wire Line
	6450 2600 8900 2600
Wire Wire Line
	6450 2700 8900 2700
Wire Wire Line
	6450 5150 8950 5150
Wire Wire Line
	8950 5250 6450 5250
Wire Wire Line
	6450 5350 8950 5350
Wire Wire Line
	8950 5450 6450 5450
$Comp
L Device:R R29
U 1 1 5E624B95
P 8350 4700
F 0 "R29" H 8420 4746 50  0000 L CNN
F 1 "10kR" H 8420 4655 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 8280 4700 50  0001 C CNN
F 3 "~" H 8350 4700 50  0001 C CNN
F 4 "RC0805FR-0710KL" H 8350 4700 50  0001 C CNN "Manufacturer Part Number"
	1    8350 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 4950 8350 4950
Wire Wire Line
	8350 4850 8350 4950
Connection ~ 8350 4950
Wire Wire Line
	8350 4950 8650 4950
$Comp
L Device:R R24
U 1 1 5E6297EE
P 8350 1950
F 0 "R24" H 8420 1996 50  0000 L CNN
F 1 "10kR" H 8420 1905 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 8280 1950 50  0001 C CNN
F 3 "~" H 8350 1950 50  0001 C CNN
F 4 "RC0805FR-0710KL" H 8350 1950 50  0001 C CNN "Manufacturer Part Number"
	1    8350 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 2200 8350 2200
Wire Wire Line
	8350 2100 8350 2200
Connection ~ 8350 2200
Wire Wire Line
	8350 2200 8650 2200
Text HLabel 2050 900  0    50   Input ~ 0
V3_3
Wire Wire Line
	2050 900  8350 900 
Wire Wire Line
	8350 900  8350 1700
Wire Wire Line
	8350 1700 8150 1700
Wire Wire Line
	8150 1700 8150 3000
Wire Wire Line
	8150 3000 8350 3000
Wire Wire Line
	8350 3000 8350 4550
Connection ~ 8350 1700
Wire Wire Line
	8350 1700 8350 1800
Text Label 6650 2400 0    50   ~ 0
MOTOR_1A
Text Label 6650 2500 0    50   ~ 0
MOTOR_1B
Text Label 6650 2600 0    50   ~ 0
MOTOR_2A
Text Label 6650 2700 0    50   ~ 0
MOTOR_2B
Text Label 6700 5150 0    50   ~ 0
MOTOR_3A
Text Label 6700 5250 0    50   ~ 0
MOTOR_3B
Text Label 6700 5350 0    50   ~ 0
MOTOR_4A
Text Label 6700 5450 0    50   ~ 0
MOTOR_4B
Text Label 4100 2950 1    50   ~ 0
MOTOR_1_CUR_SENS
Text Label 4450 2950 1    50   ~ 0
MOTOR_2_CUR_SENS
Text Label 4150 5700 1    50   ~ 0
MOTOR_3_CUR_SENS
Text Label 4500 5700 1    50   ~ 0
MOTOR_4_CUR_SENS
Text Label 6050 1550 1    50   ~ 0
VINT_1
Text Label 6050 4250 1    50   ~ 0
VINT_2
Text Label 4600 4550 0    50   ~ 0
VCP_2
Text Label 4550 1750 0    50   ~ 0
VCP_1
$EndSCHEMATC
