#include "baston.h"

Baston::Baston() : Magica(ES::Magica, 8, 4, 8, 10, TipoDeArma:: baston) {} 

int Baston::habilidadMagica() {
    srand(static_cast<unsigned int>(time(0))); 
    int probabilidad = rand() % 100; 

    if (probabilidad < 25) { // 25% de probabilidad de activar la habilidad mágica
        cout << "¡Habilidad mágica activada! El bastón lanza un rayo mágico que inflige daño adicional.\n";
        return dano * 2; // Doble de daño
    } else {
        cout << "La habilidad mágica del bastón no se activó.\n";
        return dano; // Daño normal
    }
}