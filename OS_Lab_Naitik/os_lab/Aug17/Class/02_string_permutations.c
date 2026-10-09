#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int l, int r) {
    if (l == r) {
        printf("%s\n", str);
    } else {
        for (int i = l; i <= r; i++) {
            swap((str + l), (str + i));
            permute(str, l + 1, r);
            swap((str + l), (str + i));
        }
    }
}

int main() {
    char str[100];

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }

    if (pid == 0) {
        printf("Child Process (PID: %d)\n", getpid());
        printf("Enter a string: ");
        scanf("%s", str);

        printf("All permutations of %s:\n", str);
        permute(str, 0, strlen(str) - 1);

        exit(0);
    } else {
        wait(NULL);
        printf("Parent process completed.\n");
    }

    return 0;
}
