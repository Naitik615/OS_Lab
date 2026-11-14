#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        // Child calculates even sum
        int even_sum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                even_sum += arr[i];
            }
        }
        printf("Child process -> Sum of even numbers = %d\n", even_sum);
    } else {
        // Parent calculates odd sum
        wait(NULL);
        int odd_sum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                odd_sum += arr[i];
            }
        }
        printf("Parent process -> Sum of odd numbers = %d\n", odd_sum);
    }

    return 0;
}

