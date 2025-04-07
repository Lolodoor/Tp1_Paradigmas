#pragma once

#include "../combate.h"

class Garrote : public Combate {
    public:
        Garrote();
        int atacar() override;
};
