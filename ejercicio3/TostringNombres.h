#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../ejercicio2/personajes/personaje.h"
#include "../ejercicio2/armas/armas.h"
#include "factory/PersonajeFactory.h"

// con estas funciones se convierten los enums a string para imprimirlos

string nombreArma(const unique_ptr<Arma>& arma);
string nombrePersonaje(const shared_ptr<Personaje>& personaje);
