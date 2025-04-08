#include "hechicero.h"


Hechicero::Hechicero(shared_ptr<Arma> arma1, shared_ptr<Arma> arma2)
    : Magos(TipoPersonaje::hechicero, 100, 200, false, {arma1, arma2}) {
    srand(time(nullptr));
}

int Hechicero::habilidad(shared_ptr<Personaje> enemigo, shared_ptr<Arma> a) {
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

        if (armaMagica->obtenerTipoArma() == TipoDeArma::libroDeHechizos) {

            int danoBase = armaMagica->obtenerDano();
            int danoTotal = danoBase * 2; // Doble de daño para el libro de hechizos

            enemigo->recibirDano(danoTotal);
            return danoTotal;
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