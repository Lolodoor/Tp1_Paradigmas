#include "espada.h"


Espada::Espada() : Combate(ES::Combate, 10, 3, 10, TipoDeArma::espada) {}

int Espada::atacar(){
    return dano;
}
