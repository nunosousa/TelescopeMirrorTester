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
P 4500 2700
F 0 "C15" H 4615 2746 50  0000 L CNN
F 1 "1uC" H 4615 2655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4538 2550 50  0001 C CNN
F 3 "~" H 4500 2700 50  0001 C CNN
F 4 "CC0805MKX7R7BB105" H 4500 2700 50  0001 C CNN "Manufacturer Part Number"
	1    4500 2700
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
P 900 3300
F 0 "C16" H 1015 3346 50  0000 L CNN
F 1 "0.1uC" H 1015 3255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 938 3150 50  0001 C CNN
F 3 "~" H 900 3300 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 900 3300 50  0001 C CNN "Manufacturer Part Number"
	1    900  3300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C17
U 1 1 5E58C960
P 3650 2050
F 0 "C17" H 3765 2096 50  0000 L CNN
F 1 "10uC" H 3765 2005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3688 1900 50  0001 C CNN
F 3 "~" H 3650 2050 50  0001 C CNN
F 4 "CC0805MRX5R6BB106" H 3650 2050 50  0001 C CNN "Manufacturer Part Number"
	1    3650 2050
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
P 9750 4750
F 0 "R25" H 9820 4796 50  0000 L CNN
F 1 "1kR" H 9820 4705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 9680 4750 50  0001 C CNN
F 3 "~" H 9750 4750 50  0001 C CNN
F 4 "" H 9750 4750 50  0001 C CNN "Manufacturer Part Number"
	1    9750 4750
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
P 3350 1900
F 0 "L2" H 3450 1800 50  0000 C CNN
F 1 "L" H 3450 1900 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3350 1900 50  0001 C CNN
F 3 "~" H 3350 1900 50  0001 C CNN
F 4 "BLM21SP471SH1D" H 3350 1900 50  0001 C CNN "Manufacturer Part Number"
	1    3350 1900
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C24
U 1 1 5E644FBE
P 1150 7000
F 0 "C24" H 800 7050 50  0000 L CNN
F 1 "6.8pC" H 800 6950 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1188 6850 50  0001 C CNN
F 3 "~" H 1150 7000 50  0001 C CNN
F 4 "C0805C689J5GACTU" H 1150 7000 50  0001 C CNN "Manufacturer Part Number"
	1    1150 7000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C25
U 1 1 5E645661
P 2200 7000
F 0 "C25" H 2315 7046 50  0000 L CNN
F 1 "6.8pC" H 2315 6955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2238 6850 50  0001 C CNN
F 3 "~" H 2200 7000 50  0001 C CNN
F 4 "C0805C689J5GACTU" H 2200 7000 50  0001 C CNN "Manufacturer Part Number"
	1    2200 7000
	1    0    0    -1  
$EndComp
Text HLabel -3800 10500 0    50   Input ~ 0
END_STOP_X-
Text HLabel -3800 10700 0    50   Input ~ 0
END_STOP_Y-
$Comp
L Connector:Conn_ARM_JTAG_SWD_10 J6
U 1 1 5EA3EDDE
P 10550 5350
F 0 "J6" H 11300 4750 50  0000 R CNN
F 1 "Conn_ARM_JTAG_SWD_10" H 11650 4600 50  0000 R CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_2x05_P1.27mm_Vertical" H 10550 5350 50  0001 C CNN
F 3 "http://infocenter.arm.com/help/topic/com.arm.doc.ddi0314h/DDI0314H_coresight_components_trm.pdf" V 10200 4100 50  0001 C CNN
F 4 "3220-10-0100-00" H 10550 5350 50  0001 C CNN "Manufacturer Part Number"
	1    10550 5350
	-1   0    0    -1  
$EndComp
NoConn ~ 10650 5950
NoConn ~ 10050 5550
NoConn ~ 10050 5450
Text HLabel 10550 5950 3    50   Input ~ 0
GND
Text HLabel -3800 9100 0    50   Output ~ 0
~POS2_NCS
Text HLabel -1800 9000 2    50   Output ~ 0
~POS2_NRESET
Text HLabel 10550 4750 1    50   Input ~ 0
V3_3
Wire Wire Line
	9750 4900 9750 5250
Text HLabel 9750 4600 1    50   Input ~ 0
V3_3
Connection ~ 9750 5250
Wire Wire Line
	9750 5250 10050 5250
Wire Wire Line
	8800 5250 9750 5250
Wire Wire Line
	8800 5350 10050 5350
Text HLabel 4450 5150 3    50   Input ~ 0
GND
Text Label 4450 4500 3    50   ~ 0
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
Text Label 6050 1450 3    50   ~ 0
VDDIO_1
Text Label -3000 8250 3    50   ~ 0
VDDIO
Connection ~ 2150 900 
Text HLabel 2650 1500 3    50   Input ~ 0
GND
Text Label 2900 2850 3    50   ~ 0
VDDANA
Text Label -2700 8200 3    50   ~ 0
VDDANA
Text Label -2700 12600 1    50   ~ 0
GNDANA
Text Label 8800 5050 0    50   ~ 0
~RESET
Text Label -4050 11900 0    50   ~ 0
~RESET
Text Label 8800 5250 0    50   ~ 0
SWCLK
Text Label -4050 11600 0    50   ~ 0
SWCLK
Text Label 8800 5350 0    50   ~ 0
SWDIO
Text Label -4050 11700 0    50   ~ 0
SWDIO
Text Label 2100 6750 2    50   ~ 0
XIN32
Text Label 1450 6750 2    50   ~ 0
XOUT32
Text Label -4100 8800 0    50   ~ 0
XIN32
Text Label -4100 8900 0    50   ~ 0
XOUT32
Wire Wire Line
	4450 4850 4450 4500
Wire Wire Line
	2150 900  2250 900 
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
Text Label 1850 7250 2    50   ~ 0
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
P 7950 5750
AR Path="/5EA3CC42/5EACBF43" Ref="C?"  Part="1" 
AR Path="/5E5070AC/5EACBF43" Ref="C40"  Part="1" 
F 0 "C40" H 8065 5796 50  0000 L CNN
F 1 "4.7uC" H 8065 5705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7988 5600 50  0001 C CNN
F 3 "~" H 7950 5750 50  0001 C CNN
F 4 "C0805C475K9PACTU" H 7950 5750 50  0001 C CNN "Manufacturer Part Number"
	1    7950 5750
	1    0    0    -1  
$EndComp
Text HLabel 7950 5900 3    50   Input ~ 0
GND
$Comp
L Device:R R30
U 1 1 5EACE22E
P 7950 5300
F 0 "R30" H 8020 5346 50  0000 L CNN
F 1 "100kR" H 8020 5255 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7880 5300 50  0001 C CNN
F 3 "~" H 7950 5300 50  0001 C CNN
	1    7950 5300
	1    0    0    -1  
$EndComp
Text HLabel 7950 5150 1    50   Input ~ 0
V3_3
Wire Wire Line
	7950 5450 7950 5550
$Comp
L Device:C C41
U 1 1 5EADCE78
P 1250 5700
F 0 "C41" H 1365 5746 50  0000 L CNN
F 1 "5pC" H 1365 5655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1288 5550 50  0001 C CNN
F 3 "~" H 1250 5700 50  0001 C CNN
F 4 "08055A5R0CAT2A" H 1250 5700 50  0001 C CNN "Manufacturer Part Number"
	1    1250 5700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C42
U 1 1 5EADD5A5
P 2150 5700
F 0 "C42" H 2265 5746 50  0000 L CNN
F 1 "5pC" H 2265 5655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2188 5550 50  0001 C CNN
F 3 "~" H 2150 5700 50  0001 C CNN
F 4 "08055A5R0CAT2A" H 2150 5700 50  0001 C CNN "Manufacturer Part Number"
	1    2150 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 5550 1250 5500
Wire Wire Line
	1250 5500 1550 5500
Wire Wire Line
	1850 5500 2150 5500
Wire Wire Line
	2150 5500 2150 5550
Text Label 1900 5500 0    50   ~ 0
XOUT
Text Label 1350 5500 0    50   ~ 0
XIN
Wire Wire Line
	2200 6750 2200 6850
Wire Wire Line
	1150 6850 1150 6750
Wire Wire Line
	1150 7250 1150 7150
Wire Wire Line
	2200 7250 2200 7150
Wire Wire Line
	1250 5850 1250 5950
Wire Wire Line
	2150 5950 2150 5850
Wire Wire Line
	1700 5700 1700 5950
Connection ~ 1700 5950
Wire Wire Line
	1700 5950 2150 5950
$Comp
L Device:Crystal_GND24 Y2
U 1 1 5EADC4C3
P 1700 5500
F 0 "Y2" H 1800 5700 50  0000 L CNN
F 1 "12MHz" H 1800 5800 50  0000 L CNN
F 2 "Crystal:Crystal_SMD_3225-4Pin_3.2x2.5mm_HandSoldering" H 1700 5500 50  0001 C CNN
F 3 "https://www.iqdfrequencyproducts.com/products/pn/LFXTAL071742Reel.pdf" H 1700 5500 50  0001 C CNN
F 4 "LFXTAL071742REEL" H 1700 5500 50  0001 C CNN "Manufacturer Part Number"
	1    1700 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 5300 1700 5250
Wire Wire Line
	1700 5250 1050 5250
Wire Wire Line
	1050 5250 1050 5950
Wire Wire Line
	1050 5950 1250 5950
Connection ~ 1250 5950
Text Label 2100 5950 2    50   ~ 0
GNDANA
Wire Wire Line
	1250 5950 1700 5950
$Comp
L Device:Crystal Y1
U 1 1 5EAF4BB1
P 1650 6750
F 0 "Y1" H 1650 7018 50  0000 C CNN
F 1 "32.768kHz" H 1650 6927 50  0000 C CNN
F 2 "Crystal:Crystal_SMD_2012-2Pin_2.0x1.2mm_HandSoldering" H 1650 6750 50  0001 C CNN
F 3 "https://support.epson.biz/td/api/doc_check.php?dl=brief_FC-12D&lang=en" H 1650 6750 50  0001 C CNN
F 4 "FC-12M 32.7680KA-X3" H 1650 6750 50  0001 C CNN "Manufacturer Part Number"
	1    1650 6750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 6750 1500 6750
Wire Wire Line
	1800 6750 2200 6750
Wire Wire Line
	1150 7250 2200 7250
Wire Wire Line
	8800 5050 10050 5050
Text Label 8300 5550 2    50   ~ 0
~RESET
Wire Wire Line
	8300 5550 7950 5550
Connection ~ 7950 5550
Wire Wire Line
	7950 5550 7950 5600
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
Text Label 900  2850 3    50   ~ 0
VDDIO_1
Text Label 1400 2850 3    50   ~ 0
VDDIO_2
Text Label 1900 2850 3    50   ~ 0
VDDIO_3
Text HLabel 900  3450 3    50   Input ~ 0
GND
Wire Wire Line
	900  3150 900  2850
$Comp
L Device:C C43
U 1 1 5EB14A14
P 1400 3300
F 0 "C43" H 1515 3346 50  0000 L CNN
F 1 "0.1uC" H 1515 3255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1438 3150 50  0001 C CNN
F 3 "~" H 1400 3300 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 1400 3300 50  0001 C CNN "Manufacturer Part Number"
	1    1400 3300
	1    0    0    -1  
$EndComp
Text HLabel 1400 3450 3    50   Input ~ 0
GND
Wire Wire Line
	1400 3150 1400 2850
$Comp
L Device:C C44
U 1 1 5EB166B6
P 1900 3300
F 0 "C44" H 2015 3346 50  0000 L CNN
F 1 "0.1uC" H 2015 3255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1938 3150 50  0001 C CNN
F 3 "~" H 1900 3300 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 1900 3300 50  0001 C CNN "Manufacturer Part Number"
	1    1900 3300
	1    0    0    -1  
$EndComp
Text HLabel 1900 3450 3    50   Input ~ 0
GND
Wire Wire Line
	1900 2850 1900 3150
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
P 2400 3300
F 0 "C45" H 2515 3346 50  0000 L CNN
F 1 "0.1uC" H 2515 3255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2438 3150 50  0001 C CNN
F 3 "~" H 2400 3300 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 2400 3300 50  0001 C CNN "Manufacturer Part Number"
	1    2400 3300
	1    0    0    -1  
$EndComp
Text HLabel 2400 3450 3    50   Input ~ 0
GND
Wire Wire Line
	2400 3150 2400 2850
Text Label 2400 2850 3    50   ~ 0
VDDIOB
$Comp
L Device:C C46
U 1 1 5EB24A6F
P 2900 3300
F 0 "C46" H 3015 3346 50  0000 L CNN
F 1 "0.1uC" H 3015 3255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2938 3150 50  0001 C CNN
F 3 "~" H 2900 3300 50  0001 C CNN
F 4 "CC0805ZRY5V8BB104" H 2900 3300 50  0001 C CNN "Manufacturer Part Number"
	1    2900 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 3150 2900 2850
Text HLabel 3650 2200 3    50   Input ~ 0
GND
Text HLabel 2900 3450 3    50   Input ~ 0
GND
Text Label 6450 1500 3    50   ~ 0
VDDANA
Wire Wire Line
	6450 1800 6450 1500
Text Label 3650 1600 3    50   ~ 0
VDDANA
Wire Wire Line
	3650 1900 3650 1600
Wire Wire Line
	3650 1900 3500 1900
Connection ~ 3650 1900
$EndSCHEMATC
