//
// Created by Jeziel on 2/23/2026.
//

#ifndef INHERITENCE_LAB_BANKCLASSES_H
#define INHERITENCE_LAB_BANKCLASSES_H

#endif //INHERITENCE_LAB_BANKCLASSES_H
#include <iostream>
#include <string>



#include <memory>
using namespace std;

class Transaction {
public:
    Transaction(string method, double money) {
        type = method;
        amount = money;
    };
    string type;
    double amount;
    string timestamp;
};

class BankAccount {
    public:
        BankAccount();
        BankAccount(const BankAccount& other) = default;
        BankAccount& operator=(const BankAccount& other) = default;
        virtual ~BankAccount() = default;
        BankAccount(string name, string number, double money) {
            accountName = name;
            accountNumber = number;
            balance = money;;
        }
        void printHistory() {
            cout << "-Transaction History-" << endl;
            for (int i = 0; i < transactionHistory.size(); i++) {
                cout << transactionHistory[i].type << ": $" << transactionHistory[i].amount << endl;
            }

        }
        //Setters
        void SetName(string name) {
            accountName = name;
        }
        //Getters
        string GetName() {
            return accountName;
        }
        string GetNumber() {
            return accountNumber;
        }
        double GetBalance() {
            return balance;
        }
        //+/- Operators
        BankAccount& operator+=(double amount) {
            if (amount > -1) {
                balance += amount;
                transactionHistory.push_back(Transaction("Deposit", amount));
            }
            return *this;
        }
        virtual BankAccount& operator-=(double amount) {
            if (amount > -1 && balance > amount) {
                balance -= amount;
                transactionHistory.push_back(Transaction("Withdrawal", amount));
            }
            else {
                if (amount < 0) {
                    cout << "Amount cannot be negative." << endl;
                }
                if (amount > balance) {
                    cout << "Insufficient funds." << endl;
                }
            }
            return *this;
        }
        virtual void calculateInterest() {}
        //Comparison functions
        bool operator==(const BankAccount& other) const {
            return accountNumber == other.accountNumber;
        }
        bool operator<(const BankAccount& other) const {
            return balance < other.balance;
        }
        bool operator>(const BankAccount& other) const {
            return balance > other.balance;
        }
        //Static Utility Functions
        static void printAccount(const BankAccount& account) {
            cout << "Account Name: " << account.accountName << endl;
            cout << "Account Number: " << account.accountNumber << endl;
            cout << "Balance: " << account.balance << endl;
        }
        static BankAccount* createAccountFromInput();

    private:
        string accountNumber;
        string accountName;
        double balance;
        vector<Transaction> transactionHistory;
};

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(string name, string number, double money) : BankAccount(name, number, money) {
        transactionFee = .50;
    };
    //Withdraw
    BankAccount& operator-=(double amount) override {
        return BankAccount::operator-=(amount + transactionFee);
    }

private:
    double transactionFee;
};

class SavingAccount : public BankAccount {
public:
    SavingAccount(string name, string number, double money) : BankAccount(name, number, money) {
        interestRate = .02;
    };
    void calculateInterest() {
        *this += GetBalance() * interestRate;
    }
private:
    double interestRate;
};

inline BankAccount* BankAccount::createAccountFromInput() {
    int type;
    string name;
    string number;
    double money;
    cout << "Enter type of account: 1. Checking($0.50 Fee) 2. Savings(2% Interest)" << endl;
    cin >> type;
    cout << "Enter account name:" << endl;
    cin >> name;
    cout << "Enter account number:" << endl;
    cin >> number;
    cout << "Enter account balance:" << endl;
    cin >> money;
    if (type == 1) {
        cout << "Created Checking Account " << name << " with account number " << number << " with a balance of $" << money << endl;
        return new CheckingAccount(name, number, money);
    }
    else{
        cout << "Created Savings Account " << name << " with account number " << number << " with a balance of $" << money << endl;
        return new SavingAccount(name, number, money);
    }
}