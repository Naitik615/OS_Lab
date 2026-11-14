#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t id = fork();

    if (id < 0) {
        printf("Error creating process\n");
        return 1;
    }

    if (id == 0) {
        printf("Child Process\n");
    } else {
        printf("Parent Process\n");
    }

    return 0;
}

