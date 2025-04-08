#pragma once

#include "../magos.h"
#include "../../../armas/armas.h"
#include "../../../armas/combate/combate.h"
#include "../../../armas/magicas/magicas.h"

class Hechicero : public Magos {
public:
    Hechicero(); 
    int habilidad(shared_ptr<Personaje> enemigo, shared_ptr<Arma> a) override;
};
