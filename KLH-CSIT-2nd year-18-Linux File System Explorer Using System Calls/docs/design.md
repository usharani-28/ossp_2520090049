# System Design

## Project

Linux File System Explorer Using System Calls

## 1. Overview

The Linux File System Explorer is a command-line based system programming project developed using the C programming language.

The system provides a menu-driven interface through which users can perform common file and directory operations using Linux/POSIX system calls and APIs.

The main purpose is to demonstrate how a user-level C program interacts with the Linux operating system for file system management.

## 2. Architecture

The project follows the following architecture:

User
  |
  v
File System Explorer
  |
  v
C Functions
  |
  v
Linux/POSIX System Calls and APIs
  |
  v
Linux Kernel
  |
  v
File System

## 3. Main Modules

### 3.1 Main Control Module

File:

main.c

Responsibilities:

- Display the main menu
- Accept the user's choice
- Call the appropriate operation
- Control program execution
- Exit the program

### 3.2 File Operations Module

File:

file_operations.c

Responsibilities:

- Create files
- Write data to files
- Read file contents
- Delete files
- Rename files

System calls/APIs used:

- open()
- write()
- read()
- close()
- unlink()
- rename()

### 3.3 Directory Operations Module

File:

directory_operations.c

Responsibilities:

- Display current directory
- List directory contents
- Create directories
- Remove directories
- Change directories

System calls/APIs used:

- getcwd()
- opendir()
- readdir()
- closedir()
- mkdir()
- rmdir()
- chdir()

### 3.4 File Information Module

File:

file_info.c

Responsibilities:

- Display file metadata
- Display file size
- Display owner ID
- Display group ID
- Display permissions
- Display modification information

System call/API used:

- stat()

### 3.5 Search Module

File:

search.c

Responsibilities:

- Search for a file by name
- Traverse subdirectories recursively
- Display matching file paths

System calls/APIs used:

- opendir()
- readdir()
- stat()
- closedir()

## 4. Header File

File:

explorer.h

The header file contains function declarations shared between the program modules.

This allows the project to be divided into multiple source files while maintaining a clear program structure.

## 5. Build System

File:

Makefile

The Makefile automates compilation of all source files.

Source files:

- main.c
- file_operations.c
- directory_operations.c
- file_info.c
- search.c

The output executable is:

explorer

## 6. User Interaction Flow

1. Program starts.
2. Main menu is displayed.
3. User selects an operation.
4. The corresponding function is called.
5. The function invokes the required Linux/POSIX system call or API.
6. The operation is performed by the operating system.
7. The result or error message is displayed.
8. The menu is displayed again.
9. The program continues until the user selects Exit.

## 7. Error Handling

The project checks the return values of system calls and APIs.

When an operation fails, the program uses perror() to display an appropriate error message.

Examples:

open: No such file or directory

chdir: No such file or directory

This demonstrates basic error handling in Linux system programming.

## 8. Design Principles

The project follows these principles:

- Modular programming
- System call based implementation
- Separation of file and directory operations
- Reusable function declarations
- Error checking
- Command-line interaction
- Linux/POSIX compatibility

## 9. Advantages

- Demonstrates practical Linux system programming
- Provides hands-on understanding of system calls
- Demonstrates file descriptors and file I/O
- Demonstrates directory management
- Demonstrates file metadata retrieval
- Demonstrates recursive directory traversal
- Provides clear modular source code

## 10. Future Enhancements

Possible future improvements include:

- Displaying file types
- Human-readable file sizes
- Formatted timestamps
- Permission display in symbolic form
- Search result counting
- Improved command-line navigation
- More detailed error reporting
