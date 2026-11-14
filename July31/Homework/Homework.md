# July 31 - Homework

## Questions

1. **Parent Prints Even Numbers, Child Prints Odd Numbers**
   Write a C program in which the parent process prints all even numbers from 1 to 20, and the child process prints all odd numbers from 1 to 20.

2. **Create Three Child Processes**
   Write a C program to create three child processes using `fork()`. Each child process should print its child number, PID, and PPID.

3. **Child Exit Status Using `wait()`**
   Write a C program where the child process exits with status code 10. The parent process waits for the child using `wait()` and prints the child's exit status.

4. **Demonstrate an Orphan Process**
   Write a C program to demonstrate an orphan process. The child process should print its PPID before and after the parent terminates.

5. **Demonstrate a Zombie Process**
   Write a C program to demonstrate a zombie process. Observe the zombie process using `ps` while the parent is sleeping.

6. **Execute the `date` Command Using `fork()`, `exec()`, and `wait()`**
   Write a C program using `fork()`, `exec()`, and `wait()` to execute the system `date` command.

