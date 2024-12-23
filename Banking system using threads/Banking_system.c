#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Shared account balance
int balance = 1000;

// Mutex for thread safety
pthread_mutex_t mutex;

// Transaction struct
typedef struct tran {
    char type; // 'D' for Deposit, 'W' for Withdraw
    int amount;
} transaction;

// Transaction processing function
void* process_transaction(void* arg) {
    transaction* t = (transaction*)arg;

    pthread_mutex_lock(&mutex); // Lock the mutex for thread safety

    if (t->type == 'D') {
        balance += t->amount;
        printf("Deposit amount: %d, Updated balance: %d\n", t->amount, balance);
    } else if (t->type == 'W') {
        if (t->amount > balance) {
            printf("Sorry!!! Transaction not possible (Insufficient funds)\n");
        } else {
            balance -= t->amount;
            printf("Withdrawn amount: %d, Updated balance: %d\n", t->amount, balance);
        }
    }

    pthread_mutex_unlock(&mutex); // Unlock the mutex
    pthread_exit(NULL);
}

int main() {
    pthread_t tid; // Thread variable
    pthread_mutex_init(&mutex, NULL); // Initialize the mutex

    int choice;
    transaction t;

    while (1) {
        // Display menu
        printf("\n===== MENU =====\n");
        printf("1. Deposit Amount\n");
        printf("2. Withdraw Amount\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user choice
        if (choice == 1) {
            t.type = 'D';
            printf("Enter the amount to deposit: ");
            scanf("%d", &t.amount);

            // Create thread for deposit
            pthread_create(&tid, NULL, process_transaction, (void*)&t);
            pthread_join(tid, NULL); // Wait for the thread to complete
        } else if (choice == 2) {
            t.type = 'W';
            printf("Enter the amount to withdraw: ");
            scanf("%d", &t.amount);

            // Create thread for withdrawal
            pthread_create(&tid, NULL, process_transaction, (void*)&t);
            pthread_join(tid, NULL); // Wait for the thread to complete
        } else if (choice == 3) {
            printf("Exiting the program. Final balance: %d\n", balance);
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    pthread_mutex_destroy(&mutex); // Destroy the mutex
    return 0;
}
