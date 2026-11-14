#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Demonstrating Zombie and Orphan processes\n");

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        printf("Child process (PID: %d, PPID: %d)\n", getpid(), getppid());
        printf("Child sleeping for 4 seconds to observe orphan state after parent terminates...\n");
        sleep(4);
        printf("Child woke up! New PPID (adopted): %d\n", getppid());
    } else {
        printf("Parent process (PID: %d). Exiting now to make child an orphan...\n", getpid());
        exit(0);
    }

    return 0;
}

