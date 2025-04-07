#include "hacha_doble.h"

HachaDoble::HachaDoble() : Combate(ES::Combate, 20, 20, 4, TipoDeArma::dobleHacha) {}

int HachaDoble::atacar() {
    return 20;
}
