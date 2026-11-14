#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("[Child] Started. PID: %d, Initial PPID: %d\n", getpid(), getppid());
        sleep(2); // Wait for parent to terminate
        printf("[Child] After parent died. PID: %d, New PPID: %d\n", getpid(), getppid());
    } else {
        // Parent process terminates immediately
        printf("[Parent] PID: %d exiting now...\n", getpid());
        exit(0);
    }

    return 0;
}

