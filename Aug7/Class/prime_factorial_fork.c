#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

long long factorial(int num) {
    long long f = 1;
    for (int i = 1; i <= num; i++) {
        f *= i;
    }
    return f;
}

int main() {
    int num;
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) return 1;

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        if (isPrime(num))
            printf("Child: %d is a Prime number\n", num);
        else
            printf("Child: %d is NOT a Prime number\n", num);
    } else {
        wait(NULL);
        printf("Parent: Factorial of %d = %lld\n", num, factorial(num));
    }

    return 0;
}

