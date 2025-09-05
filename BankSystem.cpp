#include "BankSystem.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

BankSystem::BankSystem(string file) {
    filename = file;
    loadFromFile();
}

void BankSystem::saveToFile() {
    ofstream out(filename);
    for (auto &acc : accounts) {
        out << acc.serialize() << endl;
    }
    out.close();
}

void BankSystem::loadFromFile() {
    accounts.clear();
    ifstream in(filename);
    string line;
    while (getline(in, line)) {
        if (!line.empty()) {
            accounts.push_back(BankAccount::deserialize(line));
        }
    }
    in.close();
}

void BankSystem::menu() {
    int choice;
    while (true) {
        cout << "\n===== Bank Management System =====";
        cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Account";
        cout << "\n5. Modify Account\n6. Delete Account\n7. Show All Accounts";
        cout << "\n8. Analytics\n9. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: displayAccount(); break;
            case 5: modifyAccount(); break;
            case 6: deleteAccount(); break;
            case 7: displayAll(); break;
            case 8: analytics(); break;
            case 9: saveToFile(); exit(0);
            default: cout << "Invalid choice.\n";
        }
    }
}

void BankSystem::createAccount() {
    std::string accNo;
    string name, addr;
    char type;
    double bal;

    cout << "Enter account no: ";
    cin >> accNo;
    cout << "Enter name: ";
    cin.ignore(); getline(cin, name);
    cout << "Enter address: ";
    getline(cin, addr);
    cout << "Enter type (s/c): ";
    cin >> type;
    type = tolower(type); 
    cout << "Enter initial balance: ";
    cin >> bal;

    accounts.push_back(BankAccount(accNo, name, addr, type, bal));
    saveToFile();
    cout << "Account created successfully!\n";
}

void BankSystem::deposit() {
    std::string accNo;
    double amt;
    cout << "Enter account no: "; cin >> accNo;
    for (auto &acc : accounts) {
        if (acc.getAccNo() == accNo) {
            cout << "Enter amount: "; cin >> amt;
            acc.deposit(amt);
            saveToFile();
            cout << "Deposited successfully.\n";
            return;
        }
    }
    cout << "Account not found.\n";
}

void BankSystem::withdraw() {
    std::string accNo;
    double amt;
    cout << "Enter account no: "; cin >> accNo;
    for (auto &acc : accounts) {
        if (acc.getAccNo() == accNo) {
            cout << "Enter amount: "; cin >> amt;
            if (acc.withdraw(amt)) {
                saveToFile();
                cout << "Withdrawn successfully.\n";
            } else {
                cout << "Insufficient funds.\n";
            }
            return;
        }
    }
    cout << "Account not found.\n";
}

void BankSystem::displayAccount() {
    std::string accNo;
    cout << "Enter account no: "; cin >> accNo;
    for (auto &acc : accounts) {
        if (acc.getAccNo() == accNo) {
            acc.display();
            return;
        }
    }
    cout << "Account not found.\n";
}

void BankSystem::modifyAccount() {
    std::string accNo;
    cout << "Enter account no: "; cin >> accNo;
    for (auto &acc : accounts) {
        if (acc.getAccNo() == accNo) {
            string newName, newAddr; char newType;
            cout << "Enter new name: ";
            cin.ignore(); getline(cin, newName);
            cout << "Enter new address: ";
            getline(cin, newAddr);
            cout << "Enter new type (s/c): ";
            cin >> newType;
            newType = tolower(newType);
            acc.modify(newName, newAddr, newType);
            saveToFile();
            cout << "Modified successfully.\n";
            return;
        }
    }
    cout << "Account not found.\n";
}

void BankSystem::deleteAccount() {
    std::string accNo;
    cout << "Enter account no: "; cin >> accNo;
    auto it = remove_if(accounts.begin(), accounts.end(),
                        [accNo](BankAccount &acc) { return acc.getAccNo() == accNo; });
    if (it != accounts.end()) {
        accounts.erase(it, accounts.end());
        saveToFile();
        cout << "Deleted successfully.\n";
    } else {
        cout << "Account not found.\n";
    }
}

void BankSystem::displayAll() {
    if (accounts.empty()) {
        cout << "No accounts available.\n";
        return;
    }
    for (auto &acc : accounts) {
        acc.display();
        cout << "---------------------\n";
    }
}

void BankSystem::analytics() {
    if (accounts.empty()) {
        cout << "No accounts to analyze.\n";
        return;
    }

    double total = 0;
    int savingsCount = 0, currentCount = 0;
    BankAccount richest = accounts[0];

    for (auto &acc : accounts) {
    total += acc.getBalance();
    char type = tolower(acc.getAccType());
    if (type == 's') savingsCount++;
    else if (type == 'c') currentCount++;

    if (acc.getBalance() > richest.getBalance())
        richest = acc;
}

    cout << "\n===== Analytics =====";
    cout << "\nTotal Bank Balance: " << total;
    cout << "\nSavings Accounts: " << savingsCount;
    cout << "\nCurrent Accounts: " << currentCount;
    cout << "\nRichest Account Holder: " << richest.getName()
         << " (" << richest.getBalance() << ")";
    cout << "\n=====================\n";
}