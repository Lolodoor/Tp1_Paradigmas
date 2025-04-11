#pragma once

#include "../combate.h"

class Lanza : public Combate {
    public:
        Lanza();
        int ataqueEspecial() override;
        int vuelo() const {
            cout << "¡Vuelo! La lanza va por el aire y agarra una velocidad aumentada.\n";
            return velocidadAtaque * 2; 
        }
};
