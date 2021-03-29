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
L MCU_Microchip_ATmega:ATmega1284P-PU U?
U 1 1 6061E5F3
P 2850 3150
F 0 "U?" H 2000 2300 50  0000 C CNN
F 1 "ATmega1284P-PU" H 1950 2150 50  0000 C CNN
F 2 "Package_DIP:DIP-40_W15.24mm" H 2850 3150 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8272-8-bit-AVR-microcontroller-ATmega164A_PA-324A_PA-644A_PA-1284_P_datasheet.pdf" H 2850 3150 50  0001 C CNN
	1    2850 3150
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J?
U 1 1 6061F728
P 4900 1100
F 0 "J?" H 4928 1076 50  0000 L CNN
F 1 "Conn_01x04_Female" H 4928 985 50  0000 L CNN
F 2 "" H 4900 1100 50  0001 C CNN
F 3 "~" H 4900 1100 50  0001 C CNN
	1    4900 1100
	1    0    0    -1  
$EndComp
Text Notes 4700 800  0    50   ~ 0
GPS
$Comp
L RF_Module:RFM95W-915S2 U?
U 1 1 606219F2
P 6850 1450
F 0 "U?" H 6850 2131 50  0000 C CNN
F 1 "RFM95W-915S2" H 6850 2040 50  0000 C CNN
F 2 "" H 3550 3100 50  0001 C CNN
F 3 "https://www.hoperf.com/data/upload/portal/20181127/5bfcbea20e9ef.pdf" H 3550 3100 50  0001 C CNN
	1    6850 1450
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x12_Female J?
U 1 1 606248C2
P 4800 2550
F 0 "J?" H 4828 2526 50  0000 L CNN
F 1 "Conn_01x12_Female" H 4828 2435 50  0000 L CNN
F 2 "" H 4800 2550 50  0001 C CNN
F 3 "~" H 4800 2550 50  0001 C CNN
	1    4800 2550
	1    0    0    -1  
$EndComp
Text Notes 4500 1800 0    50   ~ 0
eink breakout
$Comp
L Connector:Micro_SD_Card J?
U 1 1 60621969
P 9550 1450
F 0 "J?" H 9500 2167 50  0000 C CNN
F 1 "Micro_SD_Card" H 9500 2076 50  0000 C CNN
F 2 "" H 10700 1750 50  0001 C CNN
F 3 "http://katalog.we-online.de/em/datasheet/693072010801.pdf" H 9550 1450 50  0001 C CNN
	1    9550 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D?
U 1 1 606350FC
P 6300 3200
F 0 "D?" V 6339 3083 50  0000 R CNN
F 1 "LED" V 6248 3083 50  0000 R CNN
F 2 "" H 6300 3200 50  0001 C CNN
F 3 "~" H 6300 3200 50  0001 C CNN
	1    6300 3200
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 60635D60
P 6300 2900
F 0 "R?" H 6370 2946 50  0000 L CNN
F 1 "R" H 6370 2855 50  0000 L CNN
F 2 "" V 6230 2900 50  0001 C CNN
F 3 "~" H 6300 2900 50  0001 C CNN
	1    6300 2900
	1    0    0    -1  
$EndComp
Text GLabel 6300 2600 0    50   Input ~ 0
A7
Wire Wire Line
	6300 2750 6300 2600
$Comp
L power:GND #PWR?
U 1 1 60639DB7
P 6300 3350
F 0 "#PWR?" H 6300 3100 50  0001 C CNN
F 1 "GND" H 6305 3177 50  0000 C CNN
F 2 "" H 6300 3350 50  0001 C CNN
F 3 "" H 6300 3350 50  0001 C CNN
	1    6300 3350
	1    0    0    -1  
$EndComp
Text GLabel 4600 3150 0    50   Input ~ 0
A0
Text GLabel 8650 1250 0    50   Input ~ 0
4
$Comp
L power:GND #PWR?
U 1 1 60649079
P 4700 1000
F 0 "#PWR?" H 4700 750 50  0001 C CNN
F 1 "GND" V 4705 872 50  0000 R CNN
F 2 "" H 4700 1000 50  0001 C CNN
F 3 "" H 4700 1000 50  0001 C CNN
	1    4700 1000
	0    1    1    0   
$EndComp
Text GLabel 4700 1100 0    50   Input ~ 0
14
Text GLabel 4700 1200 0    50   Input ~ 0
12
Text GLabel 4600 2150 0    50   Input ~ 0
3V_SWITCH
Text GLabel 4700 1300 0    50   Input ~ 0
3V_SWITCH
Text GLabel 8650 1450 0    50   Input ~ 0
3V_SWITCH
$Comp
L power:GND #PWR?
U 1 1 60651931
P 8250 1650
F 0 "#PWR?" H 8250 1400 50  0001 C CNN
F 1 "GND" H 8255 1477 50  0000 C CNN
F 2 "" H 8250 1650 50  0001 C CNN
F 3 "" H 8250 1650 50  0001 C CNN
	1    8250 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 1650 8250 1650
Text GLabel 8650 1750 0    50   Input ~ 0
MISO
Text GLabel 8650 1550 0    50   Input ~ 0
SCK
Text GLabel 8650 1350 0    50   Input ~ 0
MOSI
$Comp
L power:GND #PWR?
U 1 1 606533A5
P 10350 2050
F 0 "#PWR?" H 10350 1800 50  0001 C CNN
F 1 "GND" H 10355 1877 50  0000 C CNN
F 2 "" H 10350 2050 50  0001 C CNN
F 3 "" H 10350 2050 50  0001 C CNN
	1    10350 2050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 6065D5EE
P 4600 2250
F 0 "#PWR?" H 4600 2000 50  0001 C CNN
F 1 "GND" V 4605 2122 50  0000 R CNN
F 2 "" H 4600 2250 50  0001 C CNN
F 3 "" H 4600 2250 50  0001 C CNN
	1    4600 2250
	0    1    1    0   
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 6065E09E
P 4600 2050
F 0 "#PWR?" H 4600 1900 50  0001 C CNN
F 1 "+3V3" H 4615 2223 50  0000 C CNN
F 2 "" H 4600 2050 50  0001 C CNN
F 3 "" H 4600 2050 50  0001 C CNN
	1    4600 2050
	1    0    0    -1  
$EndComp
Text GLabel 6350 1650 0    50   Input ~ 0
23
Text GLabel 6350 1450 0    50   Input ~ 0
22
Text GLabel 7350 1850 2    50   Input ~ 0
11
Text GLabel 6350 1350 0    50   Input ~ 0
MISO
Text GLabel 6350 1250 0    50   Input ~ 0
MOSI
Text GLabel 6350 1150 0    50   Input ~ 0
SCK
$Comp
L power:GND #PWR?
U 1 1 60665EE6
P 6750 2050
F 0 "#PWR?" H 6750 1800 50  0001 C CNN
F 1 "GND" H 6755 1877 50  0000 C CNN
F 2 "" H 6750 2050 50  0001 C CNN
F 3 "" H 6750 2050 50  0001 C CNN
	1    6750 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 2050 6850 2050
Connection ~ 6750 2050
Wire Wire Line
	6850 2050 6950 2050
Connection ~ 6850 2050
Text GLabel 4600 2350 0    50   Input ~ 0
SCK
Text GLabel 4600 2450 0    50   Input ~ 0
MISO
Text GLabel 4600 2550 0    50   Input ~ 0
MOSI
Text GLabel 4600 2650 0    50   Input ~ 0
18
Text GLabel 4600 2750 0    50   Input ~ 0
19
Text GLabel 4600 2850 0    50   Input ~ 0
20
Text GLabel 4600 2950 0    50   Input ~ 0
21
Text GLabel 4600 3050 0    50   Input ~ 0
15
Text GLabel 3450 1450 2    50   Input ~ 0
A0
Text GLabel 3450 1550 2    50   Input ~ 0
A1
Text GLabel 3450 1650 2    50   Input ~ 0
A2
Text GLabel 3450 1750 2    50   Input ~ 0
A3
Text GLabel 3450 1850 2    50   Input ~ 0
A4
Text GLabel 3450 1950 2    50   Input ~ 0
A5
Text GLabel 3450 2050 2    50   Input ~ 0
A6
Text GLabel 3450 2150 2    50   Input ~ 0
A7
Text GLabel 3450 2350 2    50   Input ~ 0
0
Text GLabel 3450 2450 2    50   Input ~ 0
1
Text GLabel 3450 2550 2    50   Input ~ 0
2
Text GLabel 3450 2650 2    50   Input ~ 0
3
Text GLabel 3450 2750 2    50   Input ~ 0
4
Text GLabel 3450 2850 2    50   Input ~ 0
5
Text GLabel 3450 2950 2    50   Input ~ 0
6
Text GLabel 3450 3050 2    50   Input ~ 0
7
Text GLabel 3450 3250 2    50   Input ~ 0
16
Text GLabel 3450 3350 2    50   Input ~ 0
17
Text GLabel 3450 3450 2    50   Input ~ 0
18
Text GLabel 3450 3550 2    50   Input ~ 0
19
Text GLabel 3450 3650 2    50   Input ~ 0
20
Text GLabel 3450 3750 2    50   Input ~ 0
21
Text GLabel 3450 3850 2    50   Input ~ 0
22
Text GLabel 3450 3950 2    50   Input ~ 0
23
Text GLabel 3450 4150 2    50   Input ~ 0
8
Text GLabel 3450 4250 2    50   Input ~ 0
9
Text GLabel 3450 4350 2    50   Input ~ 0
10
Text GLabel 3450 4450 2    50   Input ~ 0
11
Text GLabel 3450 4550 2    50   Input ~ 0
12
Text GLabel 3450 4650 2    50   Input ~ 0
13
Text GLabel 3450 4750 2    50   Input ~ 0
14
Text GLabel 3450 4850 2    50   Input ~ 0
15
$Comp
L power:GND #PWR?
U 1 1 6068DD1E
P 2850 5150
F 0 "#PWR?" H 2850 4900 50  0001 C CNN
F 1 "GND" H 2855 4977 50  0000 C CNN
F 2 "" H 2850 5150 50  0001 C CNN
F 3 "" H 2850 5150 50  0001 C CNN
	1    2850 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 60690C3F
P 1950 2450
F 0 "C?" H 2065 2496 50  0000 L CNN
F 1 "0.1uF" H 2065 2405 50  0000 L CNN
F 2 "" H 1988 2300 50  0001 C CNN
F 3 "~" H 1950 2450 50  0001 C CNN
	1    1950 2450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60691979
P 1950 2600
F 0 "#PWR?" H 1950 2350 50  0001 C CNN
F 1 "GND" H 1955 2427 50  0000 C CNN
F 2 "" H 1950 2600 50  0001 C CNN
F 3 "" H 1950 2600 50  0001 C CNN
	1    1950 2600
	1    0    0    -1  
$EndComp
Text GLabel 1950 2150 0    50   Input ~ 0
AREF
Wire Wire Line
	2950 1150 2850 1150
$Comp
L power:+3V3 #PWR?
U 1 1 60694BA9
P 2850 900
F 0 "#PWR?" H 2850 750 50  0001 C CNN
F 1 "+3V3" H 2865 1073 50  0000 C CNN
F 2 "" H 2850 900 50  0001 C CNN
F 3 "" H 2850 900 50  0001 C CNN
	1    2850 900 
	1    0    0    -1  
$EndComp
Connection ~ 2850 1150
Wire Wire Line
	2850 1150 2850 950 
Wire Wire Line
	2250 1450 1950 1450
Wire Wire Line
	1950 1450 1950 1250
$Comp
L Device:R R?
U 1 1 606A07E7
P 1950 1100
F 0 "R?" H 2020 1146 50  0000 L CNN
F 1 "10K" H 2020 1055 50  0000 L CNN
F 2 "" V 1880 1100 50  0001 C CNN
F 3 "~" H 1950 1100 50  0001 C CNN
	1    1950 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 950  2850 950 
Connection ~ 2850 950 
Wire Wire Line
	2850 950  2850 900 
Connection ~ 1950 1450
$Comp
L Device:C C?
U 1 1 606A2D75
P 900 1600
F 0 "C?" H 1015 1646 50  0000 L CNN
F 1 "0.1uF" H 1015 1555 50  0000 L CNN
F 2 "" H 938 1450 50  0001 C CNN
F 3 "~" H 900 1600 50  0001 C CNN
	1    900  1600
	1    0    0    -1  
$EndComp
Text GLabel 900  1750 0    50   Input ~ 0
DTR
$Comp
L Device:Crystal Y?
U 1 1 606A633A
P 2050 1750
F 0 "Y?" V 2004 1881 50  0000 L CNN
F 1 "Crystal" V 2095 1881 50  0000 L CNN
F 2 "" H 2050 1750 50  0001 C CNN
F 3 "~" H 2050 1750 50  0001 C CNN
	1    2050 1750
	0    1    1    0   
$EndComp
Wire Wire Line
	900  1450 1950 1450
Wire Wire Line
	2250 1650 2200 1650
Wire Wire Line
	2200 1650 2200 1600
Wire Wire Line
	2200 1600 2050 1600
Wire Wire Line
	2250 1850 2200 1850
Wire Wire Line
	2200 1850 2200 1900
Wire Wire Line
	2200 1900 2050 1900
Wire Wire Line
	2050 1600 1850 1600
Connection ~ 2050 1600
Wire Wire Line
	2050 1900 1850 1900
Connection ~ 2050 1900
$Comp
L Device:C C?
U 1 1 606AB90C
P 1700 1600
F 0 "C?" V 1650 1450 50  0000 C CNN
F 1 "22pF" V 1750 1450 50  0000 C CNN
F 2 "" H 1738 1450 50  0001 C CNN
F 3 "~" H 1700 1600 50  0001 C CNN
	1    1700 1600
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 606ABF72
P 1700 1900
F 0 "C?" V 1650 1700 50  0000 C CNN
F 1 "22pF" V 1750 1700 50  0000 C CNN
F 2 "" H 1738 1750 50  0001 C CNN
F 3 "~" H 1700 1900 50  0001 C CNN
	1    1700 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	1550 1600 1350 1600
Wire Wire Line
	1350 1600 1350 1900
Wire Wire Line
	1350 1900 1550 1900
Wire Wire Line
	1350 1900 1350 2050
Connection ~ 1350 1900
$Comp
L power:GND #PWR?
U 1 1 606B495A
P 1350 2050
F 0 "#PWR?" H 1350 1800 50  0001 C CNN
F 1 "GND" H 1355 1877 50  0000 C CNN
F 2 "" H 1350 2050 50  0001 C CNN
F 3 "" H 1350 2050 50  0001 C CNN
	1    1350 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 2050 1950 2050
Wire Wire Line
	1950 2050 1950 2300
$EndSCHEMATC
