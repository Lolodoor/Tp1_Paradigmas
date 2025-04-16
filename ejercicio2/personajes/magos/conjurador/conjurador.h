#pragma once

#include "../magos.h"
#include "../../../armas/armas.h"
#include "../../../armas/combate/combate.h"
#include "../../../armas/magicas/magicas.h"

class Conjurador : public Magos {
public:
    Conjurador(unique_ptr<Arma> arma1, unique_ptr<Arma> arma2);
    int habilidad(shared_ptr<Personaje> enemigo, unique_ptr<Arma> a) override;
};
