#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    char command[100];

    // Read Linux command from user
    printf("Enter a Linux command: ");
    fgets(command, sizeof(command), stdin);

    // Remove newline character
    command[strcspn(command, "\n")] = '\0';

    // Create child process
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        printf("Process creation failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child Process
        printf("\nChild Process\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());

        printf("Executing command: %s\n\n", command);

        // Execute command
        execlp(command, command, NULL);

        // Executes only if exec fails
        perror("Execution failed");
        exit(1);
    }
    else {
        // Parent Process
        printf("\nParent Process\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n", pid);

        // Wait for child to finish
        wait(NULL);

        printf("\nChild process completed.\n");
    }

    return 0;
}
