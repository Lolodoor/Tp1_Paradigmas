#include "magos.h"

Magos::Magos(TipoPersonaje tipo, int vida, int mana, bool muerto, 
             pair<unique_ptr<Arma>, unique_ptr<Arma>> armas)
    : tipo(tipo), vida(vida), mana(mana), armas(std::move(armas)), muerto(muerto) {}

    
int Magos::obtenerVida() const {
    return vida;
}
TipoPersonaje Magos::obtenerTipo() const {
    return tipo;
}
int Magos::obtenerMana() const {
    return mana;
}
bool Magos::estaMuerto() {
    return muerto;
}

void Magos::recibirDano(int dano) {
    vida -= dano;
    if (vida <= 0) {
        muerto = true;
    }
}
void Magos::curar(int curacion) {
    vida += curacion;
    if (vida > 100) {
        vida = 100; 
    }
}

void Magos::equiparArma(unique_ptr<Arma> arma) {
    if (!armas.first) {
        armas.first = std::move(arma);
    } else if (!armas.second) {
        armas.second = std::move(arma);
    } else {
        armas.first = std::move(arma);
    }
}

pair<unique_ptr<Arma>, unique_ptr<Arma>>& Magos::obtenerArmas() {
    return armas;
}





