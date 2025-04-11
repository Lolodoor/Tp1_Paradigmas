#pragma once

#include "../combate.h"

class HachaSimple : public Combate {
    public:
        HachaSimple();
        int ataqueEspecial() override;
        int hachaDeThor() const {
            cout << "¡Hacha de Thor! El hacha simple lanza un rayo que inflige daño adicional.\n";
            return dano * 2; 
        }

};
