#include "cel_type_convert.h"

double byte8_to_double(uint8_t *bytes, int offset) 
{
    int64_t temp;
    temp = bytes[offset] | bytes[offset + 1] << 8 | bytes[offset + 2] << 16 | bytes[offset + 3] << 24| bytes[offset + 4] <<32| bytes[offset + 5] << 40| bytes[offset + 6] << 48| bytes[offset + 7] << 56;
    return *(double *)&temp;
}

float byte4_to_float(uint8_t *bytes, int offset) 
{
    int32_t temp;
    temp = bytes[offset] | bytes[offset + 1] << 8 | bytes[offset + 2] << 16 | bytes[offset + 3] << 24;
    return *(float *)&temp;
}

int32_t byte4_to_int(uint8_t *bytes, int offset) 
{
    int result;
    result = bytes[offset] | bytes[offset + 1] << 8 | bytes[offset + 2] << 16 | bytes[offset + 3] << 24;
    return result;
}

int16_t byte2_to_short(uint8_t *bytes, int offset) 
{
    short result;
    result = bytes[offset] | bytes[offset + 1] << 8;
    return result;
}

void float_to_byte4(float value, uint8_t *bytes, int offset) 
{
    uint32_t *temp = (uint32_t *)&value;

    for (int i = 0; i < 4; i++)
    {
        bytes[i] = (*temp >> (i * 8)) & 0xFF;   // little endian
    }
}

void double_to_byte8(double value, uint8_t *bytes, int offset) 
{
    uint64_t *temp = (uint64_t *)&value;

    for (int i = 0; i < 8; i++)
    {
        bytes[i] = (*temp >> (i * 8)) & 0xFF;   // little endian
    }
}

void int_to_byte4(int value, uint8_t *bytes, int offset) 
{
    uint32_t *temp = (uint32_t *)&value;

    for (int i = 0; i < 4; i++)
    {
        bytes[i] = (*temp >> (i * 8)) & 0xFF;   // little endian
    }
}

void short_to_byte2(short value, uint8_t *bytes, int offset) 
{
    uint16_t *temp = (uint16_t *)&value;

    for (int i = 0; i < 2; i++)
    {
        bytes[i] = (*temp >> (i * 8)) & 0xFF;   // little endian
    }
}