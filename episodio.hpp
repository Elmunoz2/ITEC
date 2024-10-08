#ifndef EPISODIO_HPP
#define EPISODIO_HPP

#include "video.hpp"
#include <string>

class episodio : public video {
public:
    std::string titulo_episodio;
    int duracion_episodio;
    int num_episodio;

public:
    episodio(long id, std::string nombre_pelicula, std::string genero_pelicula, int duracion_pelicula, float calificacion_pelicula, std::string nombreSerie, std::string titulo_episodio, int duracion_episodio, int num_episodio);

    void mostrar() const;
    float getCalificacion() const;
};

#endif // EPISODIO_HPP
