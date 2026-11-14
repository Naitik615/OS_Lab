#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t p = fork();

    if (p < 0) {
        printf("Fork failed!\n");
        return 1;
    }

    if (p == 0) {
        printf("[Child Process]\n");
        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
    } else {
        printf("[Parent Process]\n");
        printf("Parent PID: %d, Child PID: %d\n", getpid(), p);
    }

    return 0;
}

