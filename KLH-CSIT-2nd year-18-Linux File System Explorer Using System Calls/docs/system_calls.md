# Linux System Calls and APIs

## Project

Linux File System Explorer Using System Calls

## 1. Introduction

This project demonstrates how a C program can interact with the Linux operating system using system calls and POSIX APIs.

The project performs file and directory operations through low-level operating system interfaces instead of relying only on high-level file management functions.

## 2. File Operations

### open()

Purpose:

Opens an existing file or creates a new file.

Usage in project:

- Create a file
- Open a file for reading
- Open a file for writing

Example flags:

O_RDONLY
O_WRONLY
O_CREAT
O_TRUNC

### read()

Purpose:

Reads data from an open file using a file descriptor.

Usage in project:

- Reading file contents

### write()

Purpose:

Writes data to an open file using a file descriptor.

Usage in project:

- Writing content to files

### close()

Purpose:

Closes an open file descriptor.

Usage in project:

- Closing files after read/write/create operations

### unlink()

Purpose:

Removes a file from the file system.

Usage in project:

- Deleting files

### rename()

Purpose:

Changes the name or path of a file.

Usage in project:

- Renaming files

## 3. Directory Operations

### getcwd()

Purpose:

Returns the current working directory.

Usage in project:

- Displaying the current directory

### opendir()

Purpose:

Opens a directory stream for reading directory contents.

Usage in project:

- Listing directories
- Searching directories

### readdir()

Purpose:

Reads entries from an opened directory.

Usage in project:

- Displaying file and directory names
- Traversing directories during search

### closedir()

Purpose:

Closes an opened directory stream.

Usage in project:

- Closing directories after directory operations

### mkdir()

Purpose:

Creates a new directory.

Usage in project:

- Creating directories

### rmdir()

Purpose:

Removes an empty directory.

Usage in project:

- Removing directories

### chdir()

Purpose:

Changes the current working directory of the process.

Usage in project:

- Navigating between directories

## 4. File Metadata

### stat()

Purpose:

Retrieves information about a file or directory.

Information obtained in this project includes:

- File size
- Owner ID
- Group ID
- Permissions
- Modification time

Usage in project:

- Displaying file information
- Identifying directories during recursive search

## 5. File Descriptors

File descriptors are integer values used by Linux to identify open files and other input/output resources.

The open() function returns a file descriptor when a file is successfully opened.

The project stores this value in an integer variable:

int fd;

The file descriptor is then used by:

- read()
- write()
- close()

## 6. Error Handling

Most system calls return a value that indicates whether the operation succeeded or failed.

The project checks these return values.

When an operation fails, perror() is used to display the corresponding error message.

Examples:

open: No such file or directory

chdir: No such file or directory

## 7. System Call Summary

System Call/API | Purpose

getcwd() | Get current working directory

open() | Open or create a file

read() | Read data from a file

write() | Write data to a file

close() | Close a file descriptor

unlink() | Delete a file

rename() | Rename a file

stat() | Get file metadata

mkdir() | Create a directory

rmdir() | Remove an empty directory

chdir() | Change working directory

opendir() | Open a directory

readdir() | Read directory entries

closedir() | Close a directory

perror() | Display error information

## 8. Operating System Concepts Demonstrated

The project demonstrates the following Operating System concepts:

- System calls
- File descriptors
- File I/O
- Directory management
- File metadata
- File permissions
- Process working directory
- Error handling
- Recursive directory traversal
- User program interaction with the Linux kernel

## 9. Conclusion

The Linux File System Explorer provides practical experience with Linux/POSIX system calls and APIs.

By implementing file creation, reading, writing, deletion, renaming, directory management, file searching, and metadata retrieval, the project demonstrates how system-level file operations are performed by a C program in Linux.
