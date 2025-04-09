#pragma once

#include <iostream>
#include <string>
#include "../personajes/personaje.h"

using namespace std;

enum class TipoDeArma;

enum class ES {Magica, Combate};

class Arma {
public:
    virtual ES obtenerTipo() const = 0;
    virtual int obtenerDano() const = 0;
    virtual int obtenerVelocidadAtaque() const = 0;
    virtual int obtenerCostoAtaque() const = 0;
    virtual int atacar() = 0;
    virtual TipoDeArma obtenerTipoArma() const = 0; 
    virtual int obtenerPeso() const = 0;
    virtual ~Arma() {}
};