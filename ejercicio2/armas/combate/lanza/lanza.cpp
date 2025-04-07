#include "lanza.h"

Lanza::Lanza() : Combate(ES::Combate, 8, 7, 5, TipoDeArma::lanza) {}

int Lanza::atacar() {
    return 8;
}
