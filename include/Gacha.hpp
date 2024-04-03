#ifndef AYED_TP2_1C2024_GACHA_HPP
#define AYED_TP2_1C2024_GACHA_HPP

#include "Salto.hpp"
#include "Vector.hpp"

class Gacha {
public:
    Gacha();

    Salto generar_salto();

    Vector<Salto> generar_salto_multiple();

    Vector<Salto> generar_salto_multiple(size_t cantidad);

    void exportar_saltos();
};

#endif