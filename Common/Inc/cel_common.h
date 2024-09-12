/**
 * @file cel_common.h
 * @author blackcat
 * @brief Common Marco Library
 * @version 0.1
 * @date 2024-09-12
 * 
 * Reference: 
 * https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Arduino.h
 */

#ifndef CEL_COMMON_H_
#define CEL_COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(__unix__) || defined(__unix)
#define HASOS
#endif

// Windows / Linux
#if defined(HASOS)
#include <time.h>
// STM32
#else
#include "main.h"
#endif

/**
 * ==================== Boolean ==================== 
 */

#define TRUE    0x1
#define FALSE   0x0

/**
 * ==================== Bit Operator ==================== 
 */

#define HIGH    0x1
#define LOW     0x0
#define INPUT   0x0
#define OUTPUT  0x1
#define INPUT_PULLUP 0x2

#define bit_read(value, bit)     (((value) >> (bit)) & 0x01)
#define bit_set(value, bit)      ((value) |= (1UL << (bit)))
#define bit_clear(value, bit)    ((value) &= ~(1UL << (bit)))
#define bit_toggle(value, bit)   ((value) ^= (1UL << (bit)))

/**
 * ==================== Math ==================== 
 */

#define PI          3.1415926535897932384626433832795
#define HALF_PI     1.5707963267948966192313216916398
#define TWO_PI      6.283185307179586476925286766559
#define DEG_TO_RAD  0.017453292519943295769236907684886
#define RAD_TO_DEG  57.295779513082320876798154814105
#define EULER       2.718281828459045235360287471352

#define min(a,b)        ((a)<(b)?(a):(b))
#define max(a,b)        ((a)>(b)?(a):(b))
#define abs(x)          ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)        ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg)    ((deg)*DEG_TO_RAD)
#define degrees(rad)    ((rad)*RAD_TO_DEG)
#define sq(x)           ((x)*(x))

/**
 * ==================== Get Array Size ==================== 
 */

#define array_size(x) (sizeof(x) / sizeof((x)[0]))

#endif /* CEL_COMMON_H_ */
