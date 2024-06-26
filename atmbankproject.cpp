#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Account
{
private:
    string accountNumber;
    string pin;
    double balance;

public:
    // Default constructor
    Account() : accountNumber(""), pin(""), balance(0.0) {}
    // Parameterized constructor
    Account(const string &accNum, const string &pinCode, double initialBalance)
        : accountNumber(accNum), pin(pinCode), balance(initialBalance) {}
    bool validatePIN(const string &enteredPin) const
    {
        return pin == enteredPin;
    }
    double checkBalance() const
    {
        return balance;
    }
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successful. Current balance: $" << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful. Current balance: $" << balance << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient balance." << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount." << endl;
        }
    }
};
class ATM
{
private:
    unordered_map<string, Account> accounts;

public:
    void addAccount(const string &accNum, const string &pinCode, double initialBalance)
    {
        Account newAccount(accNum, pinCode, initialBalance);
        accounts[accNum] = newAccount;
    }

    Account *getAccount(const string &accNum)
    {
        auto it = accounts.find(accNum);
        if (it != accounts.end())
        {
            return &(it->second);
        }
        else
        {
            return nullptr;
        }
    }
};
int main()
{
    ATM atm;

    // Adding some accounts to the ATM system atm.addAccount("123456789", "1234", 1000.0);
    atm.addAccount("987654321", "4321", 2000.0);
    string accountNumber,
        pin;
    cout << "Enter account number:
            ";	cin >> accountNumber;

        Account *account = atm.getAccount(accountNumber);
    if (account)
    {
        cout << "Enter PIN: ";
        cin >> pin;
        if (account->validatePIN(pin))
        {
            int choice;
            do
            {
                cout << "\nATM Menu:\n";
                cout << "1. Check Balance\n";

                cout << "2. Deposit Money\n";
                cout << "3. Withdraw Money\n";
                cout << "4. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    cout << "Current balance: $" << account->checkBalance()
                         << endl;
                    break;
                case 2:
                {
                    double depositAmount;
                    cout << "Enter amount to deposit: ";
                    cin >> depositAmount;
                    account -
                        > deposit(depositAmount);
                    break;
                }
                case 3:
                {
                    double withdrawAmount;
                    cout << "Enter amount to withdraw: ";
                    cin >> withdrawAmount;
                    account -
                        > withdraw(withdrawAmount);
                    break;
                }
                case 4:
                    cout << "Thank you for using the ATM. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                }
            } while (choice != 4);
        }
        else
        {
            cout << "Invalid PIN. Access denied." << endl;
        }
    }
    else
    {
        cout << "Account not found." << endl;
    }
    return 0;
}
