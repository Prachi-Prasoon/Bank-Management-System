#include "BankAccount.h"
#include <sstream>

// Default constructor
BankAccount::BankAccount() : accNo(""), name(""), address(""), accType('\0'), balance(0.0) {}

BankAccount::BankAccount(std::string accNo, std::string name, std::string address, char accType, double balance) {
    this->accNo = accNo;
    this->name = name;
    this->address = address;
    this->accType = accType;
    this->balance = balance;
}

std::string BankAccount::getAccNo() const { return accNo; }
std::string BankAccount::getName() const { return name; }
double BankAccount::getBalance() const { return balance; }
char BankAccount::getAccType() const { return accType; }

void BankAccount::deposit(double amount) {
    balance += amount;
}

bool BankAccount::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

void BankAccount::display() const {
    std::cout << "\nAccount No: " << accNo
              << "\nName: " << name
              << "\nAddress: " << address
              << "\nAccount Type: " << (tolower(accType) == 's' ? "Savings" : "Current")
              << "\nBalance: " << balance << std::endl;
}

void BankAccount::modify(std::string newName, std::string newAddr, char newType) {
    name = newName;
    address = newAddr;
    accType = tolower(newType); 
}

// Save account as single line
std::string BankAccount::serialize() const {
    std::stringstream ss;
    ss << accNo << "|" << name << "|" << address << "|" << accType << "|" << balance;
    return ss.str();
}

// Load account from line
BankAccount BankAccount::deserialize(const std::string &line) {
    std::stringstream ss(line);
    std::string accNo, name, address;
    char actype;
    double balance;

    getline(ss, accNo, '|');
    getline(ss, name, '|');
    getline(ss, address, '|');
    ss >> actype;
    ss.ignore(1); // skip delimiter
    ss >> balance;

    return BankAccount(accNo, name, address, actype, balance);
}