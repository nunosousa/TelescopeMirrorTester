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

void cb_init(circular_buffer *cb, size_t capacity, size_t item_size, void *buffer);
void cb_push(circular_buffer *cb, const void *item);
void cb_undo_push(circular_buffer *cb, void *item);
void cb_pop(circular_buffer *cb, void *item);
