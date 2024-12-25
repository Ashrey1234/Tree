#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int accountNumber;
    float balance;
} Account;

void deposit(Account *acc, float amount) {
    acc->balance += amount;
    printf("Deposited %.2f. New balance: %.2f\n", amount, acc->balance);
}

void withdraw(Account *acc, float amount) {
    if (acc->balance < amount) {
        printf("Insufficient balance Current balance: %.2f\n", acc->balance);
    } else {
        acc->balance -= amount;
        printf("Withdrew %.2f. New balance: %.2f\n", amount, acc->balance);
    }
}

int main() {
    Account acc;
    printf("Enter your account number: ");
    scanf("%d", &acc.accountNumber);
    printf("Enter initial balance: ");
    scanf("%f", &acc.balance);

    int choice;
    float amount;

    do {
        printf("\nBanking Operations:\n");
        printf("1 Deposit\n");
        printf("2 Withdraw\n");
        printf("3 Exit\n");
        printf("Enter the  choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to be  deposit: ");
                scanf("%f", &amount);
                deposit(&acc, amount);
                break;
            case 2:
                printf("Enter amount to be withdraw: ");
                scanf("%f", &amount);
                withdraw(&acc, amount);
                break;
            case 3:
                printf("Thanks for using our banking system.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}
