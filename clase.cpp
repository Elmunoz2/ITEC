#include "clase.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

pelicula::pelicula(long id, string nombre_pelicula, string genero_pelicula, int duracion_pelicula, float calificacion_pelicula)
    : id(id), nombre_pelicula(nombre_pelicula), genero_pelicula(genero_pelicula), duracion_pelicula(duracion_pelicula), calificacion_pelicula(calificacion_pelicula), suma_calificaciones(calificacion_pelicula), contador_calificaciones(1) {
    if (calificacion_pelicula == 0) {
        contador_calificaciones = 0;
    }
}

void pelicula::calificar() {
    if (calificacion_pelicula == 0) {
        float nueva_calificacion;
        cout << "Califica la pelicula " << nombre_pelicula << " (1-5): ";
        cin >> nueva_calificacion;

        if (nueva_calificacion < 1 || nueva_calificacion > 5) {
            cout << "Calificacion invalida. Por favor ingrese un valor entre 1 y 5." << endl;
        } else {
            calificacion_pelicula = nueva_calificacion;
            suma_calificaciones = nueva_calificacion;
            contador_calificaciones = 1;
            cout << "Calificacion actualizada a " << calificacion_pelicula << endl;
        }
    } else {
        prom();
    }
}

void pelicula::mostrar() const {
    cout << "-----------------------------------------------------------" << endl;
    cout << endl;
    cout << "Id : " << id << endl;
    cout << "Nombre : " << nombre_pelicula << endl;
    cout << "Genero : " << genero_pelicula << endl;
    cout << "Duracion : " << duracion_pelicula << " minutos" << endl;
    cout << "Calificacion : " << calificacion_pelicula << endl;
    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
}

void pelicula::prom() {
    while (true) {
        float nueva_calificacion;
        cout << "\nCalifica la pelicula " << nombre_pelicula << " (1-5) o ingresa 0 para dejar de calificar: ";
        cin >> nueva_calificacion;

        if (nueva_calificacion == 0) {
            break;
        }

        if (nueva_calificacion < 1 || nueva_calificacion > 5) {
            cout << "Calificacion invalida. Por favor ingrese un valor entre 1 y 5." << endl;
        } else {
            suma_calificaciones += nueva_calificacion;
            contador_calificaciones++;
            calificacion_pelicula = suma_calificaciones / contador_calificaciones;
            cout << fixed << setprecision(2);
            cout << "Calificacion actualizada a " << calificacion_pelicula << endl;
        }
    }
}

bool operator > (const pelicula& object1, const pelicula& object2) {
    return object1.obtenerCalificacion() > object2.obtenerCalificacion();
}

float pelicula::obtenerCalificacion() const {
    return calificacion_pelicula;
}

string pelicula::getGenero() const {
    return genero_pelicula;
}