#include "espada.h"


Espada::Espada() : Combate(ES::Combate, 10, 3, 10, 20, TipoDeArma::espada) {}


int Espada::ataqueEspecial() {
    srand(static_cast<unsigned int>(time(0))); 
    int probabilidad = rand() % 100; 

    if (probabilidad < 30) { // 30% de probabilidad de corte crítico
        cout << "¡Corte crítico! La espada inflige daño adicional.\n";
        return dano * 2; // Doble de daño
    } else {
        cout << "El ataque especial de la espada no logró un corte crítico.\n";
        return dano; 
    }
}

int Espada::filo() const {
    cout << "¡Filo! La espada inflige mas dano al ser lanzada.\n";
    return dano * 1.5; 
}
    