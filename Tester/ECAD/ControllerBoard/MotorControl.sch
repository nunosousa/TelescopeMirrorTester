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
P 9000 1700
F 0 "U?" H 9000 911 50  0000 C CNN
F 1 "DRV8833PW" H 9000 820 50  0000 C CNN
F 2 "Package_SO:TSSOP-16_4.4x5mm_P0.65mm" H 9450 2150 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/drv8833.pdf" H 8850 2250 50  0001 C CNN
	1    9000 1700
	1    0    0    -1  
$EndComp
Text HLabel 9600 2100 2    50   Output ~ 0
MOTOR_OUT_2-
Text HLabel 9600 2000 2    50   Output ~ 0
MOTOR_OUT_2+
Text HLabel 9600 1900 2    50   Output ~ 0
MOTOR_OUT_1-
Text HLabel 9600 1800 2    50   Output ~ 0
MOTOR_OUT_1+
Text HLabel 9600 4850 2    50   Output ~ 0
MOTOR_OUT_4-
Text HLabel 9600 4750 2    50   Output ~ 0
MOTOR_OUT_4+
Text HLabel 9600 4650 2    50   Output ~ 0
MOTOR_OUT_3-
Text HLabel 9600 4550 2    50   Output ~ 0
MOTOR_OUT_3+
Text HLabel 1350 850  0    50   Input ~ 0
12V_POWER_IN
Text HLabel 950  7350 0    50   Input ~ 0
GND
$Comp
L Device:R R?
U 1 1 5E52ACD2
P 7650 5300
F 0 "R?" H 7580 5254 50  0000 R CNN
F 1 "1R" H 7580 5345 50  0000 R CNN
F 2 "" V 7580 5300 50  0001 C CNN
F 3 "~" H 7650 5300 50  0001 C CNN
	1    7650 5300
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5E52B98B
P 7300 5300
F 0 "R?" H 7370 5346 50  0000 L CNN
F 1 "1R" H 7370 5255 50  0000 L CNN
F 2 "" V 7230 5300 50  0001 C CNN
F 3 "~" H 7300 5300 50  0001 C CNN
	1    7300 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E52A923
P 7600 2550
F 0 "R?" H 7670 2596 50  0000 L CNN
F 1 "1R" H 7670 2505 50  0000 L CNN
F 2 "" V 7530 2550 50  0001 C CNN
F 3 "~" H 7600 2550 50  0001 C CNN
	1    7600 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E529A2C
P 7250 2550
F 0 "R?" H 7320 2596 50  0000 L CNN
F 1 "1R" H 7320 2505 50  0000 L CNN
F 2 "" V 7180 2550 50  0001 C CNN
F 3 "~" H 7250 2550 50  0001 C CNN
	1    7250 2550
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:DRV8833PW U?
U 1 1 5E51A8F9
P 9000 4450
F 0 "U?" H 9000 3661 50  0000 C CNN
F 1 "DRV8833PW" H 9000 3570 50  0000 C CNN
F 2 "Package_SO:TSSOP-16_4.4x5mm_P0.65mm" H 9450 4900 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/drv8833.pdf" H 8850 5000 50  0001 C CNN
	1    9000 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 2400 9000 2700
Wire Wire Line
	7600 2700 7250 2700
Wire Wire Line
	7200 2700 7200 5450
Wire Wire Line
	7200 5450 7300 5450
Connection ~ 7600 2700
Connection ~ 7650 5450
Wire Wire Line
	9000 5450 9000 5150
Wire Wire Line
	7650 5150 7650 4350
Wire Wire Line
	7300 4250 7300 5150
Wire Wire Line
	7600 2400 7600 1600
Wire Wire Line
	7250 2400 7250 1500
Wire Wire Line
	950  7350 5800 7350
Wire Wire Line
	5800 7350 5800 5450
Wire Wire Line
	5800 5450 7200 5450
Connection ~ 7200 5450
Text Notes 7550 2850 0    50   ~ 0
Rated for 200mA
Text Notes 7550 5600 0    50   ~ 0
Rated for 200mA
Text HLabel 8400 1800 0    50   Input ~ 0
MOTOR_CTRL_1A
Text HLabel 8400 1900 0    50   Input ~ 0
MOTOR_CTRL_1B
Text HLabel 8400 2000 0    50   Input ~ 0
MOTOR_CTRL_2A
Text HLabel 8400 2100 0    50   Input ~ 0
MOTOR_CTRL_2B
Text HLabel 8400 4550 0    50   Input ~ 0
MOTOR_CTRL_3A
Text HLabel 8400 4650 0    50   Input ~ 0
MOTOR_CTRL_3B
Text HLabel 8400 4750 0    50   Input ~ 0
MOTOR_CTRL_4A
Text HLabel 8400 4850 0    50   Input ~ 0
MOTOR_CTRL_4B
$Comp
L Device:CP C?
U 1 1 5E54E959
P 10550 1050
F 0 "C?" H 10668 1096 50  0000 L CNN
F 1 "10uCP" H 10668 1005 50  0000 L CNN
F 2 "" H 10588 900 50  0001 C CNN
F 3 "~" H 10550 1050 50  0001 C CNN
	1    10550 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 800  10550 800 
Wire Wire Line
	10550 800  10550 900 
$Comp
L Device:CP C?
U 1 1 5E54FC20
P 10550 3750
F 0 "C?" H 10668 3796 50  0000 L CNN
F 1 "10uCP" H 10668 3705 50  0000 L CNN
F 2 "" H 10588 3600 50  0001 C CNN
F 3 "~" H 10550 3750 50  0001 C CNN
	1    10550 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 3750 9300 3400
Wire Wire Line
	9300 3400 10550 3400
Wire Wire Line
	10550 3400 10550 3600
Wire Wire Line
	10550 3900 10550 4150
Wire Wire Line
	10550 5450 9000 5450
Connection ~ 9000 5450
Wire Wire Line
	9000 2700 10550 2700
Wire Wire Line
	10550 2700 10550 1450
Connection ~ 9000 2700
Connection ~ 7250 2700
Wire Wire Line
	7250 2700 7200 2700
Wire Wire Line
	7600 2700 9000 2700
Wire Wire Line
	7250 1500 8400 1500
Wire Wire Line
	7600 1600 8400 1600
Connection ~ 7300 5450
Wire Wire Line
	7300 5450 7650 5450
Wire Wire Line
	7650 5450 9000 5450
Wire Wire Line
	7300 4250 8400 4250
Wire Wire Line
	7650 4350 8400 4350
Text Notes 10300 1300 0    50   ~ 0
Low-ESR (ceramic)\nbypass capacitor
Text Notes 10400 4050 0    50   ~ 0
Low-ESR (ceramic)\nbypass capacitor
$Comp
L Device:C C?
U 1 1 5E554940
P 7700 900
F 0 "C?" H 7815 946 50  0000 L CNN
F 1 "0.01uC" H 7815 855 50  0000 L CNN
F 2 "" H 7738 750 50  0001 C CNN
F 3 "~" H 7700 900 50  0001 C CNN
	1    7700 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 800  8500 800 
Wire Wire Line
	8500 800  8500 600 
Wire Wire Line
	8500 600  7700 600 
Wire Wire Line
	7700 600  7700 750 
Connection ~ 9300 800 
Wire Wire Line
	7700 1050 7700 1400
Wire Wire Line
	7700 1400 8400 1400
$Comp
L Device:C C?
U 1 1 5E556072
P 7750 3700
F 0 "C?" H 7865 3746 50  0000 L CNN
F 1 "0.01uC" H 7865 3655 50  0000 L CNN
F 2 "" H 7788 3550 50  0001 C CNN
F 3 "~" H 7750 3700 50  0001 C CNN
	1    7750 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 3400 7750 3550
Connection ~ 9300 3400
Wire Wire Line
	7750 3850 7750 4150
Wire Wire Line
	7750 4150 8400 4150
Text Notes 7350 750  0    50   ~ 0
Low-ESR ceramic\ncapacitor rated for 16 V.
Text Notes 7500 3550 0    50   ~ 0
Low-ESR ceramic\ncapacitor rated for 16 V.
$Comp
L Device:C C?
U 1 1 5E5579B2
P 9650 1050
F 0 "C?" H 9765 1096 50  0000 L CNN
F 1 "2.2uC" H 9765 1005 50  0000 L CNN
F 2 "" H 9688 900 50  0001 C CNN
F 3 "~" H 9650 1050 50  0001 C CNN
	1    9650 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 1000 9200 650 
Wire Wire Line
	9200 650  9650 650 
Wire Wire Line
	9650 650  9650 900 
Wire Wire Line
	9650 1200 9650 1450
Wire Wire Line
	9650 1450 10550 1450
Connection ~ 10550 1450
Wire Wire Line
	10550 1450 10550 1200
$Comp
L Device:C C?
U 1 1 5E5593EC
P 9650 3750
F 0 "C?" H 9765 3796 50  0000 L CNN
F 1 "2.2uC" H 9765 3705 50  0000 L CNN
F 2 "" H 9688 3600 50  0001 C CNN
F 3 "~" H 9650 3750 50  0001 C CNN
	1    9650 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 3750 9200 3250
Wire Wire Line
	9200 3250 9650 3250
Wire Wire Line
	9650 3250 9650 3600
Wire Wire Line
	9650 3900 9650 4150
Wire Wire Line
	9650 4150 10550 4150
Connection ~ 10550 4150
Wire Wire Line
	10550 4150 10550 5450
Text Notes 9600 900  0    50   ~ 0
Ceramic capacitor\nrated 6.3 V.
Text Notes 9550 3600 0    50   ~ 0
Ceramic capacitor\nrated 6.3 V.
Text HLabel 9600 1600 2    50   Output ~ 0
MOTOR_FAULT_12
Text HLabel 9600 4350 2    50   Output ~ 0
MOTOR_FAULT_34
Text HLabel 8400 1300 0    50   Input ~ 0
MOTOR_SLEEP_12
Text HLabel 8400 4050 0    50   Input ~ 0
MOTOR_SLEEP_34
Wire Wire Line
	9300 1000 9300 800 
Wire Wire Line
	9300 3400 9000 3400
Wire Wire Line
	8500 800  8500 1100
Wire Wire Line
	8500 1100 6700 1100
Wire Wire Line
	6700 1100 6700 3050
Wire Wire Line
	6700 3050 9000 3050
Wire Wire Line
	9000 3050 9000 3400
Connection ~ 8500 800 
Connection ~ 9000 3400
Wire Wire Line
	9000 3400 7750 3400
$Comp
L Regulator_Switching:TPS562200 U?
U 1 1 5E567A0E
P 3000 1650
F 0 "U?" H 3000 2017 50  0000 C CNN
F 1 "TPS562200" H 3000 1926 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 3050 1400 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/tps563200.pdf" H 3000 1650 50  0001 C CNN
	1    3000 1650
	1    0    0    -1  
$EndComp
$EndSCHEMATC
