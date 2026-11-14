#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void printFibonacci(int n) {
    int a = 0, b = 1;
    printf("Child: Fibonacci series up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int isArmstrong(int num) {
    int original = num;
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += digit * digit * digit;
        num /= 10;
    }
    return sum == original;
}

void printArmstrong(int limit) {
    printf("Parent: Armstrong numbers up to %d:\n", limit);
    for (int i = 1; i <= limit; i++) {
        if (isArmstrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter value of n: ");
    if (scanf("%d", &n) != 1) return 1;

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        printFibonacci(n);
    } else {
        wait(NULL);
        printArmstrong(n);
    }

    return 0;
}

