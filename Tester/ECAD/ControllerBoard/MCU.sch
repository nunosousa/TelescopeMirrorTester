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
Text HLabel 5350 3000 0    50   Output ~ 0
MOTOR_CTRL_1A
Text HLabel 5350 3100 0    50   Output ~ 0
MOTOR_CTRL_1B
Text HLabel 5350 3300 0    50   Output ~ 0
MOTOR_CTRL_2A
Text HLabel 5350 3200 0    50   Output ~ 0
MOTOR_CTRL_2B
Text HLabel 5350 3500 0    50   Input ~ 0
MOTOR_FAULT_12
Text HLabel 5350 3400 0    50   Output ~ 0
MOTOR_SLEEP_12
$Comp
L Device:C C12
U 1 1 5E58564D
P 1250 3400
F 0 "C12" H 1365 3446 50  0000 L CNN
F 1 "10uC" H 1365 3355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1288 3250 50  0001 C CNN
F 3 "~" H 1250 3400 50  0001 C CNN
F 4 "CC0805MRX5R6BB106" H 1250 3400 50  0001 C CNN "Manufacturer Part Number"
	1    1250 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 5E588280
P 2400 1150
F 0 "C13" H 2515 1196 50  0000 L CNN
F 1 "0.1uC" H 2515 1105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2438 1000 50  0001 C CNN
F 3 "~" H 2400 1150 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 2400 1150 50  0001 C CNN "Manufacturer Part Number"
	1    2400 1150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C16
U 1 1 5E58C2F2
P 900 2200
F 0 "C16" H 1015 2246 50  0000 L CNN
F 1 "0.1uC" H 1015 2155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 938 2050 50  0001 C CNN
F 3 "~" H 900 2200 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 900 2200 50  0001 C CNN "Manufacturer Part Number"
	1    900  2200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C17
U 1 1 5E58C960
P 2850 3400
F 0 "C17" H 2965 3446 50  0000 L CNN
F 1 "10uC" H 2965 3355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2888 3250 50  0001 C CNN
F 3 "~" H 2850 3400 50  0001 C CNN
F 4 "CC0805MRX5R6BB106" H 2850 3400 50  0001 C CNN "Manufacturer Part Number"
	1    2850 3400
	1    0    0    -1  
$EndComp
Text HLabel 5350 2800 0    50   Input ~ 0
POS_MISO
Text HLabel 5350 2600 0    50   Output ~ 0
POS_MOSI
Text HLabel 5350 2700 0    50   Output ~ 0
POS_SCLK
Text HLabel 6750 2900 2    50   Output ~ 0
~POS1_NCS
Text HLabel 5350 2900 0    50   Input ~ 0
POS_MOTION
Text HLabel 6750 3200 2    50   Output ~ 0
~POS1_NRESET
Text HLabel 5350 3800 0    50   Input ~ 0
END_STOP_X+
Text HLabel 5350 4000 0    50   Input ~ 0
END_STOP_Y+
Text HLabel 6750 4400 2    50   BiDi ~ 0
LASER_SDA
Text HLabel 6750 4300 2    50   Output ~ 0
LASER_SCL
$Comp
L Device:R R25
U 1 1 5E5EDE05
P 9800 2050
F 0 "R25" H 9870 2096 50  0000 L CNN
F 1 "1kR" H 9870 2005 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 9730 2050 50  0001 C CNN
F 3 "~" H 9800 2050 50  0001 C CNN
F 4 "" H 9800 2050 50  0001 C CNN "Manufacturer Part Number"
	1    9800 2050
	1    0    0    -1  
$EndComp
Text HLabel 5350 4700 0    50   BiDi ~ 0
USB_D+
Text HLabel 5350 4600 0    50   BiDi ~ 0
USB_D-
Text HLabel 6750 4100 2    50   Input ~ 0
OC_ALOADS
Text HLabel 5350 4800 0    50   Input ~ 0
OC_DLOADS
Text HLabel 5350 2500 0    50   Output ~ 0
~PS_ALOADS
Text HLabel 5350 2400 0    50   Output ~ 0
~PS_DLOADS
$Comp
L Device:C C24
U 1 1 5E644FBE
P 1600 6200
F 0 "C24" H 1250 6250 50  0000 L CNN
F 1 "6.8pC" H 1250 6150 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1638 6050 50  0001 C CNN
F 3 "~" H 1600 6200 50  0001 C CNN
F 4 "C0805C689J5GACTU" H 1600 6200 50  0001 C CNN "Manufacturer Part Number"
	1    1600 6200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C25
U 1 1 5E645661
P 2650 6200
F 0 "C25" H 2765 6246 50  0000 L CNN
F 1 "6.8pC" H 2765 6155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2688 6050 50  0001 C CNN
F 3 "~" H 2650 6200 50  0001 C CNN
F 4 "C0805C689J5GACTU" H 2650 6200 50  0001 C CNN "Manufacturer Part Number"
	1    2650 6200
	1    0    0    -1  
$EndComp
Text HLabel 5350 3900 0    50   Input ~ 0
END_STOP_X-
Text HLabel 5350 4100 0    50   Input ~ 0
END_STOP_Y-
$Comp
L Connector:Conn_ARM_JTAG_SWD_10 J6
U 1 1 5EA3EDDE
P 10600 2650
F 0 "J6" H 11350 2050 50  0000 R CNN
F 1 "Conn_ARM_JTAG_SWD_10" H 11700 1900 50  0000 R CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_2x05_P1.27mm_Vertical" H 10600 2650 50  0001 C CNN
F 3 "http://infocenter.arm.com/help/topic/com.arm.doc.ddi0314h/DDI0314H_coresight_components_trm.pdf" V 10250 1400 50  0001 C CNN
F 4 "3220-10-0100-00" H 10600 2650 50  0001 C CNN "Manufacturer Part Number"
	1    10600 2650
	-1   0    0    -1  
$EndComp
NoConn ~ 10700 3250
NoConn ~ 10100 2850
NoConn ~ 10100 2750
Text HLabel 10600 3250 3    50   Input ~ 0
GND
Text HLabel 6750 3000 2    50   Output ~ 0
~POS2_NCS
Text HLabel 6750 3100 2    50   Output ~ 0
~POS2_NRESET
Text HLabel 10600 2050 1    50   Input ~ 0
V3_3
Wire Wire Line
	9800 2200 9800 2550
Text HLabel 9800 1900 1    50   Input ~ 0
V3_3
Connection ~ 9800 2550
Wire Wire Line
	9800 2550 10100 2550
Wire Wire Line
	8850 2550 9800 2550
Wire Wire Line
	8850 2650 10100 2650
Text HLabel 2300 3250 0    50   Input ~ 0
V3_3
Text HLabel 1250 3550 3    50   Input ~ 0
GND
Text HLabel 2400 1300 3    50   Input ~ 0
GND
Text Label 6050 1450 3    50   ~ 0
VDDIO_1
Text Label 2900 1750 3    50   ~ 0
VDDANA
Text Label 8850 2350 0    50   ~ 0
~RESET
Text Label 8850 2550 0    50   ~ 0
SWCLK
Text Label 5100 4900 0    50   ~ 0
SWCLK
Text Label 8850 2650 0    50   ~ 0
SWDIO
Text Label 5100 5000 0    50   ~ 0
SWDIO
Text Label 2550 5950 2    50   ~ 0
XIN32
Text Label 1900 5950 2    50   ~ 0
XOUT32
Text Label 5050 2200 0    50   ~ 0
XIN32
Text Label 5050 2300 0    50   ~ 0
XOUT32
Wire Wire Line
	5350 5000 5100 5000
Wire Wire Line
	5350 4900 5100 4900
Wire Wire Line
	5350 2300 5050 2300
Wire Wire Line
	5350 2200 5050 2200
Text HLabel 6750 3400 2    50   Output ~ 0
MOTOR_CTRL_3A
Text HLabel 6750 3300 2    50   Output ~ 0
MOTOR_CTRL_3B
Text HLabel 6750 3500 2    50   Output ~ 0
MOTOR_CTRL_4A
Text HLabel 6750 3600 2    50   Output ~ 0
MOTOR_CTRL_4B
Text HLabel 6750 3700 2    50   Input ~ 0
MOTOR_FAULT_34
Text HLabel 6750 3800 2    50   Output ~ 0
MOTOR_SLEEP_34
Text HLabel 5350 4300 0    50   Input ~ 0
END_STOP_Z-
Text HLabel 5350 4200 0    50   Input ~ 0
END_STOP_Z+
Text Label 2300 6450 2    50   ~ 0
GNDANA
$Comp
L MCU_Microchip_SAMD:ATSAMD51J18A-A U15
U 1 1 5EAA3C2C
P 6050 3600
F 0 "U15" H 6450 1800 50  0000 C CNN
F 1 "ATSAMD51J18A-A" H 6650 1700 50  0000 C CNN
F 2 "Package_QFP:TQFP-64_10x10mm_P0.5mm" H 6050 3600 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/60001507E.pdf" H 6050 3600 50  0001 C CNN
F 4 "ATSAMD51J18A-AUT" H 6050 3600 50  0001 C CNN "Manufacturer Part Number"
	1    6050 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5EACBF43
P 10600 4650
AR Path="/5EA3CC42/5EACBF43" Ref="C?"  Part="1" 
AR Path="/5E5070AC/5EACBF43" Ref="C40"  Part="1" 
F 0 "C40" H 10715 4696 50  0000 L CNN
F 1 "4.7uC" H 10715 4605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 10638 4500 50  0001 C CNN
F 3 "~" H 10600 4650 50  0001 C CNN
F 4 "C0805C475K9PACTU" H 10600 4650 50  0001 C CNN "Manufacturer Part Number"
	1    10600 4650
	-1   0    0    -1  
$EndComp
Text HLabel 10600 4800 3    50   Input ~ 0
GND
$Comp
L Device:R R30
U 1 1 5EACE22E
P 10600 4200
F 0 "R30" H 10670 4246 50  0000 L CNN
F 1 "100kR" H 10670 4155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 10530 4200 50  0001 C CNN
F 3 "~" H 10600 4200 50  0001 C CNN
	1    10600 4200
	-1   0    0    -1  
$EndComp
Text HLabel 10600 4050 1    50   Input ~ 0
V3_3
Wire Wire Line
	10600 4350 10600 4450
$Comp
L Device:C C41
U 1 1 5EADCE78
P 1700 4900
F 0 "C41" H 1815 4946 50  0000 L CNN
F 1 "5pC" H 1815 4855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1738 4750 50  0001 C CNN
F 3 "~" H 1700 4900 50  0001 C CNN
F 4 "08055A5R0CAT2A" H 1700 4900 50  0001 C CNN "Manufacturer Part Number"
	1    1700 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C42
U 1 1 5EADD5A5
P 2600 4900
F 0 "C42" H 2715 4946 50  0000 L CNN
F 1 "5pC" H 2715 4855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2638 4750 50  0001 C CNN
F 3 "~" H 2600 4900 50  0001 C CNN
F 4 "08055A5R0CAT2A" H 2600 4900 50  0001 C CNN "Manufacturer Part Number"
	1    2600 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 4750 1700 4700
Wire Wire Line
	1700 4700 2000 4700
Wire Wire Line
	2300 4700 2600 4700
Wire Wire Line
	2600 4700 2600 4750
Text Label 1750 4700 0    50   ~ 0
XOUT
Text Label 2400 4700 0    50   ~ 0
XIN
Wire Wire Line
	2650 5950 2650 6050
Wire Wire Line
	1600 6050 1600 5950
Wire Wire Line
	1600 6450 1600 6350
Wire Wire Line
	2650 6450 2650 6350
Wire Wire Line
	1700 5050 1700 5150
Wire Wire Line
	2600 5150 2600 5050
Wire Wire Line
	2150 4900 2150 5150
Connection ~ 2150 5150
Wire Wire Line
	2150 5150 2600 5150
$Comp
L Device:Crystal_GND24 Y2
U 1 1 5EADC4C3
P 2150 4700
F 0 "Y2" H 2250 4900 50  0000 L CNN
F 1 "12MHz" H 2250 5000 50  0000 L CNN
F 2 "Crystal:Crystal_SMD_3225-4Pin_3.2x2.5mm_HandSoldering" H 2150 4700 50  0001 C CNN
F 3 "https://www.iqdfrequencyproducts.com/products/pn/LFXTAL071742Reel.pdf" H 2150 4700 50  0001 C CNN
F 4 "LFXTAL071742REEL" H 2150 4700 50  0001 C CNN "Manufacturer Part Number"
	1    2150 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 4500 2150 4450
Wire Wire Line
	2150 4450 1500 4450
Wire Wire Line
	1500 4450 1500 5150
Wire Wire Line
	1500 5150 1700 5150
Connection ~ 1700 5150
Text Label 2550 5150 2    50   ~ 0
GNDANA
Wire Wire Line
	1700 5150 2150 5150
$Comp
L Device:Crystal Y1
U 1 1 5EAF4BB1
P 2100 5950
F 0 "Y1" H 2100 6218 50  0000 C CNN
F 1 "32.768kHz" H 2100 6127 50  0000 C CNN
F 2 "Crystal:Crystal_SMD_2012-2Pin_2.0x1.2mm_HandSoldering" H 2100 5950 50  0001 C CNN
F 3 "https://support.epson.biz/td/api/doc_check.php?dl=brief_FC-12D&lang=en" H 2100 5950 50  0001 C CNN
F 4 "FC-12M 32.7680KA-X3" H 2100 5950 50  0001 C CNN "Manufacturer Part Number"
	1    2100 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 5950 1950 5950
Wire Wire Line
	2250 5950 2650 5950
Wire Wire Line
	1600 6450 2650 6450
Wire Wire Line
	8850 2350 10100 2350
Text Label 10250 4450 0    50   ~ 0
~RESET
Wire Wire Line
	10250 4450 10600 4450
Connection ~ 10600 4450
Wire Wire Line
	10600 4450 10600 4500
Text Label 6150 1450 3    50   ~ 0
VDDIO_2
Text Label 6250 1450 3    50   ~ 0
VDDIO_3
Wire Wire Line
	6250 1450 6250 1800
Wire Wire Line
	6150 1450 6150 1800
Wire Wire Line
	6050 1450 6050 1800
Text Label 900  1750 3    50   ~ 0
VDDIO_1
Text Label 1400 1750 3    50   ~ 0
VDDIO_2
Text Label 1900 1750 3    50   ~ 0
VDDIO_3
Text HLabel 900  2350 3    50   Input ~ 0
GND
$Comp
L Device:C C43
U 1 1 5EB14A14
P 1400 2200
F 0 "C43" H 1515 2246 50  0000 L CNN
F 1 "0.1uC" H 1515 2155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1438 2050 50  0001 C CNN
F 3 "~" H 1400 2200 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 1400 2200 50  0001 C CNN "Manufacturer Part Number"
	1    1400 2200
	1    0    0    -1  
$EndComp
Text HLabel 1400 2350 3    50   Input ~ 0
GND
$Comp
L Device:C C44
U 1 1 5EB166B6
P 1900 2200
F 0 "C44" H 2015 2246 50  0000 L CNN
F 1 "0.1uC" H 2015 2155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1938 2050 50  0001 C CNN
F 3 "~" H 1900 2200 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 1900 2200 50  0001 C CNN "Manufacturer Part Number"
	1    1900 2200
	1    0    0    -1  
$EndComp
Text HLabel 1900 2350 3    50   Input ~ 0
GND
Text HLabel 6150 5400 3    50   Input ~ 0
GND
Text HLabel 6050 5400 3    50   Input ~ 0
GND
Text Label 5100 5200 0    50   ~ 0
~RESET
Wire Wire Line
	5350 5200 5100 5200
$Comp
L Device:C C45
U 1 1 5EB1E444
P 2400 2200
F 0 "C45" H 2515 2246 50  0000 L CNN
F 1 "0.1uC" H 2515 2155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2438 2050 50  0001 C CNN
F 3 "~" H 2400 2200 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 2400 2200 50  0001 C CNN "Manufacturer Part Number"
	1    2400 2200
	1    0    0    -1  
$EndComp
Text HLabel 2400 2350 3    50   Input ~ 0
GND
Text Label 2400 1750 3    50   ~ 0
VDDIOB
$Comp
L Device:C C46
U 1 1 5EB24A6F
P 2900 2200
F 0 "C46" H 3015 2246 50  0000 L CNN
F 1 "0.1uC" H 3015 2155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2938 2050 50  0001 C CNN
F 3 "~" H 2900 2200 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 2900 2200 50  0001 C CNN "Manufacturer Part Number"
	1    2900 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 2050 2900 1750
Text HLabel 2850 3550 3    50   Input ~ 0
GND
Text HLabel 2900 2350 3    50   Input ~ 0
GND
Text Label 6450 1500 3    50   ~ 0
VDDANA
Wire Wire Line
	6450 1800 6450 1500
Text Label 2850 2900 3    50   ~ 0
VDDANA
$Comp
L Device:Ferrite_Bead FB2
U 1 1 5EB4257A
P 2450 3250
F 0 "FB2" V 2176 3250 50  0000 C CNN
F 1 "Ferrite_Bead" V 2267 3250 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2380 3250 50  0001 C CNN
F 3 "~" H 2450 3250 50  0001 C CNN
F 4 "BLM21SP471SH1D" H 2450 3250 50  0001 C CNN "Manufacturer Part Number"
	1    2450 3250
	0    1    1    0   
$EndComp
Wire Wire Line
	2600 3250 2850 3250
Wire Wire Line
	2850 2900 2850 3250
Connection ~ 2850 3250
Text HLabel 2900 1300 3    50   Input ~ 0
GND
Wire Wire Line
	2900 1000 2400 1000
$Comp
L Device:C C?
U 1 1 5EB4D769
P 2900 1150
AR Path="/5EA3CC42/5EB4D769" Ref="C?"  Part="1" 
AR Path="/5E5070AC/5EB4D769" Ref="C47"  Part="1" 
F 0 "C47" H 3015 1196 50  0000 L CNN
F 1 "4.7uC" H 3015 1105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2938 1000 50  0001 C CNN
F 3 "~" H 2900 1150 50  0001 C CNN
F 4 "C0805C475K9PACTU" H 2900 1150 50  0001 C CNN "Manufacturer Part Number"
	1    2900 1150
	1    0    0    -1  
$EndComp
Connection ~ 2400 1000
Wire Wire Line
	2400 1000 2150 1000
Text Label 2500 1000 0    50   ~ 0
VDDCORE
$Comp
L Device:L L1
U 1 1 5EB53C2E
P 2000 1000
F 0 "L1" V 2190 1000 50  0000 C CNN
F 1 "10uL" V 2099 1000 50  0000 C CNN
F 2 "Inductor_SMD:L_Taiyo-Yuden_MD-3030" H 2000 1000 50  0001 C CNN
F 3 "~" H 2000 1000 50  0001 C CNN
F 4 "LQH3NPN100MJRL" H 2000 1000 50  0001 C CNN "Manufacturer Part Number"
	1    2000 1000
	0    -1   -1   0   
$EndComp
Text Label 1650 1000 0    50   ~ 0
VSW
Wire Wire Line
	1650 1000 1850 1000
Text Label 5650 1600 3    50   ~ 0
VSW
Wire Wire Line
	5650 1600 5650 1800
Text Label 5750 1400 3    50   ~ 0
VDDCORE
Wire Wire Line
	5750 1400 5750 1800
Wire Wire Line
	5950 1800 5950 1500
Text Label 5950 1500 3    50   ~ 0
VDDIOB
Wire Notes Line
	3300 600  3300 2700
Wire Notes Line
	3300 2700 650  2700
Wire Notes Line
	650  2700 650  600 
Wire Notes Line
	650  600  3300 600 
Text Notes 700  850  0    50   ~ 0
Place close to\nrespective pin
Wire Wire Line
	1250 3250 1250 2950
Text Label 1250 2950 3    50   ~ 0
VDDIOB
Wire Wire Line
	2400 1700 1900 1700
Wire Wire Line
	900  1700 900  2050
Wire Wire Line
	2400 1700 2400 2050
Wire Wire Line
	1400 1700 1400 2050
Connection ~ 1400 1700
Wire Wire Line
	1400 1700 900  1700
Wire Wire Line
	1900 1700 1900 2050
Connection ~ 1900 1700
Wire Wire Line
	1900 1700 1400 1700
Wire Wire Line
	900  1700 900  1650
Connection ~ 900  1700
Text HLabel 900  1650 1    50   Input ~ 0
V3_3
Text Label 5100 3700 0    50   ~ 0
XOUT
Text Label 5100 3600 0    50   ~ 0
XIN
Wire Wire Line
	5100 3600 5350 3600
Wire Wire Line
	5350 3700 5100 3700
NoConn ~ 5350 4400
NoConn ~ 5350 4500
NoConn ~ 6750 4200
NoConn ~ 6750 4000
NoConn ~ 6750 3900
NoConn ~ 6750 2800
NoConn ~ 6750 2700
NoConn ~ 6750 2600
NoConn ~ 6750 2500
NoConn ~ 6750 2400
NoConn ~ 6750 2300
$Comp
L Device:Net-Tie_2 NT1
U 1 1 5EB51051
P 2900 5300
F 0 "NT1" H 2900 5481 50  0000 C CNN
F 1 "Net-Tie_2" H 2900 5390 50  0000 C CNN
F 2 "NetTie:NetTie-2_SMD_Pad0.5mm" H 2900 5300 50  0001 C CNN
F 3 "~" H 2900 5300 50  0001 C CNN
	1    2900 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:Net-Tie_2 NT2
U 1 1 5EB51A99
P 2950 6700
F 0 "NT2" H 2950 6881 50  0000 C CNN
F 1 "Net-Tie_2" H 2950 6790 50  0000 C CNN
F 2 "NetTie:NetTie-2_SMD_Pad0.5mm" H 2950 6700 50  0001 C CNN
F 3 "~" H 2950 6700 50  0001 C CNN
	1    2950 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 5300 2600 5300
Wire Wire Line
	2600 5300 2600 5150
Connection ~ 2600 5150
Wire Wire Line
	2850 6700 2650 6700
Wire Wire Line
	2650 6700 2650 6450
Connection ~ 2650 6450
Text HLabel 3000 5300 2    50   Input ~ 0
GND
Text HLabel 3050 6700 2    50   Input ~ 0
GND
$EndSCHEMATC
