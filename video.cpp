#include "video.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

video::video(long id, string nombre_pelicula, string genero_pelicula, int duracion_pelicula, float calificacion_pelicula, string nombreSerie)
    : pelicula(id, nombre_pelicula, genero_pelicula, duracion_pelicula, calificacion_pelicula), nombreSerie_(nombreSerie) {}

void video::calificar() {
    if (calificacion_pelicula == 0) {
        float nueva_calificacion;
        cout << "Califica la serie " << nombreSerie_ << " (1-5): ";
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

void video::prom() {
    while (true) {
        float nueva_calificacion;
        cout << "\nCalifica la serie " << nombreSerie_ << " (1-5) o ingresa 0 para dejar de calificar: ";
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

void video::mostrar() const {
    cout << "-----------------------------------------------------------" << endl;
    cout << endl;
    cout << "Id : " << id << endl;
    cout << "Nombre Serie : " << nombreSerie_ << endl;
    cout << "Genero : " << genero_pelicula << endl;
    cout << "Calificacion : " << calificacion_pelicula << endl;
    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
}

bool operator > (const video& object1, const video& object2) {
    return object1.obtenerCalificacion() > object2.obtenerCalificacion();
}
