#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *file = fopen("nonexistent_file.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        printf("Error number: %d\n", errno);
        printf("Error description: %s\n", strerror(errno));
    } else {
        fclose(file);
    }

    return 0;
}
