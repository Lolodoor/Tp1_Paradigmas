#include "garrote.h"

Garrote::Garrote() : Combate(ES::Combate, 15, 1, 12, TipoDeArma::garrote) {}

int Garrote::atacar() {
    return 15;
}
