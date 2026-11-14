#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 1; i <= 3; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            printf("Fork failed for child %d\n", i);
            return 1;
        }

        if (pid == 0) {
            printf("Child %d -> PID: %d, PPID: %d\n", i, getpid(), getppid());
            return 0; // Child exits so it doesn't fork further
        }
    }

    // Parent waits for all 3 children
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    printf("Parent process finished waiting for all children.\n");
    return 0;
}

