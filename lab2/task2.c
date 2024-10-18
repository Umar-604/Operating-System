#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char profession[50];
    int salary;
} Person;

int main() {
    Person p1;

    // Initialize the structure
    strcpy(p1.name, "Alice");
    strcpy(p1.profession, "Engineer");
    p1.salary = 50000;

    // Print the structure's data
    printf("Name: %s\n", p1.name);
    printf("Profession: %s\n", p1.profession);
    printf("Salary: $%d\n", p1.salary);

    return 0;
}
