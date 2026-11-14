#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid > 0) {
        // Parent creates and writes to input.txt
        FILE *fp = fopen("input.txt", "w");
        if (fp == NULL) {
            printf("Error opening file for writing\n");
            return 1;
        }

        fprintf(fp, "Name: Naitik Dhiman\n");
        fprintf(fp, "University Roll No: 2026101\n");
        fprintf(fp, "Class: B.Tech CSE\n");
        fclose(fp);

        printf("Parent: input.txt written and closed.\n");
        wait(NULL);
    } else {
        // Child waits a moment then reads input.txt
        sleep(1);
        FILE *fp = fopen("input.txt", "r");
        if (fp == NULL) {
            printf("Child: Could not open input.txt\n");
            return 1;
        }

        printf("Child: Reading contents of input.txt:\n---\n");
        char ch;
        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch);
        }
        printf("---\n");
        fclose(fp);
    }

    return 0;
}

