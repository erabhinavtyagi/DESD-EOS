# Embedded OS

## Day 1
- Created Repository.
- Added .gitignore, pushed "Hello World" program to check the working of github.
- Learned Basic Git commands.

## Day 2
- Basic Calculator using Makefile.
    - add(), sub(), mul(), div()

## Day 3
- Section Demo Program
- Process Id / Parent Process ID Demo Program
- Library call and System Call Demo Program
- Used "STRACE" Command

## Day 4
- File operations on Kernel
    - open(), close(), read(), write()
- Static Library & Dynamic Library programs
    - Static Linking & Dynamic Linking

## Day 5
- Process Scheduling 
- Fork Demo
    -created a child process

## Day 6
- Fork Demo (cont.)
    - created a child process and checked PID & PPID
- Zombie Process Program
- Orphan Process Program
- Program to check the number of Zombie Process a system can handle.
- Installed EMUX in PC.

## Day 7
- Pipe Demo Program
- FIFO Demo
    -   Created FIFO with access permissions "0660" 
    -   Sender program
    -   Receiver program
- Thread Demo Program

## Day 8
- Assignment 01: Application of FIFO
    1. Write your own utility using **System Calls** (open,close,read,write) to copy data from one file to another file. Essentially you are implementing a copy utility.
    Fullfledged utility should support the following options:
    - Handling all the Errors.
    - cp srcfile destfile
    2. Write your own utility using **Library Calls** (fopen,fclose,fread,fwrite) to copy data from one file to another file. Essentially you are implementing a copy utility.
    Fullfledged utility should support the following options:
    - Handling all the Errors.
    - cp srcfile destfile
    3. Case Study
        Which of the following program took more time to copy files.
        - Small
        - Medium
        - Large

- Program Threadjoin.
- Program Thread Attributes
    - Joinable & Detachable
- Program to check Race Condition.

## Day 9
- Program Mutex Demo
- Program for Recursive
    - Problem
    - Solution
- Program for Mutex-Trylock
- Program for Mutex-Timedlock

## Day 10
- Semaphore
    - Mutual Exclusion Program
    - Overview of Use of Semaphore in signaling
- Cross Compilation done for all programs

## Day 11
- Program without using Signalling Method (Problem)
- Program using Signalling Method (Solution)
- Program for Read/Write Lock Method.

## Day 12
- Program for Exec() system Call
    - Exec_demo
    - To create own Dummy_shell (Assignment)
- Program for Barrier Synchronization
    - Problem 
    - Solution
- Program for Conditional Variable
    - Problem
    - Solution
