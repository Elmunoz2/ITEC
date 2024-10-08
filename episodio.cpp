#include "episodio.hpp"
#include <iostream>

using namespace std;

episodio::episodio(long id, string nombre_pelicula, string genero_pelicula, int duracion_pelicula, float calificacion_pelicula, string nombreSerie, string titulo_episodio, int duracion_episodio, int num_episodio)
    : video(id, nombre_pelicula, genero_pelicula, duracion_pelicula, calificacion_pelicula, nombreSerie), titulo_episodio(titulo_episodio), duracion_episodio(duracion_episodio), num_episodio(num_episodio) {}

void episodio::mostrar() const {
    cout << "-----------------------------------------------------------" << endl;
    cout << endl;
    cout << "Id : " << id << endl;
    cout << "Nombre Serie : " << nombreSerie_ << endl;
    cout << "Titulo del Episodio : " << titulo_episodio << endl;
    cout << "Numero de Episodio : " << num_episodio << endl;
    cout << "Duracion : " << duracion_episodio << " minutos" << endl;
    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
}
