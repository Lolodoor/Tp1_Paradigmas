#include "espada.h"


Espada::Espada() : Combate(ES::Combate, 10, 10, 3, TipoDeArma::espada) {}

int Espada::atacar(){
    return dano;
}