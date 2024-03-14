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
    // Constructor default.
    Salto() = default;

    // Constructor.
    Salto(Rareza rareza, Recompensa recompensa);

    // Pre: -
    // Post: Devuelve la rareza del Salto.
    Rareza obtener_rareza();

    // Pre: -
    // Post: Carga la información al stream de salida.
    friend std::ostream& operator<<(std::ostream& os, const Salto& salto);
};

#endif