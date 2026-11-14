#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork error\n");
        return 1;
    }

    if (pid == 0) {
        // Child creates file and writes even numbers
        FILE *fp = fopen("even.txt", "w");
        if (fp == NULL) {
            printf("Child: Could not create even.txt\n");
            return 1;
        }

        for (int i = 2; i <= 20; i += 2) {
            fprintf(fp, "%d\n", i);
        }
        fclose(fp);
        printf("Child: Successfully wrote even numbers to even.txt\n");
    } else {
        // Parent waits and reads the file
        wait(NULL);
        FILE *fp = fopen("even.txt", "r");
        if (fp == NULL) {
            printf("Parent: Could not read even.txt\n");
            return 1;
        }

        printf("Parent: Reading even.txt:\n");
        int num;
        while (fscanf(fp, "%d", &num) == 1) {
            printf("%d ", num);
        }
        printf("\n");
        fclose(fp);
    }

    return 0;
}

