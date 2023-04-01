#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "../cli/cli.h"

typedef enum
{
    MOTOR_A,
    MOTOR_B,
    MOTOR_C
} motor_t;

typedef enum
{
    FORWARD_DRIVE,
    REVERSE_DRIVE,
    BRAKE,
    COAST
} motor_drive_t;

void motor_init(void);

// setMaxSpeed {A, B, C}motorID (int)maxSpeed
cli_status_t setMaxSpeed_func(int argc, char **argv);

// getMaxSpeed {A, B, C}motorID
cli_status_t getMaxSpeed_func(int argc, char **argv);

// setMinSpeed {A, B, C}motorID (int)minSpeed
cli_status_t setMinSpeed_func(int argc, char **argv);

// getMinSpeed {A, B, C}motorID
cli_status_t getMinSpeed_func(int argc, char **argv);

// setAcc {A, B, C}motorID (int)acc
cli_status_t setAcc_func(int argc, char **argv);

// getAcc {A, B, C}motorID
cli_status_t getAcc_func(int argc, char **argv);

// setDec {A, B, C}motorID (int)dec
cli_status_t setDec_func(int argc, char **argv);

// getDec {A, B, C}motorID
cli_status_t getDec_func(int argc, char **argv);

// setSpeed {A, B, C}motorID (int)speed
cli_status_t setSpeed_func(int argc, char **argv);

// getSpeed {A, B, C}motorID
cli_status_t getSpeed_func(int argc, char **argv);

// getLimitSw {A, B, C}motorID
cli_status_t getLimitSw_func(int argc, char **argv);

// limitSw {A, B, C}motorID (bool)swState (bool)direction
cli_status_t limitSw_func(int argc, char **argv);

#endif /* MOTOR_CONTROL_H */
