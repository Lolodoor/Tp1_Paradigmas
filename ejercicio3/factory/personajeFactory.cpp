#include "personajeFactory.h"

shared_ptr<Arma> PersonajeFactory::crearArma(TipoDeArma a) {
    switch (a) {
        case TipoDeArma::espada:
            return make_shared<Espada>();
        case TipoDeArma::hacha:
            return make_shared<HachaSimple>();
        case TipoDeArma::garrote:
            return make_shared<Garrote>();
        case TipoDeArma::lanza:
            return make_shared<Lanza>();
        case TipoDeArma::dobleHacha:
            return make_shared<HachaDoble>();
        case TipoDeArma::baston:
            return make_shared<Baston>();
        case TipoDeArma::amuleto:
            return make_shared<Amuleto>();
        case TipoDeArma::libroDeHechizos:
            return make_shared<LibroDeHechizos>();
        case TipoDeArma::pocion:
            return make_shared<Pocion>();
        default:
            cout << "Error: Tipo de arma no reconocido." << endl;
            return nullptr;
    }
}

shared_ptr<Personaje> PersonajeFactory::crearPersonaje(TipoPersonaje p) {
    switch (p) {
        case TipoPersonaje::barbaro:
            return make_shared<barbaro>(nullptr, nullptr);
        case TipoPersonaje::paladin:
            return make_shared<Paladin>(nullptr, nullptr);
        case TipoPersonaje::gladiador:
            return make_shared<Gladiador>(nullptr, nullptr);
        case TipoPersonaje::caballero:
            return make_shared<Caballero>(nullptr, nullptr);
        case TipoPersonaje::mercenario:
            return make_shared<Mercenario>(nullptr, nullptr);
        case TipoPersonaje::hechicero:
            return make_shared<Hechicero>(nullptr, nullptr);
        case TipoPersonaje::conjurador:
            return make_shared<Conjurador>(nullptr, nullptr);
        case TipoPersonaje::brujo:
            return make_shared<Brujo>(nullptr, nullptr);
        case TipoPersonaje::nigromante:
            return make_shared<Nigromante>(nullptr, nullptr);
        default:
            cout << "Error: Tipo de personaje no reconocido." << endl;
            return nullptr;
    }
}

shared_ptr<Personaje> PersonajeFactory::crearPersonajeArmado(TipoPersonaje p, pair<shared_ptr<Arma>, shared_ptr<Arma>> armas) {
    switch (p) {
        case TipoPersonaje::barbaro:
            return make_shared<barbaro>(armas.first, armas.second);
        case TipoPersonaje::paladin:
            return make_shared<Paladin>(armas.first, armas.second);
        case TipoPersonaje::gladiador:
            return make_shared<Gladiador>(armas.first, armas.second);
        case TipoPersonaje::caballero:
            return make_shared<Caballero>(armas.first, armas.second);
        case TipoPersonaje::mercenario:
            return make_shared<Mercenario>(armas.first, armas.second);
        case TipoPersonaje::hechicero:
            return make_shared<Hechicero>(armas.first, armas.second);
        case TipoPersonaje::conjurador:
            return make_shared<Conjurador>(armas.first, armas.second);
        case TipoPersonaje::brujo:
            return make_shared<Brujo>(armas.first, armas.second);
        case TipoPersonaje::nigromante:
            return make_shared<Nigromante>(armas.first, armas.second);
        default:
            cout << "Error: Tipo de personaje no reconocido." << endl;
            return nullptr;
    }
}