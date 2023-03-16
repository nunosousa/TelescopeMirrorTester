#include "cbuffer.h"

#include <stddef.h>
#include <string.h>

/*
 * Successive calls to uart_getchar() will be satisfied from the
 * internal buffer until that buffer is emptied.
 */
void cb_init(cbuffer *cb, size_t capacity, size_t item_size, void *buffer)
{
    cb->buffer = buffer;
    if (cb->buffer == NULL)
        // handle error
        cb->buffer_end = (char *)cb->buffer + capacity * item_size;
    cb->capacity = capacity;
    cb->count = 0;
    cb->item_size = item_size;
    cb->head = cb->buffer;
    cb->tail = cb->buffer;
}

/*
 * Successive calls to uart_getchar() will be satisfied from the
 * internal buffer until that buffer is emptied.
 */
void cb_push(cbuffer *cb, const void *item)
{
    if (cb->count == cb->capacity)
    {
        // handle error
    }
    memcpy(cb->head, item, cb->item_size);
    cb->head = (char *)cb->head + cb->item_size;
    if (cb->head == cb->buffer_end)
        cb->head = cb->buffer;
    cb->count++;
}

/*
 * Successive calls to uart_getchar() will be satisfied from the
 * internal buffer until that buffer is emptied.
 */
void cb_undo_push(cbuffer *cb, void *item)
{
    if (cb->count == 0)
    {
        // handle error
    }
    cb->head = (char *)cb->head - cb->item_size;
    if (cb->head == cb->buffer)
        cb->head = cb->buffer_end;
    memcpy(item, cb->head, cb->item_size);
    cb->count--;
}

/*
 * Successive calls to uart_getchar() will be satisfied from the
 * internal buffer until that buffer is emptied.
 */
void cb_pop(cbuffer *cb, void *item)
{
    if (cb->count == 0)
    {
        // handle error
    }
    memcpy(item, cb->tail, cb->item_size);
    cb->tail = (char *)cb->tail + cb->item_size;
    if (cb->tail == cb->buffer_end)
        cb->tail = cb->buffer;
    cb->count--;
}

/*
 * Successive calls to uart_getchar() will be satisfied from the
 * internal buffer until that buffer is emptied.
 */
size_t cb_count(cbuffer *cb)
{
    return cb->count;
}