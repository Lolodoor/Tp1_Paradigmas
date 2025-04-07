#include "pocion.h"

Pocion::Pocion() : Magica(ES::Magica, 20, 15, 2, TipoDeArma::pocion) {}

int Pocion::atacar() {
    return 20;
}
