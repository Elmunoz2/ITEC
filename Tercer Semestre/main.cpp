#include <iostream>
#include "Bank.h"

int main() {
    Bank myBank;

    myBank.addAccount("12345", 1000.0);
    myBank.addAccount("67890", 1500.0);

    myBank.deposit("12345", 200.0);
    cout << "Balance de la cuenta 12345 despues del deposito: " << myBank.getBalance("12345") << endl;

    int result = myBank.deposit("11111", 100.0); // Intento de depositar en una cuenta inexistente
    if (result == -1) {
        cout << "Deposito fallido. Cuenta no encontrada." << endl;
    }

    return 0;
}


