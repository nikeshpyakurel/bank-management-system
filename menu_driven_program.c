#include <stdio.h>
#include <stdlib.h>

// Structure For Accounts
struct Acc
{
    char name[50];
    int acc_num;
    float balance;
    char type[10];
};

// Global Variable
struct Acc customers[100000];
int customerDetails = 0;

// All Function Define
void addCustomer();
void customerInformation();
void amountDeposit();
void amountWithdrawl();
void balanceChecking();
void customerSearching();
void operationOption();

int main()
{
    int choice;
    do
    {
        operationOption();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addCustomer();
            break;
        case 2:
            customerInformation();
            break;
        case 3:
            amountDeposit();
            break;
        case 4:
            amountWithdrawl();
            break;
        case 5:
            balanceChecking();
            break;
        case 6:
            customerSearching();
            break;
        case 7:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (1);

    return 0;
}

// Function to print the menu
void operationOption()
{
    printf("\n\n\t\t\t\t****************************Welcome To NIC ASIA BANK*************************\n");
    printf("Menu:\n");
    printf("1. Add customer\n");
    printf("2. View customers\n");
    printf("3. Deposit amount\n");
    printf("4. Withdraw amount\n");
    printf("5. Check balance\n");
    printf("6. Search Customers\n");
    printf("7. Exit program\n");
}

// Function to add a new customer
void addCustomer()
{
    printf("\n\n\t\t\t\t****************************Add Customer*************************************\n");
    struct Acc customer;
    printf("Enter FullName (JhonDeo): ");
    scanf("%s", customer.name);
    printf("Enter AccountNumber: ");
    scanf("%d", &customer.acc_num);
    printf("Enter Balance: ");
    scanf("%f", &customer.balance);
    printf("Enter Account Type (Saving/Salary): ");
    scanf("%s", customer.type);
    customers[customerDetails++] = customer;
    printf("Customer Added Successfully.\n");
}

// Function to view all customers
void customerInformation()
{
    printf("\n\n\t\t\t\t****************************Customer Details**********************************\n");
    if (customerDetails == 0)
    {
        printf("No Customers Found.\n");
        return;
    }
    for (int i = 0; i < customerDetails; i++)
    {
        printf("Name: %s\n", customers[i].name);
        printf("Account number: %d\n", customers[i].acc_num);
        printf("Balance: %.2f\n", customers[i].balance);
        printf("Account type: %s\n", customers[i].type);
        printf("\n");
    }
}

// Function to deposit an amount for a customer
void amountDeposit()
{
    printf("\n\n\t\t\t\t****************************Deposit Amount****************************\n");
    int acc_num;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &acc_num);
    int found = 0;
    for (int i = 0; i < customerDetails; i++)
    {
        if (customers[i].acc_num == acc_num)
        {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            customers[i].balance += amount;
            printf("Amount Deposited Successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Customer Not Found.\n");
    }
}

// Function to withdraw an amount for a customer
void amountWithdrawl()
{
    printf("\n\n\t\t\t\t****************************Withdrawl Account****************************\n");
    int acc_num;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &acc_num);
    int found = 0;
    for (int i = 0; i < customerDetails; i++)
    {
        if (customers[i].acc_num == acc_num)
        {
            printf("Enter Amount to Withdrawl: ");
            scanf("%f", &amount);
            if (customers[i].balance < amount)
            {

                printf("Insufficiant Balance.\n");
            }
            else
            {

                customers[i].balance -= amount;
                printf("Amount Withdrawl Successfully.\n");
            }
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Customer Not Found.\n");
    }
}

void balanceChecking()
{
    printf("\n\n\t\t\t\t****************************Check Balance****************************\n");
    int acc_num;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &acc_num);
    int found = 0;
    for (int i = 0; i < customerDetails; i++)
    {
        if (customers[i].acc_num == acc_num)
        {
            amount = customers[i].balance;
            printf("Your Remaning Balance is : %f \n", amount);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Customer Not Found.\n");
    }
}
void customerSearching()
{
    printf("\n\n\t\t\t\t****************************Search Customer****************************\n");
    int acc_num;
    printf("Enter account number: ");
    scanf("%d", &acc_num);
    int found = 0;
    for (int i = 0; i < customerDetails; i++)
    {
        if (customers[i].acc_num == acc_num)
        {
            printf("Name: %s\n", customers[i].name);
            printf("Account number: %d\n", customers[i].acc_num);
            printf("Balance: %.2f\n", customers[i].balance);
            printf("Account Type: %s\n", customers[i].type);
            printf("\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Customer Not Found.\n");
    }
}