#pragma once

#include "../magicas.h"

class Baston : public Magica {
public:
    Baston();
    int atacar() override;
};