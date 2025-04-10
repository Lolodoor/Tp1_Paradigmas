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

// para mostrar que compila bien todo
int main() {
    // Crear armas primero
    auto espada = make_shared<Espada>();
    auto baston = make_shared<Baston>();
    
    // Crear personajes con sus armas
    auto Barbaro = make_shared<barbaro>(espada, nullptr);  // Segunda arma null por ahora
    auto hechicero = make_shared<Hechicero>(baston, nullptr);  // Segunda arma null por ahora
    
    cout << "Estado inicial:" << endl;
    cout << "Vida del bárbaro: " << Barbaro->obtenerVida() << endl;
    cout << "Vida del hechicero: " << hechicero->obtenerVida() << endl;
    
    // Probar ataques
    int danoEspada = espada->atacar();
    int danoBaston = baston->atacar();
    
    cout << "\nPrueba de daño:" << endl;
    cout << "Daño de espada: " << danoEspada << endl;
    cout << "Daño de bastón: " << danoBaston << endl;
    
    // Aplicar daño
    hechicero->recibirDano(danoEspada);
    cout << "Vida del hechicero después de recibir daño: " << hechicero->obtenerVida() << endl;
    
    // Probar curación
    hechicero->curar(20);
    cout << "Vida del hechicero después de curarse: " << hechicero->obtenerVida() << endl;
    
    // Verificar estado
    cout << "\nEstado del hechicero:" << endl;
    cout << "¿Está muerto? " << (hechicero->estaMuerto() ? "Sí" : "No") << endl;
    
    // Probar habilidad del bárbaro
    cout << "\nProbando habilidad del bárbaro (Furia):" << endl;
    cout << "Daño normal de espada: " << espada->atacar() << endl;
    
    int danoHabilidad = Barbaro->habilidad(hechicero, espada);
    cout << "Daño con Furia activada: " << danoHabilidad << endl;
    cout << "Vida del hechicero después de la Furia: " << hechicero->obtenerVida() << endl;
    
    // Probar funciones adicionales
    cout << "\nPruebas adicionales:" << endl;
    cout << "Peso de la espada: " << espada->obtenerPeso() << endl;
    cout << "Peso del bastón: " << baston->obtenerPeso() << endl;
    
    // Obtener tipos de armas
    cout << "Tipo de arma (espada): " << static_cast<int>(espada->obtenerTipoArma()) << endl; // esto me va a devolver un numero por el enum
    cout << "Tipo de arma (bastón): " << static_cast<int>(baston->obtenerTipoArma()) << endl;
    
    // Probar stats de personajes
    cout << "\nStats de personajes:" << endl;
    cout << "Tipo de personaje (Bárbaro): " << static_cast<int>(Barbaro->obtenerTipo()) << endl; // esto me va a devolver un numero por el enum
    cout << "Tipo de personaje (Hechicero): " << static_cast<int>(hechicero->obtenerTipo()) << endl;
    
    // Probar velocidad y costo de ataque de armas
    cout << "\nStats de armas:" << endl;
    cout << "Velocidad de ataque (espada): " << espada->obtenerVelocidadAtaque() << endl;
    cout << "Costo de ataque (espada): " << espada->obtenerCostoAtaque() << endl;
    cout << "Velocidad de ataque (bastón): " << baston->obtenerVelocidadAtaque() << endl;
    cout << "Costo de ataque (bastón): " << baston->obtenerCostoAtaque() << endl;
    
    return 0;
}
