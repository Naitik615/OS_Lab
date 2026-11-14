#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok(".", 'S');
    if (key == -1) {
        perror("ftok error");
        return 1;
    }

    int shmid = shmget(key, 1024, 0666);
    if (shmid == -1) {
        perror("shmget error");
        return 1;
    }

    // Attach to shared memory (read-only)
    char *str = (char *)shmat(shmid, NULL, SHM_RDONLY);
    if (str == (char *)-1) {
        perror("shmat error");
        return 1;
    }

    printf("Reader: Data read from shared memory:\n%s", str);

    // Detach
    shmdt(str);

    // Destroy the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);
    printf("Shared memory segment cleaned up successfully.\n");
    return 0;
}

