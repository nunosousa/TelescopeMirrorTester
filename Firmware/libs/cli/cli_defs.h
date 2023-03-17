#ifndef CLI_DEFS_H
#define CLI_DEFS_H

#include <stddef.h>

#define MAX_BUF_SIZE 40    /* Maximum size of CLI Rx buffer */

typedef enum
{
    CLI_OK,         /* API execution successful.                */
    CLI_E_NULL_PTR, /* Null pointer error.                      */
    CLI_E_IO,
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
    cmd_t *cmd_tbl;             /* Pointer to series of commands which are to be accepted. */
    size_t cmd_cnt;             /* Number of commands in cmd_tbl.                          */
} cli_t;

#endif
