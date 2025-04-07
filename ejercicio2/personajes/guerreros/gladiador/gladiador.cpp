#include "gladiador.h"

Gladiador::Gladiador() : Guerrero(TipoPersonaje::gladiador, 100, 150, false) {}

int Gladiador::habilidad(shared_ptr<Personaje> enemigo, shared_ptr<Arma> a) {
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
        int danoReducido = danoBase * 0.8; // Reduce el daño recibido en un 20%
        enemigo->recibirDano(danoReducido * 0.8); 
        return danoReducido;

    } else if (a->obtenerTipo() == ES::Combate) {
        auto armaCombate = dynamic_pointer_cast<Combate>(a);
        if (!armaCombate) {
            cerr << "Error: arma no es del tipo Combate." << endl;
            return 0;
        }

        int danoBase = armaCombate->obtenerDano();
        int danoIncrementado = danoBase * 1.3; // Incrementa el daño en un 30% con armas de combate
        enemigo->recibirDano(danoIncrementado);
        return danoIncrementado;
    } else {
        cerr << "Error: tipo de arma no válido." << endl;
        return 0;
    }
}

