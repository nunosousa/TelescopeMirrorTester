/*
 * Copyright (c) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Sample echo app for CDC ACM class
 *
 * Sample app for USB CDC ACM class driver. The received data is echoed back
 * to the serial port.
 */

#include "command_parser/command_parser.h"
#include "motor_control/motor_control.h"
#include "position_sensor/position_sensor.h"

void main(void)
{
	command_parser_init();
}
