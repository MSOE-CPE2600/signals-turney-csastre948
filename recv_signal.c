/**
 * @file recv_signal.c
 * @brief Receives SIGUSR1 signals with data and prints the received value.
 *
 * Modified by: Carla Sastre
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Signal handler for SIGUSR1. Prints the received data.
 */
void handle_sigusr1(int sig, siginfo_t *info, void *context) {
    printf("Received SIGUSR1 with value: %d from process %d\n", info->si_value.sival_int, info->si_pid);
}

int main() {
    struct sigaction sa;

    // Set up the sigaction structure
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO; // Use SA_SIGINFO to get extended information
    sa.sa_sigaction = handle_sigusr1;

    // Register the signal handler for SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for SIGUSR1... (PID: %d)\n", getpid());

    // Infinite loop to wait for signals
    while (1) {
        pause(); // Suspend execution until a signal is received
    }

    return 0;
}
