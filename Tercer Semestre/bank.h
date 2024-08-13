#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Bank {
public:
    void addAccount(string accountNumber, double initialBalance);
    double getBalance(string accountNumber);
    int deposit(string accountNumber, double amount);

private:
    struct BankAccount {
        string accountNumber;
        double balance;
    };

    vector<BankAccount> accounts;

    int findAccountIndex(string accountNumber);
};

#endif // BANK_H
