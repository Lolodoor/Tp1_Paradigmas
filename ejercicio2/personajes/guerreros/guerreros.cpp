#include "guerreros.h"

Guerrero::Guerrero(TipoPersonaje tipo, int vida, int energia, bool muerto, 
                   pair<unique_ptr<Arma>, unique_ptr<Arma>> armas)
    : tipo(tipo), vida(vida), energia(energia), armas(std::move(armas)), muerto(muerto) {}

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

void Guerrero::equiparArma(unique_ptr<Arma> arma) {
    if (!armas.first) {
        armas.first = std::move(arma);
    } else if (!armas.second) {
        armas.second = std::move(arma);
    } else {
        cout << "Ambos espacios de armas están ocupados." << endl;
    }
}

pair<unique_ptr<Arma>, unique_ptr<Arma>>& Guerrero::obtenerArmas() {
    return armas;
}





