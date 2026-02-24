//Assignment: Inheritance Lab
//Date: 2/23/26
//Author: Jeziel Torres
#include <iostream>
#include <memory>
using namespace std;
#include <vector>
#include "bankclasses.h"



int main() {
    vector<BankAccount*> accounts;
    int choice;
    int viewAccount;
    int accountChoice;
    double amountChange;
    string accountNameInput;

    do {
        cout << "Bank Account Manager" << endl;
        cout << "1. Create Account" << endl << "2. View Accounts" << endl << "3. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                accounts.push_back(BankAccount::createAccountFromInput());
                break;
            case 2:
                cout << "Choose account to view:" << endl;
                for (int i = 0; i < accounts.size(); i++) {
                    cout << i + 1 << ". " << accounts[i]->GetName() << endl;
                }
                cin >> viewAccount;
                if (viewAccount > accounts.size()) {
                    cout << "Invalid account choice" << endl;
                    break;
                }
                accountChoice = 0;
                while (accountChoice != -1) {
                    BankAccount::printAccount(*accounts[viewAccount - 1]);
                    cout << "1. Change Name" << endl << "2. Deposit" << endl << "3. Withdraw" << endl << "4. Compare Account" << endl << "5. Add Interest(Savings Only)" << endl << "6. Print History" << endl << "-1. Exit" << endl;
                    cin >> accountChoice;
                    if (accountChoice > 6 || accountChoice < -1) {
                        cout << "Invalid Choice" << endl;
                    }
                    else if (accountChoice == 1) {
                        cout << "Enter new account name:" << endl;
                        cin >> accountNameInput;
                        accounts[viewAccount - 1]->SetName(accountNameInput);
                    }
                    else if (accountChoice == 2) {
                        cout << "Enter amount to deposit:" << endl;
                        cin >> amountChange;
                        *accounts[viewAccount - 1] += amountChange;
                    }
                    else if (accountChoice == 3) {
                        cout << "Enter amount to withdraw:" << endl;
                        cin >> amountChange;
                        if (accounts[viewAccount - 1]->GetBalance() < amountChange) {
                            cout << "Insufficient Funds" << endl;
                        }
                        else {
                            *accounts[viewAccount - 1] -= amountChange;
                            cout << "New Balance: " << accounts[viewAccount - 1]->GetBalance() << endl;
                        }
                    }
                    else if (accountChoice == 4) {
                        int compareAccount = 0;
                        cout << "Choose account to compare:" << endl;
                        for (int i = 0; i < accounts.size(); i++) {
                            cout << i + 1 << ". " << accounts[i]->GetName() << endl;
                        }
                        cin >> compareAccount;
                        if (compareAccount > accounts.size()) {
                            cout << "Invalid account choice" << endl;
                        }
                        else {
                            if (accounts[viewAccount - 1] == accounts[compareAccount - 1]) {
                                cout << "Same Account Number: True" << endl;
                            }
                            else {
                                cout << "Same Account Number: False" << endl;
                            }
                            if (accounts[viewAccount - 1] > accounts[compareAccount - 1]) {
                                cout << accounts[viewAccount - 1]->GetName() << " has a larger balance than " << accounts[compareAccount - 1]->GetName() << endl << endl;
                            }
                            else if (accounts[viewAccount - 1] < accounts[compareAccount - 1]) {
                                cout << accounts[viewAccount - 1]->GetName() << " has a smaller balance than " << accounts[compareAccount - 1]->GetName() << endl << endl;
                            }
                        }
                    }
                    else if (accountChoice == 5) {
                            accounts[viewAccount -1]->calculateInterest();
                            cout << "Added Interest. New Amount: $" << accounts[viewAccount - 1]->GetBalance() << endl;
                    }
                    else if (accountChoice == 6) {
                        accounts[viewAccount - 1]->printHistory();
                    }
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
        }
    }while (choice != 3); {
        return 0;
    }
}