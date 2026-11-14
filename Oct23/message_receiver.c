#include <stdio.h>
#include <stdlib.h>
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

    if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0) == -1) {
        perror("msgrcv error");
        return 1;
    }

    printf("Message received from queue: %s", message.msg_text);

    // Destroy the message queue after reading
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}

