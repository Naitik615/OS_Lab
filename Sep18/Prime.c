#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int checkPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int arr[] = {4, 7, 10, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int fd[2];

    if (pipe(fd) == -1) {
        printf("Pipe failed\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid > 0) {
        // Parent process calculates sum and sends via pipe
        close(fd[0]);
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += arr[i];
        }
        printf("Parent: Array sum calculated = %d. Sending to child...\n", total);
        write(fd[1], &total, sizeof(total));
        close(fd[1]);

        wait(NULL);
    } else {
        // Child process reads sum from pipe and checks prime
        close(fd[1]);
        int received_sum;
        read(fd[0], &received_sum, sizeof(received_sum));
        close(fd[0]);

        printf("Child: Received sum = %d\n", received_sum);
        if (checkPrime(received_sum)) {
            printf("Child: %d is a Prime number\n", received_sum);
        } else {
            printf("Child: %d is NOT a Prime number\n", received_sum);
        }
    }

    return 0;
}

