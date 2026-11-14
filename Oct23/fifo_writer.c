#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

int main() {
    char *myfifo = "myfifo";

    if (mkfifo(myfifo, 0666) == -1 && errno != EEXIST) {
        perror("mkfifo");
        return 1;
    }

    printf("FIFO Writer: Opening FIFO for write...\n");
    int fd = open(myfifo, O_WRONLY);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    char message[100];
    printf("Enter text to send: ");
    if (fgets(message, sizeof(message), stdin) != NULL) {
        write(fd, message, strlen(message) + 1);
        printf("Sent: %s", message);
    }

    close(fd);
    return 0;
}

