
#ifndef PINS_H
#define PINS_H

// Motor input register: PORTD (Due to INT0/INT1)
#define MOTOR_A_C1	PD2
#define MOTOR_A_C2	PD4
#define MOTOR_B_C1	PD3
#define MOTOR_B_C2	PD7

// Motor control register: PORTB (Mainly due to OC1A and OC1B being there)
#define MOTOR_A_DIR	PB0
#define MOTOR_A_PWM	PB1
#define MOTOR_B_DIR	PB4
#define MOTOR_B_PWM	PB2

#define UPDATE_FREQUENCY 200

#define TOOTH_PER_WHEEL 13
#define TOOTH_PER_LINE 	25
#define TOOTH_PER_TURN	18

#define TICKS_PER_REV	412.5
#define TICKS_PER_TOOTH	TICKS_PER_REV/TOOTH_PER_WHEEL

#define TICKS_PER_LINE TICKS_PER_TOOTH*TOOTH_PER_LINE
#define TICKS_PER_TURN TICKS_PER_TOOTH*TOOTH_PER_TURN

#endif
