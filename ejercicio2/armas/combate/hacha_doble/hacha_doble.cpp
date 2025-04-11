#include "hacha_doble.h"

HachaDoble::HachaDoble() : Combate(ES::Combate, 20, 20, 4, 10, TipoDeArma::dobleHacha) {}


int HachaDoble::ataqueEspecial() {
    srand(static_cast<unsigned int>(time(0))); 
    int probabilidad = rand() % 100; 

    if (probabilidad < 20) { // 20% de probabilidad de aumentar la velocidad de ataque
        cout << "¡Ataque rápido! El hacha doble aumenta su velocidad de ataque.\n";
        int velocidadIncrementada = velocidadAtaque + 10; // Aumentar la velocidad en 10
        cout << "Velocidad de ataque aumentada a: " << velocidadIncrementada << ".\n";
        return dano; 
    } else {
        cout << "El ataque especial del hacha doble no logró aumentar la velocidad.\n";
        return dano; 
    }
}

int HachaDoble::torbellino() const {
    cout << "¡Torbellino! El hacha doble lanza un torbellino que inflige daño adicional a los enemigos cercanos.\n";
    return dano * 2; 
}