#include "combate.h"

Combate::Combate(ES tipo, int dano, int velocidad, int costo, TipoDeArma tipoArma)
    : tipo(tipo), dano(dano), velocidadAtaque(velocidad), costoAtaque(costo), tipoArma(tipoArma) {
    
}

ES Combate::obtenerTipo() const {
    return tipo;
}

int Combate::obtenerDano() const {
    return dano;
}

int Combate::obtenerVelocidadAtaque() const {
    return velocidadAtaque;
}

int Combate::obtenerCostoAtaque() const {
    return costoAtaque;
}

int Combate::atacar() {
    return dano;
}

TipoDeArma Combate::obtenerTipoArma() const {
    return tipoArma; 
}