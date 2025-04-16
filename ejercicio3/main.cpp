#include "factory/PersonajeFactory.h"
#include "main.h"
#include <iostream>

using namespace std;


vector<vector<int>> generarAleatorio() {

    // genera un número aleatorio entre 0 y 2 para el número de armas que tendrá el mago y el guerrero
    // genera un numero entre 3 y 7 para el número de magos y guerreros que habrá

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
    vector<TipoPersonaje> tiposMagos = {
        TipoPersonaje::hechicero,
        TipoPersonaje::nigromante,
        TipoPersonaje::conjurador,
        TipoPersonaje::brujo
    };
    
    int magoIndex = rand() % tiposMagos.size();
    return PersonajeFactory::crearPersonajeArmado(tiposMagos[magoIndex], armas);
}

shared_ptr<Personaje> generarGuerreroAleatorio(pair<shared_ptr<Arma>, shared_ptr<Arma>> armas) {
    vector<TipoPersonaje> tiposGuerreros = {
        TipoPersonaje::paladin,
        TipoPersonaje::barbaro,
        TipoPersonaje::caballero,
        TipoPersonaje::mercenario,
        TipoPersonaje::gladiador
    };
    
    int guerreroIndex = rand() % tiposGuerreros.size();
    return PersonajeFactory::crearPersonajeArmado(tiposGuerreros[guerreroIndex], armas);
}

shared_ptr<Arma> generarArmaAleatoria() {
    vector<TipoDeArma> armasCombate = {
        TipoDeArma::hacha,
        TipoDeArma::dobleHacha,
        TipoDeArma::espada,
        TipoDeArma::lanza,
        TipoDeArma::garrote
    };

    vector<TipoDeArma> armasMagicas = {
        TipoDeArma::pocion,
        TipoDeArma::amuleto,
        TipoDeArma::baston,
        TipoDeArma::libroDeHechizos
    };

    int tipoArma = rand() % 2; // 0 para combate, 1 para mágica
    if (tipoArma == 0) {
        int armaIndex = rand() % armasCombate.size();
        return PersonajeFactory::crearArma(armasCombate[armaIndex]);
    } else {
        int armaIndex = rand() % armasMagicas.size();
        return PersonajeFactory::crearArma(armasMagicas[armaIndex]);
    }
}

int main() {
    // Inicializar la semilla de números aleatorios una sola vez
    srand(time(0));

    // Generar los vectores aleatorios para magos y guerreros para ver cuántos se crean y cuantas armas tienen
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


