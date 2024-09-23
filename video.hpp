#ifndef VIDEO_HPP
#define VIDEO_HPP

#include "clase.hpp"
#include <string>

class video : public pelicula {
protected:
    std::string nombreSerie_;
public:
    video(long id, std::string nombre_pelicula, std::string genero_pelicula, int duracion_pelicula, float calificacion_pelicula, std::string nombreSerie);

    void calificar() override;
    void mostrar() const;
    void prom() override;

    friend bool operator > (const video& object1, const video& object2);
};

#endif // VIDEO_HPP
