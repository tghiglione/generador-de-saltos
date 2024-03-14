#ifndef AYED_TP2_1C2024_SALTO_HPP
#define AYED_TP2_1C2024_SALTO_HPP

#include "Recompensa.hpp"
#include <ctime>

enum Rareza {
    CINCO_ESTRELLAS = 5, CUATRO_ESTRELLAS = 4, TRES_ESTRELLAS = 3
};

class Salto {
private:
    time_t hora_obtencion{};
    Rareza rareza{};
    Recompensa recompensa;
public:
    Salto() = default;

    Salto(Rareza rareza, Recompensa recompensa);

    Rareza obtener_rareza();

    friend std::ostream& operator<<(std::ostream& os, const Salto& salto);
};

#endif