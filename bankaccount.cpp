#include <iostream>
#include <string>
using namespace std;

// BankAccount Class Definition
class BankAccount
{
private:
    string accountNumber;
    double balance;

public:
    // Constructor to initialize accountNumber and balance
    BankAccount(string accNum)
	{
        accountNumber = accNum;
        balance = 0.0;
        cout << "Account " << accountNumber << " created with balance $0.0\n";
    }

    // Method to deposit money
    void deposit(double amount)
	{
        if (amount > 0)
		{
            balance += amount;
            cout << "Deposited $" << amount << ". Current balance: $" << balance << endl;
        }
		else
		{
            cout << "Deposit amount must be positive.\n";
        }
    }

    // Method to withdraw money
    void withdraw(double amount)
	{
        if (amount > balance)
		{
            cout << "Insufficient balance. Withdrawal failed.\n";
        }
		else if (amount <= 0)
		{
            cout << "Withdrawal amount must be positive.\n";
        }
		else
		{
            balance -= amount;
            cout << "Withdrew $" << amount << ". Current balance: $" << balance << endl;
        }
    }

    // Method to check balance
    void checkBalance() const
	{
        cout << "Current balance: $" << balance << endl;
    }
};

// Main Function
int main()
{
    // Create an instance of BankAccount
    string accountNumber;
    cout << "Enter your account number: ";
    cin >> accountNumber;
    BankAccount myAccount(accountNumber);

    int choice;
    double amount;

    do
	{
        cout << "\nBank Account Menu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
		{
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                myAccount.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                myAccount.withdraw(amount);
                break;
            case 3:
                myAccount.checkBalance();
                break;
            case 4:
                cout << "Exiting. Thank you!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
