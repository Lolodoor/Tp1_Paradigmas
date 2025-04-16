#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "../../ejercicio2/personajes/personaje.h"
#include "../../ejercicio2/personajes/guerreros/barbaro/barbaro.h"
#include "../../ejercicio2/personajes/guerreros/paladin/paladin.h"
#include "../../ejercicio2/personajes/guerreros/gladiador/gladiador.h"
#include "../../ejercicio2/personajes/guerreros/caballero/caballero.h"
#include "../../ejercicio2/personajes/guerreros/mercenario/mercenario.h"
#include "../../ejercicio2/personajes/guerreros/guerreros.h"
#include "../../ejercicio2/personajes/magos/magos.h"
#include "../../ejercicio2/personajes/magos/hechicero/hechicero.h"
#include "../../ejercicio2/personajes/magos/conjurador/conjurador.h"
#include "../../ejercicio2/personajes/magos/brujo/brujo.h"
#include "../../ejercicio2/personajes/magos/nigromante/nigromante.h"
#include "../../ejercicio2/armas/armas.h"
#include "../../ejercicio2/armas/magicas/magicas.h"
#include "../../ejercicio2/armas/magicas/baston/baston.h"
#include "../../ejercicio2/armas/magicas/amuleto/amuleto.h"
#include "../../ejercicio2/armas/magicas/libro_de_hechizos/libro_de_hechizos.h"
#include "../../ejercicio2/armas/magicas/pocion/pocion.h"
#include "../../ejercicio2/armas/combate/combate.h"
#include "../../ejercicio2/armas/combate/espada/espada.h"
#include "../../ejercicio2/armas/combate/hacha_simple/hacha_simple.h"
#include "../../ejercicio2/armas/combate/hacha_doble/hacha_doble.h"
#include "../../ejercicio2/armas/combate/garrote/garrote.h"
#include "../../ejercicio2/armas/combate/lanza/lanza.h"

using namespace std;

class PersonajeFactory{
    public:
        static unique_ptr<Arma> crearArma(TipoDeArma a);
        static shared_ptr<Personaje> crearPersonaje(TipoPersonaje p);
        static shared_ptr<Personaje> crearPersonajeArmado(TipoPersonaje p, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas);
           
};