typedef struct circular_buffer
{
    void *buffer;     // data buffer
    void *buffer_end; // end of data buffer
    size_t capacity;  // maximum number of items in the buffer
    size_t count;     // number of items in the buffer
    size_t item_size; // size of each item in the buffer
    void *head;       // pointer to head
    void *tail;       // pointer to tail
} circular_buffer;

void cb_init(circular_buffer *cb, size_t capacity, size_t item_size, void *buffer)
{
    cb->buffer = buffer;
    if(cb->buffer == NULL)
        // handle error
    cb->buffer_end = (char *)cb->buffer + capacity * item_size;
    cb->capacity = capacity;
    cb->count = 0;
    cb->item_size = item_size;
    cb->head = cb->buffer;
    cb->tail = cb->buffer;
}

void cb_push(circular_buffer *cb, const void *item)
{
    if(cb->count == cb->capacity){
        // handle error
    }
    memcpy(cb->head, item, cb->item_size);
    cb->head = (char*)cb->head + cb->item_size;
    if(cb->head == cb->buffer_end)
        cb->head = cb->buffer;
    cb->count++;
}

void cb_undo_push(circular_buffer *cb, void *item);
{
    if(cb->count == 0){
        // handle error
    }
    cb->head = (char*)cb->head - cb->item_size;
    if(cb->head == cb->buffer)
        cb->head = cb->buffer_end;
    memcpy(item, cb->head, cb->item_size);
    cb->count--;
}

void cb_pop(circular_buffer *cb, void *item)
{
    if(cb->count == 0){
        // handle error
    }
    memcpy(item, cb->tail, cb->item_size);
    cb->tail = (char*)cb->tail + cb->item_size;
    if(cb->tail == cb->buffer_end)
        cb->tail = cb->buffer;
    cb->count--;
}
