#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    char write_msg[] = "Hello from Parent process via Pipe!";
    char read_msg[100];

    if (pipe(fd) == -1) {
        perror("pipe error");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork error");
        return 1;
    }

    if (pid > 0) {
        // Parent writes to pipe
        close(fd[0]); // Close unused read end
        write(fd[1], write_msg, strlen(write_msg) + 1);
        close(fd[1]);
        wait(NULL);
    } else {
        // Child reads from pipe
        close(fd[1]); // Close unused write end
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received message: %s\n", read_msg);
        close(fd[0]);
    }

    return 0;
}

