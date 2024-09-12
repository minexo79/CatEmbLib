#include <stdio.h>
#include <stdlib.h>

#include "cel_ringbuf.h"

ringbuf_t ringbuf;

uint8_t put_data[] = "CatEmbLib!!";

void print_buffer(ringbuf_t *rb)
{
    printf("----------------------\n");
    printf("Ring buffer head: %d\n", rb->head);             // head
    printf("Ring buffer tail: %d\n", rb->tail);             // tail
    printf("Ring buffer free: %d\n", ringbuf_free(rb));     // free size
    printf("----------------------\n");
}

void put(uint8_t * data)
{
    ringbuf_put(&ringbuf, data, sizeof(data) - 1);
    printf("Put data: %s\n", data);
}

void get()
{
    uint8_t get_data[6] = {0};

    ringbuf_get(&ringbuf, get_data, sizeof(get_data) - 1);
    printf("Get data: %s\n", get_data);
}   

int main (void)
{
    // initialize the ring buffer
    ringbuf_init(&ringbuf, 24);

    // put data into the ring buffer
    put(put_data);
    put(put_data);
    print_buffer(&ringbuf);

    // get data from the ring buffer
    get();
    get();
    get();
    print_buffer(&ringbuf);

    // put data into the ring buffer
    put(put_data);
    put(put_data);
    put(put_data);
    print_buffer(&ringbuf);

    // get data from the ring buffer
    get();
    get();
    print_buffer(&ringbuf);

    // flush the ring buffer
    ringbuf_flush(&ringbuf);
    printf("Flush the ring buffer\n");
    print_buffer(&ringbuf);

    return 0;
}