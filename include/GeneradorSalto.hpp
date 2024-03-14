#ifndef AYED_TP2_1C2024_GENERADORSALTO_HPP
#define AYED_TP2_1C2024_GENERADORSALTO_HPP

#include "Salto.hpp"
#include <vector>

class GeneradorSalto {
private:
    enum Elementos {
        VIENTO = 0,
        FUEGO = 1,
        ELECTRICO = 2,
        CUANTICO = 3,
        FISICO = 4,
        IMAGINARIO = 5,
        HIELO = 6,
        SIN_ELEMENTO = 7
    };

    enum Vias {
        NIHILIDAD = 0,
        DESTRUCCION = 1,
        ABUNDANCIA = 2,
        ERUDICION = 3,
        CACERIA = 4,
        CONSERVACION = 5,
        ARMONIA = 6
    };

    enum Tipos {
        PERSONAJE = 0,
        CONO_DE_LUZ = 1
    };

    static const std::vector<Recompensa> RECOMPENSAS_CINCO_ESTRELLAS;
    static const std::vector<Recompensa> RECOMPENSAS_CUATRO_ESTRELLAS;
    static const std::vector<Recompensa> RECOMPENSAS_TRES_ESTRELLAS;

    // Pre: Recompensas no puede estar vacío.
    // Post: Devuelve una recompensa elegida al azar.
    static Recompensa elegir_recompensa_aleatoria(std::vector<Recompensa> recompensas);

public:
    // Pre: -
    // Post: Genera y devuelve un Salto aleatorio de 5 estrellas.
    static Salto generar_salto_5_estrellas();

    // Pre: -
    // Post: Genera y devuelve un Salto aleatorio de 4 estrellas.
    static Salto generar_salto_4_estrellas();

    // Pre: -
    // Post: Genera y devuelve un Salto aleatorio de 3 estrellas.
    static Salto generar_salto_3_estrellas();
};

#endif