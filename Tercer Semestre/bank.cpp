#include "Bank.h"

void Bank::addAccount(string accountNumber, double initialBalance) {
    accounts.push_back({accountNumber, initialBalance});
}

double Bank::getBalance(string accountNumber) {
    int index = findAccountIndex(accountNumber);
    if (index != -1) {
        return accounts[index].balance;
    }
    return -1; // Devuelve -1 si no se encuentra la cuenta
}

int Bank::findAccountIndex(string accountNumber) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1; // Devuelve -1 si no se encuentra la cuenta
}

int Bank::deposit(string accountNumber, double amount) {
    int index = findAccountIndex(accountNumber);
    if (index != -1) {
        accounts[index].balance += amount;
        return 0; // Indica que el depósito fue exitoso
    }
    return -1; // Indica que la cuenta no se encontró
}