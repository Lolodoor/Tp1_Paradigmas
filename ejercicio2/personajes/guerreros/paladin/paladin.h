#pragma once

#include "../guerreros.h"
#include "../../../armas/armas.h"
#include "../../../armas/combate/combate.h"
#include "../../../armas/magicas/magicas.h"

class Paladin : public Guerrero {
    public:
    Paladin();
    int habilidad(shared_ptr<Personaje> enemigo, shared_ptr<Arma> a) override;
};