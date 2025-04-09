#include "guerreros.h"

Guerrero::Guerrero(TipoPersonaje tipo, int vida, int energia, bool muerto, 
                   pair<shared_ptr<Arma>, shared_ptr<Arma>> armas)
    : tipo(tipo), vida(vida), energia(energia), armas(armas), muerto(muerto) {}

int Guerrero::obtenerVida() const {return vida;}
TipoPersonaje Guerrero::obtenerTipo() const {return tipo;}
int Guerrero::obtenerEnergia() const {return energia;}
bool Guerrero::estaMuerto() {return muerto;}

void Guerrero::recibirDano(int dano) {
    vida -= dano;
    if (vida <= 0) {
        muerto = true;
    }
}
void Guerrero::curar(int curacion) {
    vida += curacion;
    if (vida > 100) {
        vida = 100; 
    }
}

void Guerrero::equiparArma(shared_ptr<Arma> arma) {
    if (armas.first == nullptr) {
        armas.first = arma;
    } else if (armas.second == nullptr) {
        armas.second = arma;
    } else {
        cout << "ya tiene las dos armas" << endl;
    }
}

pair<shared_ptr<Arma>, shared_ptr<Arma>> Guerrero::obtenerArmas() const {
    return armas;
}





