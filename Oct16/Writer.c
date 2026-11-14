#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

int main() {
    char *fifo_path = "myfifo";

    // Create named pipe if it doesn't already exist
    if (mkfifo(fifo_path, 0666) == -1 && errno != EEXIST) {
        perror("mkfifo error");
        return 1;
    }

    printf("Opening FIFO for writing (waiting for reader)...\n");
    int fd = open(fifo_path, O_WRONLY);
    if (fd == -1) {
        perror("open error");
        return 1;
    }

    char msg[128];
    printf("Enter message to send: ");
    if (fgets(msg, sizeof(msg), stdin) != NULL) {
        write(fd, msg, strlen(msg) + 1);
        printf("Message sent successfully.\n");
    }

    close(fd);
    return 0;
}

