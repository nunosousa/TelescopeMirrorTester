/*! @file cli.h
 * @brief Command-line interface API definitions.
 */

/*!
 * @defgroup CLI API
 */
#ifndef CLI_H
#define CLI_H

#include <stddef.h>
#include <stdint.h>

#define CMD_TOKEN_DELIMITERS " \r\n" /* cli token separator characters */
#define MAXIMUM_TOKEN_SIZE 20        /* maximum individual token size */

typedef enum
{
    CLI_OK,              /* API execution successful.                */
    CLI_E_CMD_NOT_FOUND, /* Command name not found in command table. */
    CLI_E_INVALID_ARGS,  /* Invalid function parameters/arguments.   */
    CLI_E_BUF_FULL,      /* CLI buffer full.                         */
    CLI_IDLE             /* No command to execute at the moment      */
} cli_status_t;

/*!
 * @brief Function type declaration.
 */
typedef cli_status_t (*cmd_func_ptr_t)(int argc, char **argv);

/*!
 * @brief Command structure, consisting of a name and function pointer.
 */
typedef struct
{
    char *cmd;           /* Command name.                            */
    cmd_func_ptr_t func; /* Function pointer to associated function. */
} cmd_t;

/*!
 * @brief Command-line interface handle structure.
 */
typedef struct
{
    cmd_t *cmd_tbl;  /* Pointer to series of commands which are to be accepted. */
    uint8_t cmd_cnt; /* Number of commands in cmd_tbl.                          */
} cli_t;

/*!
 * @brief This API initialises the command-line interface.
 *
 * @param[in] cli : Pointer to cli handle struct.
 *
 * @return cli_status_t
 */
cli_status_t cli_init(void);

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
