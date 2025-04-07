#pragma once

#include "../combate.h"

class Lanza : public Combate {
    public:
        Lanza();
        int atacar() override;
};
