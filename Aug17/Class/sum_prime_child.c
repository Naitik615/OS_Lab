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
    int arr[] = {3, 5, 7, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        int sum = 0;
        printf("Child process:\nArray elements: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
        printf("\nSum of array = %d\n", sum);

        if (checkPrime(sum)) {
            printf("The sum %d is a Prime number.\n", sum);
        } else {
            printf("The sum %d is NOT a Prime number.\n", sum);
        }
    } else {
        wait(NULL);
        printf("Parent process: Child finished prime check.\n");
    }

    return 0;
}

