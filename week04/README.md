# Week 4

## Description

### Task 1

C-file (program) prints a text with PID of current process (for child it is equal to 0).
Bash file (ex1.sh) launch the program 10 times.

Please, when you compile C-file, **COMPILE** it as `ex1`.

### Task 2

The program creates new processes by using `fork()` 3 times.
It will create 8 processes (each one creates their own processes).
When the root process is terminated, all child processes will be terminated as well.

Please, launch the program on background.
Example: `./ex2 &`.
