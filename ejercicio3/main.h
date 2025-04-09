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
#include "TostringNombres.h"

using namespace std;

vector<vector<int>> generarAleatorio();
shared_ptr<Personaje> generarMagoAleatorio(pair<shared_ptr<Arma>, shared_ptr<Arma>> armas);
shared_ptr<Personaje> generarGuerreroAleatorio(pair<shared_ptr<Arma>, shared_ptr<Arma>> armas);
shared_ptr<Arma> generarArmaAleatoria();
