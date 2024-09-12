/**
 * @file cel_ringbuf.h
 * @author blackcat
 * @brief Ring buffer Library
 * @version 0.1
 * @date 2024-09-12
 * 
 * Reference: 
 * https://hackmd.io/@sysprog/concurrency-ringbuffer
 * https://github.com/AndersKaloer/Ring-Buffer/blob/master/ringbuffer.c
 * https://hackmd.io/@Aquamay/S1eTd_LcO#%E9%99%A3%E5%88%97%E6%A8%A1%E6%93%AC%E7%92%B0%E5%BD%A2%E4%BD%87%E5%88%97
 * https://leetcode.com/problems/design-circular-queue
 */

#ifndef CEL_RINGBUF_H
#define CEL_RINGBUF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/**
 * @brief Ring buffer structure
 * 
 */
typedef struct ringbuf {
    uint8_t *buffer;            // Pointer to the buffer
    uint32_t head;              // Head of the buffer
    uint32_t tail;              // Tail of the buffer
    uint32_t size;              // The buffer Total size
} ringbuf_t;

/**
 * @brief Initialize the ring buffer
 * 
 * @param rb the ring buffer
 * @param size the size of the buffer
 * @return char 0 if the buffer is successfully initialized, -1 if the buffer is full or no access to the buffer
 */
char ringbuf_init(ringbuf_t * rb, uint32_t size);

/**
 * @brief insert data into the ring buffer 
 * 
 * @param rb the ring buffer
 * @param data the data to be inserted
 * @param size the size of the data to be inserted
 * @return int the number of bytes inserted, -1 if the buffer is full or no access to the buffer
 */
int ringbuf_put(ringbuf_t *rb, uint8_t *data, uint32_t size);

/**
 * @brief extracted data from the ring buffer
 * 
 * @param rb the ring buffer
 * @param data the data to be inserted
 * @param size the size of the data to be extracted
 * @return int the number of bytes inserted, -1 if the buffer is empty or no access to the buffer
 */
int ringbuf_get(ringbuf_t *rb, uint8_t *data, uint32_t size);

/**
 * @brief peek one data from the ring buffer
 * 
 * @param rb the ring buffer
 * @param data the data to be inserted
 * @param idx the index of the data to be peeked
 */
void ringbuf_peek(ringbuf_t *rb, uint8_t *data, uint32_t idx);

/**
 * @brief get the free bytes in the buffer
 * 
 * @param rb the ring buffer
 * @return int the free bytes in the buffer
 */
int ringbuf_free(ringbuf_t *rb);

/**
 * @brief flush the ring buffer
 * 
 * @param rb the ring buffer
 */
void ringbuf_flush(ringbuf_t *rb);

/**
 * @brief Check if the ring buffer is empty
 * 
 * @param rb the ring buffer
 * @return char 1 if the buffer is empty, 0 if the buffer is not empty
 */
char ringbuf_is_empty(ringbuf_t * rb);

/**
 * @brief Check if the ring buffer is full
 * 
 * @param rb the ring buffer
 * @return char 1 if the buffer is full, 0 if the buffer is not full
 */
char ringbuf_is_full(ringbuf_t * rb);

#endif /* CEL_RINGBUF_H */