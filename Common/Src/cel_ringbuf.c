#include "cel_ringbuf.h"

char ringbuf_init(ringbuf_t * rb, uint32_t size)
{
    if (rb == NULL)
    {
        // return -1 if the buffer is full or no access to the buffer
        return -1;
    }

    rb->buffer = (uint8_t *)malloc(size + 1 * sizeof(uint8_t));
    if (rb->buffer == NULL)
    {
        // return -1 if the buffer is full or no access to the buffer
        return -1;
    }

    rb->head = 0;
    rb->tail = 0;
    rb->size = size + 1; // add 1 to the size to distinguish between full and empty

    // return 0 if the buffer is successfully initialized
    return 0;
}


int ringbuf_put(ringbuf_t *rb, uint8_t *data)
{
    // check if the buffer is full (tail - head > size)
    if (ringbuf_is_full(rb))
    {
        return -1;
    }

    rb->tail = (rb->tail + 1) % rb->size;
    rb->buffer[rb->tail] = *data;

    // return 0 if the data is inserted
    return 0;
}

int ringbuf_put_array(ringbuf_t *rb, uint8_t *data, uint32_t size)
{
    uint32_t put_size = 0;
    
    for (size_t i = 0; i < size; i++) 
    {
        if (ringbuf_put(rb, &data[i]) < 0)
            break;

        put_size++;
    }
    
    return put_size;
}

int ringbuf_get(ringbuf_t *rb, uint8_t *data)
{
    // check if the buffer is empty (head - tail < size)
    if (ringbuf_is_empty(rb))
    {
        return -1;
    }

    // update the head
    rb->head = (rb->head + 1) % rb->size;
    *data = rb->buffer[rb->head];

    // return 0 if the data is extracted
    return 0;
}

int ringbuf_get_array(ringbuf_t *rb, uint8_t *data, uint32_t size)
{
    uint32_t get_size = 0;

    for (size_t i = 0; i < size; i++) 
    {
        if (ringbuf_get(rb, &data[i]) < 0)
            break;

        get_size++;
    }
    
    return get_size;
}

int ringbuf_free(ringbuf_t *rb)
{
    // return the free bytes in the buffer
    return (rb->tail + rb->size - rb->head) % rb->size;
}

void ringbuf_flush(ringbuf_t *rb)
{
    // reset the head and tail
    rb->head = 0;
    rb->tail = 0;
}

void ringbuf_peek(ringbuf_t *rb, uint8_t *data, uint32_t idx)
{
    *data = rb->buffer[(rb->head + idx) % rb->size];
}

char ringbuf_is_empty(ringbuf_t * rb) 
{
    return (rb->tail == rb->head);
}

char ringbuf_is_full(ringbuf_t * rb) 
{
    return (((rb->tail + 1) % rb->size) == rb->head);
}