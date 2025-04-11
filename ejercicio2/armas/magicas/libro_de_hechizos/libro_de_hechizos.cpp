#include "libro_de_hechizos.h"

LibroDeHechizos::LibroDeHechizos() : Magica(ES::Magica, 15, 2, 10, 15, TipoDeArma::libroDeHechizos) {}

int LibroDeHechizos::habilidadMagica() {
    srand(static_cast<unsigned int>(time(0))); 
    int probabilidad = rand() % 100; 

    if (probabilidad < 30) { // 30% de probabilidad de activar la habilidad mágica
        cout << "¡Habilidad mágica activada! El libro de hechizos lanza un hechizo que relentiza a los enemigos.\n";
        return dano;
    } else {
        cout << "La habilidad mágica del libro de hechizos no se activó.\n";
        return dano; // Daño normal
    }
}