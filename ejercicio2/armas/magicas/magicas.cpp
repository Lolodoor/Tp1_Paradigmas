#include "magicas.h"

Magica::Magica(ES tipo, int dano, int velocidad, int costo, TipoDeArma tipoArma)
    : tipo(tipo), dano(dano), velocidadAtaque(velocidad), costoAtaque(costo), TipoArma(tipoArma) {}

ES Magica::obtenerTipo() const {
    return tipo;
}

int Magica::obtenerDano() const {
    return dano;
}

int Magica::obtenerVelocidadAtaque() const {
    return velocidadAtaque;
}

int Magica::obtenerCostoAtaque() const {
    return costoAtaque;
}

int Magica::atacar() {
    return dano;
}

TipoDeArma Magica::obtenerTipoArma() const {
    return TipoArma; 
}

