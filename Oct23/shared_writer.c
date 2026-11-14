#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok(".", 'S');
    if (key == -1) {
        perror("ftok error");
        return 1;
    }

    // Allocate 1024 bytes of shared memory
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget error");
        return 1;
    }

    // Attach to shared memory
    char *str = (char *)shmat(shmid, NULL, 0);
    if (str == (char *)-1) {
        perror("shmat error");
        return 1;
    }

    printf("Enter string to write into shared memory: ");
    if (fgets(str, 1024, stdin) != NULL) {
        printf("Data written to shared memory: %s", str);
    }

    // Detach from shared memory
    shmdt(str);

    printf("Writer detached. Now run shared_reader to view the data.\n");
    return 0;
}

