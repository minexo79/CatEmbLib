#include "cel_ringbuf.h"

char ringbuf_init(ringbuf_t * rb, uint32_t size)
{
    if (rb == NULL)
    {
        // return -1 if the buffer is full or no access to the buffer
        return -1;
    }

    rb->buffer = (uint8_t *)malloc(size * sizeof(uint8_t));
    if (rb->buffer == NULL)
    {
        // return -1 if the buffer is full or no access to the buffer
        free(rb);
        return -1;
    }

    rb->head = 0;
    rb->tail = 0;
    rb->size = size;

    // return 0 if the buffer is successfully initialized
    return 0;
}

int ringbuf_put(ringbuf_t *rb, uint8_t *data, uint32_t size)
{
    int put_size = 0;

    // check if the buffer is full (tail - head > size)
    if (rb->tail - rb->head > (int32_t)size)
    {
        return -1;
    }

    for (size_t i = 0 ; i < size; i++)
    {
        // if tail is at the end of the buffer, move it to the beginning (mod rb size)
        rb->buffer[(rb->tail + i) % rb->size] = data[i];
        put_size++;
    }

    // update the tail
    rb->tail = (rb->tail + size) % rb->size;

    // return the number of bytes inserted
    return put_size;
}

int ringbuf_get(ringbuf_t *rb, uint8_t *data, uint32_t size)
{
    int get_size = 0;

    // check if the buffer is empty (head - tail < size)
    if (rb->tail - rb->head < (int32_t)size)
    {
        return -1;
    }

    for (size_t i = 0; i < size; i++)
    {
        // if head is at the end of the buffer, move it to the beginning (mod rb size)
        data[i] = rb->buffer[(rb->head + i) % rb->size];
        get_size++;
    }

    // update the head
    rb->head = (rb->head + size) % rb->size;

    // return the number of bytes extracted
    return get_size;
}

int ringbuf_free(ringbuf_t *rb)
{
    // return the free bytes in the buffer
    return rb->size - (rb->tail - rb->head);
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

void ringbuf_delete(ringbuf_t *rb)
{
    // free the buffer array
    free(rb->buffer);
    // free the ring buffer
    free(rb);
}