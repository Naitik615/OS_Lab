#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork error\n");
        return 1;
    }

    if (pid == 0) {
        printf("Child process (PID: %d) opening sample.txt...\n", getpid());
        int fd = open("sample.txt", O_RDONLY);
        if (fd < 0) {
            perror("Child failed to open file");
            return 1;
        }

        char buf[128];
        int bytes = read(fd, buf, sizeof(buf) - 1);
        if (bytes > 0) {
            buf[bytes] = '\0';
            printf("Child read from file: %s\n", buf);
        }
        close(fd);
    } else {
        wait(NULL);
        printf("Parent: Child finished reading.\n");
    }

    return 0;
}

