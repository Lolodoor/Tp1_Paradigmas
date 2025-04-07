#include <iostream>
#include <memory>
#include "personajes/guerreros/barbaro/barbaro.h"
#include "personajes/guerreros/paladin/paladin.h"
#include "personajes/guerreros/gladiador/gladiador.h" 
#include "personajes/guerreros/caballero/caballero.h" 
#include "personajes/guerreros/guerreros.h"
#include "armas/magicas/magicas.h"
#include "armas/magicas/baston/baston.h"
#include "armas/magicas/amuleto/amuleto.h"
#include "armas/magicas/libro_de_hechizos/libro_de_hechizos.h"
#include "armas/magicas/pocion/pocion.h"
#include "armas/combate/combate.h"
#include "armas/combate/espada/espada.h"
#include "armas/combate/hacha_simple/hacha_simple.h"
#include "armas/combate/hacha_doble/hacha_doble.h"
#include "armas/combate/garrote/garrote.h"
#include "armas/combate/lanza/lanza.h"
#include "personajes/personaje.h"

using namespace std;

int main() {
    // Crear un caballero
    shared_ptr<Caballero> caballero = make_shared<Caballero>();

    // Crear un enemigo (Barbaro)
    shared_ptr<barbaro> enemigo = make_shared<barbaro>();

    // Crear un arma de combate (Baston)
    shared_ptr<Baston> baston = make_shared<Baston>();

    // Equipar el arma al caballero
    caballero->equiparArma(baston);

    // Probar el arma equipada del caballero
    cout << "Probando el arma equipada del caballero:" << endl;
    ES tipoArma = baston->obtenerTipo();
    cout << "Tipo de arma: " << (tipoArma == ES::Magica ? "Magica" : "Combate") << endl;
    cout << "Daño del arma: " << baston->obtenerDano() << endl;

    // Mostrar energía inicial
    int energiaInicial = caballero->obtenerEnergia();
    cout << "Energía inicial del caballero: " << energiaInicial << endl;

    // Probar la habilidad del caballero
    cout << "\nProbando la habilidad del caballero:" << endl;
    int energiaAntesAtaque = caballero->obtenerEnergia();
    int danoCausado = caballero->habilidad(enemigo, baston);
    int energiaDespuesAtaque = caballero->obtenerEnergia();

    // Calcular energía gastada y regenerada
    int energiaGastada = energiaAntesAtaque - energiaDespuesAtaque;
    int energiaRegenerada = energiaDespuesAtaque - energiaInicial;

    cout << "Daño causado por el caballero: " << danoCausado << endl;
    cout << "Energía gastada en el ataque: " << energiaGastada << endl;
    cout << "Energía regenerada: " << energiaRegenerada << endl;

    // Mostrar energía final
    cout << "Energía final del caballero: " << caballero->obtenerEnergia() << endl;

    // Simular múltiples ataques
    for (int i = 0; i < 5; ++i) { // Realizar 5 ataques
        cout << "Ataque " << i + 1 << ":" << endl;
        int dano = caballero->habilidad(enemigo, baston);
        cout << "Daño infligido: " << dano << endl;
        cout << "Energía actual del caballero: " << caballero->obtenerEnergia() << endl;
        cout << "-----------------------------" << endl;
    }

    return 0;
}
