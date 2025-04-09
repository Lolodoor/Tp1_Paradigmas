#include "../ejercicio3/TostringNombres.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <memory>
using namespace std;

enum class Ataque {golpeFuerte, golpeRapido, defensaYgolpe};

string AtaqueToString(Ataque a);
Ataque obtenerAtaqueJugador1();
Ataque obtenerAtaqueJugador2();
shared_ptr<Personaje> crearPersonajeRival();
shared_ptr<Arma> crearArmaJugador() ;
shared_ptr<Personaje> crearPersonajeJugador();
void resolverRonda(shared_ptr<Personaje> jugador1, shared_ptr<Personaje> jugador2, Ataque ataque1, Ataque ataque2);
