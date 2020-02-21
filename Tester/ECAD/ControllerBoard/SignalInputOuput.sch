EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 4
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
L Connector:Conn_01x02_Male J?
U 1 1 5E55B73E
P 1700 2850
AR Path="/5E5070AC/5E55B73E" Ref="J?"  Part="1" 
AR Path="/5E55806E/5E55B73E" Ref="J?"  Part="1" 
F 0 "J?" H 1808 3031 50  0000 C CNN
F 1 "Conn_01x02_Male" H 1808 2940 50  0000 C CNN
F 2 "" H 1700 2850 50  0001 C CNN
F 3 "~" H 1700 2850 50  0001 C CNN
	1    1700 2850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J?
U 1 1 5E55B744
P 1700 3250
AR Path="/5E5070AC/5E55B744" Ref="J?"  Part="1" 
AR Path="/5E55806E/5E55B744" Ref="J?"  Part="1" 
F 0 "J?" H 1808 3431 50  0000 C CNN
F 1 "Conn_01x02_Male" H 1808 3340 50  0000 C CNN
F 2 "" H 1700 3250 50  0001 C CNN
F 3 "~" H 1700 3250 50  0001 C CNN
	1    1700 3250
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J?
U 1 1 5E55B74A
P 1700 3650
AR Path="/5E5070AC/5E55B74A" Ref="J?"  Part="1" 
AR Path="/5E55806E/5E55B74A" Ref="J?"  Part="1" 
F 0 "J?" H 1808 3831 50  0000 C CNN
F 1 "Conn_01x02_Male" H 1808 3740 50  0000 C CNN
F 2 "" H 1700 3650 50  0001 C CNN
F 3 "~" H 1700 3650 50  0001 C CNN
	1    1700 3650
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J?
U 1 1 5E55B750
P 1700 4050
AR Path="/5E5070AC/5E55B750" Ref="J?"  Part="1" 
AR Path="/5E55806E/5E55B750" Ref="J?"  Part="1" 
F 0 "J?" H 1808 4231 50  0000 C CNN
F 1 "Conn_01x02_Male" H 1808 4140 50  0000 C CNN
F 2 "" H 1700 4050 50  0001 C CNN
F 3 "~" H 1700 4050 50  0001 C CNN
	1    1700 4050
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J?
U 1 1 5E55B756
P 1700 4450
AR Path="/5E5070AC/5E55B756" Ref="J?"  Part="1" 
AR Path="/5E55806E/5E55B756" Ref="J?"  Part="1" 
F 0 "J?" H 1808 4631 50  0000 C CNN
F 1 "Conn_01x02_Male" H 1808 4540 50  0000 C CNN
F 2 "" H 1700 4450 50  0001 C CNN
F 3 "~" H 1700 4450 50  0001 C CNN
	1    1700 4450
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J?
U 1 1 5E55B75C
P 1700 4850
AR Path="/5E5070AC/5E55B75C" Ref="J?"  Part="1" 
AR Path="/5E55806E/5E55B75C" Ref="J?"  Part="1" 
F 0 "J?" H 1808 5031 50  0000 C CNN
F 1 "Conn_01x02_Male" H 1808 4940 50  0000 C CNN
F 2 "" H 1700 4850 50  0001 C CNN
F 3 "~" H 1700 4850 50  0001 C CNN
	1    1700 4850
	1    0    0    -1  
$EndComp
Text Notes 900  2800 0    50   ~ 0
End Stop X+
Text Notes 900  3200 0    50   ~ 0
End Stop X-
Text Notes 900  3600 0    50   ~ 0
End Stop Y+
Text Notes 900  4000 0    50   ~ 0
End Stop Y-
Text Notes 900  4400 0    50   ~ 0
End Stop Z+
Text Notes 900  4800 0    50   ~ 0
End Stop Z-
Text Label 1850 3350 0    50   ~ 0
GND
Text Label 1850 3750 0    50   ~ 0
GND
Text Label 1850 4150 0    50   ~ 0
GND
Text Label 1850 4550 0    50   ~ 0
GND
Text Label 1850 4950 0    50   ~ 0
GND
Text Label 1850 2950 0    50   ~ 0
GND
Text Label 1850 2850 0    50   ~ 0
END_STOP_X+
Text Label 1850 3250 0    50   ~ 0
END_STOP_X-
Text Label 1850 3650 0    50   ~ 0
END_STOP_Y+
Text Label 1850 4050 0    50   ~ 0
END_STOP_Y-
Text Label 1850 4450 0    50   ~ 0
END_STOP_Z+
Text Label 1850 4850 0    50   ~ 0
END_STOP_Z-
Wire Wire Line
	1900 2950 2400 2950
Wire Wire Line
	2400 2950 2400 3350
Wire Wire Line
	2400 3350 1900 3350
Wire Wire Line
	2400 3350 2400 3750
Wire Wire Line
	2400 3750 1900 3750
Connection ~ 2400 3350
Wire Wire Line
	2400 3750 2400 4150
Wire Wire Line
	2400 4150 1900 4150
Connection ~ 2400 3750
Wire Wire Line
	2400 4150 2400 4550
Wire Wire Line
	2400 4550 1900 4550
Connection ~ 2400 4150
Wire Wire Line
	2400 4550 2400 4950
Wire Wire Line
	2400 4950 1900 4950
Connection ~ 2400 4550
$Comp
L Connector:Conn_01x04_Male J?
U 1 1 5E560967
P 10250 5900
AR Path="/5E5070AC/5E560967" Ref="J?"  Part="1" 
AR Path="/5E55806E/5E560967" Ref="J?"  Part="1" 
F 0 "J?" H 10358 6181 50  0000 C CNN
F 1 "Conn_01x04_Male" H 10358 6090 50  0000 C CNN
F 2 "" H 10250 5900 50  0001 C CNN
F 3 "~" H 10250 5900 50  0001 C CNN
	1    10250 5900
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x08_Male J?
U 1 1 5E56096D
P 10250 4500
AR Path="/5E5070AC/5E56096D" Ref="J?"  Part="1" 
AR Path="/5E55806E/5E56096D" Ref="J?"  Part="1" 
F 0 "J?" H 10358 4981 50  0000 C CNN
F 1 "Conn_01x08_Male" H 10358 4890 50  0000 C CNN
F 2 "" H 10250 4500 50  0001 C CNN
F 3 "~" H 10250 4500 50  0001 C CNN
	1    10250 4500
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x08_Male J?
U 1 1 5E560973
P 10250 2850
AR Path="/5E5070AC/5E560973" Ref="J?"  Part="1" 
AR Path="/5E55806E/5E560973" Ref="J?"  Part="1" 
F 0 "J?" H 10358 3331 50  0000 C CNN
F 1 "Conn_01x08_Male" H 10358 3240 50  0000 C CNN
F 2 "" H 10250 2850 50  0001 C CNN
F 3 "~" H 10250 2850 50  0001 C CNN
	1    10250 2850
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x08_Male J?
U 1 1 5E560979
P 10250 1300
AR Path="/5E5070AC/5E560979" Ref="J?"  Part="1" 
AR Path="/5E55806E/5E560979" Ref="J?"  Part="1" 
F 0 "J?" H 10358 1781 50  0000 C CNN
F 1 "Conn_01x08_Male" H 10358 1690 50  0000 C CNN
F 2 "" H 10250 1300 50  0001 C CNN
F 3 "~" H 10250 1300 50  0001 C CNN
	1    10250 1300
	-1   0    0    1   
$EndComp
Text Notes 10050 750  0    50   ~ 0
Position\nSensor\nX
Text Notes 10050 2300 0    50   ~ 0
Position\nSensor\nY
Text Notes 10050 3950 0    50   ~ 0
Position\nSensor\nZ
Text Notes 10050 5550 0    50   ~ 0
Laser\nModule
Text Label 10200 900  0    50   ~ 0
VCC_5V
Text Label 10200 2450 0    50   ~ 0
VCC_5V
Text Label 10200 4100 0    50   ~ 0
VCC_5V
Text Label 10200 6000 0    50   ~ 0
VCC_5V
Text Label 10200 5700 0    50   ~ 0
GND
Text Label 10200 4800 0    50   ~ 0
GND
Text Label 10200 3150 0    50   ~ 0
GND
Text Label 10200 1600 0    50   ~ 0
GND
Text Label 10200 5900 0    50   ~ 0
LASER_SCL
Text Label 10200 5800 0    50   ~ 0
LASER_SDA
Text Label 10200 1000 0    50   ~ 0
~POSX_NCS
Text Label 10200 1100 0    50   ~ 0
POS_MISO
Text Label 10200 1200 0    50   ~ 0
POS_MOSI
Text Label 10200 1300 0    50   ~ 0
POS_SCLK
Text Label 10200 1400 0    50   ~ 0
POSX_MOTION
Text Label 10200 1500 0    50   ~ 0
~POSX_NRESET
Text Label 10200 2650 0    50   ~ 0
POS_MISO
Text Label 10200 4300 0    50   ~ 0
POS_MISO
Text Label 10200 2750 0    50   ~ 0
POS_MOSI
Text Label 10200 4400 0    50   ~ 0
POS_MOSI
Text Label 10200 2850 0    50   ~ 0
POS_SCLK
Text Label 10200 4500 0    50   ~ 0
POS_SCLK
Text Label 10200 2550 0    50   ~ 0
~POSY_NCS
Text Label 10200 4200 0    50   ~ 0
~POSZ_NCS
Text Label 10200 2950 0    50   ~ 0
POSY_MOTION
Text Label 10200 4600 0    50   ~ 0
POSZ_MOTION
Text Label 10200 3050 0    50   ~ 0
~POSY_NRESET
Text Label 10200 4700 0    50   ~ 0
~POSZ_NRESET
Wire Wire Line
	10050 5700 9700 5700
Wire Wire Line
	9700 5700 9700 4800
Wire Wire Line
	9700 4800 10050 4800
Wire Wire Line
	9700 4800 9700 3150
Wire Wire Line
	9700 3150 10050 3150
Connection ~ 9700 4800
Wire Wire Line
	9700 3150 9700 1600
Wire Wire Line
	9700 1600 10050 1600
Connection ~ 9700 3150
Wire Wire Line
	10050 900  9600 900 
Wire Wire Line
	9600 900  9600 2450
Wire Wire Line
	9600 2450 10050 2450
Wire Wire Line
	9600 2450 9600 4100
Wire Wire Line
	9600 4100 10050 4100
Connection ~ 9600 2450
Wire Wire Line
	9600 4100 9600 6000
Wire Wire Line
	9600 6000 10050 6000
Connection ~ 9600 4100
Wire Wire Line
	10050 1100 9350 1100
Wire Wire Line
	9350 1100 9350 2650
Wire Wire Line
	9350 2650 10050 2650
Wire Wire Line
	9350 2650 9350 4300
Wire Wire Line
	9350 4300 10050 4300
Connection ~ 9350 2650
Wire Wire Line
	10050 1200 9200 1200
Wire Wire Line
	9200 1200 9200 2750
Wire Wire Line
	9200 2750 10050 2750
Wire Wire Line
	9200 2750 9200 4400
Wire Wire Line
	9200 4400 10050 4400
Connection ~ 9200 2750
Wire Wire Line
	10050 1300 9050 1300
Wire Wire Line
	9050 1300 9050 2850
Wire Wire Line
	9050 2850 10050 2850
Wire Wire Line
	9050 2850 9050 4500
Wire Wire Line
	9050 4500 10050 4500
Connection ~ 9050 2850
$EndSCHEMATC
