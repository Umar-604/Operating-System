#include <stdio.h>

int main() {
    FILE *file = fopen("example.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Move the file pointer to the 15th byte
    if (fseek(file, 15, SEEK_SET) != 0) {
        perror("Error seeking in file");
        fclose(file);
        return 1;
    }

    // Get the current position of the file pointer
    long position = ftell(file);
    if (position == -1L) {
        perror("Error telling position in file");
        fclose(file);
        return 1;
    }

    printf("File pointer is now at position: %ld\n", position);

    fclose(file);
    return 0;
}
