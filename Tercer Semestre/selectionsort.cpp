//Selection Sort 

// [2,18,33,3,10] (CUADRATICO)
// minVal = X, 2, compara con el que sigue (18), 18 > 2, True, se queda. y con todos los demas.
// minVal = X, 2, compara con el que sigue (33), 33 ....
// minVal = X, 18, mismo proceso, llega hasta el 3 y hacen swap.
// Posicion = se guarda la posicion del menor (en este caso "3") y hacen swap.

#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        // Encontrar el valor mínimo en el resto del vector
        int minVal = i;
        for (int j = i + 1; j < n; j++) {
            if (vec[j] < vec[minVal]) {
                minVal = j;
            }
        }
        // Intercambiar el valor mínimo encontrado con el primer valor no ordenado
        if (minVal != i) {
            swap(vec[i], vec[minVal]);
        }
    }
}

int main(){
    vector<int> vec = {2,18,33,3,10};
    selectionSort(vec);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
        }
}