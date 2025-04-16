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
#include "TostringNombres.h"

using namespace std;

vector<vector<int>> generarAleatorio();
shared_ptr<Personaje> generarMagoAleatorio(pair<unique_ptr<Arma>, unique_ptr<Arma>> armas);
shared_ptr<Personaje> generarGuerreroAleatorio(pair<unique_ptr<Arma>, unique_ptr<Arma>> armas);
unique_ptr<Arma> generarArmaAleatoria();
