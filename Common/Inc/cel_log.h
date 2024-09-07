#ifndef CEL_LOG_H_
#define CEL_LOG_H_

#include "cel_common.h"

/**
 * @brief 
 * Log level Enum
 */
typedef enum LogLevel
{
    LOG_ERROR = 0,
    LOG_WARN,
    LOG_INFO,
    LOG_DEBUG,
} LogLevel;

/**
 * @brief 
 * Change The Max Log level Be Printout
 * @param level The log level
 */
void log_level_change(LogLevel level);

/**
 * @brief 
 * Log message with level, file, line and message
 * @param level The log level
 * @param file The file name, if full assert is enabled, this will be __FILE__.
 * @param line The line number, if full assert is enabled, this will be __LINE__.
 * @param message The log message
 */
void log_message(LogLevel level, const char *file, int line, const char *message);

#define LOG(level, message) log_message(level, __FILE__, __LINE__, message)

#endif /* LOG_H_ */
