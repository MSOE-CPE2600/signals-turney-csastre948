/**
 * @file send_signal.c
 * @brief Sends SIGUSR1 signals with random integer values to a target process.
 *
 * Modified by: Carla Sastre
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t target_pid = atoi(argv[1]); // Convert the argument to a PID

    // Seed the random number generator
    srand(time(NULL));
    int random_value = rand() % 100; // Generate a random integer between 0 and 99

    // Create a sigval structure to hold the data
    union sigval value;
    value.sival_int = random_value;

    // Send the signal with the attached data
    if (sigqueue(target_pid, SIGUSR1, value) == -1) {
        perror("sigqueue");
        exit(EXIT_FAILURE);
    }

    printf("Sent SIGUSR1 with value: %d to process %d\n", random_value, target_pid);

    return 0;
}

