#include <iostream>
using namespace std;

struct Movie {
    string title;
    int year;
};

int main()
{
    Movie movie;
    movie.title = "Intensamente";
    movie.year = 2016;
    cout << "Titulo: " << movie.title << endl << "Ano de estreno: " << movie.year << endl;

    // Crear una estructura Profesores, atletas, clientes......
    // Estructura 4
    // ID entero
    // Nombre string
    // email string
    // telefono entero
    // Pedir datos al usuario
    
    return 0;
}