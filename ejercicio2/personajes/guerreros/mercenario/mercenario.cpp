#include "mercenario.h"

Mercenario::Mercenario(shared_ptr<Arma> arma1, shared_ptr<Arma> arma2)
    : Guerrero(TipoPersonaje::mercenario, 100, 150, false, {arma1, arma2}) {}

int Mercenario::habilidad(shared_ptr<Personaje> enemigo, shared_ptr<Arma> a) {
    if (!enemigo || !a) {
        cerr << "Error: enemigo o arma no válidos." << endl;
        return 0;
    }

    int danoBase = 0;

    if (a->obtenerTipo() == ES::Magica) {
        // Usa el daño base del arma mágica
        danoBase = a->obtenerDano();
    } else if (a->obtenerTipo() == ES::Combate) {
        // Usa el daño base del arma de combate
        auto armaCombate = dynamic_pointer_cast<Combate>(a);
        if (!armaCombate) {
            cerr << "Error: arma no es del tipo Combate." << endl;
            return 0;
        }
        danoBase = armaCombate->obtenerDano();
    } else {
        cerr << "Error: tipo de arma no válido." << endl;
        return 0;
    }

    // Preguntar al usuario si quiere curarse a cambio de infligir menos daño
    cout << "¿Quieres curarte a cambio de infligir menos daño? (1: Sí, 0: No): ";
    int opcion;
    cin >> opcion;

    int danoReducido = 0;
    if (opcion == 1) {
        int curacion = 20; // Cantidad de vida que se cura
        this->curar(curacion); // Cura al mercenario
        danoReducido = static_cast<int>(danoBase * 0.3); // Reduce el 30% del daño base
    }

    int danoTotal = danoBase - danoReducido;
    if (danoTotal < 0) danoTotal = 0; // Asegurarse de que el daño no sea negativo
    enemigo->recibirDano(danoTotal);

    // Mostrar mensajes para verificar el comportamiento
    cout << "Daño base: " << danoBase << ", Daño reducido: " << danoReducido << ", Daño total: " << danoTotal << endl;

    return danoTotal;
}