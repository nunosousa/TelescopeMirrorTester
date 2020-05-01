EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel -3800 10000 0    50   Output ~ 0
MOTOR_CTRL_1A
Text HLabel -3800 10100 0    50   Output ~ 0
MOTOR_CTRL_1B
Text HLabel -3800 10300 0    50   Output ~ 0
MOTOR_CTRL_2A
Text HLabel -3800 10200 0    50   Output ~ 0
MOTOR_CTRL_2B
Text HLabel -3800 9900 0    50   Input ~ 0
MOTOR_FAULT_12
Text HLabel -3800 9800 0    50   Output ~ 0
MOTOR_SLEEP_12
Text HLabel -2900 12300 3    50   Input ~ 0
GND
$Comp
L Device:C C15
U 1 1 5E5846F6
P 3750 1350
F 0 "C15" H 3865 1396 50  0000 L CNN
F 1 "1uC" H 3865 1305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3788 1200 50  0001 C CNN
F 3 "~" H 3750 1350 50  0001 C CNN
F 4 "CC0805MKX7R7BB105" H 3750 1350 50  0001 C CNN "Manufacturer Part Number"
	1    3750 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 5E58564D
P 1100 1350
F 0 "C12" H 1215 1396 50  0000 L CNN
F 1 "10uC" H 1215 1305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1138 1200 50  0001 C CNN
F 3 "~" H 1100 1350 50  0001 C CNN
F 4 "CC0805MRX5R6BB106" H 1100 1350 50  0001 C CNN "Manufacturer Part Number"
	1    1100 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C14
U 1 1 5E586DB7
P 1600 1350
F 0 "C14" H 1715 1396 50  0000 L CNN
F 1 "0.1uC" H 1715 1305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1638 1200 50  0001 C CNN
F 3 "~" H 1600 1350 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 1600 1350 50  0001 C CNN "Manufacturer Part Number"
	1    1600 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 5E588280
P 2150 1350
F 0 "C13" H 2265 1396 50  0000 L CNN
F 1 "0.1uC" H 2265 1305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2188 1200 50  0001 C CNN
F 3 "~" H 2150 1350 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 2150 1350 50  0001 C CNN "Manufacturer Part Number"
	1    2150 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C16
U 1 1 5E58C2F2
P 2700 1350
F 0 "C16" H 2815 1396 50  0000 L CNN
F 1 "0.1uC" H 2815 1305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2738 1200 50  0001 C CNN
F 3 "~" H 2700 1350 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 2700 1350 50  0001 C CNN "Manufacturer Part Number"
	1    2700 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C17
U 1 1 5E58C960
P 3250 1350
F 0 "C17" H 3365 1396 50  0000 L CNN
F 1 "10uC" H 3365 1305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3288 1200 50  0001 C CNN
F 3 "~" H 3250 1350 50  0001 C CNN
F 4 "CC0805MRX5R6BB106" H 3250 1350 50  0001 C CNN "Manufacturer Part Number"
	1    3250 1350
	1    0    0    -1  
$EndComp
Text HLabel -3800 9200 0    50   Input ~ 0
POS_MISO
Text HLabel -3800 9400 0    50   Output ~ 0
POS_MOSI
Text HLabel -3800 9500 0    50   Output ~ 0
POS_SCLK
Text HLabel -3800 9000 0    50   Output ~ 0
~POS1_NCS
Text HLabel -3800 9300 0    50   Input ~ 0
POS_MOTION
Text HLabel -1800 9100 2    50   Output ~ 0
~POS1_NRESET
Text HLabel -3800 10400 0    50   Input ~ 0
END_STOP_X+
Text HLabel -3800 10600 0    50   Input ~ 0
END_STOP_Y+
Text HLabel -3800 9600 0    50   BiDi ~ 0
LASER_SDA
Text HLabel -3800 9700 0    50   Output ~ 0
LASER_SCL
$Comp
L Device:R R25
U 1 1 5E5EDE05
P 9500 3400
F 0 "R25" H 9570 3446 50  0000 L CNN
F 1 "1kR" H 9570 3355 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 9430 3400 50  0001 C CNN
F 3 "~" H 9500 3400 50  0001 C CNN
F 4 "" H 9500 3400 50  0001 C CNN "Manufacturer Part Number"
	1    9500 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R28
U 1 1 5E5F34E6
P 9100 3400
F 0 "R28" H 9170 3446 50  0000 L CNN
F 1 "10kR" H 9170 3355 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 9030 3400 50  0001 C CNN
F 3 "~" H 9100 3400 50  0001 C CNN
F 4 "RC0805FR-0710KL" H 9100 3400 50  0001 C CNN "Manufacturer Part Number"
	1    9100 3400
	1    0    0    -1  
$EndComp
Text HLabel -3800 11300 0    50   BiDi ~ 0
USB_D+
Text HLabel -3800 11200 0    50   BiDi ~ 0
USB_D-
Text HLabel -3800 11100 0    50   Input ~ 0
OC_ALOADS
Text HLabel -3800 11000 0    50   Input ~ 0
OC_DLOADS
Text HLabel -1800 8800 2    50   Output ~ 0
~PS_ALOADS
Text HLabel -1800 8900 2    50   Output ~ 0
~PS_DLOADS
$Comp
L Device:L L2
U 1 1 5E58F693
P 2400 900
F 0 "L2" H 2500 800 50  0000 C CNN
F 1 "L" H 2500 900 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2400 900 50  0001 C CNN
F 3 "~" H 2400 900 50  0001 C CNN
F 4 "BLM21SP471SH1D" H 2400 900 50  0001 C CNN "Manufacturer Part Number"
	1    2400 900 
	0    -1   -1   0   
$EndComp
$Comp
L Device:Crystal_GND3 Y1
U 1 1 5E64392E
P 1400 3150
F 0 "Y1" H 1400 3418 50  0000 C CNN
F 1 "Crystal_GND3" H 1400 3327 50  0000 C CNN
F 2 "Crystal:Crystal_SMD_MicroCrystal_MS1V-T1K" H 1400 3150 50  0001 C CNN
F 3 "https://www.microcrystal.com/fileadmin/Media/Products/32kHz/Datasheet/MS1V-T1K.pdf" H 1400 3150 50  0001 C CNN
F 4 "MS1V-T1K-32.768KHZ-7PF-20PPM-TA-QC-AU" H 1400 3150 50  0001 C CNN "Manufacturer Part Number"
	1    1400 3150
	-1   0    0    -1  
$EndComp
$Comp
L Device:C C24
U 1 1 5E644FBE
P 1100 3400
F 0 "C24" H 750 3450 50  0000 L CNN
F 1 "6.8pC" H 750 3350 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1138 3250 50  0001 C CNN
F 3 "~" H 1100 3400 50  0001 C CNN
F 4 "C0805C689J5GACTU" H 1100 3400 50  0001 C CNN "Manufacturer Part Number"
	1    1100 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C25
U 1 1 5E645661
P 1700 3400
F 0 "C25" H 1815 3446 50  0000 L CNN
F 1 "6.8pC" H 1815 3355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1738 3250 50  0001 C CNN
F 3 "~" H 1700 3400 50  0001 C CNN
F 4 "C0805C689J5GACTU" H 1700 3400 50  0001 C CNN "Manufacturer Part Number"
	1    1700 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 3150 1100 3150
Wire Wire Line
	1100 3150 1100 3250
Wire Wire Line
	1700 3250 1700 3150
Wire Wire Line
	1700 3150 1550 3150
Wire Wire Line
	1700 3650 1700 3550
Wire Wire Line
	1700 3650 1400 3650
Wire Wire Line
	1100 3650 1100 3550
Wire Wire Line
	1400 3350 1400 3650
Connection ~ 1400 3650
Text HLabel -3800 10500 0    50   Input ~ 0
END_STOP_X-
Text HLabel -3800 10700 0    50   Input ~ 0
END_STOP_Y-
$Comp
L Connector:Conn_ARM_JTAG_SWD_10 J6
U 1 1 5EA3EDDE
P 10300 4000
F 0 "J6" H 11050 3400 50  0000 R CNN
F 1 "Conn_ARM_JTAG_SWD_10" H 11400 3250 50  0000 R CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_2x05_P1.27mm_Vertical" H 10300 4000 50  0001 C CNN
F 3 "http://infocenter.arm.com/help/topic/com.arm.doc.ddi0314h/DDI0314H_coresight_components_trm.pdf" V 9950 2750 50  0001 C CNN
F 4 "3220-10-0100-00" H 10300 4000 50  0001 C CNN "Manufacturer Part Number"
	1    10300 4000
	-1   0    0    -1  
$EndComp
NoConn ~ 10400 4600
NoConn ~ 9800 4200
NoConn ~ 9800 4100
Text HLabel 10300 4600 3    50   Input ~ 0
GND
Text HLabel -3800 9100 0    50   Output ~ 0
~POS2_NCS
Text HLabel -1800 9000 2    50   Output ~ 0
~POS2_NRESET
Wire Wire Line
	1100 3650 1300 3650
Text HLabel 10300 3400 1    50   Input ~ 0
V3_3
Wire Wire Line
	9500 3550 9500 3900
Text HLabel 9500 3250 1    50   Input ~ 0
V3_3
Connection ~ 9500 3900
Wire Wire Line
	9500 3900 9800 3900
Wire Wire Line
	9100 3700 9100 3550
Text HLabel 9100 3250 1    50   Input ~ 0
V3_3
Wire Wire Line
	8550 3900 9500 3900
Wire Wire Line
	8550 4000 9800 4000
Connection ~ 9100 3700
Wire Wire Line
	9100 3700 9800 3700
Wire Wire Line
	8550 3700 9100 3700
Text HLabel 3750 1500 3    50   Input ~ 0
GND
Text Label 3750 850  3    50   ~ 0
VDDCORE
Text Label -2600 8150 3    50   ~ 0
VDDCORE
Text Label 1600 1200 1    50   ~ 0
VDDIN
Text HLabel 1600 1500 3    50   Input ~ 0
GND
Text HLabel 950  900  0    50   Input ~ 0
V3_3
Text Label -2900 8250 3    50   ~ 0
VDDIN
$Comp
L Device:Net-Tie_2 NT1
U 1 1 5EA796ED
P 1300 900
F 0 "NT1" H 1300 1081 50  0000 C CNN
F 1 "Net-Tie_2" H 1300 990 50  0000 C CNN
F 2 "NetTie:NetTie-2_SMD_Pad0.5mm" H 1300 900 50  0001 C CNN
F 3 "~" H 1300 900 50  0001 C CNN
	1    1300 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 900  1600 900 
Wire Wire Line
	1600 900  1600 1200
Text HLabel 1100 1500 3    50   Input ~ 0
GND
Wire Wire Line
	1200 900  1100 900 
Wire Wire Line
	1100 1200 1100 900 
Connection ~ 1100 900 
Wire Wire Line
	1100 900  950  900 
Text HLabel 2150 1500 3    50   Input ~ 0
GND
Wire Wire Line
	2150 1200 2150 900 
Wire Wire Line
	2150 900  1600 900 
Connection ~ 1600 900 
Text Label 2150 1200 1    50   ~ 0
VDDIO
Text Label -3000 8250 3    50   ~ 0
VDDIO
Connection ~ 2150 900 
Wire Wire Line
	2700 1200 2700 900 
Wire Wire Line
	2700 900  3250 900 
Wire Wire Line
	3250 900  3250 1200
Connection ~ 2700 900 
Text HLabel 2700 1900 3    50   Input ~ 0
GND
Text Label 2850 900  0    50   ~ 0
VDDANA
Text Label -2700 8200 3    50   ~ 0
VDDANA
$Comp
L Device:Net-Tie_2 NT6
U 1 1 5EA8474B
P 2700 1800
F 0 "NT6" H 2700 1981 50  0000 C CNN
F 1 "Net-Tie_2" H 2700 1890 50  0000 C CNN
F 2 "NetTie:NetTie-2_SMD_Pad0.5mm" H 2700 1800 50  0001 C CNN
F 3 "~" H 2700 1800 50  0001 C CNN
	1    2700 1800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2700 1700 2700 1550
Wire Wire Line
	2700 1550 3250 1550
Text Label 2850 1550 0    50   ~ 0
GNDANA
Text Label -2700 12600 1    50   ~ 0
GNDANA
Wire Wire Line
	3250 1550 3250 1500
Wire Wire Line
	2700 1500 2700 1550
Connection ~ 2700 1550
Text Label 8550 3700 0    50   ~ 0
~RESET
Text Label -4050 11900 0    50   ~ 0
~RESET
Text Label 8550 3900 0    50   ~ 0
SWCLK
Text Label -4050 11600 0    50   ~ 0
SWCLK
Text Label 8550 4000 0    50   ~ 0
SWDIO
Text Label -4050 11700 0    50   ~ 0
SWDIO
Text Label 2000 2700 2    50   ~ 0
XIN32
Text Label 2000 2550 2    50   ~ 0
XOUT32
Wire Wire Line
	1700 3150 1700 2700
Wire Wire Line
	1700 2700 2000 2700
Connection ~ 1700 3150
Wire Wire Line
	1100 3150 1100 2550
Wire Wire Line
	1100 2550 2000 2550
Connection ~ 1100 3150
Connection ~ 1300 3650
Wire Wire Line
	1300 3650 1400 3650
Text Label -4100 8800 0    50   ~ 0
XIN32
Text Label -4100 8900 0    50   ~ 0
XOUT32
Wire Wire Line
	3750 1200 3750 850 
Wire Wire Line
	2150 900  2250 900 
Wire Wire Line
	2550 900  2700 900 
Wire Wire Line
	-4050 11900 -3800 11900
Wire Wire Line
	-3800 11700 -4050 11700
Wire Wire Line
	-3800 11600 -4050 11600
Wire Wire Line
	-3800 8900 -4100 8900
Wire Wire Line
	-3800 8800 -4100 8800
Wire Wire Line
	-2900 8500 -2900 8250
Wire Wire Line
	-3000 8250 -3000 8500
Wire Wire Line
	-2700 8500 -2700 8200
Wire Wire Line
	-2600 8500 -2600 8150
Wire Wire Line
	-2700 12300 -2700 12600
Text HLabel -1800 9500 2    50   Output ~ 0
MOTOR_CTRL_3A
Text HLabel -1800 9400 2    50   Output ~ 0
MOTOR_CTRL_3B
Text HLabel -3800 11500 0    50   Output ~ 0
MOTOR_CTRL_4A
Text HLabel -3800 11400 0    50   Output ~ 0
MOTOR_CTRL_4B
Text HLabel -1800 9200 2    50   Input ~ 0
MOTOR_FAULT_34
Text HLabel -1800 9300 2    50   Output ~ 0
MOTOR_SLEEP_34
Text HLabel -3800 10900 0    50   Input ~ 0
END_STOP_Z-
Text HLabel -3800 10800 0    50   Input ~ 0
END_STOP_Z+
Wire Wire Line
	1300 3650 1300 4000
Text Label 1300 4000 1    50   ~ 0
GNDANA
$Comp
L MCU_Microchip_SAMD:ATSAMD51J18A-A U15
U 1 1 5EAA3C2C
P 6050 3600
F 0 "U15" H 6050 1711 50  0000 C CNN
F 1 "ATSAMD51J18A-A" H 6050 1620 50  0000 C CNN
F 2 "Package_QFP:TQFP-64_10x10mm_P0.5mm" H 6050 3600 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/60001507E.pdf" H 6050 3600 50  0001 C CNN
F 4 "ATSAMD51J18A-AUT" H 6050 3600 50  0001 C CNN "Manufacturer Part Number"
	1    6050 3600
	1    0    0    -1  
$EndComp
$EndSCHEMATC
