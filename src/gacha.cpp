#include "gacha.hpp"
#include "generador_salto.hpp"
#include "vector.hpp"
#include "salto.hpp"
#include <random>
#include <fstream>

gacha::gacha() {
        contador_4_estrellas = 0;
        contador_5_estrellas = 0;
}

rareza gacha::sistema_pity() {
    rareza rareza_generada;
    int numero_random = generador_numero_random();

    if(contador_5_estrellas >= 89){
        contador_5_estrellas = 0;
        contador_4_estrellas++;
        rareza_generada = CINCO_ESTRELLAS;
    }else if(contador_5_estrellas < 89 && contador_4_estrellas >= 9){
        contador_4_estrellas = 0;
        contador_5_estrellas++;
        rareza_generada = CUATRO_ESTRELLAS;
    }else{
        if(numero_random == 0){
            contador_5_estrellas = 0;
            contador_4_estrellas++;
            rareza_generada = CINCO_ESTRELLAS;
        }else if(numero_random > 0 && numero_random <= 10){
            contador_4_estrellas = 0;
            contador_5_estrellas++;
            rareza_generada = CUATRO_ESTRELLAS;
        }else{
            contador_5_estrellas++;
            contador_4_estrellas++;
            rareza_generada = TRES_ESTRELLAS;
        }
    }
    return rareza_generada;
}

salto gacha::generar_salto() {
    salto salto_generado;
    rareza rareza_obtenida = sistema_pity();

    switch (rareza_obtenida) {
        case CINCO_ESTRELLAS:
            salto_generado = generador_salto::generar_salto_5_estrellas();
            break;
        case CUATRO_ESTRELLAS:
            salto_generado = generador_salto::generar_salto_4_estrellas();
            break;
        case TRES_ESTRELLAS:
            salto_generado = generador_salto::generar_salto_3_estrellas();
            break;
    }
    saltos_para_archivar.alta(salto_generado);
    return salto_generado;
}

vector<salto> gacha::generar_salto_multiple() {
    vector<salto> saltos_generados;
    for(size_t i = 1; i <= DIEZ_SALTOS_MULTIPLES; i++){
        salto nuevo_salto = generar_salto();
        saltos_generados.alta(nuevo_salto);
    }
    return saltos_generados;
}

vector<salto> gacha::generar_salto_multiple(size_t cantidad) {
    vector<salto> saltos_generados;
    for(size_t i = 1; i <= cantidad; i++){
        salto nuevo_salto = generar_salto();
        saltos_generados.alta(nuevo_salto);
    }
    return saltos_generados;
}

void gacha::exportar_saltos() {
    std::ofstream archivo_saltos_generados("registro_saltos.csv",std::ofstream::app);
    if(archivo_saltos_generados.is_open()){
        for (size_t i = 0; i < saltos_para_archivar.tamanio(); i++){
            archivo_saltos_generados << saltos_para_archivar[i] << std::endl;
        }
        archivo_saltos_generados.close();

        while (saltos_para_archivar.tamanio() > 0) {  //vacio vector una vez que exporta los elementos
            saltos_para_archivar.baja();
        }
        std::cout << "Archivo generado exitosamente" << std::endl;
    }else{
        std::cout << "Error al abrir el archivo" << std::endl;
    };

}

int gacha::generador_numero_random() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 99);
    return dis(gen);
}





