#pragma once
#include "../magicas.h"

class Pocion : public Magica {
public:
    Pocion();
    int habilidadMagica() override;
    int pocionDeVelocidad() const {
        cout << "¡Poción de velocidad activada! Aumenta la velocidad de ataque del usuario.\n";
        return velocidadAtaque * 1.5; 
    }
};

