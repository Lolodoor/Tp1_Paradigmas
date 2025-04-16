#include "nigromante.h"

Nigromante::Nigromante(unique_ptr<Arma> arma1, unique_ptr<Arma> arma2)
    : Magos(
        TipoPersonaje::nigromante,100,200,false,pair<unique_ptr<Arma>, unique_ptr<Arma>>(std::move(arma1), std::move(arma2))) {
    srand(time(nullptr));
}

int Nigromante::habilidad(shared_ptr<Personaje> enemigo, unique_ptr<Arma> a) {
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
    }
    else if (a->obtenerTipo() == ES::Combate) {
        Combate* armaCombate = dynamic_cast<Combate*>(a.get());
        if (!armaCombate) {
            cerr << "Error: arma no es del tipo Combate." << endl;
            return 0;
        }

        int danoBase = armaCombate->obtenerDano();
        enemigo->recibirDano(danoBase);

        // Check if the Nigromante is killed and resurrect with 25 health
        if (this->obtenerVida() <= 0) {
            this->curar(25);
            cout << "El Nigromante ha renacido con 25 de vida!" << endl;
        }

        return danoBase;
    } else {
        cerr << "Error: tipo de arma no válido." << endl;
        return 0;
    }
    return 0;
}