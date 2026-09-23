# Build Instructions

## Project

Linux File System Explorer Using System Calls

## Requirements

The project requires:

- Linux / Ubuntu
- GCC compiler
- GNU Make
- Bash terminal

## Check GCC

Run:

gcc --version

## Check Make

Run:

make --version

## Navigate to Source Directory

From the project root:

cd src

## Build the Project

Run:

make

The Makefile compiles the following source files:

- main.c
- file_operations.c
- directory_operations.c
- file_info.c
- search.c

The executable generated is:

explorer

## Run the Program

Run:

./explorer

The program displays a menu for performing file and directory operations.

## Clean the Build

To remove the compiled executable:

make clean

## Manual Compilation

The project can also be compiled without Make using:

gcc -Wall -Wextra -std=c11 main.c file_operations.c directory_operations.c file_info.c search.c -o explorer

## Execution

After successful compilation:

./explorer

## Test Execution

For testing with the prepared test data, navigate to the data directory from the project root:

cd data

Then run:

../src/explorer

This allows the program to perform operations inside the data directory without modifying the source-code directory.

## Expected Result

The project should compile successfully without errors and display the Linux File System Explorer menu.

Example:

===== Linux File System Explorer =====
1. Show Current Directory
2. List Files and Directories
3. Create a File
4. Write to a File
5. Read a File
6. Delete a File
7. Rename a File
8. Show File Information
9. Create a Directory
10. Remove a Directory
11. Change Directory
12. Search for a File
13. Exit
