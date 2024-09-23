
// Bubble Source (CUADRATICO)

// [2, 5, 8, 12] : Xi <= Xi +1
// 2 es mas grande  que 5, no no es, 5 es mas grande que 8, no no es, 8 es mayor de 12, no no es

// [5, 2, 7, 3, | 12]
// 5 es mayor que 2, si es, hacen swap, 5 es mgrande que 7, no, 7 es mas grande que 3, si y hacen swap 

#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubblesort(vector<int> &vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {  
            if (vec[j] > vec[j + 1]) {
                swap (vec[j], vec [j+1]);
            }
        }
    }
}

int main() {
    vector<int> vec;

    cout << "Introduce 7 calificaciones: ";
    for (int i = 0; i < 7; i++) {
        int cali;
        cin >> cali;
        vec.push_back(cali);
    }
    
    bubblesort(vec);  
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    
    return 0;
}