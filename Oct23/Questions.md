# October 23 - Lab Work (IPC Mechanisms)

## Questions

1. **Odd-Even Sum Using Fork**
   Write a C program using `fork()` where the parent process calculates the sum of all odd numbers from an array and the child process calculates the sum of all even numbers.

2. **Unnamed Pipe Demonstration**
   Write a C program to demonstrate inter-process communication using an ordinary pipe (`pipe()`). The parent writes a message into the pipe and the child reads and displays it.

3. **FIFO (Named Pipe) IPC**
   Write two C programs (`fifo_writer.c` and `fifo_reader.c`) to demonstrate IPC between two independent processes using a FIFO / named pipe.

4. **Message Queue IPC**
   Write two C programs (`message_sender.c` and `message_receiver.c`) using System V Message Queues (`msgget()`, `msgsnd()`, `msgrcv()`, `msgctl()`) to send and receive messages.

5. **Shared Memory IPC**
   Write two C programs (`shared_writer.c` and `shared_reader.c`) using System V Shared Memory (`shmget()`, `shmat()`, `shmdt()`, `shmctl()`) to share data between two independent processes.

