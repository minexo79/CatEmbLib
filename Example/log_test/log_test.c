#include "cel_common.h"
#include "cel_log.h"

int main(void)
{
    log_level_change(LOG_DEBUG);

    LOG(LOG_INFO, "This is Info Message!");
    LOG(LOG_WARN, "This is Warning Message!");
    LOG(LOG_ERROR, "This is Error Message!");
    LOG(LOG_DEBUG, "This is Debug Message!");

    return 0;
}