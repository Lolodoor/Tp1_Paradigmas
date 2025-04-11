#pragma once

#include "../magicas.h"

class LibroDeHechizos : public Magica {
public:
    LibroDeHechizos();
    int habilidadMagica() override;
    string darkHole() const {
        return "hechizo oscuro, fortalece todas las habilidades mágicas del usuario y debilita a los enemigos.\n";
    }
};


