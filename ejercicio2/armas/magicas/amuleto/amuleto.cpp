#include "amuleto.h"

Amuleto::Amuleto() : Magica(ES::Magica, 0, 1, 10, 0, TipoDeArma::baston) {}

int Amuleto::habilidadMagica() {
    srand(static_cast<unsigned int>(time(0))); 
    int probabilidad = rand() % 100; 

    if (probabilidad < 20) { // 20% de probabilidad de activar la habilidad mágica
        cout << "¡Habilidad mágica activada! El amuleto hace un destello magico que enseguece a los enemigos cernanos.\n";
        return dano ; 
    } else {
        cout << "La habilidad mágica del amuleto no se activó.\n";
        return dano; 
    }
}

string Amuleto::escudoInduvidual() const {
    return "El amuleto proporciona un escudo individual que reduce el daño recibido en un 50% durante un turno.";
}