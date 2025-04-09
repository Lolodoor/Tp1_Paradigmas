#include "main.h"

string AtaqueToString(Ataque a) {
    switch (a) {
        case Ataque::golpeFuerte:
            return "Golpe Fuerte";
        case Ataque::golpeRapido:
            return "Golpe Rapido";
        case Ataque::defensaYgolpe:
            return "Defensa y Golpe";
        default:
            return "ese ataque no existe";
    }
}

Ataque obtenerAtaqueJugador1() {
    int opcion;
    while (true) {
        cout << "Elige tu ataque:\n";
        cout << "1. Golpe Fuerte\n";
        cout << "2. Golpe Rápido\n";
        cout << "3. Defensa y Golpe\n";
        cin >> opcion;

        if (opcion == 1 || opcion == 2 || opcion == 3) {
            break;
        } else {
            cout << "Opción inválida. Por favor, elige una opción válida.\n";
        }
    }

    switch (opcion) {
        case 1: return Ataque::golpeFuerte;
        case 2: return Ataque::golpeRapido;
        case 3: return Ataque::defensaYgolpe;
        default: return Ataque::defensaYgolpe;  // Nunca debería llegar aquí
    }
}

Ataque obtenerAtaqueJugador2() {
    return static_cast<Ataque>(rand() % 3 + 1); 
}

shared_ptr<Personaje> crearPersonajeRival() {
    srand(static_cast<unsigned int>(time(0))); 
    TipoPersonaje tipo = static_cast<TipoPersonaje>(rand() % 9); 
    shared_ptr<Arma> arma = PersonajeFactory::crearArma(static_cast<TipoDeArma>(rand() % 9));
    return PersonajeFactory::crearPersonaje(tipo, {arma, nullptr});
}

shared_ptr<Arma> crearArmaJugador() {
    int opcion;
    cout << "Elige tu arma:\n";
    cout << "1. Espada\n";
    cout << "2. Hacha\n";
    cout << "3. Garrote\n";
    cout << "4. Lanza\n";
    cout << "5. Hacha Doble\n";
    cout << "6. Baston\n";
    cout << "7. Amuleto\n";
    cout << "8. Libro de Hechizos\n";
    cout << "9. Pocion\n";
    cin >> opcion;

    switch (opcion) {
        case 1: return PersonajeFactory::crearArma(TipoDeArma::espada);
        case 2: return PersonajeFactory::crearArma(TipoDeArma::hacha);
        case 3: return PersonajeFactory::crearArma(TipoDeArma::garrote);
        case 4: return PersonajeFactory::crearArma(TipoDeArma::lanza);
        case 5: return PersonajeFactory::crearArma(TipoDeArma::dobleHacha);
        case 6: return PersonajeFactory::crearArma(TipoDeArma::baston);
        case 7: return PersonajeFactory::crearArma(TipoDeArma::amuleto);
        case 8: return PersonajeFactory::crearArma(TipoDeArma::libroDeHechizos);
        case 9: return PersonajeFactory::crearArma(TipoDeArma::pocion);
        default:
            cout << "Opción inválida.\n";
            return nullptr;
    }
}

shared_ptr<Personaje> crearPersonajeJugador() {
    int opcion;
    cout << "Elige tu personaje:\n";
    cout << "1. Barbaro\n";
    cout << "2. Paladin\n";
    cout << "3. Gladiador\n";
    cout << "4. Caballero\n";
    cout << "5. Mercenario\n";
    cout << "6. Hechicero\n";
    cout << "7. Conjurador\n";
    cout << "8. Brujo\n";
    cout << "9. Nigromante\n";
    cin >> opcion;

    shared_ptr<Arma> arma = crearArmaJugador();
    if (!arma) {
        cout << "Error al crear el arma. Saliendo del programa.\n";
        return nullptr;
    }
    switch (opcion) {
        case 1: return PersonajeFactory::crearPersonaje(TipoPersonaje::barbaro, {arma, nullptr});
        case 2: return PersonajeFactory::crearPersonaje(TipoPersonaje::paladin, {arma, nullptr});
        case 3: return PersonajeFactory::crearPersonaje(TipoPersonaje::gladiador, {arma, nullptr});
        case 4: return PersonajeFactory::crearPersonaje(TipoPersonaje::caballero, {arma, nullptr});
        case 5: return PersonajeFactory::crearPersonaje(TipoPersonaje::mercenario, {arma, nullptr});
        case 6: return PersonajeFactory::crearPersonaje(TipoPersonaje::hechicero, {arma, nullptr});
        case 7: return PersonajeFactory::crearPersonaje(TipoPersonaje::conjurador, {arma, nullptr});
        case 8: return PersonajeFactory::crearPersonaje(TipoPersonaje::brujo, {arma, nullptr});
        case 9: return PersonajeFactory::crearPersonaje(TipoPersonaje::nigromante, {arma, nullptr});
        default:
            cout << "Opción inválida.\n";
            return nullptr;
    }
}

void resolverRonda(shared_ptr<Personaje> jugador1, shared_ptr<Personaje> jugador2, Ataque ataque1, Ataque ataque2) {
    int vidaJugador1 = jugador1->obtenerVida();
    int vidaJugador2 = jugador2->obtenerVida();
    cout << "Vida de " << nombrePersonaje(jugador1) << ": " << vidaJugador1 << "\n";
    cout << "Vida de " << nombrePersonaje(jugador2) << ": " << vidaJugador2 << "\n";


    if (ataque1 == ataque2) {
        cout << "Ambos jugadores eligieron " << AtaqueToString(ataque1) << ". No hay daño esta ronda.\n";
        return;
    }

    auto armaJugador1 = jugador1->obtenerArmas().first;
    auto armaJugador2 = jugador2->obtenerArmas().first;

    string nombreArma1 = armaJugador1 ? nombreArma(armaJugador1) : "Sin Arma";
    string nombreArma2 = armaJugador2 ? nombreArma(armaJugador2) : "Sin Arma";

    string tipoJugador1 = nombrePersonaje(jugador1);
    string tipoJugador2 = nombrePersonaje(jugador2);

    if (ataque1 == Ataque::golpeFuerte && ataque2 == Ataque::golpeRapido) {
        cout << tipoJugador1 << " ataca con " << nombreArma1 << " y hace 10 puntos de daño a " << tipoJugador2 << ".\n";
        vidaJugador2 -= 10;
    } else if (ataque1 == Ataque::golpeRapido && ataque2 == Ataque::defensaYgolpe) {
        cout << tipoJugador1 << " ataca con " << nombreArma1 << " y hace 10 puntos de daño a " << tipoJugador2 << ".\n";
        vidaJugador2 -= 10;
    } else if (ataque1 == Ataque::defensaYgolpe && ataque2 == Ataque::golpeFuerte) {
        cout << tipoJugador1 << " bloquea el ataque de " << tipoJugador2 << " y hace 10 puntos de daño.\n";
        vidaJugador2 -= 10;
    } else {
        cout << tipoJugador2 << " ataca con " << nombreArma2 << " y hace 10 puntos de daño a " << tipoJugador1 << ".\n";
        vidaJugador1 -= 10;
    }
    cout << tipoJugador1 << " tiene " << vidaJugador1 << " puntos de vida restantes.\n";
    cout << tipoJugador2 << " tiene " << vidaJugador2 << " puntos de vida restantes.\n";
}

int main() {
    // Main function implementation
    return 0;
}

