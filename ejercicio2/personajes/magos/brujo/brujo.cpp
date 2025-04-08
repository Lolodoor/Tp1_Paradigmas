#include "brujo.h"

Brujo::Brujo() : Magos(TipoPersonaje::brujo, 100, 200, false) {}

int Brujo::habilidad(shared_ptr<Personaje> enemigo, shared_ptr<Arma> a) {
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

        if (armaMagica->obtenerTipoArma() == TipoDeArma::pocion) {
            int opcion;
            cout << "Elige el efecto de la poción:" << endl;
            cout << "1. Daño extra" << endl;
            cout << "2. Curación" << endl;
            cout << "3. Regeneración de mana" << endl;
            cin >> opcion;

            switch (opcion) {
                case 1: {
                    int danoExtra = 50; // Ejemplo: aumenta el daño en 50
                    cout << "El brujo usa una poción de daño extra. Daño aumentado en " << danoExtra << " puntos." << endl;
                    enemigo->recibirDano(danoExtra);
                    return danoExtra;
                }
                case 2: {
                    int vidaCurada = 30; // Ejemplo: cura 30 puntos de vida
                    cout << "El brujo usa una poción de curación. Se cura " << vidaCurada << " puntos de vida." << endl;
                    this->curar(vidaCurada);
                    return vidaCurada;
                }
                case 3: {
                    int manaRegenerada = 40; // Ejemplo: regenera 40 puntos de mana
                    cout << "El brujo usa una poción de mana. Regenera " << manaRegenerada << " puntos de mana." << endl;
                    this->mana += manaRegenerada;
                    if (this->mana > 200) { // Suponiendo que el mana máximo es 200
                        this->mana = 200;
                    }
                    return manaRegenerada;
                }
                default:
                    cerr << "Opción no válida. No se aplicó ningún efecto." << endl;
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