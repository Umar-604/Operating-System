#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int value = 5;

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        value += 15;
        return 0;
    } else {
        // Parent process
        wait(NULL); // Wait for child process to finish
        printf("PARENT: value = %d\n", value); // Corrected to include newline
        return 0;
    }
}
