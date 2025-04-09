#include "magos.h"

Magos::Magos(TipoPersonaje tipo, int vida, int mana, bool muerto, 
             pair<shared_ptr<Arma>, shared_ptr<Arma>> armas)
    : tipo(tipo), vida(vida), mana(mana), armas(armas), muerto(muerto) {}

    
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

void Magos::equiparArma(shared_ptr<Arma> arma) {
    if (armas.first == nullptr) {
        armas.first = arma;
    } else if (armas.second == nullptr) {
        armas.second = arma;
    } else {
        cout << "ya tiene las dos armas" << endl;
    }
}

pair<shared_ptr<Arma>, shared_ptr<Arma>> Magos::obtenerArmas() const {
    return armas;
}





