#pragma once

#include "../personaje.h"

class Magos : public Personaje {
    protected:
        TipoPersonaje tipo;
        int vida;
        int mana;
        pair<unique_ptr<Arma>, unique_ptr<Arma>> armas;
        bool muerto;
    public:
        Magos(TipoPersonaje tipo, int vida, int mana, bool muerto, 
              pair<unique_ptr<Arma>, unique_ptr<Arma>> armas);

        int obtenerVida() const override;
        TipoPersonaje obtenerTipo() const override;
        void recibirDano(int dano) override;
        void curar(int curacion) override;
        pair<unique_ptr<Arma>, unique_ptr<Arma>>& obtenerArmas() override;
        void equiparArma(unique_ptr<Arma> arma) override;
        bool estaMuerto() override;
        int obtenerMana() const;
        virtual int habilidad(shared_ptr<Personaje> enemigo, unique_ptr<Arma> a) = 0;
};


