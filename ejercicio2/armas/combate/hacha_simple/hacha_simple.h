#pragma once

#include "../combate.h"

class HachaSimple : public Combate {
    public:
        HachaSimple();
        int atacar() override;
};
