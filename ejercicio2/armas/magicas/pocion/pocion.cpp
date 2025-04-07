#include "pocion.h"

Pocion::Pocion() : Magica(ES::Magica, 20, 2, 15, TipoDeArma::pocion) {}

int Pocion::atacar() {
    return dano;
}
