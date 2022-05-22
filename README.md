# Embedded OS Assignment

## Day 1

- 2 Tier and 3 Tier Embedded Systems
- Hardware
  - CPU
    - PC/ IP
    - GPRs
    - Flags
    - Stack Pointer (SP)
  - Memory
    - Code
    - Data
  - Peripheral
- Bare Metal Systems
- SP, SF, Stack
  - SP - Register inside a CPU -> pointing to the top of stack
  - Stack - Chunk of memory
  - SF - Frame created on the Stack when you call a function. Deleted when you return from the function
- Frame Pointer - points to the base of the frame
- How are arguments passed to the function
  - Stack
  - Registers

## Day 2

- Booting procedure

  - ROM BL
  - PBL
  - SBL (Uboot)
  - Kernel (Linux)
  - RFS (Buildroot)

## Day 3 and 4

- Makefile
- Toolchain

  - Build System
  - Host System
  - Target System

- Program

  - Program Sections
    - Text
    - Data
    - BSS
    - Heap
    - Stack

- Address Space

- Program vs Process

  - Program
    - Executable// Binary
    - Compiled
    - Dormant
  - Process
    - Thread
    - Process / Program under execution
    - Active

- OS

  - Process Management
  - Memory Management
  - I/O Management
    - Device Drivers
    - File System
    - Networking
    - GUI

- Kernel Mode vs User Mode

  - Kernel Mode aka Supervisor Mode
    - Kernel Space
    - Kernel Heap
    - Kernel Stack
  - User Mode
    - User Space
    - User Heap
    - User Stack

- Process ID (PID)

  - getpid()

- Man

  - man -k pid
  - man 2 getpid

- Process Control Block (PCB)

  - PID
  - Base Address of the Process
  - Size of the Address space

- Library Calls
- System Calls

- strace

- Differentiated between library and system call

- Shell

  - Command Line
  - Parsing
  - Built-in Commands
  - Shell Scripts

- Users and Groups

  - Users
    - User ID
    - Group ID
    - User Name
    - Group Name
    - Home Directory
    - Shell
  - Groups
    - Group ID
    - Group Name
    - Group Members

- Superuser
