#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main() {
    int file = open("example.txt", O_CREAT | O_WRONLY, 0644);

    if (file == -1) {
        perror("Error opening file");
        printf("Error number: %d\n", errno);
    } else {
        printf("File opened successfully\n");
        close(file);
    }

    return 0;
}
