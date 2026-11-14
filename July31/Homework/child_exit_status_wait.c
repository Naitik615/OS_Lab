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
        printf("Child process executing (PID: %d), exiting with status 10...\n", getpid());
        exit(10);
    } else {
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Parent: Child exited normally with status code = %d\n", WEXITSTATUS(status));
        } else {
            printf("Parent: Child terminated abnormally\n");
        }
    }

    return 0;
}

