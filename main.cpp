#include <iostream>
#include <vector>
#include "clase.hpp"
#include "video.hpp"
#include "episodio.hpp"

using namespace std;

//g++ main.cpp clase.cpp video.cpp episodio.cpp -o miPrograma


void calificarYMostrar(pelicula& peli) {
    int respuesta;
    cout << "1. Calificar Pelicula:\n"
         << "2. Mostrar Informacion:\n"
         << "Opcion: ";
    cin >> respuesta;
    if (respuesta == 1) {
        peli.calificar();
        cout << "\nDeseas calificar de nuevo:\n"
             << "1. Si\n"
             << "2. No\n"
             << "Opcion: ";
        int opcion2;
        cin >> opcion2;
        if (opcion2 == 1) {
            peli.prom();
        }
    } else if (respuesta == 2) {
        peli.mostrar();
    } else {
        cout << "Opcion invalida." << endl;
    }
}

void calificarYMostrar_serie(video& serie, vector<episodio>& episodios) {
    int respuesta;
    cout << "\n1. Calificar Serie\n"
         << "2. Mostrar Episodios\n"
         << "3. Info de la serie\n"
         << "Opcion: ";
    cin >> respuesta;
    
    if (respuesta == 1) {
        serie.calificar();
        cout << "\nDeseas calificar de nuevo:\n"
             << "1. Si\n"
             << "2. No\n"
             << "Opcion: ";
        int opcion2;
        cin >> opcion2;
        if (opcion2 == 1) {
            serie.prom();
        }
    } 
    else if (respuesta == 2) {
        for (vector<episodio>::size_type i = 0; i < episodios.size(); ++i) {
            cout << i + 1 << ". " << episodios[i].titulo_episodio << "\n";
        }
        cout << "Elige el episodio a mostrar: ";
        vector<episodio>::size_type opcion3;
        cin >> opcion3;
        if (opcion3 > 0 && opcion3 <= episodios.size()) {
            episodios[opcion3 - 1].mostrar();
        } 
    } 
    else if (respuesta == 3) {
        serie.mostrar();
    } 
    else {
        cout << "Opcion invalida." << endl;
    }
}

void menuPeliculas(vector<pelicula>& peliculas) {
    pelicula mayor(0, "", "", 0);

    while (true) {
        cout << "\nElige la pelicula:\n"
             << "1. Toy Story\n"
             << "2. Madagascar\n"
             << "3. Avengers\n"
             << "4. Exorcista\n"
             << "5. SCI - New York\n"
             << "6. Pelicula Mejor Calificada\n"
             << "7. Volver al menu principal\n"
             << "Opcion: ";

        int opcion;
        cin >> opcion;

        if (opcion >= 1 && opcion <= 5) {
            calificarYMostrar(peliculas[opcion - 1]);
        } else if (opcion == 6) {
            for (const auto& p : peliculas) {
                if (p > mayor) {
                    mayor = p;
                }
            }
            cout << "Pelicula Mejor Calificada:\n";
            mayor.mostrar();
        } else if (opcion == 7) {
            break;
        } else {
            cout << "Opcion invalida." << endl;
        }
    }
}

void menuSerie(vector<video>& series, vector<vector<episodio>>& episodios) {
    video mayor(0, "", "", 0, 0.0, "");

    while (true) {
        cout << "\nElige la serie:\n"
             << "1. La casa de Papel\n"
             << "2. Breaking Bad\n"
             << "3. Game of Thrones\n"
             << "4. Serie Mejor Calificada\n"
             << "5. Volver al menu principal\n"
             << "Opcion: ";

        int opcion;
        cin >> opcion;

        if (opcion >= 1 && opcion <= 3) {
            calificarYMostrar_serie(series[opcion - 1], episodios[opcion - 1]);
        } else if (opcion == 4) {
            for (const auto& s : series) {
                if (s > mayor) {
                    mayor = s;
                }
            }
            cout << "Serie Mejor Calificada:\n";
            mayor.mostrar();
        } else if (opcion == 5) {
            break;
        } else {
            cout << "Opcion invalida." << endl;
        }
    }
}

void menuGenero(vector<pelicula>& peliculas, vector<video>& series, vector<vector<episodio>>) {
    vector<string> generos = { "Infantil", "Fantasia", "Miedo", "Drama" };
    while (true) {
        cout << "\nElige el genero:\n"
             << "1. Infantil\n"
             << "2. Fantasia\n"
             << "3. Miedo\n"
             << "4. Drama\n"
             << "5. Volver al menu principal\n"
             << "Opcion: ";

        int opcion;
        cin >> opcion;

        if (opcion >= 1 && opcion <= 4) {
            cout << "\nPeliculas del genero seleccionado:\n";
            for (const auto& peli : peliculas) {
                if (peli.getGenero() == generos[opcion - 1]) {
                    peli.mostrar();
                }
            }
            cout << "Series del genero seleccionado:\n";
            for (const auto& serie : series) {
                if (serie.getGenero() == generos[opcion - 1]) {
                    serie.mostrar();
                }
            }
        } else if (opcion == 5) {
            break;
        } else {
            cout << "Opcion invalida." << endl;
        }
    }
}

int main() {
    vector<pelicula> peliculas = {
        pelicula(19861, "Toy Story", "Infantil", 175),
        pelicula(19862, "Madagascar", "Infantil", 200),
        pelicula(19863, "Avengers", "Fantasia", 162),
        pelicula(19864, "Exorcista", "Miedo", 170),
        pelicula(19865, "SCI - New York", "Drama", 146)
    };

    vector<video> series = {
        video(1986, "x", "Drama", 120, 0.0, "La Casa de Papel"),
        video(1234, "x", "Drama", 50, 0.0, "Breaking Bad"),
        video(9876, "x", "Fantasia", 60, 0.0, "Game of Thrones"),
        video(2345, "x", "Miedo", 60, 0.0, "Stranger Things"),
        video(7890, "x", "Infantil", 60, 0.0, "Paw Patrol")
    };

vector<vector<episodio>> episodios = {
    { 
        episodio(19861, "E1", "Drama", 120, 0.0, "La Casa de Papel", "El final del camino", 48, 1),
        episodio(19862, "E2", "Drama", 120, 0.0, "La Casa de Papel", "Suspiros de Espana", 43, 2),
        episodio(19863, "E3", "Drama", 120, 0.0, "La Casa de Papel", "Plan Paris", 41, 3)
    },
    { 
        episodio(12341, "E1", "Drama", 50, 0.0, "Breaking Bad", "Principio del fin", 44, 1),
        episodio(12342, "E2", "Drama", 50, 0.0, "Breaking Bad", "El gato en la bolsa", 35, 2),
        episodio(12343, "E3", "Drama", 50, 0.0, "Breaking Bad", "Y la bolsa en el rio", 31, 3)
    },
    { 
        episodio(98761, "E1", "Fantasia", 60, 0.0, "Game of Thrones", "Cuatro Marcos", 29, 1),
        episodio(98762, "E2", "Fantasia", 60, 0.0, "Game of Thrones", "Luna Traicionera", 45, 2),
        episodio(98763, "E3", "Fantasia", 60, 0.0, "Game of Thrones", "Especies Raras", 46, 3) 
    },
    { 
        episodio(23451, "E1", "Miedo", 60, 0.0, "Stranger Things", "Cuatro Marcos", 49, 1),
        episodio(23452, "E2", "Miedo", 60, 0.0, "Stranger Things", "Luna Traicionera", 65, 2),
        episodio(23453, "E3", "Miedo", 60, 0.0, "Stranger Things", "Especies Raras", 55, 3) 
    },
    { 
        episodio(78901, "E1", "Infantil", 60, 0.0, "Paw Patrol", "Cuatro Marcos", 11, 1),
        episodio(78902, "E2", "Infantil", 60, 0.0, "Paw Patrol", "Luna Traicionera", 12, 2),
        episodio(78903, "E3", "Infantil", 60, 0.0, "Paw Patrol", "Especies Raras", 15, 3) 
    }
};


    while (true) {
        cout << "\nBienvenido a Esflix\n"
             << "Elige:\n"
             << "1. Peliculas\n"
             << "2. Series\n"
             << "3. Generos\n"
             << "4. Salir\n"
             << "Opcion:";

        int opcion;
        cin >> opcion;

        if (opcion == 1) {
            menuPeliculas(peliculas);
        } else if (opcion == 2) {
            menuSerie(series, episodios);
        } else if (opcion == 3) {
            menuGenero(peliculas, series, episodios);
        } else if (opcion == 4){
            break;
        } else {
            cout << "Opcion invalida." << endl;
        }
    }

    return 0;
}
