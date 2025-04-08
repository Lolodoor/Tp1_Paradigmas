#include "nigromante.h"

Nigromante::Nigromante() : Magos(TipoPersonaje::nigromante, 100, 200, false) {}

int Nigromante::habilidad(shared_ptr<Personaje> enemigo, shared_ptr<Arma> a) {
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
    }
    else if (a->obtenerTipo() == ES::Combate) {
        auto armaCombate = dynamic_pointer_cast<Combate>(a);
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