/**
 * @file signal_segfault.c
 * @brief Handles SIGSEGV caused by dereferencing a NULL pointer.
 *
 * Modified by: Carla Sastre
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Signal handler for SIGSEGV - prints a message when segmentation fault occurs.
 */
void handle_segfault(int sig) {
    printf("Caught SIGSEGV: Segmentation fault occurred.\n");
    exit(1); // Terminate the program
}

int main() {
    // Register the signal handler for SIGSEGV
    signal(SIGSEGV, handle_segfault);

    // Dereference a NULL pointer to cause a segmentation fault
    printf("Dereferencing a NULL pointer to cause SIGSEGV...\n");
    int *ptr = NULL;
    printf("The value at ptr is: %d\n", *ptr); // This line causes SIGSEGV

    // Program execution will return here after handling SIGSEGV
    printf("Continuing after SIGSEGV...\n");

    return 0;
}
