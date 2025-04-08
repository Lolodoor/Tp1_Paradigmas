#include "conjurador.h"

Conjurador::Conjurador(shared_ptr<Arma> arma1, shared_ptr<Arma> arma2)
    : Magos(TipoPersonaje::conjurador, 100, 200, false, {arma1, arma2}) {
    srand(time(nullptr));
}

int Conjurador::habilidad(shared_ptr<Personaje> enemigo, shared_ptr<Arma> a) {
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

        if (armaMagica->obtenerTipoArma() == TipoDeArma::amuleto) {
            // Probabilidad de curarse y regenerar energía
            if (rand() % 100 < 30) { // 30% de probabilidad
                int vidaCurada = static_cast<int>(0.2 * vida); // Curar 20% de la vida que tiene 
                this->curar(vidaCurada);

                int manaRegenerada = 50; // Regenerar 50 puntos de mana
                this->mana += mana;
                if (this->mana > 200) { // Suponiendo que el mana máximo es 200
                    this->mana = 200;
                }

                cout << "El conjurador se curó " << vidaCurada << " puntos de vida y regeneró " << manaRegenerada << " puntos de mana." << endl;
                return vidaCurada;
            } else {
                cout << "El conjurador no logró activar el efecto del amuleto." << endl;
                return 0;
            }
        } else {
            int danoBase = armaMagica->obtenerDano();
            enemigo->recibirDano(danoBase);
            return danoBase;
        }

    } else if (a->obtenerTipo() == ES::Combate) {
        auto armaCombate = dynamic_pointer_cast<Combate>(a);
        if (!armaCombate) {
            cerr << "Error: arma no es del tipo Combate." << endl;
            return 0;
        }

        int danoBase = armaCombate->obtenerDano();
        enemigo->recibirDano(danoBase);
        return danoBase;
    } else {
        cerr << "Error: tipo de arma no válido." << endl;
        return 0;
    }
}