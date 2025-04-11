#pragma once

#include "../magicas.h"

class Amuleto : public Magica {
public:
    Amuleto();
    int habilidadMagica() override;
    string escudoInduvidual() const;
};


