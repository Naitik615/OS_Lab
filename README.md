# Operating Systems Lab



**Name:** Naitik Dhiman  
**Section:** IOS 

**Roll No:** 40  
**Course:** B.Tech Computer Science & Engineering  

---

## 📁 Repository & Folder Structure

```text
my_os_lab/
├── July31/
│   ├── Class/
│   │   ├── Questions.md
│   │   ├── q1_pid_ppid.c
│   │   ├── q2_parent_child.c
│   │   ├── q3_wait.c
│   │   ├── q4_fibonacci_factorial.c
│   │   └── q5_fibonacci_factorial_sum.c
│   └── Homework/
│       ├── Homework.md
│       ├── parent_even_child_odd.c
│       ├── three_child_processes.c
│       ├── child_exit_status_wait.c
│       ├── orphan_process_demo.c
│       ├── zombie_process_demo.c
│       └── date_exec.c
├── Aug7/
│   └── Class/
│       ├── Questions.md
│       ├── prime_factorial_fork.c
│       └── fibonacci_armstrong_fork.c
├── Aug17/
│   └── Class/
│       ├── Questions.md
│       ├── sum_prime_child.c
│       └── permutation_child.c
├── Sep18/
│   ├── Questions.md
│   ├── Prime.c
│   └── input.c
├── Sep25/
│   ├── Questions.md
│   ├── child_open_file.c
│   ├── even_numbers.c
│   └── zombie_orphan.c
├── Oct16/
│   ├── Questions.md
│   └── Writer.c
├── Oct23/
│   ├── Questions.md
│   ├── odd_even_sum_fork.c
│   ├── pipe.c
│   ├── fifo_writer.c
│   ├── fifo_reader.c
│   ├── message_sender.c
│   ├── message_receiver.c
│   ├── shared_writer.c
│   └── shared_reader.c
└── Oct30/
    ├── Questions.md
    ├── fcfs.c
    ├── sjf.c
    ├── priority.c
    ├── fifo_page.c
    └── lru_page.c
```

---

## 🛠️ Compilation & Execution

Compile any program using `gcc`:

```bash
# Example 1: Process fork
gcc July31/Class/q1_pid_ppid.c -o q1
./q1

# Example 2: Scheduling
gcc Oct30/fcfs.c -o fcfs
./fcfs
```

### IPC Programs Execution:
- **FIFO (Named Pipe):** Run writer first in terminal 1 (`./fifo_writer`), then reader in terminal 2 (`./fifo_reader`).
- **Message Queue:** Run sender first (`./message_sender`), then receiver (`./message_receiver`).
- **Shared Memory:** Run writer first (`./shared_writer`), then reader (`./shared_reader`).

