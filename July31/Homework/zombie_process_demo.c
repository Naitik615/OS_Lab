#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        // Child terminates immediately
        printf("Child process (PID: %d) terminating immediately.\n", getpid());
        exit(0);
    } else {
        // Parent does not call wait() and sleeps
        printf("Parent process (PID: %d) sleeping for 10 seconds. Check ps command for zombie child (defunct).\n", getpid());
        sleep(10);
        wait(NULL); // Reaps zombie child
        printf("Parent reaped child and is now exiting.\n");
    }

    return 0;
}

