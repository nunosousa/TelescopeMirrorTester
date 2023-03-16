#ifndef CBUFFER_H
#define CBUFFER_H

#include <stddef.h>

struct circular_buffer
{
    void *buffer;     // data buffer
    void *buffer_end; // end of data buffer
    size_t capacity;  // maximum number of items in the buffer
    size_t count;     // number of items in the buffer
    size_t item_size; // size of each item in the buffer
    void *head;       // pointer to head
    void *tail;       // pointer to tail
};
typedef struct circular_buffer cbuffer;

void cb_init(cbuffer *cb, size_t capacity, size_t item_size, void *buffer);
void cb_push(cbuffer *cb, const void *item);
void cb_undo_push(cbuffer *cb, void *item);
void cb_pop(cbuffer *cb, void *item);
size_t cb_count(cbuffer *cb);

#endif /* CBUFFER_H */
