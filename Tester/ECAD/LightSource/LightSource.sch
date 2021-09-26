EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L Device_custom:Battery_Two_Cells BT1
U 1 1 614F2F4E
P 2100 4000
F 0 "BT1" H 1992 4046 50  0000 R CNN
F 1 "Battery_Two_Cells" H 1992 3955 50  0000 R CNN
F 2 "Battery_custom:BatteryHolder_Keystone_1012" V 2100 4060 50  0001 C CNN
F 3 "~" V 2100 4060 50  0001 C CNN
F 4 "tbd" H 2100 4000 50  0001 C CNN "Manufacturer Part Number"
	1    2100 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:LED_RGB D1
U 1 1 61511DC7
P 9800 3850
F 0 "D1" V 9846 3520 50  0000 R CNN
F 1 "LED_RGB" V 9755 3520 50  0000 R CNN
F 2 "" H 9800 3800 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1811021530_Lite-On-LTST-K563BGEW_C284911.pdf" H 9800 3800 50  0001 C CNN
F 4 "LTST-K563BGEW" H 9800 3850 50  0001 C CNN "Manufacturer Part Number"
	1    9800 3850
	0    -1   -1   0   
$EndComp
$Comp
L Device:Laserdiode_1A3C LD2
U 1 1 615131F9
P 6850 3850
F 0 "LD2" V 6846 3762 50  0000 R CNN
F 1 "Laserdiode_1A3C" V 6755 3762 50  0000 R CNN
F 2 "OptoDevice:LaserDiode_TO18-D5.6-3" H 6750 3825 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/2001060931_Sharp-Microelectronics-GH05035A2G_C473922.pdf" H 6880 3650 50  0001 C CNN
F 4 "GH05035A2G" H 6850 3850 50  0001 C CNN "Manufacturer Part Number"
	1    6850 3850
	0    -1   -1   0   
$EndComp
$Comp
L Device:Laserdiode_1A3C LD1
U 1 1 61513BFE
P 5850 3850
F 0 "LD1" V 5846 3762 50  0000 R CNN
F 1 "Laserdiode_1A3C" V 5755 3762 50  0000 R CNN
F 2 "OptoDevice:LaserDiode_TO18-D5.6-3" H 5750 3825 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/2001060931_Sharp-Microelectronics-GH04580A2GX_C473921.pdf" H 5880 3650 50  0001 C CNN
F 4 "GH04580A2GX" H 5850 3850 50  0001 C CNN "Manufacturer Part Number"
	1    5850 3850
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
