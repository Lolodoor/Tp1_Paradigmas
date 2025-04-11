#pragma once

#include "../magicas.h"

class Baston : public Magica {
public:
    Baston();
    int habilidadMagica() override;
    int bolaDeFuego() const {
        cout << "¡Bola de fuego lanzada! El bastón lanza una bola de fuego que inflige daño adicional.\n";
        return dano * 2; 
    }
};