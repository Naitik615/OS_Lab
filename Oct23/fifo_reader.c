#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    char *myfifo = "myfifo";

    printf("FIFO Reader: Opening FIFO for reading...\n");
    int fd = open(myfifo, O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    char buffer[100];
    int bytes = read(fd, buffer, sizeof(buffer));
    if (bytes > 0) {
        printf("FIFO Reader received: %s", buffer);
    }

    close(fd);
    unlink(myfifo); // Clean up the named pipe
    return 0;
}

