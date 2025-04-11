#include "hacha_simple.h"

HachaSimple::HachaSimple() : Combate(ES::Combate, 12, 10, 2, 5 ,TipoDeArma::hacha) {}



int HachaSimple::ataqueEspecial() {
    srand(static_cast<unsigned int>(time(0))); 
    int probabilidad = rand() % 100; \

    if (probabilidad < 30) { // 30% de probabilidad de activar el ataque especial
        cout << "¡Golpe pesado! El hacha simple aumenta su peso, reduce su velocidad y hace más daño.\n";
        int nuevoPeso = peso + 2; // Aumentar el peso en 2
        int nuevaVelocidad = velocidadAtaque - 1; // Reducir la velocidad en 1
        int nuevoDano = dano + 8; // Aumentar el daño en 8

        cout << "Nuevo peso: " << nuevoPeso << ", nueva velocidad de ataque: " << nuevaVelocidad 
             << ", nuevo daño: " << nuevoDano << ".\n";

        return nuevoDano; // Retornar el daño aumentado
    } else {
        cout << "El ataque especial del hacha simple no se activó.\n";
        return dano; // Daño normal
    }
}