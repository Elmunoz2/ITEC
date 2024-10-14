#include <iostream>
#include <string>

using namespace std;

string encoder(const string& str) {
    string encoded = "";

    if (str.empty()) {
        return encoded;
    }

    int contador = 1;  // Inicializa el contador de caracteres repetidos
    char prev = str[0];  // Guarda el primer carácter como referencia

    // Recorre el string desde el segundo carácter
    for (size_t i = 1; i < str.length(); i++) {
        if (str[i] == prev) {  // Si el carácter actual es igual al anterior
            contador++;
        } else {
            // Agrega el carácter anterior y su contador a la cadena codificada
            encoded += prev + to_string(contador);
            prev = str[i];  // Actualiza el carácter anterior al actual
            contador = 1;   // Reinicia el contador
        }
    }

    // Agrega el último carácter y su contador
    encoded += prev + to_string(contador);

    return encoded;  // Devuelve la cadena codificada
}

int main() {
    string input;
    cout << "Ingresa una cadena para codificar: ";
    cin >> input;

    string encodedString = encoder(input);
    cout << "Cadena codificada: " << encodedString << endl;

    return 0;
}