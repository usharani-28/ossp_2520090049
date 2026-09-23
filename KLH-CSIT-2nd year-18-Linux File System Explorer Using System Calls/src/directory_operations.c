#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include "explorer.h"

// Show Current Directory
void showCurrentDirectory() {
    char path[1024];

    if (getcwd(path, sizeof(path)) != NULL) {
        printf("\nCurrent Directory: %s\n", path);
    } else {
        perror("getcwd");
    }
}


// List Files and Directories
void listFiles() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    printf("\nFiles and Directories:\n");

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}


// Create a Directory
void createDirectory() {
    char dirname[100];

    printf("\nEnter directory name: ");
    scanf("%99s", dirname);

    if (mkdir(dirname, 0755) == 0) {
        printf("Directory '%s' created successfully!\n", dirname);
    } else {
        perror("mkdir");
    }
}


// Remove a Directory
void removeDirectory() {
    char dirname[100];

    printf("\nEnter directory name to remove: ");
    scanf("%99s", dirname);

    if (rmdir(dirname) == 0) {
        printf("Directory '%s' removed successfully!\n", dirname);
    } else {
        perror("rmdir");
    }
}


// Change Directory
void changeDirectory() {
    char dirname[100];

    printf("\nEnter directory name: ");
    scanf("%99s", dirname);

    if (chdir(dirname) == 0) {
        printf("Changed directory to '%s' successfully!\n", dirname);
    } else {
        perror("chdir");
    }
}
