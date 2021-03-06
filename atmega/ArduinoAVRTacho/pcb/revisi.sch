EESchema Schematic File Version 4
EELAYER 26 0
EELAYER END
$Descr User 7874 7874
encoding utf-8
Sheet 1 1
Title "ArdShield"
Date "2019-04-09"
Rev ""
Comp "Mufit"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_UNO_R3 A1
U 1 1 5CAC2F56
P 4650 3500
F 0 "A1" H 4650 4678 50  0000 C CNN
F 1 "Arduino_UNO_R3" H 4650 4587 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 4800 2450 50  0001 L CNN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 4450 4550 50  0001 C CNN
	1    4650 3500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x05_Male J-VCC1
U 1 1 5CAC312E
P 3150 2050
F 0 "J-VCC1" H 3256 2428 50  0000 C CNN
F 1 "Conn_01x05_Male" H 3256 2337 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 3150 2050 50  0001 C CNN
F 3 "~" H 3150 2050 50  0001 C CNN
	1    3150 2050
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR03
U 1 1 5CAC3283
P 3550 1700
F 0 "#PWR03" H 3550 1550 50  0001 C CNN
F 1 "VCC" H 3567 1873 50  0000 C CNN
F 2 "" H 3550 1700 50  0001 C CNN
F 3 "" H 3550 1700 50  0001 C CNN
	1    3550 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 2250 3550 2250
Wire Wire Line
	3550 2250 3550 2150
Connection ~ 3550 1850
Wire Wire Line
	3550 1850 3550 1700
Wire Wire Line
	3350 1950 3550 1950
Connection ~ 3550 1950
Wire Wire Line
	3550 1950 3550 1850
Wire Wire Line
	3350 1850 3550 1850
Wire Wire Line
	3350 2050 3550 2050
Connection ~ 3550 2050
Wire Wire Line
	3550 2050 3550 1950
Wire Wire Line
	3350 2150 3550 2150
Connection ~ 3550 2150
Wire Wire Line
	3550 2150 3550 2050
$Comp
L power:VCC #PWR05
U 1 1 5CAC34BA
P 4850 2350
F 0 "#PWR05" H 4850 2200 50  0001 C CNN
F 1 "VCC" H 4867 2523 50  0000 C CNN
F 2 "" H 4850 2350 50  0001 C CNN
F 3 "" H 4850 2350 50  0001 C CNN
	1    4850 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 2350 4850 2500
$Comp
L Connector:Conn_01x05_Male J-GND1
U 1 1 5CAC371C
P 2500 2050
F 0 "J-GND1" H 2606 2428 50  0000 C CNN
F 1 "Conn_01x05_Male" H 2606 2337 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 2500 2050 50  0001 C CNN
F 3 "~" H 2500 2050 50  0001 C CNN
	1    2500 2050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5CAC3879
P 2800 2350
F 0 "#PWR01" H 2800 2100 50  0001 C CNN
F 1 "GND" H 2805 2177 50  0000 C CNN
F 2 "" H 2800 2350 50  0001 C CNN
F 3 "" H 2800 2350 50  0001 C CNN
	1    2800 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 1850 2800 1850
Wire Wire Line
	2800 1850 2800 1950
Wire Wire Line
	2700 2250 2800 2250
Connection ~ 2800 2250
Wire Wire Line
	2700 2150 2800 2150
Connection ~ 2800 2150
Wire Wire Line
	2800 2150 2800 2250
Wire Wire Line
	2700 2050 2800 2050
Connection ~ 2800 2050
Wire Wire Line
	2800 2050 2800 2150
Wire Wire Line
	2700 1950 2800 1950
Connection ~ 2800 1950
Wire Wire Line
	2800 1950 2800 2050
Wire Wire Line
	2800 2250 2800 2350
$Comp
L power:GND #PWR04
U 1 1 5CAC4456
P 4650 4750
F 0 "#PWR04" H 4650 4500 50  0001 C CNN
F 1 "GND" H 4655 4577 50  0000 C CNN
F 2 "" H 4650 4750 50  0001 C CNN
F 3 "" H 4650 4750 50  0001 C CNN
	1    4650 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 4600 4650 4750
$Comp
L Connector:Conn_01x04_Male J-LM471
U 1 1 5CAC56AF
P 2500 3150
F 0 "J-LM471" H 2606 3428 50  0000 C CNN
F 1 "Conn_01x04_Male" H 2606 3337 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 2500 3150 50  0001 C CNN
F 3 "~" H 2500 3150 50  0001 C CNN
	1    2500 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 3050 3050 3050
Text Label 3050 3050 0    50   ~ 0
ADC0
Wire Wire Line
	2700 3150 3050 3150
Text Label 3050 3150 0    50   ~ 0
ADC2
$Comp
L power:GND #PWR02
U 1 1 5CAC6011
P 2800 3400
F 0 "#PWR02" H 2800 3150 50  0001 C CNN
F 1 "GND" H 2805 3227 50  0000 C CNN
F 2 "" H 2800 3400 50  0001 C CNN
F 3 "" H 2800 3400 50  0001 C CNN
	1    2800 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 3250 2800 3250
Wire Wire Line
	2800 3250 2800 3350
Wire Wire Line
	2700 3350 2800 3350
Connection ~ 2800 3350
Wire Wire Line
	2800 3350 2800 3400
Wire Wire Line
	5150 3500 5350 3500
Wire Wire Line
	5150 3600 5350 3600
Wire Wire Line
	5150 3700 5350 3700
Text Label 5350 3500 0    50   ~ 0
ADC0
Text Label 5350 3600 0    50   ~ 0
ADC1
Text Label 5350 3700 0    50   ~ 0
ADC2
$Comp
L Connector:Conn_01x04_Male J-I2CLCD1
U 1 1 5CAC7BF6
P 2600 4150
F 0 "J-I2CLCD1" H 2706 4428 50  0000 C CNN
F 1 "Conn_01x04_Male" H 2706 4337 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 2600 4150 50  0001 C CNN
F 3 "~" H 2600 4150 50  0001 C CNN
	1    2600 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 4050 3050 4050
Text Label 3050 4050 0    50   ~ 0
SCL1
Wire Wire Line
	2800 4150 3050 4150
Text Label 3050 4150 0    50   ~ 0
SDA1
$Comp
L power:VCC #PWR08
U 1 1 5CAC8B7E
P 3350 4200
F 0 "#PWR08" H 3350 4050 50  0001 C CNN
F 1 "VCC" H 3367 4373 50  0000 C CNN
F 2 "" H 3350 4200 50  0001 C CNN
F 3 "" H 3350 4200 50  0001 C CNN
	1    3350 4200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 5CAC8BCE
P 3350 4350
F 0 "#PWR09" H 3350 4100 50  0001 C CNN
F 1 "GND" H 3355 4177 50  0000 C CNN
F 2 "" H 3350 4350 50  0001 C CNN
F 3 "" H 3350 4350 50  0001 C CNN
	1    3350 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 4350 2800 4350
Wire Wire Line
	3350 4200 3350 4250
Wire Wire Line
	3350 4250 2800 4250
Wire Wire Line
	5150 3900 5350 3900
Text Label 5350 3900 0    50   ~ 0
SDA1
Wire Wire Line
	5150 4000 5350 4000
Text Label 5350 4000 0    50   ~ 0
SCL1
$Comp
L Connector:Conn_01x03_Male J-VSEN1
U 1 1 5CACA9BE
P 2500 5150
F 0 "J-VSEN1" H 2606 5428 50  0000 C CNN
F 1 "Conn_01x03_Male" H 2606 5337 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 2500 5150 50  0001 C CNN
F 3 "~" H 2500 5150 50  0001 C CNN
	1    2500 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 5050 2900 5050
Text Label 2900 5050 0    50   ~ 0
ADC1
$Comp
L power:VCC #PWR06
U 1 1 5CACB310
P 3000 5150
F 0 "#PWR06" H 3000 5000 50  0001 C CNN
F 1 "VCC" H 3017 5323 50  0000 C CNN
F 2 "" H 3000 5150 50  0001 C CNN
F 3 "" H 3000 5150 50  0001 C CNN
	1    3000 5150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5CACB34B
P 3000 5250
F 0 "#PWR07" H 3000 5000 50  0001 C CNN
F 1 "GND" H 3005 5077 50  0000 C CNN
F 2 "" H 3000 5250 50  0001 C CNN
F 3 "" H 3000 5250 50  0001 C CNN
	1    3000 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 5150 2700 5150
Wire Wire Line
	3000 5250 2700 5250
$Comp
L Connector:Conn_01x06_Male J-DAC1
U 1 1 5CACC30D
P 3300 5200
F 0 "J-DAC1" H 3406 5578 50  0000 C CNN
F 1 "Conn_01x06_Male" H 3406 5487 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 3300 5200 50  0001 C CNN
F 3 "~" H 3300 5200 50  0001 C CNN
	1    3300 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 4200 5350 4200
Text Label 5350 4200 0    50   ~ 0
SDA2
Wire Wire Line
	5150 4300 5350 4300
Text Label 5350 4300 0    50   ~ 0
SCL2
Wire Wire Line
	3500 5200 3800 5200
Text Label 3800 5200 0    50   ~ 0
SCL2
Wire Wire Line
	3500 5300 3800 5300
Text Label 3800 5300 0    50   ~ 0
SDA2
$Comp
L power:VCC #PWR010
U 1 1 5CACFC88
P 3850 5400
F 0 "#PWR010" H 3850 5250 50  0001 C CNN
F 1 "VCC" H 3867 5573 50  0000 C CNN
F 2 "" H 3850 5400 50  0001 C CNN
F 3 "" H 3850 5400 50  0001 C CNN
	1    3850 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 5400 3500 5400
$Comp
L power:GND #PWR011
U 1 1 5CAD06C7
P 3850 5500
F 0 "#PWR011" H 3850 5250 50  0001 C CNN
F 1 "GND" H 3855 5327 50  0000 C CNN
F 2 "" H 3850 5500 50  0001 C CNN
F 3 "" H 3850 5500 50  0001 C CNN
	1    3850 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 5500 3500 5500
$Comp
L Connector:Conn_01x02_Male J-VOUT1
U 1 1 5CAD118A
P 4300 5000
F 0 "J-VOUT1" H 4273 4973 50  0000 R CNN
F 1 "Conn_01x02_Male" H 4273 4882 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4300 5000 50  0001 C CNN
F 3 "~" H 4300 5000 50  0001 C CNN
	1    4300 5000
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4100 5000 3500 5000
Wire Wire Line
	3500 5100 4100 5100
$Comp
L power:GND #PWR012
U 1 1 5CAD26B1
P 4100 5200
F 0 "#PWR012" H 4100 4950 50  0001 C CNN
F 1 "GND" H 4105 5027 50  0000 C CNN
F 2 "" H 4100 5200 50  0001 C CNN
F 3 "" H 4100 5200 50  0001 C CNN
	1    4100 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 5200 4100 5100
Connection ~ 4100 5100
$Comp
L Transistor_BJT:2N3904 Q1
U 1 1 5CAD80A9
P 6100 2950
F 0 "Q1" H 6291 2996 50  0000 L CNN
F 1 "2N3904" H 6291 2905 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6300 2875 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 6100 2950 50  0001 L CNN
	1    6100 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5CAD821C
P 6200 2450
F 0 "R1" H 6270 2496 50  0000 L CNN
F 1 "4k7" H 6270 2405 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 6130 2450 50  0001 C CNN
F 3 "~" H 6200 2450 50  0001 C CNN
	1    6200 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 2600 6200 2750
$Comp
L Connector:Conn_01x02_Male J-ICP1
U 1 1 5CAD8DF4
P 5600 2950
F 0 "J-ICP1" H 5706 3128 50  0000 C CNN
F 1 "Conn_01x02_Male" H 5706 3037 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_Altech_AK300-2_P5.00mm" H 5600 2950 50  0001 C CNN
F 3 "~" H 5600 2950 50  0001 C CNN
	1    5600 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 2950 5800 2950
Wire Wire Line
	5800 3050 5800 3150
Wire Wire Line
	5800 3150 6050 3150
$Comp
L power:GND #PWR013
U 1 1 5CADB283
P 6050 3250
F 0 "#PWR013" H 6050 3000 50  0001 C CNN
F 1 "GND" H 6055 3077 50  0000 C CNN
F 2 "" H 6050 3250 50  0001 C CNN
F 3 "" H 6050 3250 50  0001 C CNN
	1    6050 3250
	1    0    0    -1  
$EndComp
Connection ~ 6050 3150
Wire Wire Line
	6050 3150 6200 3150
$Comp
L power:VCC #PWR014
U 1 1 5CADC0B6
P 6200 2200
F 0 "#PWR014" H 6200 2050 50  0001 C CNN
F 1 "VCC" H 6217 2373 50  0000 C CNN
F 2 "" H 6200 2200 50  0001 C CNN
F 3 "" H 6200 2200 50  0001 C CNN
	1    6200 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 2200 6200 2300
$Comp
L Device:LED D1
U 1 1 5CADCF66
P 6500 2600
F 0 "D1" V 6538 2483 50  0000 R CNN
F 1 "LED" V 6447 2483 50  0000 R CNN
F 2 "LED_SMD:LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 6500 2600 50  0001 C CNN
F 3 "~" H 6500 2600 50  0001 C CNN
	1    6500 2600
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R2
U 1 1 5CADD018
P 6500 2200
F 0 "R2" H 6570 2246 50  0000 L CNN
F 1 "330" H 6570 2155 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 6430 2200 50  0001 C CNN
F 3 "~" H 6500 2200 50  0001 C CNN
	1    6500 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 2750 6200 2750
Connection ~ 6200 2750
Wire Wire Line
	6500 2750 6800 2750
Connection ~ 6500 2750
Text Label 6800 2750 0    50   ~ 0
ICP
Wire Wire Line
	6500 2350 6500 2450
$Comp
L power:VCC #PWR015
U 1 1 5CADFCC9
P 6500 1950
F 0 "#PWR015" H 6500 1800 50  0001 C CNN
F 1 "VCC" H 6517 2123 50  0000 C CNN
F 2 "" H 6500 1950 50  0001 C CNN
F 3 "" H 6500 1950 50  0001 C CNN
	1    6500 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 1950 6500 2050
Wire Wire Line
	6050 3150 6050 3250
Wire Wire Line
	4150 3700 3950 3700
Text Label 3950 3700 0    50   ~ 0
ICP
$EndSCHEMATC
