#include "generarAleatorio.h"

vector< vector<int> > generarAleatorio(){
    srand(time(0));
    vector<int> armasMago;
    vector<int> armasGuerrero;

    int valorMago = 3 + rand() % 5;
    int valorGuerrero = 3 + rand() % 5;

    for (int i = 0; i < valorMago; i++) {
        int numero = rand() % 3;
        armasMago.push_back(numero);
    }
    
    for (int i = 0; i < valorGuerrero; i++) {
        int numero = rand() % 3;
        armasGuerrero.push_back(numero);
    }

    vector< vector<int> > armas;
    armas.push_back(armasMago);
    armas.push_back(armasGuerrero);

    return armas;
    
}
