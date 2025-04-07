#include "baston.h"

Baston::Baston() : Magica(ES::Magica, 8, 8, 4, TipoDeArma:: baston) {} 

int Baston::atacar() {
    return 8;
}


