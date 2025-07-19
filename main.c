#include "logger.h"

int main(void) {
    logger_start();
    logger_log("Starting Operating System Simulator");
    logger_log("Stopping Operating System Simulator");
    logger_stop();
}
