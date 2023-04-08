#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <stdint.h>

#define NUMBER_OF_MOTORS 3

typedef enum
{
    MOTOR_A = 0,
    MOTOR_B = 1,
    MOTOR_C = 2,
    NONE = 3
} motor_t;

typedef enum
{
    FORWARD_DRIVE,
    REVERSE_DRIVE,
    BRAKE,
    COAST
} motor_drive_t;

typedef enum
{
    FORWARD_LIMIT_SW,
    REVERSE_LIMIT_SW,
    LIMIT_SW_OFF
} limit_switch_t;

typedef struct
{
    uint8_t max_speed;       /* Motor max allowed duty cycle in % */
    uint8_t min_speed;       /* Motor min allowed duty cycle in % */
    uint8_t speed;           /* Motor current duty cycle */
    motor_drive_t drive;     /* Motor current drive status */
    uint16_t current;        /* Motor current */
    limit_switch_t position; /* Limit switches state */
} motor_parameters_t;

/*
 * tbd
 */
void motor_init(void);

/*
 * tbd
 */
void motor_drive(motor_t motorID, motor_drive_t drive, uint8_t speed);

/*
 * tbd
 */
motor_parameters_t *get_motor_state(motor_t motorID);

#endif /* MOTOR_CONTROL_H */
