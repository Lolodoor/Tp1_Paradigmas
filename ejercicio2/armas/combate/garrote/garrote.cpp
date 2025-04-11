#include "garrote.h"

Garrote::Garrote() : Combate(ES::Combate, 15, 1, 12, 35, TipoDeArma::garrote) {}


int Garrote::ataqueEspecial() {
    srand(static_cast<unsigned int>(time(0))); 
    int probabilidad = rand() % 100; 

    if (probabilidad < 15) { // 15% de probabilidad de golpe fuerte
        cout << "¡Golpe fuerte! El garrote inflige daño masivo.\n";
        return dano * 3; // Triple de daño
    } else {
        cout << "El ataque especial del garrote no logró un golpe fuerte.\n";
        return dano; 
    }
}
  