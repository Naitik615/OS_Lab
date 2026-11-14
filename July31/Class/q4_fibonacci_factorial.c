#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n = 7;
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork error\n");
        return 1;
    }

    if (pid == 0) {
        printf("Child process (Fibonacci series up to %d terms):\n", n);
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            printf("%d ", a);
            int next = a + b;
            a = b;
            b = next;
        }
        printf("\n");
    } else {
        wait(NULL);
        long long fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        printf("Parent process: Factorial of %d = %lld\n", n, fact);
    }

    return 0;
}

