#include "garrote.h"

Garrote::Garrote() : Combate(ES::Combate, 15, 12, 1, TipoDeArma::garrote) {}

int Garrote::atacar() {
    return 15;
}
