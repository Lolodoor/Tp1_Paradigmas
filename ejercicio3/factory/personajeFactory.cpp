#include "PersonajeFactory.h"

unique_ptr<Arma> PersonajeFactory::crearArma(TipoDeArma a) {
    switch (a) {
        case TipoDeArma::espada:
            return make_unique<Espada>();
        case TipoDeArma::hacha:
            return make_unique<HachaSimple>();
        case TipoDeArma::garrote:
            return make_unique<Garrote>();
        case TipoDeArma::lanza:
            return make_unique<Lanza>();
        case TipoDeArma::dobleHacha:
            return make_unique<HachaDoble>();
        case TipoDeArma::baston:
            return make_unique<Baston>();
        case TipoDeArma::amuleto:
            return make_unique<Amuleto>();
        case TipoDeArma::libroDeHechizos:
            return make_unique<LibroDeHechizos>();
        case TipoDeArma::pocion:
            return make_unique<Pocion>();
        default:
            cout << "Error: Tipo de arma no reconocido." << endl;
            return nullptr;
    }
}

shared_ptr<Personaje> PersonajeFactory::crearPersonaje(TipoPersonaje p) {
    switch (p) {
        case TipoPersonaje::barbaro:
            return make_shared<Barbaro>(nullptr, nullptr);
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

shared_ptr<Personaje> PersonajeFactory::crearPersonajeArmado(TipoPersonaje p, pair<unique_ptr<Arma>, unique_ptr<Arma>> armas) {
    switch (p) {
        case TipoPersonaje::barbaro:
            return make_shared<Barbaro>(std::move(armas.first), std::move(armas.second));
        case TipoPersonaje::paladin:
            return make_shared<Paladin>(std::move(armas.first), std::move(armas.second));
        case TipoPersonaje::gladiador:
            return make_shared<Gladiador>(std::move(armas.first), std::move(armas.second));
        case TipoPersonaje::caballero:
            return make_shared<Caballero>(std::move(armas.first), std::move(armas.second));
        case TipoPersonaje::mercenario:
            return make_shared<Mercenario>(std::move(armas.first), std::move(armas.second));
        case TipoPersonaje::hechicero:
            return make_shared<Hechicero>(std::move(armas.first), std::move(armas.second));
        case TipoPersonaje::conjurador:
            return make_shared<Conjurador>(std::move(armas.first), std::move(armas.second));
        case TipoPersonaje::brujo:
            return make_shared<Brujo>(std::move(armas.first), std::move(armas.second));
        case TipoPersonaje::nigromante:
            return make_shared<Nigromante>(std::move(armas.first), std::move(armas.second));
        default:
            cout << "Error: Tipo de personaje no reconocido." << endl;
            return nullptr;
    }
}
