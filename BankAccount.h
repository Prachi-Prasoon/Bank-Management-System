#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    std::string accNo;
    string name, address;
    char accType;   // 's' = savings, 'c' = current
    double balance;

public:
    BankAccount();
    BankAccount(std::string accNo, std::string name, std::string address, char accType, double balance);

    // Getters
    std::string getAccNo() const;
    string getName() const;
    double getBalance() const;
    char getAccType() const;

    // Operations
    void deposit(double amount);
    bool withdraw(double amount);
    void display() const;
    void modify(string newName, string newAddr, char newType);

    // Persistence helpers
    string serialize() const;
    static BankAccount deserialize(const string &line);
};

#endif