#pragma once

#include "../combate.h"

class Espada : public Combate {
public:
    Espada();
    int ataqueEspecial() override;
    int filo() const;
};