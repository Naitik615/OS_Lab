#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n = 6;
    pid_t p1 = fork();

    if (p1 < 0) {
        printf("First fork failed\n");
        return 1;
    }

    if (p1 == 0) {
        // Child 1
        printf("Child 1: Fibonacci series for %d terms:\n", n);
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            printf("%d ", a);
            int next = a + b;
            a = b;
            b = next;
        }
        printf("\n");

        pid_t p2 = fork();
        if (p2 < 0) {
            printf("Second fork failed\n");
            return 1;
        }

        if (p2 == 0) {
            // Child 2
            long long fact = 1;
            for (int i = 1; i <= n; i++) {
                fact *= i;
            }
            printf("Child 2: Factorial of %d = %lld\n", n, fact);
        } else {
            wait(NULL);
        }
    } else {
        wait(NULL);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        printf("Parent: Sum of first %d natural numbers = %d\n", n, sum);
    }

    return 0;
}

