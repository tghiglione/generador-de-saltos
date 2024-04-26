#include "gacha.hpp"
#include "vector.hpp"
#include "menu.hpp"

#include <iostream>


menu::menu() {
    salida = false;
}

void menu::elegir_opcion_menu() {
    gacha gacha;

    cout << TITULO_MENU << endl;

    while (!salida) {

        cout << INSTRUCCIONES_DE_MENU << endl;
        cin >> opcion_elegida;

        switch (opcion_elegida) {
            case SALIDA_DEL_MENU:
                salida = true;
                break;
            case GENERAR_SALTO: {
                salto salto_generado = gacha.generar_salto();
                cout << salto_generado << endl;
            }
                break;
            case GENERAR_DIEZ_SALTOS: {
                vector<salto> diez_saltos_generados = gacha.generar_salto_multiple();
                for (size_t i = 0; i < diez_saltos_generados.tamanio(); i++) {
                    cout << diez_saltos_generados[i] << endl;
                }
            }
                break;
            case GENERAR_MULTIPLES_SALTOS: {
                size_t cantidad_saltos;
                cout << "Ingrese la cantidad de saltos deseados: " << endl;
                cin >> cantidad_saltos;
                vector<salto> saltos_multiples_generados = gacha.generar_salto_multiple(cantidad_saltos);
                for (size_t i = 0; i < saltos_multiples_generados.tamanio(); i++) {
                    cout << saltos_multiples_generados[i] << endl;
                }
            }
                break;
            case EXPORTAR_SALTOS:
                gacha.exportar_saltos();
                break;
            default:
                cout << OPCION_INVALIDA << endl;
                break;
        }
    }
}
