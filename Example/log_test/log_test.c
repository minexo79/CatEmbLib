#include "cel_common.h"
#include "cel_log.h"

int main(void)
{
    log_message(LOG_INFO, __FILE__, __LINE__, "Hello, World!");
    log_message(LOG_WARN, __FILE__, __LINE__, "Hello, World!");
    log_message(LOG_ERROR, __FILE__, __LINE__, "Hello, World!");
    log_message(LOG_DEBUG, __FILE__, __LINE__, "Hello, World!");

    return 0;
}