
#include "explorer.h"
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>



// Main Function
int main() {
    int choice;

    while (1) {
        printf("\n===== Linux File System Explorer =====\n");
        printf("1. Show Current Directory\n");
        printf("2. List Files and Directories\n");
        printf("3. Create a File\n");
        printf("4. Write to a File\n");
        printf("5. Read a File\n");
        printf("6. Delete a File\n");
	printf("7. Rename a File\n");
	printf("8. Show File Information\n");
	printf("9. Create a Directory\n");
	printf("10. Remove a Directory\n");
	printf("11. Change Directory\n");
	printf("12. Search for a File\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showCurrentDirectory();
                break;

            case 2:
                listFiles();
                break;

            case 3:
                createFile();
                break;

            case 4:
                writeFile();
                break;

            case 5:
                readFile();
                break;

            case 6:
                deleteFile();
                break;

	   case 7:
    		renameFile();
    		break;
	   case 8:
    		showFileInfo();
    		break;
	   case 9:
    		createDirectory();
    		break;
	   case 10:
		removeDirectory();
		break;
	   case 11:
    		changeDirectory();
    		break;
	   case 12:
    		searchFile();
    		break;
	   case 13:
    		printf("Exiting Explorer...\n");
    		exit(0);
        }
    }

    return 0;
}








































































































