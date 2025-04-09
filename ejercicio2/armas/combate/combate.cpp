#include "combate.h"

Combate::Combate(ES tipo, int dano, int velocidad, int costo, int peso, TipoDeArma tipoArma)
    : tipo(tipo), dano(dano), velocidadAtaque(velocidad), costoAtaque(costo), peso (peso),tipoArma(tipoArma) {
    
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
    cout << "Atacando con " << static_cast<int>(tipoArma) << endl;
    return dano;
}

TipoDeArma Combate::obtenerTipoArma() const {
    return tipoArma; 
}

int Combate::obtenerPeso() const {
    return peso;
}