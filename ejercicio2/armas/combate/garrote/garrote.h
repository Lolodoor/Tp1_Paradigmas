#pragma once

#include "../combate.h"

class Garrote : public Combate {
    public:
        Garrote();
        int ataqueEspecial() override;
        int garroteDeNegan() const {
            cout << "¡Garrote de Negan! El garrote de negan tiene alambre de pua y hace mucho mas dano.\n";
            return dano * 3; 
        }
};
