#include "magicas.h"

Magica::Magica(ES tipo, int dano, int velocidad, int costo,int peso, TipoDeArma tipoArma)
    : tipo(tipo), dano(dano), velocidadAtaque(velocidad), costoAtaque(costo),peso(peso), TipoArma(tipoArma) {}

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
    cout << "Atacando con " << dano << " de dano" << endl;
    return dano;
}

TipoDeArma Magica::obtenerTipoArma() const {
    return TipoArma; 
}

int Magica::obtenerPeso() const {
    return peso;
}

