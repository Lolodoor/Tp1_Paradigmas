#include "lanza.h"

Lanza::Lanza() : Combate(ES::Combate, 8, 5, 7, TipoDeArma::lanza) {}

int Lanza::atacar() {
    return 8;
}
