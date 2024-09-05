#ifndef CEL_TYPE_CONVERT_H_
#define CEL_TYPE_CONVERT_H_

#include "cel_common.h"

/**
 * @brief 
 * Convert 8 bytes to double
 * @param bytes the pointer to the first byte
 * @param offset the offset
 * @return double 
 */
double byte8_to_double(uint8_t *, int);

/**
 * @brief 
 * Convert 4 bytes to float
 * @param uint8_t * the pointer to the first byte
 * @param int the offset
 * @return float
 */
float byte4_to_float(uint8_t *, int);

/**
 * @brief 
 * Convert 4 bytes to int
 * @param uint8_t * the pointer to the first byte
 * @param int the offset
 * @return float
 */
int32_t byte4_to_int(uint8_t *, int);

/**
 * @brief 
 * Convert 2 bytes to short
 * @param uint8_t * the pointer to the first byte
 * @param int the offset
 * @return float
 */
int16_t byte2_to_short(uint8_t *, int);

/**
 * @brief 
 * Convert double to 8 bytes
 * @param value the double number
 * @param bytes the pointer to the first byte
 * @param offset the offset
 * @return void
 */
void double_to_byte8(double, uint8_t *, int);

/**
 * @brief 
 * Convert float to 4 bytes
 * @param float the float number
 * @param uint8_t * the pointer to the first byte
 * @param int the offset
 * @return void
 */
void float_to_byte4(float, uint8_t *, int);

/**
 * @brief 
 * Convert int to 4 bytes
 * @param int the int number
 * @param uint8_t * the pointer to the first byte
 * @param int the offset
 * @return void
 */
void int_to_byte4(int, uint8_t *, int);

/**
 * @brief 
 * Convert short to 2 bytes
 * @param int the int number
 * @param uint8_t * the pointer to the first byte
 * @param int the offset
 * @return void
 */
void short_to_byte2(short, uint8_t *, int);

#endif /* CEL_TYPE_CONVERT_H_ */