#pragma once

#include "../combate.h"

class HachaDoble : public Combate {
    public:
        HachaDoble();
        int atacar() override;
};
