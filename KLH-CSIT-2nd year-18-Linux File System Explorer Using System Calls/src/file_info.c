#include <stdio.h>
#include <sys/stat.h>
#include "explorer.h"

// Display File Information
void showFileInfo() {
    char filename[100];
    struct stat fileStat;

    printf("\nEnter file name: ");
    scanf("%99s", filename);

    if (stat(filename, &fileStat) == -1) {
        perror("stat");
        return;
    }

    printf("\n===== File Information =====\n");
    printf("File Name       : %s\n", filename);
    printf("File Size       : %ld bytes\n", fileStat.st_size);
    printf("Owner ID        : %d\n", fileStat.st_uid);
    printf("Group ID        : %d\n", fileStat.st_gid);
    printf("Permissions     : %o\n", fileStat.st_mode & 0777);
    printf("Last Modified   : %ld\n", fileStat.st_mtime);
}
