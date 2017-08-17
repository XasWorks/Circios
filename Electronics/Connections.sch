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
LIBS:CirciosParts
EELAYER 25 0
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
L ArduinoNano MCU1
U 1 1 5995A60A
P 5500 5550
F 0 "MCU1" H 5500 5300 60  0000 C CNN
F 1 "ArduinoNano" H 5500 7000 60  0000 C CNN
F 2 "" H 5500 5550 60  0001 C CNN
F 3 "" H 5500 5550 60  0001 C CNN
	1    5500 5550
	1    0    0    -1  
$EndComp
$Comp
L MotorController M1
U 1 1 5995AEDD
P 5500 2800
F 0 "M1" H 5300 2800 60  0000 C CNN
F 1 "MotorController" H 5500 3625 60  0000 C CNN
F 2 "" H 5450 2800 60  0001 C CNN
F 3 "" H 5450 2800 60  0001 C CNN
	1    5500 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 2100 5050 2100
Wire Wire Line
	4700 2100 4700 4550
Wire Wire Line
	4700 3450 5000 3450
Wire Wire Line
	4700 4550 5000 4550
Connection ~ 4700 3450
Wire Wire Line
	5950 2200 6350 2200
Wire Wire Line
	6350 2200 6350 4550
Wire Wire Line
	6350 2700 5950 2700
Wire Wire Line
	6350 4550 6000 4550
Connection ~ 6350 2700
$Comp
L 5VStepUp U1
U 1 1 5995B843
P 5000 3450
F 0 "U1" H 4850 3950 60  0000 C CNN
F 1 "5VStepUp" H 5000 4075 60  0000 C CNN
F 2 "" H 5000 3450 60  0001 C CNN
F 3 "" H 5000 3450 60  0001 C CNN
	1    5000 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	5000 3350 5000 3150
Wire Wire Line
	5000 3150 6350 3150
Connection ~ 6350 3150
Wire Wire Line
	5000 3550 4900 3550
Wire Wire Line
	4900 3550 4900 2700
Wire Wire Line
	4900 2700 5050 2700
$Comp
L Battery_Cell BT1
U 1 1 5995BBA6
P 3700 2200
F 0 "BT1" H 3800 2300 50  0000 L CNN
F 1 "Battery_Cell" H 3800 2200 50  0000 L CNN
F 2 "" V 3700 2260 50  0001 C CNN
F 3 "" V 3700 2260 50  0001 C CNN
	1    3700 2200
	-1   0    0    1   
$EndComp
Connection ~ 4700 2100
Wire Wire Line
	3700 2400 3900 2400
Wire Wire Line
	3900 2400 3900 2200
Wire Wire Line
	3900 2200 5050 2200
Wire Wire Line
	5950 2100 6500 2100
Wire Wire Line
	6500 2100 6500 4350
Wire Wire Line
	6500 4350 6000 4350
Wire Wire Line
	5950 2300 6850 2300
Text GLabel 6850 2300 2    60   Input ~ 0
MotorAPWM
Text GLabel 6850 2450 2    60   Input ~ 0
MotorADirection
Wire Wire Line
	5950 2400 6750 2400
Wire Wire Line
	6750 2400 6750 2450
Wire Wire Line
	6750 2450 6850 2450
Text GLabel 4400 5400 0    60   Input ~ 0
MotorAPWM
Wire Wire Line
	4400 5400 4850 5400
Text GLabel 4400 5250 0    60   Input ~ 0
MotorADirection
Wire Wire Line
	4400 5250 5000 5250
Text GLabel 4400 5550 0    60   Input ~ 0
MotorBPWM
Text GLabel 4400 5700 0    60   Input ~ 0
MotorBDirection
Wire Wire Line
	4850 5550 4400 5550
Wire Wire Line
	4850 5450 4850 5550
Wire Wire Line
	4850 5450 5000 5450
Wire Wire Line
	4400 5700 4850 5700
Text GLabel 6850 2600 2    60   Input ~ 0
MotorBPWM
Text GLabel 6850 2750 2    60   Input ~ 0
MotorBDirection
Wire Wire Line
	6850 2600 6750 2600
Wire Wire Line
	6750 2600 6750 2500
Wire Wire Line
	6750 2500 5950 2500
Wire Wire Line
	6850 2750 6700 2750
Wire Wire Line
	6700 2750 6700 2600
Wire Wire Line
	6700 2600 5950 2600
Text GLabel 4450 4650 0    60   Input ~ 0
MotorAGreen
Text GLabel 4450 4800 0    60   Input ~ 0
MotorBGreen
Wire Wire Line
	4450 4650 5000 4650
Wire Wire Line
	4450 4800 4850 4800
Wire Wire Line
	4850 4800 4850 4750
Wire Wire Line
	4850 4750 5000 4750
Text GLabel 4450 4950 0    60   Input ~ 0
MotorAYellow
Wire Wire Line
	4450 4950 4850 4950
Wire Wire Line
	4850 4950 4850 4850
Wire Wire Line
	4850 4850 5000 4850
Wire Wire Line
	4850 5400 4850 5350
Wire Wire Line
	4850 5350 5000 5350
Wire Wire Line
	4850 5700 4850 5650
Wire Wire Line
	4850 5650 5000 5650
Text GLabel 4450 5100 0    60   Input ~ 0
MotorBYellow
Wire Wire Line
	4450 5100 4850 5100
Wire Wire Line
	4850 5100 4850 5150
Wire Wire Line
	4850 5150 5000 5150
Text GLabel 4500 2350 0    60   Input ~ 0
MotorARed
Text GLabel 4500 2500 0    60   Input ~ 0
MotorAWhite
Text GLabel 4500 2650 0    60   Input ~ 0
MotorBRed
Text GLabel 4500 2800 0    60   Input ~ 0
MotorBWhite
Wire Wire Line
	4500 2800 4850 2800
Wire Wire Line
	4850 2800 4850 2600
Wire Wire Line
	4850 2600 5050 2600
Wire Wire Line
	4500 2650 4800 2650
Wire Wire Line
	4800 2650 4800 2500
Wire Wire Line
	4800 2500 5050 2500
Wire Wire Line
	4500 2500 4750 2500
Wire Wire Line
	4750 2500 4750 2400
Wire Wire Line
	4750 2400 5050 2400
Wire Wire Line
	4500 2350 4650 2350
Wire Wire Line
	4650 2350 4650 2300
Wire Wire Line
	4650 2300 5050 2300
$EndSCHEMATC
