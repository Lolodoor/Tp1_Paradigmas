#include "amuleto.h"

Amuleto::Amuleto() : Magica(ES::Magica, 0, 1, 10,TipoDeArma::baston) {}

int Amuleto::atacar() {
    return dano;
}
