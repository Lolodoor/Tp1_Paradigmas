#pragma once

#include "../personaje.h"

class Magos : public Personaje {
    protected:
        TipoPersonaje tipo;
        int vida; 
        int mana;
        pair<shared_ptr<Arma>, shared_ptr<Arma>> armas;
        bool muerto;
    public:
        Magos(TipoPersonaje tipo, int vida, int mana, bool muerto);

        int obtenerVida() const override;
        TipoPersonaje obtenerTipo() const override;
        void recibirDano(int dano) override;
        void curar(int curacion) override;
        pair<shared_ptr<Arma>, shared_ptr<Arma>> obtenerArmas() const override;
        void equiparArma(shared_ptr<Arma> arma) override;
        bool estaMuerto() override;
        int obtenerMana() const;
        virtual int habilidad(shared_ptr<Personaje> enemigo, shared_ptr<Arma> a) = 0;
        

};


