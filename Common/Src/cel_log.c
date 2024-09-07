#include "cel_log.h"

static int start_t = 0;
static LogLevel max_log_level = LOG_INFO;

#if defined(HASOS)
static double get_timestamp_millseconds(clock_t clock) 
#else
static double get_timestamp_millseconds()
#endif
{
// Windows / Linux
#if defined(HASOS)
	start_t = (start_t == 0) ? clock : start_t;
    return (double)(clock - start_t) / CLOCKS_PER_SEC;
// STM32
#else
    return HAL_GetTick() / 1e3f;	// millis to sec
#endif
}

void log_level_change(LogLevel level)
{
    max_log_level = level;
}

void log_message(LogLevel level, const char *file, int line, const char *message) 
{
    const char *level_str;
#if defined(HASOS)
    clock_t _clock = clock();
#endif

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

#if defined(HASOS)
    double timestamp = get_timestamp_millseconds(_clock);
#else
    double timestamp = get_timestamp_millseconds();
#endif
    printf("%.6f %s\t%s:%d: %s\n", timestamp, level_str, file, line, message);
}
