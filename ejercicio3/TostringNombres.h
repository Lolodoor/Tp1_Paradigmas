#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../ejercicio2/personajes/personaje.h"
#include "../ejercicio2/armas/armas.h"
#include "factory/personajeFactory.h"

string nombreArma(shared_ptr<Arma> arma);
string nombrePersonaje(shared_ptr<Personaje> personaje);