#include "factory/personajeFactory.h"
#include <iostream>

using namespace std;

string nombreArma(shared_ptr<Arma> arma) {
    if (!arma) return "Sin arma";

    switch (arma->obtenerTipoArma()) { 
        case TipoDeArma::hacha: return "Hacha Simple";
        case TipoDeArma::dobleHacha: return "Hacha Doble";
        case TipoDeArma::espada: return "Espada";
        case TipoDeArma::lanza: return "Lanza";
        case TipoDeArma::garrote: return "Garrote";
        case TipoDeArma::pocion: return "Poción";
        case TipoDeArma::amuleto: return "Amuleto";
        case TipoDeArma::baston: return "Bastón";
        case TipoDeArma::libroDeHechizos: return "Libro de Hechizos";
        default: return "Arma desconocida";
    }
}

string nombrePersonaje(shared_ptr<Personaje> personaje) {
    switch (personaje->obtenerTipo()) { 
        case TipoPersonaje::hechicero: return "Hechicero";
        case TipoPersonaje::nigromante: return "Nigromante";
        case TipoPersonaje::conjurador: return "Conjurador";
        case TipoPersonaje::brujo: return "Brujo";
        case TipoPersonaje::paladin: return "Paladín";
        case TipoPersonaje::barbaro: return "Bárbaro";
        case TipoPersonaje::caballero: return "Caballero";
        case TipoPersonaje::mercenario: return "Mercenario";
        default: return "Personaje desconocido";
    }
}

vector<vector<int>> generarAleatorio() {
    vector<int> armasMago;
    vector<int> armasGuerrero;

    int valorMago = 3 + rand() % 5;
    int valorGuerrero = 3 + rand() % 5;

    for (int i = 0; i < valorMago; i++) {
        int numero = rand() % 3;
        armasMago.push_back(numero);
    }

    for (int i = 0; i < valorGuerrero; i++) {
        int numero = rand() % 3;
        armasGuerrero.push_back(numero);
    }

    vector<vector<int>> armas;
    armas.push_back(armasMago);
    armas.push_back(armasGuerrero);

    return armas;
}

shared_ptr<Personaje> generarMagoAleatorio(pair<shared_ptr<Arma>, shared_ptr<Arma>> armas) {
    int magoIndex = rand() % 4;

    // Unpack the pair into arma1 and arma2
    shared_ptr<Arma> arma1 = armas.first;
    shared_ptr<Arma> arma2 = armas.second;

    switch (magoIndex) {
        case 0:
            return make_shared<Hechicero>(arma1, arma2);
        case 1:
            return make_shared<Nigromante>(arma1, arma2);
        case 2:
            return make_shared<Conjurador>(arma1, arma2);
        case 3:
            return make_shared<Brujo>(arma1, arma2);
        default:
            return nullptr;
    }
}

shared_ptr<Personaje> generarGuerreroAleatorio(pair<shared_ptr<Arma>, shared_ptr<Arma>> armas) {
    int guerreroIndex = rand() % 4; // Ajustar rango a 0-3 para evitar índices inválidos

    // Unpack the pair into arma1 and arma2
    shared_ptr<Arma> arma1 = armas.first;
    shared_ptr<Arma> arma2 = armas.second;

    switch (guerreroIndex) {
        case 0:
            return make_shared<Paladin>(arma1, arma2);
        case 1:
            return make_shared<barbaro>(arma1, arma2);
        case 2:
            return make_shared<Caballero>(arma1, arma2);
        case 3:
            return make_shared<Mercenario>(arma1, arma2);
        default:
            // Este caso nunca debería ocurrir, pero lo manejamos por seguridad
            cout << "Error: Índice de guerrero inválido (" << guerreroIndex << ")." << endl;
            return nullptr;
    }
}

shared_ptr<Arma> generarArmaAleatoria() {
    int tipoArma = rand() % 2; // 0 para combate, 1 para mágica
    if (tipoArma == 0) {
        int armaIndex = rand() % 5; 
        switch (armaIndex) {
            case 0: return make_shared<HachaSimple>();
            case 1: return make_shared<HachaDoble>();
            case 2: return make_shared<Espada>();
            case 3: return make_shared<Lanza>();
            case 4: return make_shared<Garrote>();
        }
    } else {
        int armaIndex = rand() % 4; 
        switch (armaIndex) {
            case 0: return make_shared<Pocion>();
            case 1: return make_shared<Amuleto>();
            case 2: return make_shared<Baston>();
            case 3: return make_shared<LibroDeHechizos>();
        }
    }
    return nullptr;
}

int main() {
    // Inicializar la semilla de números aleatorios una sola vez
    srand(time(0));

    // Generar los vectores aleatorios para magos y guerreros
    vector<vector<int>> armasConfig = generarAleatorio();
    vector<int> magosConfig = armasConfig[0];
    vector<int> guerrerosConfig = armasConfig[1];

    // Crear los magos
    vector<shared_ptr<Personaje>> magos;
    for (int config : magosConfig) {
        shared_ptr<Arma> arma1 = nullptr;
        shared_ptr<Arma> arma2 = nullptr;

        if (config == 1) {
            arma1 = generarArmaAleatoria();
        } else if (config == 2) {
            arma1 = generarArmaAleatoria();
            arma2 = generarArmaAleatoria();
        }

        pair<shared_ptr<Arma>, shared_ptr<Arma>> armas = {arma1, arma2};
        magos.push_back(generarMagoAleatorio(armas));
    }

    // Crear los guerreros
    vector<shared_ptr<Personaje>> guerreros;
    for (int config : guerrerosConfig) {
        shared_ptr<Arma> arma1 = nullptr;
        shared_ptr<Arma> arma2 = nullptr;

        if (config == 1) {
            arma1 = generarArmaAleatoria();
        } else if (config == 2) {
            arma1 = generarArmaAleatoria();
            arma2 = generarArmaAleatoria();
        }

        pair<shared_ptr<Arma>, shared_ptr<Arma>> armas = {arma1, arma2};
        guerreros.push_back(generarGuerreroAleatorio(armas));
    }

    // Mostrar información de los magos
    cout << "Magos creados:" << endl;
    for (size_t i = 0; i < magos.size(); ++i) {
        cout << "Mago " << i + 1 << " (" << nombrePersonaje(magos[i]) << "): ";
        if (magos[i]) {
            auto armas = magos[i]->obtenerArmas();
            cout << "Arma 1: " << nombreArma(armas.first) << ", ";
            cout << "Arma 2: " << nombreArma(armas.second) << endl;
        } else {
            cout << "Error al crear el mago." << endl; 
        }
    }

    // Mostrar información de los guerreros
    cout << "Guerreros creados:" << endl;
    for (size_t i = 0; i < guerreros.size(); ++i) {
        cout << "Guerrero " << i + 1 << " (" << nombrePersonaje(guerreros[i]) << "): ";
        if (guerreros[i]) {
            auto armas = guerreros[i]->obtenerArmas();
            cout << "Arma 1: " << nombreArma(armas.first) << ", ";
            cout << "Arma 2: " << nombreArma(armas.second) << endl;
        } else {
            cout << "Error al crear el guerrero." << endl;
        }
    }

    return 0;
}


