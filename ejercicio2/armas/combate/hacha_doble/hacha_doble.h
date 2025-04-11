#pragma once

#include "../combate.h"

class HachaDoble : public Combate {
    public:
        HachaDoble();
        int ataqueEspecial() override;
        int torbellino() const;
};