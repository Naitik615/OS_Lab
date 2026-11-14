#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = ftok(".", 'A');
    if (key == -1) {
        perror("ftok error");
        return 1;
    }

    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget error");
        return 1;
    }

    struct msg_buffer message;
    message.msg_type = 1;

    printf("Enter a message to send to queue: ");
    if (fgets(message.msg_text, sizeof(message.msg_text), stdin) != NULL) {
        if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
            perror("msgsnd error");
            return 1;
        }
        printf("Message sent to queue: %s", message.msg_text);
    }

    return 0;
}

