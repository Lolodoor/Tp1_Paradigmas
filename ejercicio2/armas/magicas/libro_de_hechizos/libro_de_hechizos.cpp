#include "libro_de_hechizos.h"

LibroDeHechizos::LibroDeHechizos() : Magica(ES::Magica, 15, 2, 10, TipoDeArma::libroDeHechizos) {}

int LibroDeHechizos::atacar(){
    return dano;
}
