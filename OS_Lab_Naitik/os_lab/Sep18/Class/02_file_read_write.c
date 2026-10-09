#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid;
    FILE *fp;
    int ch;

    pid = fork();

    if (pid > 0) {
        fp = fopen("input.txt", "w");

        fprintf(fp, "Name: Aditya\n");
        fprintf(fp, "University Roll No: 123456\n");
        fprintf(fp, "Class: B.Tech CSE\n");

        fclose(fp);

        wait(NULL);
    } else if (pid == 0) {
        sleep(1);

        fp = fopen("input.txt", "r");
        if (fp == NULL) {
            printf("File could not be opened\n");
            return 1;
        }

        printf("Contents of input.txt:\n");

        while ((ch = fgetc(fp)) != EOF) {
            printf("%c", ch);
        }

        fclose(fp);
    } else {
        printf("Fork failed\n");
    }

    return 0;
}
