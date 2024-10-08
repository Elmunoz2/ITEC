#ifndef CLASE_HPP
#define CLASE_HPP

#include <string>

class pelicula {
protected:
    long id;
    std::string nombre_pelicula;
    std::string genero_pelicula;
    int duracion_pelicula;
    float calificacion_pelicula;
    float suma_calificaciones;
    int contador_calificaciones;

public:
    pelicula(long id, std::string nombre_pelicula, std::string genero_pelicula, int duracion_pelicula, float calificacion_pelicula = 0.0);

    virtual void calificar();
    void mostrar()  const;
    virtual void prom();
    float obtenerCalificacion() const; // Método para obtener la calificación
    std::string getGenero() const; 

    friend bool operator > (const pelicula& object1, const pelicula& object2);
};

#endif // CLASE_HPP
