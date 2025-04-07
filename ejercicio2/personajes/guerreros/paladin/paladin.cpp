#include "paladin.h"

Paladin::Paladin() : Guerrero(TipoPersonaje::paladin, 100, 150, false) {
    srand(time(nullptr));
}


int Paladin::habilidad(shared_ptr<Personaje> enemigo, shared_ptr<Arma> a) {
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

        enemigo->recibirDano(danoTotal);
        return danoTotal;

    } else if (a->obtenerTipo() == ES::Combate) {
        auto armaCombate = dynamic_pointer_cast<Combate>(a);
        if (!armaCombate) {
            cerr << "Error: arma no es del tipo Combate." << endl;
            return 0;
        }
       
        if (armaCombate->obtenerTipoArma() == TipoDeArma::espada) { // Cambia TipoArma por TipoDeArma
            int danoBase = armaCombate->obtenerDano();
            int danoTotal = danoBase * 2; // Doble de daño

            enemigo->recibirDano(danoTotal);
            return danoTotal;
        } else {
            int danoBase = armaCombate->obtenerDano();
            enemigo->recibirDano(danoBase);
            return danoBase;
        }
    } else {
        cerr << "Error: tipo de arma no válido." << endl;
        return 0;
    }
}