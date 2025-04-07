#include "barbaro.h"


barbaro::barbaro() : Guerrero(TipoPersonaje::barbaro, 100, 150, false) {
    srand(time(nullptr));
}

int barbaro::habilidad(shared_ptr<Personaje> enemigo, shared_ptr<Arma> a) {
    if (!enemigo || !a) {
        cerr << "Error: enemigo o arma no válidos." << endl;
        return 0;
    }

    if (a->obtenerTipo() == ES::Magica) {
        auto armaMagica = dynamic_pointer_cast<Magica>(a);
        if (!armaMagica) {
            cerr << "Error: arma no es del tipo Magica." << endl;
            return 0;
        }
        int danoBase = armaMagica->obtenerDano(); 
        int danoTotal = danoBase;

        // Probabilidad de daño crítico
        if (rand() % 100 < 20) { // 20% de probabilidad
            danoTotal *= 2; // Daño crítico
        }

        enemigo->recibirDano(danoTotal);
        return danoTotal;

    } else if (a->obtenerTipo() == ES::Combate) {
        auto armaCombate = dynamic_pointer_cast<Combate>(a);
        if (!armaCombate) {
            cerr << "Error: arma no es del tipo Combate." << endl;
            return 0;
        }
        int danoBase = armaCombate->obtenerDano();
        int danoTotal = danoBase;

        // Probabilidad de daño crítico
        if (rand() % 100 < 25) { // 25% de probabilidad
            danoTotal *= 2; // Daño crítico
        }

        // Costo de ataque
        int costoEnergia = armaCombate->obtenerCostoAtaque();
        if (this->energia >= costoEnergia) {
            this->energia -= costoEnergia;
            enemigo->recibirDano(danoTotal);
            return danoTotal;
        } else {
            cerr << "Error: energía insuficiente para atacar." << endl;
            return 0; // No tiene suficiente energía
        }
    }

    cerr << "Error: tipo de arma desconocido." << endl;
    return 0;
}

