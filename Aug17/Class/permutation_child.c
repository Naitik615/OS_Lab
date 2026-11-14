#include <stdio.h>
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
        return;
    }
    for (int i = l; i <= r; i++) {
        swap((str + l), (str + i));
        permute(str, l + 1, r);
        swap((str + l), (str + i)); // backtrack
    }
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        char str[50];
        printf("Child process: Enter a string: ");
        if (scanf("%49s", str) != 1) return 1;

        int len = strlen(str);
        printf("All permutations of \"%s\":\n", str);
        permute(str, 0, len - 1);
    } else {
        wait(NULL);
        printf("Parent process: Permutations finished.\n");
    }

    return 0;
}

