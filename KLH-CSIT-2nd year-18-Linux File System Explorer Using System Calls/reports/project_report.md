# PROJECT REPORT

# Linux File System Explorer Using System Calls

## 1. Abstract

The Linux File System Explorer is a command-line based system programming project developed using the C programming language and Linux/POSIX system calls.

The project provides a menu-driven interface for performing common file and directory operations such as creating, reading, writing, deleting, and renaming files. It also provides directory management, file information retrieval, recursive file searching, and error handling.

The main objective of the project is to provide practical understanding of how a user-level C program interacts with the Linux operating system through system calls and POSIX APIs.

The project demonstrates important Operating System concepts including file descriptors, file I/O, directory management, file metadata, permissions, working directories, system calls, and error handling.

## 2. Introduction

Linux provides system calls that allow user programs to communicate with the operating system kernel and perform system-level operations.

Normally, users manage files through graphical file managers or high-level shell commands. These methods hide many of the underlying operating system mechanisms.

This project implements a Linux File System Explorer using C and Linux/POSIX interfaces. The application provides a simple command-line menu through which users can perform file and directory operations.

The project helps demonstrate the relationship between a user program, system calls, the Linux kernel, and the file system.

## 3. Problem Statement

Users commonly manage files and directories using graphical file managers or high-level commands without understanding how these operations are handled by the operating system.

The problem is to develop a command-line based Linux File System Explorer that performs common file and directory operations using Linux/POSIX system calls while demonstrating important Operating System concepts such as file descriptors, file I/O, directory management, file metadata, permissions, and error handling.

## 4. Objectives

The main objectives of the project are:

- To develop a command-line based Linux file system explorer.
- To demonstrate Linux/POSIX system calls using C.
- To perform file creation, reading, writing, deletion, and renaming.
- To perform directory creation, removal, listing, and navigation.
- To display file metadata using stat().
- To implement recursive file searching.
- To demonstrate file descriptors and low-level file I/O.
- To implement basic error handling using perror().
- To understand interaction between a user program and the Linux operating system.

## 5. Scope of the Project

The project focuses on file and directory management using Linux system calls and POSIX APIs.

The current implementation supports:

- Displaying the current directory.
- Listing files and directories.
- Creating files.
- Writing data to files.
- Reading file contents.
- Deleting files.
- Renaming files.
- Displaying file information.
- Creating directories.
- Removing empty directories.
- Changing directories.
- Recursively searching for files.
- Handling invalid file and directory operations.

## 6. Technologies Used

### Programming Language

C

### Operating System

Linux / Ubuntu

### Compiler

GCC

### Build Tool

GNU Make

### APIs

Linux/POSIX system calls and directory APIs

### Development Environment

Ubuntu through WSL and command-line tools such as Nano and Bash.

## 7. Hardware Requirements

The project can be developed and executed on a standard computer.

Minimum requirements:

- Laptop or desktop computer
- Intel Core i3 or equivalent processor
- Minimum 4 GB RAM
- Minimum 10 GB available storage
- Keyboard
- Monitor

## 8. Software Requirements

- Linux / Ubuntu
- GCC compiler
- GNU Make
- Bash terminal
- C standard library
- Linux/POSIX APIs
- Git and GitHub for version control

## 9. System Architecture

The project follows the following architecture:

User
  |
  v
Linux File System Explorer
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
Linux File System

The user selects an operation from the command-line menu. The corresponding C function is executed and invokes the required Linux/POSIX system call or API.

The operating system performs the requested operation and returns the result to the program.

## 10. Project Modules

### 10.1 Main Control Module

File:

src/main.c

Responsibilities:

- Display the main menu.
- Accept user input.
- Select the requested operation.
- Call the appropriate function.
- Continue execution until the user selects Exit.

### 10.2 File Operations Module

File:

src/file_operations.c

Responsibilities:

- Create files.
- Write content to files.
- Read files.
- Delete files.
- Rename files.

Functions:

- createFile()
- writeFile()
- readFile()
- deleteFile()
- renameFile()

### 10.3 Directory Operations Module

File:

src/directory_operations.c

Responsibilities:

- Display the current working directory.
- List directory contents.
- Create directories.
- Remove empty directories.
- Change the current directory.

Functions:

- showCurrentDirectory()
- listFiles()
- createDirectory()
- removeDirectory()
- changeDirectory()

### 10.4 File Information Module

File:

src/file_info.c

Responsibilities:

- Display file name.
- Display file size.
- Display owner ID.
- Display group ID.
- Display permissions.
- Display modification information.

Function:

- showFileInfo()

### 10.5 Search Module

File:

src/search.c

Responsibilities:

- Search for files by name.
- Traverse directories recursively.
- Display matching file paths.

Functions:

- searchFile()
- searchDirectory()

### 10.6 Header File

File:

src/explorer.h

The header file contains function declarations shared by the different source files.

This supports modular programming and avoids duplicate function declarations.

## 11. System Calls and APIs Used

### getcwd()

Used to obtain the current working directory.

### open()

Used to open files and create new files.

### read()

Used to read data from files.

### write()

Used to write data to files.

### close()

Used to close file descriptors.

### unlink()

Used to delete files.

### rename()

Used to rename files.

### stat()

Used to obtain file metadata such as size, owner ID, group ID, permissions, and modification time.

### mkdir()

Used to create directories.

### rmdir()

Used to remove empty directories.

### chdir()

Used to change the current working directory.

### opendir()

Used to open a directory stream.

### readdir()

Used to read entries from a directory.

### closedir()

Used to close an opened directory stream.

### perror()

Used to display error messages when system calls fail.

## 12. File Descriptors

A file descriptor is an integer used by Linux to identify an opened file or other input/output resource.

When open() successfully opens a file, it returns a file descriptor.

The project stores the descriptor in a variable:

int fd;

The descriptor is then used with:

- read()
- write()
- close()

This demonstrates low-level file I/O in Linux.

## 13. Recursive File Search

The search module implements recursive directory traversal.

The program:

1. Opens the current directory using opendir().
2. Reads directory entries using readdir().
3. Ignores "." and "..".
4. Builds the complete path of each entry.
5. Compares the entry name with the requested filename.
6. Uses stat() to determine whether the entry is a directory.
7. Recursively searches subdirectories.
8. Closes the directory using closedir().

During testing, the program successfully found:

./test_directory/nested.txt

## 14. Error Handling

The project checks the return values of system calls and APIs.

If an operation fails, perror() displays the corresponding system error message.

For example, when attempting to read a non-existing file:

open: No such file or directory

When attempting to change to a non-existing directory:

chdir: No such file or directory

This demonstrates basic error handling in Linux system programming.

## 15. Build Process

The project uses GNU Make.

The Makefile is located at:

src/Makefile

The project can be compiled using:

cd src
make

The generated executable is:

explorer

The program can then be executed using:

./explorer

To remove the generated executable:

make clean

## 16. Testing

The project was tested using actual program execution.

A total of 14 test cases were executed.

The test cases covered:

- Current directory display
- Directory listing
- File creation
- File writing
- File reading
- File deletion
- File renaming
- File information
- Directory creation
- Directory removal
- Directory navigation
- Recursive file search
- Invalid file handling
- Invalid directory handling

## 17. Test Results

Total Test Cases: 14

Passed: 14

Failed: 0

Overall Result:

PASS

The detailed test cases are stored in:

results/test_cases.txt

The actual test results are stored in:

results/test_results.txt

## 18. Sample Test Results

### File Creation

Input:

ossp_test.txt

Output:

File 'ossp_test.txt' created successfully!

### File Writing

Input:

Linux File System Explorer Test

Output:

Content written successfully!

### File Reading

Output:

Linux File System Explorer Test

### File Renaming

Output:

File renamed successfully!

### File Search

Search target:

nested.txt

Output:

File found: ./test_directory/nested.txt

### File Deletion

Output:

File 'ossp_renamed.txt' deleted successfully!

### Directory Creation

Output:

Directory 'temp_dir' created successfully!

### Directory Removal

Output:

Directory 'temp_dir' removed successfully!

### Invalid File

Output:

open: No such file or directory

### Invalid Directory

Output:

chdir: No such file or directory

## 19. Advantages

- Demonstrates practical Linux system programming.
- Uses real Linux/POSIX system calls.
- Provides hands-on understanding of file descriptors.
- Demonstrates low-level file I/O.
- Demonstrates directory management.
- Demonstrates file metadata retrieval.
- Demonstrates recursive directory traversal.
- Uses modular C source files.
- Includes error handling.
- Provides a simple command-line interface.

## 20. Limitations

The current version is a basic command-line file system explorer.

Limitations include:

- File names containing spaces are not supported by the current input method.
- File information displays the modification time as a numeric timestamp.
- The search is based on exact filename matching.
- The program does not provide a graphical interface.
- The program does not include advanced permission modification features.

## 21. Future Enhancements

Possible future improvements include:

- Support for file names containing spaces.
- Human-readable timestamps.
- Human-readable file sizes.
- Symbolic permission display.
- File type identification.
- Search result counting.
- More advanced search options.
- Improved command-line navigation.
- More detailed error reporting.

## 22. Conclusion

The Linux File System Explorer successfully demonstrates the use of Linux/POSIX system calls and APIs for file and directory management.

The project provides practical understanding of file descriptors, file I/O, directory operations, file metadata, permissions, recursive directory traversal, and error handling.

The implementation was divided into multiple C source files to maintain modularity and clarity.

All 14 implemented test cases were executed successfully, with 14 tests passing and 0 tests failing.

The project therefore provides a practical demonstration of how a user-level C program interacts with the Linux operating system through system-level interfaces.

## 23. Project Directory Structure

Linux File System Explorer Using System Calls/

├── README.md
├── data/
│   ├── sample.txt
│   └── test_data.txt
├── docs/
│   ├── build_instructions.md
│   ├── design.md
│   └── system_calls.md
├── reports/
│   └── project_report.md
├── results/
│   ├── test_cases.txt
│   └── test_results.txt
└── src/
    ├── Makefile
    ├── directory_operations.c
    ├── explorer
    ├── explorer.h
    ├── file_info.c
    ├── file_operations.c
    ├── main.c
    └── search.c
