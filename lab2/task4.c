#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    char writeData[] = "Hello, Umar Tariq!";
    char readData[100];
    int file;

    // Open the file
    file = open("example.txt", O_CREAT | O_WRONLY, 0644);
    if (file == -1) {
        perror("Error opening file for writing");
        return 1;
    }

    // Write data to file
    if (write(file, writeData, strlen(writeData)) == -1) {
        perror("Error writing to file");
        close(file);
        return 1;
    }

    close(file); // Close after writing

    // Re-open the file to read
    file = open("example.txt", O_RDONLY);
    if (file == -1) {
        perror("Error opening file for reading");
        return 1;
    }

    // Read data from file
    if (read(file, readData, sizeof(readData)) == -1) {
        perror("Error reading file");
        close(file);
        return 1;
    }

    printf("Read from file: %s\n", readData);

    close(file); // Close after reading

    return 0;
}
