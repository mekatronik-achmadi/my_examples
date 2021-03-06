EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:pspice
EELAYER 25 0
EELAYER END
$Descr User 7874 5906
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
L LF356 U1
U 1 1 5B80A90B
P 2700 1550
F 0 "U1" H 2700 1800 50  0000 L CNN
F 1 "LM358" H 2700 1700 50  0000 L CNN
F 2 "" H 2750 1600 50  0001 C CNN
F 3 "" H 2850 1700 50  0001 C CNN
	1    2700 1550
	1    0    0    1   
$EndComp
$Comp
L R R1
U 1 1 5B80B1C2
P 2100 1450
F 0 "R1" V 2180 1450 50  0000 C CNN
F 1 "1k" V 2100 1450 50  0000 C CNN
F 2 "" V 2030 1450 50  0001 C CNN
F 3 "" H 2100 1450 50  0001 C CNN
	1    2100 1450
	0    1    1    0   
$EndComp
Text GLabel 1800 1450 0    60   Input ~ 0
v_in
$Comp
L R R2
U 1 1 5B80B296
P 2650 700
F 0 "R2" V 2730 700 50  0000 C CNN
F 1 "5k" V 2650 700 50  0000 C CNN
F 2 "" V 2580 700 50  0001 C CNN
F 3 "" H 2650 700 50  0001 C CNN
	1    2650 700 
	0    1    1    0   
$EndComp
Text GLabel 5200 1150 0    60   Input ~ 0
v_out
Text GLabel 2200 1050 0    60   Input ~ 0
v_m
Text GLabel 2200 2000 0    60   Input ~ 0
v_p
$Comp
L VSOURCE V2
U 1 1 5B80B5F7
P 4200 3050
F 0 "V2" H 4200 2950 50  0000 C CNN
F 1 "3.3" H 4200 3150 50  0000 C CNN
F 2 "" H 4200 3050 50  0001 C CNN
F 3 "" H 4200 3050 50  0001 C CNN
	1    4200 3050
	1    0    0    -1  
$EndComp
$Comp
L VSOURCE V3
U 1 1 5B80B75D
P 5150 3050
F 0 "V3" H 5150 2950 50  0000 C CNN
F 1 "-3.3" H 5150 3150 50  0000 C CNN
F 2 "" H 5150 3050 50  0001 C CNN
F 3 "" H 5150 3050 50  0001 C CNN
	1    5150 3050
	1    0    0    -1  
$EndComp
$Comp
L 0 #GND01
U 1 1 5B80B7EF
P 4650 3900
F 0 "#GND01" H 4650 3800 50  0001 C CNN
F 1 "0" H 4650 3830 50  0000 C CNN
F 2 "" H 4650 3900 50  0001 C CNN
F 3 "" H 4650 3900 50  0001 C CNN
	1    4650 3900
	1    0    0    -1  
$EndComp
Text GLabel 4050 2200 0    60   Input ~ 0
v_p
Text GLabel 5000 2200 0    60   Input ~ 0
v_m
Text Notes 5850 3150 0    60   ~ 0
+PSPICE\n\n* .ac dec 10 100 1000k\n.tran 100u 10m\n* .dc V1 -0.5 0.5 0.1\n\n* dc 0V ac 1V\n* sin(0 1m 500)\n\n.control\nset color0=rgb:f/f/f\nset color1=rgb:0/0/0\nrun\nplot v(v_in), v(v_out)\n.endc
Text Notes 5800 1600 0    60   ~ 0
-PSPICE\n\n.include lm358.mod
$Comp
L 0 #GND02
U 1 1 5B80B513
P 1800 3950
F 0 "#GND02" H 1800 3850 50  0001 C CNN
F 1 "0" H 1800 3880 50  0000 C CNN
F 2 "" H 1800 3950 50  0001 C CNN
F 3 "" H 1800 3950 50  0001 C CNN
	1    1800 3950
	1    0    0    -1  
$EndComp
Text GLabel 1100 2350 0    60   Input ~ 0
v_in
$Comp
L VSOURCE V1
U 1 1 5B80B42C
P 1250 3150
F 0 "V1" H 1250 3050 50  0000 C CNN
F 1 "sin(0 1m 500)" H 1250 3250 50  0000 C CNN
F 2 "" H 1250 3150 50  0001 C CNN
F 3 "" H 1250 3150 50  0001 C CNN
	1    1250 3150
	1    0    0    -1  
$EndComp
$Comp
L VSOURCE V4
U 1 1 5B80E01F
P 2400 3150
F 0 "V4" H 2400 3050 50  0000 C CNN
F 1 "60mV" H 2400 3250 50  0000 C CNN
F 2 "" H 2400 3150 50  0001 C CNN
F 3 "" H 2400 3150 50  0001 C CNN
	1    2400 3150
	1    0    0    -1  
$EndComp
Text GLabel 2250 2300 0    60   Input ~ 0
v_off
$Comp
L 0 #GND03
U 1 1 5B80ED7D
P 2300 1700
F 0 "#GND03" H 2300 1600 50  0001 C CNN
F 1 "0" H 2300 1630 50  0000 C CNN
F 2 "" H 2300 1700 50  0001 C CNN
F 3 "" H 2300 1700 50  0001 C CNN
	1    2300 1700
	1    0    0    -1  
$EndComp
$Comp
L LF356 U2
U 1 1 5B80EF00
P 4450 1450
F 0 "U2" H 4450 1700 50  0000 L CNN
F 1 "LM358" H 4450 1600 50  0000 L CNN
F 2 "" H 4500 1500 50  0001 C CNN
F 3 "" H 4600 1600 50  0001 C CNN
	1    4450 1450
	1    0    0    1   
$EndComp
Text GLabel 3550 1350 0    60   Input ~ 0
v_off
$Comp
L R R6
U 1 1 5B81047F
P 4450 950
F 0 "R6" V 4530 950 50  0000 C CNN
F 1 "1k" V 4450 950 50  0000 C CNN
F 2 "" V 4380 950 50  0001 C CNN
F 3 "" H 4450 950 50  0001 C CNN
	1    4450 950 
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 5B81067B
P 3850 1350
F 0 "R3" V 3930 1350 50  0000 C CNN
F 1 "1k" V 3850 1350 50  0000 C CNN
F 2 "" V 3780 1350 50  0001 C CNN
F 3 "" H 3850 1350 50  0001 C CNN
	1    3850 1350
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 5B8108CC
P 3850 1550
F 0 "R4" V 3930 1550 50  0000 C CNN
F 1 "1k" V 3850 1550 50  0000 C CNN
F 2 "" V 3780 1550 50  0001 C CNN
F 3 "" H 3850 1550 50  0001 C CNN
	1    3850 1550
	0    1    1    0   
$EndComp
Wire Wire Line
	2250 1450 2400 1450
Wire Wire Line
	1800 1450 1950 1450
Wire Wire Line
	2500 700  2350 700 
Wire Wire Line
	2350 700  2350 1450
Connection ~ 2350 1450
Wire Wire Line
	2800 700  3100 700 
Wire Wire Line
	3100 700  3100 1550
Wire Wire Line
	3000 1550 3700 1550
Wire Wire Line
	2200 1050 4450 1050
Wire Wire Line
	2600 1050 2600 1250
Wire Wire Line
	2200 2000 2600 2000
Wire Wire Line
	2600 2000 2600 1850
Wire Wire Line
	4200 3750 5150 3750
Wire Wire Line
	4650 3900 4650 3750
Connection ~ 4650 3750
Wire Wire Line
	4050 2200 4200 2200
Wire Wire Line
	4200 2200 4200 2350
Wire Wire Line
	5000 2200 5150 2200
Wire Wire Line
	5150 2200 5150 2350
Wire Wire Line
	1250 2350 1250 2450
Wire Wire Line
	1100 2350 1250 2350
Wire Wire Line
	2250 2300 2400 2300
Wire Wire Line
	2400 2300 2400 2450
Wire Wire Line
	1250 3850 2400 3850
Wire Wire Line
	1800 3850 1800 3950
Connection ~ 1800 3850
Wire Wire Line
	2400 1650 2300 1650
Wire Wire Line
	2300 1650 2300 1700
Wire Wire Line
	4300 950  4050 950 
Wire Wire Line
	4050 950  4050 1350
Wire Wire Line
	4000 1350 4150 1350
Wire Wire Line
	4600 950  4850 950 
Wire Wire Line
	4850 950  4850 1450
Wire Wire Line
	4750 1450 5200 1450
Wire Wire Line
	5200 1450 5200 1150
Connection ~ 4850 1450
Wire Wire Line
	3700 1350 3550 1350
Connection ~ 4050 1350
Wire Wire Line
	4000 1550 4150 1550
Connection ~ 3100 1550
$Comp
L R R5
U 1 1 5B8109C1
P 4050 1800
F 0 "R5" V 4130 1800 50  0000 C CNN
F 1 "1k" V 4050 1800 50  0000 C CNN
F 2 "" V 3980 1800 50  0001 C CNN
F 3 "" H 4050 1800 50  0001 C CNN
	1    4050 1800
	-1   0    0    1   
$EndComp
Wire Wire Line
	4050 1650 4050 1550
Connection ~ 4050 1550
$Comp
L 0 #GND04
U 1 1 5B810A5E
P 3850 1950
F 0 "#GND04" H 3850 1850 50  0001 C CNN
F 1 "0" H 3850 1880 50  0000 C CNN
F 2 "" H 3850 1950 50  0001 C CNN
F 3 "" H 3850 1950 50  0001 C CNN
	1    3850 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 1950 4050 2000
Wire Wire Line
	4050 2000 3950 2000
Wire Wire Line
	3950 2000 3950 1900
Wire Wire Line
	3950 1900 3850 1900
Wire Wire Line
	3850 1900 3850 1950
Wire Wire Line
	4350 1750 4350 1900
Wire Wire Line
	4350 1900 2600 1900
Connection ~ 2600 1900
Wire Wire Line
	4450 1050 4450 1150
Connection ~ 2600 1050
$EndSCHEMATC
