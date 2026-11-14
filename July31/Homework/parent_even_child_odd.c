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
        printf("Child process (Odd numbers from 1 to 20):\n");
        for (int i = 1; i <= 20; i += 2) {
            printf("%d ", i);
        }
        printf("\n");
    } else {
        wait(NULL);
        printf("Parent process (Even numbers from 1 to 20):\n");
        for (int i = 2; i <= 20; i += 2) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}

