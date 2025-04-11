#include "lanza.h"

Lanza::Lanza() : Combate(ES::Combate, 8, 5, 7, 5, TipoDeArma::lanza) {}


int Lanza::ataqueEspecial() {
    srand(static_cast<unsigned int>(time(0))); 
    int probabilidad = rand() % 100;

    if (probabilidad < 25) { // 25% de probabilidad de activar el filo afilado al ser lanzada
        cout << "¡Filo afilado! La lanza inflige un daño crítico al ser lanzada.\n";
        return dano * 2; // Doble de daño
    } else {
        cout << "El ataque especial de la lanza no activó el filo afilado.\n";
        return dano; // Daño normal
    }
}