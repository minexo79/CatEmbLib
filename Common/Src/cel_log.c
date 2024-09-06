#include "cel_log.h"

static uint32_t get_timestamp_millseconds() 
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    return 0;
#elif (defined(__unix__) || defined(__unix))
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (uint64_t)ts.tv_sec * 1000000000 + ts.tv_nsec;
#else
    return HAL_GetTick() * 1000;
#endif
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
    printf("%0.3f %s\t%s:%d: %s\n", timestamp / 1000.0, level_str, file, line, message);
}