#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > target) {
            return vec[i]; // Devolvemos el primer número mayor que el valor dado
        }
    }
    return -1; // No hay
}

int main() {
    vector<int> vec = {5, 2, 9, 7, 4, 6};
    int target;

    cout << "Introduce el valor de referencia: ";
    cin >> target;

    int result = binarySearch(vec, target);

    if (result != -1) {
        cout << "El primer elemento mayor que " << target << " es " << result << "." << endl;
    } else {
        cout << "No se encontro ningun elemento mayor que " << target << "." << endl;
    }

    return 0;
}
