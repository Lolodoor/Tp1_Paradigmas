#include "caballero.h"

Caballero::Caballero(shared_ptr<Arma> arma1, shared_ptr<Arma> arma2)
    : Guerrero(TipoPersonaje::caballero, 100, 150, false, {arma1, arma2}) {}

int Caballero::habilidad(shared_ptr<Personaje> enemigo, shared_ptr<Arma> a) {
    if (!enemigo || !a) {
        cerr << "Error: enemigo o arma no válidos." << endl;
        return 0;
    }

    if (a->obtenerTipo() == ES::Magica) {
        auto armaMagica = dynamic_pointer_cast<Magica>(a);
        if (!armaMagica) {
            cerr << "Error: arma no es del tipo Magica." << endl;
            return 0;
        }
        int costoEnergia = armaMagica->obtenerCostoAtaque(); // Obtener el costo de energía del arma
        if (this->obtenerEnergia() < costoEnergia) {
            cerr << "Error: energía insuficiente para realizar el ataque." << endl;
            return 0;
        }
        energia -= costoEnergia; // Reducir la energía directamente

        int danoBase = armaMagica->obtenerDano();
        int danoInfligido = danoBase; 
        enemigo->recibirDano(danoInfligido);

        // 30% de probabilidad de regenerar energía
        if (rand() % 10 < 3) {
            int energiaActual = this->obtenerEnergia();
            int energiaRegenerada = energiaActual * 0.15; // Regenera 15% de energía
            energia += energiaRegenerada; 
            if (energia > 150) energia = 150; // Limitar la energía al máximo
            cout << "El caballero inflige " << danoInfligido << " de daño y regenera " 
                 << energiaRegenerada << " de energía." << endl;
        } else {
            cout << "El caballero inflige " << danoInfligido << " de daño." << endl;
        }
        return danoInfligido;

    } else if (a->obtenerTipo() == ES::Combate) {
        auto armaCombate = dynamic_pointer_cast<Combate>(a);
        if (!armaCombate) {
            cerr << "Error: arma no es del tipo Combate." << endl;
            return 0;
        }
        int costoEnergia = armaCombate->obtenerCostoAtaque(); // Obtener el costo de energía del arma
        if (this->obtenerEnergia() < costoEnergia) {
            cerr << "Error: energía insuficiente para realizar el ataque." << endl;
            return 0;
        }
        energia -= costoEnergia; // Reducir la energía directamente

        int danoBase = armaCombate->obtenerDano();
        int danoInfligido = danoBase; 
        enemigo->recibirDano(danoInfligido);

        
        if (rand() % 10 < 3) {
            int energiaActual = this->obtenerEnergia();
            int energiaRegenerada = energiaActual * 0.2;  // Regenera 20% de energía
            energia += energiaRegenerada; 
            if (energia > 150) energia = 150; // Limitar la energía al máximo
            cout << "El caballero inflige " << danoInfligido << " de daño y regenera " 
                 << energiaRegenerada << " de energía." << endl;
        } else {
            cout << "El caballero inflige " << danoInfligido << " de daño." << endl;
        }
        return danoInfligido;
    } else {
        cerr << "Error: tipo de arma no válido." << endl;
        return 0;
    }
}
