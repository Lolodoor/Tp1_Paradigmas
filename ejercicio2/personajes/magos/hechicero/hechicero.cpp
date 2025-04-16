#include "hechicero.h"

Hechicero::Hechicero(unique_ptr<Arma> arma1, unique_ptr<Arma> arma2)
    : Magos(TipoPersonaje::hechicero, 100, 200, false, pair<unique_ptr<Arma>, unique_ptr<Arma>>(std::move(arma1), std::move(arma2))) {}

int Hechicero::habilidad(shared_ptr<Personaje> enemigo, unique_ptr<Arma> a) {
    if (!enemigo || !a) {
        cerr << "Error: enemigo o arma no válidos." << endl;
        return 0;
    }

    if (a->obtenerTipo() == ES::Magica) {
        Magica* armaMagica = dynamic_cast<Magica*>(a.get());
        if (!armaMagica) {
            cerr << "Error: arma no es del tipo Magica." << endl;
            return 0;
        }

        int danoBase = armaMagica->obtenerDano();
        // Habilidad especial del hechicero: aumenta el daño mágico
        int danoTotal = danoBase * 1.5;
        enemigo->recibirDano(danoTotal);
        return danoTotal;

    } else if (a->obtenerTipo() == ES::Combate) {
        Combate* armaCombate = dynamic_cast<Combate*>(a.get());
        if (!armaCombate) {
            cerr << "Error: arma no es del tipo Combate." << endl;
            return 0;
        }

        int danoBase = armaCombate->obtenerDano();
        enemigo->recibirDano(danoBase);
        return danoBase;
    }

    cerr << "Error: tipo de arma no válido." << endl;
    return 0;
}