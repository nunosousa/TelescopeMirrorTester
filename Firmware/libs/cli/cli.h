/*
 * MIT License
 *
 * Copyright (c) 2019 Sean Farrelly
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * File        cli.h
 * Created by  Sean Farrelly
 * Version     1.0
 *
 */

/*! @file cli.h
 * @brief Command-line interface API definitions.
 */

/*!
 * @defgroup CLI API
 */
#ifndef CLI_H
#define CLI_H

#include "cli_defs.h"

/*!
 * @brief This API initialises the command-line interface.
 *
 * @param[in] cli : Pointer to cli handle struct.
 *
 * @return cli_status_t
 */
cli_status_t cli_init(cli_t *cli);

/*!
 * @brief This API must be periodically called by the user to process and execute
 *        any commands received.
 *
 * @param[in] cli : Pointer to cli handle struct.
 *
 * @return cli_status_t
 */
cli_status_t cli_process(cli_t *cli);

#endif /* CLI_H */
