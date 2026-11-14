#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        printf("Child process printing numbers:\n");
        for (int i = 1; i <= 5; i++) {
            printf("%d ", i);
        }
        printf("\nChild finished execution.\n");
    } else {
        wait(NULL);
        printf("Parent process: Child has finished, exiting now.\n");
    }

    return 0;
}

