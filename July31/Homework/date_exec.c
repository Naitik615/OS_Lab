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
        printf("Child process executing 'date' command via execlp():\n");
        execlp("date", "date", NULL);
        // If execlp fails
        perror("execlp failed");
        return 1;
    } else {
        wait(NULL);
        printf("Parent process: Child finished executing date command.\n");
    }

    return 0;
}

