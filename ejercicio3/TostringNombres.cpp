#include "TostringNombres.h"


string nombreArma(shared_ptr<Arma> arma) {
    if (!arma) return "Sin arma";

    switch (arma->obtenerTipoArma()) { 
        case TipoDeArma::hacha: return "Hacha Simple";
        case TipoDeArma::dobleHacha: return "Hacha Doble";
        case TipoDeArma::espada: return "Espada";
        case TipoDeArma::lanza: return "Lanza";
        case TipoDeArma::garrote: return "Garrote";
        case TipoDeArma::pocion: return "Poción";
        case TipoDeArma::amuleto: return "Amuleto";
        case TipoDeArma::baston: return "Bastón";
        case TipoDeArma::libroDeHechizos: return "Libro de Hechizos";
        default: return "Arma desconocida";
    }
}

string nombrePersonaje(shared_ptr<Personaje> personaje) {
    switch (personaje->obtenerTipo()) { 
        case TipoPersonaje::hechicero: return "Hechicero";
        case TipoPersonaje::nigromante: return "Nigromante";
        case TipoPersonaje::conjurador: return "Conjurador";
        case TipoPersonaje::brujo: return "Brujo";
        case TipoPersonaje::paladin: return "Paladín";
        case TipoPersonaje::barbaro: return "Bárbaro";
        case TipoPersonaje::caballero: return "Caballero";
        case TipoPersonaje::mercenario: return "Mercenario";
        case TipoPersonaje::gladiador: return "Gladiador";
        default: return "Personaje desconocido";
    }
}
