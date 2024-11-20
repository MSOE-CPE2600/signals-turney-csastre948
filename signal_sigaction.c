/**
 * @file signal_sigaction.c
 * @brief Uses sigaction to handle SIGUSR1 and print the sender's process ID.
 *
 * Modified by: Carla Sastre
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Signal handler for SIGUSR1. Prints the sender's process ID.
 */
void handle_sigusr1(int sig, siginfo_t *info, void *context) {
    printf("Received SIGUSR1 from process %d\n", info->si_pid);
}

int main() {
    struct sigaction sa;

    // Zero out the sigaction struct
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO; // Use SA_SIGINFO to get extended signal information
    sa.sa_sigaction = handle_sigusr1;

    // Register the signal handler for SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("SIGUSR1 handler registered. Process ID: %d\n", getpid());
    printf("Waiting for SIGUSR1...\n");

    // Wait indefinitely for signals
    while (1) {
        pause(); // Suspend until a signal is received
    }

    return 0;
}



