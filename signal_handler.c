/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and continues execution.
 *
 * Modified by: Your Name
 * 
 * Brief summary of modifications:
 * - The program no longer exits when SIGINT is received.
 * - The signal handler only prints a message, allowing the program to continue.
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and continues execution
 */
void handle_signal() {
    printf("Received a signal\n");
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while (1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}
