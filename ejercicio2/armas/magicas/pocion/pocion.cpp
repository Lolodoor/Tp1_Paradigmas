#include "pocion.h"

Pocion::Pocion() : Magica(ES::Magica, 20, 2, 15, 3, TipoDeArma::pocion) {}

int Pocion::habilidadMagica() {
    srand(static_cast<unsigned int>(time(0))); 
    int probabilidad = rand() % 100; 

    if (probabilidad < 50) { // 50% de probabilidad de activar la habilidad mágica
        cout << "¡Habilidad mágica activada! La poción envenena.\n";
        return dano * 1.2; 
    } else {
        cout << "La habilidad mágica de la poción no se activó.\n";
        return dano; // Daño normal
    }
}
