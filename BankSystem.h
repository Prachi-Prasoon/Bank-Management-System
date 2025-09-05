#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include "BankAccount.h"
#include <vector>

class BankSystem {
private:
    vector<BankAccount> accounts;
    string filename;

    void saveToFile();
    void loadFromFile();

public:
    BankSystem(string file = "accounts.txt");
    void menu();

    // Account operations
    void createAccount();
    void deposit();
    void withdraw();
    void displayAccount();
    void modifyAccount();
    void deleteAccount();
    void displayAll();

    // Analytics
    void analytics();
};

#endif