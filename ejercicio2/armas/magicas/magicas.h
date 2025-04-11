#pragma once
#include "../armas.h"
#include "../../personajes/personaje.h"

class Magica : public Arma {
protected:
    ES tipo;
    int dano;
    int velocidadAtaque;
    int costoAtaque;
    int peso;
    TipoDeArma TipoArma; 

public:
    Magica(ES tipo, int dano, int velocidad, int costo, int peso, TipoDeArma tipoArma); 
    ES obtenerTipo() const override;
    int obtenerDano() const override;
    int obtenerVelocidadAtaque() const override;
    int obtenerCostoAtaque() const override;
    int atacar() override;
    TipoDeArma obtenerTipoArma() const override; 
    int obtenerPeso() const override;
    virtual int habilidadMagica() = 0;
};