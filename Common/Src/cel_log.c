#include "cel_log.h"

static uint64_t get_timestamp_millseconds() 
{
    return HAL_GetTick() * 1000;
}

void log_message(LogLevel level, const char *file, int line, const char *message) 
{
    const char *level_str;

    switch (level) 
    {
        case LOG_INFO:
            level_str = "INFO";
            break;
        case LOG_WARN:
            level_str = "WARN";
            break;
        case LOG_ERROR:
            level_str = "ERROR";
            break;
        case LOG_DEBUG:
            level_str = "DEBUG";
            break;
        default:
            level_str = "UNKNOWN";
            break;
    }

    uint64_t timestamp = get_timestamp_millseconds();
    printf("%0.3f %s %s:%d: %s\n", timestamp / 1000.0, level_str, file, line, message);
}