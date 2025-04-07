#pragma once
#include "../armas.h"
#include "../../personajes/personaje.h"

class Magica : public Arma {
protected:
    ES tipo;
    int dano;
    int velocidadAtaque;
    int costoAtaque;
    TipoDeArma TipoArma; 

public:
    Magica(ES tipo, int dano, int velocidad, int costo, TipoDeArma tipoArma); 
    ES obtenerTipo() const override;
    int obtenerDano() const override;
    int obtenerVelocidadAtaque() const override;
    int obtenerCostoAtaque() const override;
    int atacar() override;
    TipoDeArma obtenerTipoArma() const override; 
};