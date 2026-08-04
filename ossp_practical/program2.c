#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    printf("Creating a new process using fork()...\n\n");

    pid = fork();

    if (pid < 0) {
        printf("Error: Process creation failed!\n");
    }
    else if (pid == 0) {
        printf("===== CHILD PROCESS =====\n");
        printf("Child Process ID (PID): %d\n", getpid());
        printf("Parent Process ID (PPID): %d\n", getppid());
        printf("Child process is executing.\n");
    }
    else {
        printf("===== PARENT PROCESS =====\n");
        printf("Parent Process ID (PID): %d\n", getpid());
        printf("Created Child Process ID: %d\n", pid);
        printf("Parent process is executing.\n");
    }

    return 0;
}
