#ifndef AYED_TP2_1C2024_GACHA_HPP
#define AYED_TP2_1C2024_GACHA_HPP

#include "salto.hpp"
#include "vector.hpp"

class gacha {
private:
    size_t contador_5_estrellas;
    size_t contador_4_estrellas;

    const size_t DIEZ_SALTOS_MULTIPLES = 10;

    vector<salto> saltos_para_archivar;

    // Pre: -
    // Post: Genera numero random entre 0 y 99
    int generador_numero_random();

    // Pre: -
    // Post: Genera una rareza dependiendo de los contadores y del numero random
    rareza sistema_pity();

public:

    //Constructor
    gacha();

    // Pre: -
    // Post: Devuelve un salto de cierta cantidad de estrellas dependiendo de la rareza obtenida
    salto generar_salto();

    // Pre: -
    // Post: Devuelve un vector de saltos. Equivale a hacer 10 veces generar_salto()
    vector<salto> generar_salto_multiple();

    // Pre: Cantidad no puede ser menor a cero
    // Post: Devuelve un vector de saltos. Equivale a hacer 'cantidad' veces generar_salto()
    vector<salto> generar_salto_multiple(size_t cantidad);

    // Pre: -
    // Post: Genera un archivo que registra los saltos totales obtenidos
    void exportar_saltos();

};

#endif