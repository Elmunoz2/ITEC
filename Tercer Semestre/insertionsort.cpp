// [3, 2, 15, 1, 7]
// Empieza desde el 2 [i = 1], compara el 3 con el 2 y swap
// [2, 3, 15, 1, 7]
// Compara el 3 > 15, FALSE, y continua
// [2, 3, 15, 1, 7]
// Compara el 15 > 1, TRUE y hacen swap 
// [2, 3, 1, 15, 7]
// Compara el 3 > 1, TRUE y hacen swap
// [2, 1, 3, 15, 7]
// Compara el 2 > 1, TRUE, y hacen swap 
// [1, 2, 3, 15, 7]
// Compara 15 > 7, TRUE y hacen swap 
// [1, 2, 3, 7, 15]

#include <iostream>
#include <vector>

using namespace std;

#include <vector>
using namespace std;

using namespace std;

bool esPrimo(int num) {
    for (int i = 2; i * i <= num; i++) {  
        if (num % i == 0) {
            return false;
        }
    }
    return true;  
}


void insertionSort(vector<int>& vec) {
    for (int i = 1; i < vec.size(); i++) {
        int key = vec[i];  // Guarda el valor actual.
        int j = i - 1;

        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];  
            j = j - 1;
        }
        vec[j + 1] = key;  
    }
}

int main() {
    vector<int> vec = {12, 5, 3, 7, 11, 4, 8, 13};

    // Quitar números no primos del vector
    for (int i = 0; i < vec.size(); i++) {
        if (!esPrimo(vec[i])) { 
            vec.erase(vec.begin() + i);  
            i--;  
        }
    }
    
    insertionSort(vec);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";  
    }
    cout << endl; 
    return 0;  
}
