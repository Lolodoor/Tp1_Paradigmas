#include "libro_de_hechizos.h"

LibroDeHechizos::LibroDeHechizos() : Magica(ES::Magica, 15, 10, 2, TipoDeArma::libroDeHechizos) {}

int LibroDeHechizos::atacar(){
    return 15;
}
