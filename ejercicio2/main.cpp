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
    // Crear armas
    auto baston = make_shared<Baston>();
    auto espada = make_shared<Espada>();
    
    // Crear personajes
    auto hechicero = make_shared<Hechicero>(baston, nullptr);
    auto Barbaro = make_shared<barbaro>(espada, nullptr);
    
    // Pruebas de armas
    cout << "\n=== Pruebas de Armas ===" << endl;
    cout << "Bastón - Arma Mágica:" << endl;
    cout << "Tipo: " << static_cast<int>(baston->obtenerTipo()) << endl; // da un numero por el enum pero prueba que funciona
    cout << "Daño: " << baston->obtenerDano() << endl;
    cout << "Velocidad de ataque: " << baston->obtenerVelocidadAtaque() << endl;
    cout << "Costo de ataque: " << baston->obtenerCostoAtaque() << endl;
    cout << "Peso: " << baston->obtenerPeso() << endl;
    cout << "Ataque: " << baston->atacar() << endl;

    cout << "\nEspada - Arma de Combate:" << endl;
    cout << "Tipo: " << static_cast<int>(espada->obtenerTipo()) << endl; // da un numero por el enum pero prueba que funciona
    cout << "Daño: " << espada->obtenerDano() << endl;
    cout << "Velocidad de ataque: " << espada->obtenerVelocidadAtaque() << endl;
    cout << "Costo de ataque: " << espada->obtenerCostoAtaque() << endl;
    cout << "Peso: " << espada->obtenerPeso() << endl;
    cout << "Ataque: " << espada->atacar() << endl;
    
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
    cout << "Vida: " << Barbaro->obtenerVida() << endl;
    cout << "Tipo: " << static_cast<int>(Barbaro->obtenerTipo()) << endl; // da un numero por el enum pero prueba que funciona
    Barbaro->recibirDano(40);
    cout << "Vida después de daño: " << Barbaro->obtenerVida() << endl;
    Barbaro->curar(15);
    cout << "Vida después de curación: " << Barbaro->obtenerVida() << endl;
    cout << "¿Está muerto?: " << (Barbaro->estaMuerto() ? "Sí" : "No") << endl;

    // Probar habilidad del bárbaro
    cout << "\n=== Prueba de Habilidades ===" << endl;
    cout << "Habilidad Bárbaro contra Hechicero:" << endl;
    int danoHabilidad = Barbaro->habilidad(hechicero, espada);
    cout << "Daño causado por habilidad del bárbaro: " << danoHabilidad << endl;

    // Probar habilidad del hechicero
    cout << "\nHabilidad Hechicero contra Bárbaro:" << endl;
    danoHabilidad = hechicero->habilidad(Barbaro, baston);
    cout << "Daño causado por habilidad del hechicero: " << danoHabilidad << endl;

    // Probar habilidades de armas
    cout << "\n=== Prueba de Habilidades de Armas ===" << endl;
    
    cout << "Bastón:" << endl;
    cout << "Bola de fuego: " << baston->bolaDeFuego() << " de daño" << endl;
    cout << "Habilidad mágica: " << baston->habilidadMagica() << " de daño" << endl;
    
    cout << "\nEspada:" << endl;
    cout << "Filo" << espada->filo() << " de daño" << endl;
    cout << "Habilidad de combate: " << espada->ataqueEspecial() << " de daño" << endl;

    return 0;
}
