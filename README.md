# Bank Management System

A **C++ console-based Bank Management System** using **object-oriented programming (OOP)**, persistent storage, and basic analytics for bank accounts.  
This system allows creating, managing, and analyzing bank accounts with support for account types, deposits, withdrawals, and more.

---

## Features

- **Account Operations**
  - Create a new account with account number, name, address, account type, and initial balance.
  - Deposit money into an account.
  - Withdraw money from an account (with balance checks).
  - View account details.
  - Modify account information (name, address, account type).
  - Delete an account.
  - Display all accounts.

- **Persistence**
  - All accounts are saved to a file (`accounts.txt`) for permanent storage.
  - Accounts are automatically loaded on program startup.

- **Analytics**
  - View total bank balance.
  - Count of **Savings** and **Current** accounts.
  - Identify the **richest account holder**.

- **Flexible Account Numbers**
  - Account numbers can be alphanumeric and up to 13–14 characters.

- **User-Friendly CLI**
  - Simple console menu with clear options for all operations.

---

## Technologies Used

- **Programming Language:** C++
- **Concepts:** Object-Oriented Programming (Classes, Encapsulation, Vectors)
- **File I/O:** Persistent storage using text files
- **Standard Library:** `<iostream>`, `<vector>`, `<fstream>`, `<algorithm>`, `<sstream>`

---

## Project Structure

<img width="571" height="300" alt="image" src="https://github.com/user-attachments/assets/36ffb7ae-8718-4bb5-9c4c-88b1b67366d5" />

BankManagementSystem/
│
├── BankAccount.h # BankAccount class definition
├── BankAccount.cpp # BankAccount class implementation
├── BankSystem.h # BankSystem class definition
├── BankSystem.cpp # BankSystem class implementation
├── main.cpp # Main entry point
└── accounts.txt # Persistent storage (created automatically)


## Key Highlights

- Fully **OOP-based architecture**
- Persistent storage ensures data is never lost
- Supports **alphanumeric account numbers**
- Built-in **analytics**
- Modular, clean, and extendable design

---

## Potential Improvements

- Add **password/login system**
- GUI interface with **Qt or SFML**
- Support for **multiple currencies**
- Advanced **analytics and reports**
- Networked version with **client-server architecture**
