#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "explorer.h"

// Create a File
void createFile() {
    char filename[100];

    printf("\nEnter file name: ");
    scanf("%99s", filename);

    int fd = open(filename, O_CREAT | O_WRONLY, 0644);

    if (fd == -1) {
        perror("open");
        return;
    }

    printf("File '%s' created successfully!\n", filename);

    close(fd);
}


// Write to a File
void writeFile() {
    char filename[100];
    char content[500];

    printf("\nEnter file name: ");
    scanf("%99s", filename);

    printf("Enter content: ");
    getchar();
    fgets(content, sizeof(content), stdin);

    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        return;
    }

    ssize_t bytesWritten = write(fd, content, strlen(content));

    if (bytesWritten == -1) {
        perror("write");
    } else {
        printf("Content written successfully!\n");
    }

    close(fd);
}


// Read a File
void readFile() {
    char filename[100];
    char buffer[1024];
    ssize_t bytesRead;

    printf("\nEnter file name: ");
    scanf("%99s", filename);

    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        perror("open");
        return;
    }

    printf("\nFile Content:\n");

    while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0';
        printf("%s", buffer);
    }

    if (bytesRead == -1) {
        perror("read");
    }

    printf("\n");

    close(fd);
}


// Delete a File
void deleteFile() {
    char filename[100];

    printf("\nEnter file name to delete: ");
    scanf("%99s", filename);

    if (unlink(filename) == 0) {
        printf("File '%s' deleted successfully!\n", filename);
    } else {
        perror("unlink");
    }
}


// Rename a File
void renameFile() {
    char oldName[100];
    char newName[100];

    printf("\nEnter current file name: ");
    scanf("%99s", oldName);

    printf("Enter new file name: ");
    scanf("%99s", newName);

    if (rename(oldName, newName) == 0) {
        printf("File renamed successfully!\n");
    } else {
        perror("rename");
    }
}
