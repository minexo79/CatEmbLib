#include "cel_log.h"

static int start_t = 0;
static LogLevel max_log_level = LOG_INFO;

static double get_timestamp_millseconds(clock_t clock) 
{
// Windows / Linux
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(__unix__) || defined(__unix)
    start_t = (start_t == 0) ? clock : start_t;
    return (double)(clock - start_t) / CLOCKS_PER_SEC;
// STM32
#else
    return HAL_GetTick() / 1000;
#endif
}

void log_level_change(LogLevel level)
{
    max_log_level = level;
}

void log_message(LogLevel level, const char *file, int line, const char *message) 
{
    const char *level_str;
    clock_t _clock = clock();

    if (level > max_log_level)
        return;

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

    double timestamp = get_timestamp_millseconds(_clock);
    printf("%.6f %s\t%s:%d: %s\n", timestamp, level_str, file, line, message);
}