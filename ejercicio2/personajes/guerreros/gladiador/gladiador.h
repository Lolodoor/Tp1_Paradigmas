#pragma once

#include "../guerreros.h"
#include "../../../armas/armas.h"
#include "../../../armas/combate/combate.h"
#include "../../../armas/magicas/magicas.h"

class Gladiador : public Guerrero {
public:
    Gladiador(shared_ptr<Arma> arma1, shared_ptr<Arma> arma2); // Constructor actualizado
    int habilidad(shared_ptr<Personaje> enemigo, shared_ptr<Arma> a) override;
};