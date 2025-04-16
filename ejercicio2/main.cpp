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
#include "personajes/guerreros/mercenario/mercenario.h"
#include "personajes/magos/hechicero/hechicero.h"
#include "personajes/magos/brujo/brujo.h"
#include "personajes/magos/nigromante/nigromante.h"

using namespace std;

int main() {
    // Crear armas iniciales
    auto baston = make_unique<Baston>();
    auto espada = make_unique<Espada>();
    
    // Crear personajes
    auto hechicero = make_shared<Hechicero>(std::move(baston), nullptr);
    auto barbaro = make_shared<Barbaro>(std::move(espada), nullptr);
    
    // Pruebas de armas
    cout << "\n=== Pruebas de Armas ===" << endl;
    auto baston_prueba_arma = make_unique<Baston>();
    cout << "Bastón - Arma Mágica:" << endl;
    cout << "Tipo: " << static_cast<int>(baston_prueba_arma->obtenerTipo()) << endl; // da un numero por el enum pero prueba que funciona
    cout << "Daño: " << baston_prueba_arma->obtenerDano() << endl;
    cout << "Velocidad de ataque: " << baston_prueba_arma->obtenerVelocidadAtaque() << endl;
    cout << "Costo de ataque: " << baston_prueba_arma->obtenerCostoAtaque() << endl;
    cout << "Peso: " << baston_prueba_arma->obtenerPeso() << endl;
    cout << "Ataque: " << baston_prueba_arma->atacar() << endl;

    auto espada_prueba_arma = make_unique<Espada>();
    cout << "\nEspada - Arma de Combate:" << endl;
    cout << "Tipo: " << static_cast<int>(espada_prueba_arma->obtenerTipo()) << endl; // da un numero por el enum pero prueba que funciona
    cout << "Daño: " << espada_prueba_arma->obtenerDano() << endl;
    cout << "Velocidad de ataque: " << espada_prueba_arma->obtenerVelocidadAtaque() << endl;
    cout << "Costo de ataque: " << espada_prueba_arma->obtenerCostoAtaque() << endl;
    cout << "Peso: " << espada_prueba_arma->obtenerPeso() << endl;
    cout << "Ataque: " << espada_prueba_arma->atacar() << endl;
    
    // Pruebas de personajes
    cout << "\n=== Pruebas de Personajes ===" << endl;
    cout << "Hechicero:" << endl;
    cout << "Vida: " << hechicero->obtenerVida() << endl;
    cout << "Tipo: " << static_cast<int>(hechicero->obtenerTipo()) << endl; // da un numero por el enum pero prueba que funciona
    hechicero->recibirDano(30);
    cout << "Vida después de daño: " << hechicero->obtenerVida() << endl;
    hechicero->curar(20);
    cout << "Vida después de curación: " << hechicero->obtenerVida() << endl;
    cout << "¿Está muerto?: " << (hechicero->estaMuerto() ? "Sí" : "No") << endl;
    
    cout << "\nBárbaro:" << endl;
    cout << "Vida: " << barbaro->obtenerVida() << endl;
    cout << "Tipo: " << static_cast<int>(barbaro->obtenerTipo()) << endl; // da un numero por el enum pero prueba que funciona
    barbaro->recibirDano(40);
    cout << "Vida después de daño: " << barbaro->obtenerVida() << endl;
    barbaro->curar(15);
    cout << "Vida después de curación: " << barbaro->obtenerVida() << endl;
    cout << "¿Está muerto?: " << (barbaro->estaMuerto() ? "Sí" : "No") << endl;

    // Crear nuevas armas para las pruebas de habilidades
    auto espada_prueba = make_unique<Espada>();
    auto baston_prueba = make_unique<Baston>();

    // Probar habilidad del bárbaro
    cout << "\n=== Prueba de Habilidades ===" << endl;
    cout << "Habilidad Bárbaro contra Hechicero:" << endl;
    int danoHabilidad = barbaro->habilidad(hechicero, std::move(espada_prueba));
    cout << "Daño causado por habilidad del bárbaro: " << danoHabilidad << endl;

    // Probar habilidad del hechicero
    cout << "\nHabilidad Hechicero contra Bárbaro:" << endl;
    danoHabilidad = hechicero->habilidad(barbaro, std::move(baston_prueba));
    cout << "Daño causado por habilidad del hechicero: " << danoHabilidad << endl;

    // Crear nuevas armas para las pruebas finales
    auto baston_final = make_unique<Baston>();
    auto espada_final = make_unique<Espada>();

    // Probar habilidades de armas
    cout << "\n=== Prueba de Habilidades de Armas ===" << endl;
    
    cout << "Bastón:" << endl;
    cout << "Bola de fuego: " << baston_final->bolaDeFuego() << " de daño" << endl;
    cout << "Habilidad mágica: " << baston_final->habilidadMagica() << " de daño" << endl;
    
    cout << "\nEspada:" << endl;
    cout << "Filo: " << espada_final->filo() << " de daño" << endl;
    cout << "Habilidad de combate: " << espada_final->ataqueEspecial() << " de daño" << endl;

    return 0;
}
