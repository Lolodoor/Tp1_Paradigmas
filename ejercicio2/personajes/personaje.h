#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Arma; 

#include "../armas/armas.h"

using namespace std;

enum class TipoDeArma {
    baston, 
    libroDeHechizos, 
    amuleto, 
    pocion, 
    espada, 
    hacha, 
    dobleHacha, 
    lanza, 
    garrote
};
enum class TipoPersonaje {
    hechicero, 
    conjurador, 
    brujo, 
    nigromante, 
    gladiador, 
    paladin, 
    caballero, 
    mercenario, 
    barbaro
};


class Personaje {
    public:
        virtual int obtenerVida() const = 0;
        virtual TipoPersonaje obtenerTipo() const = 0;
        virtual void recibirDano(int dano) = 0; 
        virtual void curar(int vida) = 0;
        virtual pair<shared_ptr<Arma>, shared_ptr<Arma>> obtenerArmas() const = 0;
        virtual void equiparArma(shared_ptr<Arma> arma) = 0;
        virtual bool estaMuerto() = 0;
        

        virtual ~Personaje() {}
};
