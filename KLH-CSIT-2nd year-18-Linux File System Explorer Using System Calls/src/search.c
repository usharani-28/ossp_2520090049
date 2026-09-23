#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "explorer.h"

// Recursive function to search for a file
void searchDirectory(const char *path, const char *filename) {
    DIR *dir;
    struct dirent *entry;
    char fullPath[1024];

    dir = opendir(path);

    if (dir == NULL) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {

        // Ignore current and parent directories
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(fullPath, sizeof(fullPath), "%s/%s",
                 path, entry->d_name);

        // Check whether the name matches
        if (strcmp(entry->d_name, filename) == 0) {
            printf("File found: %s\n", fullPath);
        }

        // Check whether it is a directory
        struct stat entryStat;

        if (stat(fullPath, &entryStat) == 0) {
            if (S_ISDIR(entryStat.st_mode)) {
                searchDirectory(fullPath, filename);
            }
        }
    }

    closedir(dir);
}


// Search for a File
void searchFile() {
    char filename[100];

    printf("\nEnter file name to search: ");
    scanf("%99s", filename);

    printf("\nSearching for '%s'...\n", filename);

    searchDirectory(".", filename);
}
