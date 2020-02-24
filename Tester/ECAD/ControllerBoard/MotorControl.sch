EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 4
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
L Driver_Motor:DRV8833PW U?
U 1 1 5E51B362
P 8850 2050
F 0 "U?" H 8850 1261 50  0000 C CNN
F 1 "DRV8833PW" H 8850 1170 50  0000 C CNN
F 2 "Package_SO:TSSOP-16_4.4x5mm_P0.65mm" H 9300 2500 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/drv8833.pdf" H 8700 2600 50  0001 C CNN
F 4 "tbd" H 8850 2050 50  0001 C CNN "Manufacturer Part Number"
	1    8850 2050
	1    0    0    -1  
$EndComp
Text HLabel 9450 2450 2    50   Output ~ 0
MOTOR_OUT_2-
Text HLabel 9450 2350 2    50   Output ~ 0
MOTOR_OUT_2+
Text HLabel 9450 2250 2    50   Output ~ 0
MOTOR_OUT_1-
Text HLabel 9450 2150 2    50   Output ~ 0
MOTOR_OUT_1+
Text HLabel 9450 5200 2    50   Output ~ 0
MOTOR_OUT_4-
Text HLabel 9450 5100 2    50   Output ~ 0
MOTOR_OUT_4+
Text HLabel 9450 5000 2    50   Output ~ 0
MOTOR_OUT_3-
Text HLabel 9450 4900 2    50   Output ~ 0
MOTOR_OUT_3+
Text HLabel 1350 850  0    50   Input ~ 0
12V_POWER_IN
Text HLabel 950  7350 0    50   Input ~ 0
GND
$Comp
L Device:R R?
U 1 1 5E52ACD2
P 7500 5650
F 0 "R?" H 7430 5604 50  0000 R CNN
F 1 "1R" H 7430 5695 50  0000 R CNN
F 2 "" V 7430 5650 50  0001 C CNN
F 3 "~" H 7500 5650 50  0001 C CNN
F 4 "tbd" H 7500 5650 50  0001 C CNN "Manufacturer Part Number"
	1    7500 5650
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5E52B98B
P 7150 5650
F 0 "R?" H 7220 5696 50  0000 L CNN
F 1 "1R" H 7220 5605 50  0000 L CNN
F 2 "" V 7080 5650 50  0001 C CNN
F 3 "~" H 7150 5650 50  0001 C CNN
F 4 "tbd" H 7150 5650 50  0001 C CNN "Manufacturer Part Number"
	1    7150 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E52A923
P 7450 2900
F 0 "R?" H 7520 2946 50  0000 L CNN
F 1 "1R" H 7520 2855 50  0000 L CNN
F 2 "" V 7380 2900 50  0001 C CNN
F 3 "~" H 7450 2900 50  0001 C CNN
F 4 "tbd" H 7450 2900 50  0001 C CNN "Manufacturer Part Number"
	1    7450 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E529A2C
P 7100 2900
F 0 "R?" H 7170 2946 50  0000 L CNN
F 1 "1R" H 7170 2855 50  0000 L CNN
F 2 "" V 7030 2900 50  0001 C CNN
F 3 "~" H 7100 2900 50  0001 C CNN
F 4 "tbd" H 7100 2900 50  0001 C CNN "Manufacturer Part Number"
	1    7100 2900
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:DRV8833PW U?
U 1 1 5E51A8F9
P 8850 4800
F 0 "U?" H 8850 4011 50  0000 C CNN
F 1 "DRV8833PW" H 8850 3920 50  0000 C CNN
F 2 "Package_SO:TSSOP-16_4.4x5mm_P0.65mm" H 9300 5250 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/drv8833.pdf" H 8700 5350 50  0001 C CNN
F 4 "tbd" H 8850 4800 50  0001 C CNN "Manufacturer Part Number"
	1    8850 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 2750 8850 3050
Wire Wire Line
	7450 3050 7100 3050
Wire Wire Line
	7050 3050 7050 5800
Wire Wire Line
	7050 5800 7150 5800
Connection ~ 7450 3050
Connection ~ 7500 5800
Wire Wire Line
	8850 5800 8850 5500
Wire Wire Line
	7500 5500 7500 4700
Wire Wire Line
	7150 4600 7150 5500
Wire Wire Line
	7450 2750 7450 1950
Wire Wire Line
	7100 2750 7100 1850
Text Notes 7400 3200 0    50   ~ 0
Rated for 200mA
Text Notes 7400 5950 0    50   ~ 0
Rated for 200mA
Text HLabel 8250 2150 0    50   Input ~ 0
MOTOR_CTRL_1A
Text HLabel 8250 2250 0    50   Input ~ 0
MOTOR_CTRL_1B
Text HLabel 8250 2350 0    50   Input ~ 0
MOTOR_CTRL_2A
Text HLabel 8250 2450 0    50   Input ~ 0
MOTOR_CTRL_2B
Text HLabel 8250 4900 0    50   Input ~ 0
MOTOR_CTRL_3A
Text HLabel 8250 5000 0    50   Input ~ 0
MOTOR_CTRL_3B
Text HLabel 8250 5100 0    50   Input ~ 0
MOTOR_CTRL_4A
Text HLabel 8250 5200 0    50   Input ~ 0
MOTOR_CTRL_4B
$Comp
L Device:CP C?
U 1 1 5E54E959
P 10400 1400
F 0 "C?" H 10518 1446 50  0000 L CNN
F 1 "10uCP" H 10518 1355 50  0000 L CNN
F 2 "" H 10438 1250 50  0001 C CNN
F 3 "~" H 10400 1400 50  0001 C CNN
F 4 "tbd" H 10400 1400 50  0001 C CNN "Manufacturer Part Number"
	1    10400 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 1150 10400 1150
Wire Wire Line
	10400 1150 10400 1250
$Comp
L Device:CP C?
U 1 1 5E54FC20
P 10400 4100
F 0 "C?" H 10518 4146 50  0000 L CNN
F 1 "10uCP" H 10518 4055 50  0000 L CNN
F 2 "" H 10438 3950 50  0001 C CNN
F 3 "~" H 10400 4100 50  0001 C CNN
F 4 "tbd" H 10400 4100 50  0001 C CNN "Manufacturer Part Number"
	1    10400 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 4100 9150 3750
Wire Wire Line
	9150 3750 10400 3750
Wire Wire Line
	10400 3750 10400 3950
Wire Wire Line
	10400 4250 10400 4500
Wire Wire Line
	10400 5800 8850 5800
Connection ~ 8850 5800
Wire Wire Line
	8850 3050 10400 3050
Wire Wire Line
	10400 3050 10400 1800
Connection ~ 8850 3050
Connection ~ 7100 3050
Wire Wire Line
	7100 3050 7050 3050
Wire Wire Line
	7450 3050 8850 3050
Wire Wire Line
	7100 1850 8250 1850
Wire Wire Line
	7450 1950 8250 1950
Connection ~ 7150 5800
Wire Wire Line
	7150 5800 7500 5800
Wire Wire Line
	7500 5800 8850 5800
Wire Wire Line
	7150 4600 8250 4600
Wire Wire Line
	7500 4700 8250 4700
Text Notes 10150 1650 0    50   ~ 0
Low-ESR (ceramic)\nbypass capacitor
Text Notes 10250 4400 0    50   ~ 0
Low-ESR (ceramic)\nbypass capacitor
$Comp
L Device:C C?
U 1 1 5E554940
P 7550 1250
F 0 "C?" H 7665 1296 50  0000 L CNN
F 1 "0.01uC" H 7665 1205 50  0000 L CNN
F 2 "" H 7588 1100 50  0001 C CNN
F 3 "~" H 7550 1250 50  0001 C CNN
F 4 "tbd" H 7550 1250 50  0001 C CNN "Manufacturer Part Number"
	1    7550 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 1150 8350 1150
Wire Wire Line
	8350 1150 8350 950 
Wire Wire Line
	8350 950  7550 950 
Wire Wire Line
	7550 950  7550 1100
Connection ~ 9150 1150
Wire Wire Line
	7550 1400 7550 1750
Wire Wire Line
	7550 1750 8250 1750
$Comp
L Device:C C?
U 1 1 5E556072
P 7600 4050
F 0 "C?" H 7715 4096 50  0000 L CNN
F 1 "0.01uC" H 7715 4005 50  0000 L CNN
F 2 "" H 7638 3900 50  0001 C CNN
F 3 "~" H 7600 4050 50  0001 C CNN
F 4 "tbd" H 7600 4050 50  0001 C CNN "Manufacturer Part Number"
	1    7600 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 3750 7600 3900
Connection ~ 9150 3750
Wire Wire Line
	7600 4200 7600 4500
Wire Wire Line
	7600 4500 8250 4500
Text Notes 7200 1100 0    50   ~ 0
Low-ESR ceramic\ncapacitor rated for 16 V.
Text Notes 7350 3900 0    50   ~ 0
Low-ESR ceramic\ncapacitor rated for 16 V.
$Comp
L Device:C C?
U 1 1 5E5579B2
P 9500 1400
F 0 "C?" H 9615 1446 50  0000 L CNN
F 1 "2.2uC" H 9615 1355 50  0000 L CNN
F 2 "" H 9538 1250 50  0001 C CNN
F 3 "~" H 9500 1400 50  0001 C CNN
F 4 "tbd" H 9500 1400 50  0001 C CNN "Manufacturer Part Number"
	1    9500 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 1350 9050 1000
Wire Wire Line
	9050 1000 9500 1000
Wire Wire Line
	9500 1000 9500 1250
Wire Wire Line
	9500 1550 9500 1800
Wire Wire Line
	9500 1800 10400 1800
Connection ~ 10400 1800
Wire Wire Line
	10400 1800 10400 1550
$Comp
L Device:C C?
U 1 1 5E5593EC
P 9500 4100
F 0 "C?" H 9615 4146 50  0000 L CNN
F 1 "2.2uC" H 9615 4055 50  0000 L CNN
F 2 "" H 9538 3950 50  0001 C CNN
F 3 "~" H 9500 4100 50  0001 C CNN
F 4 "tbd" H 9500 4100 50  0001 C CNN "Manufacturer Part Number"
	1    9500 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 4100 9050 3600
Wire Wire Line
	9050 3600 9500 3600
Wire Wire Line
	9500 3600 9500 3950
Wire Wire Line
	9500 4250 9500 4500
Wire Wire Line
	9500 4500 10400 4500
Connection ~ 10400 4500
Wire Wire Line
	10400 4500 10400 5800
Text Notes 9450 1250 0    50   ~ 0
Ceramic capacitor\nrated 6.3 V.
Text Notes 9400 3950 0    50   ~ 0
Ceramic capacitor\nrated 6.3 V.
Text HLabel 9450 1950 2    50   Output ~ 0
MOTOR_FAULT_12
Text HLabel 9450 4700 2    50   Output ~ 0
MOTOR_FAULT_34
Text HLabel 8250 1650 0    50   Input ~ 0
MOTOR_SLEEP_12
Text HLabel 8250 4400 0    50   Input ~ 0
MOTOR_SLEEP_34
Wire Wire Line
	9150 1350 9150 1150
Wire Wire Line
	9150 3750 8850 3750
Wire Wire Line
	8350 1150 8350 1450
Wire Wire Line
	8350 1450 6550 1450
Wire Wire Line
	6550 1450 6550 3400
Wire Wire Line
	6550 3400 8850 3400
Wire Wire Line
	8850 3400 8850 3750
Connection ~ 8350 1150
Connection ~ 8850 3750
Wire Wire Line
	8850 3750 7600 3750
$Comp
L Regulator_Switching:TPS562200 U?
U 1 1 5E567A0E
P 3550 3800
F 0 "U?" H 3550 4167 50  0000 C CNN
F 1 "TPS562200" H 3550 4076 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 3600 3550 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/tps563200.pdf" H 3550 3800 50  0001 C CNN
F 4 "tbd" H 3550 3800 50  0001 C CNN "Manufacturer Part Number"
	1    3550 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 7350 6600 5800
Wire Wire Line
	6600 5800 7050 5800
Wire Wire Line
	950  7350 6600 7350
Connection ~ 7050 5800
$EndSCHEMATC
