#ifndef AYED_TP2_1C2024_MENU_HPP
#define AYED_TP2_1C2024_MENU_HPP

#include <string>

using namespace std;

class menu {
private:
    enum opciones{
        SALIDA_DEL_MENU = 0,
        GENERAR_SALTO = 1,
        GENERAR_DIEZ_SALTOS = 2,
        GENERAR_MULTIPLES_SALTOS = 3,
        EXPORTAR_SALTOS = 4
    };
    const string TITULO_MENU = "Generador de saltos \n";
    const string INSTRUCCIONES_DE_MENU = "Para continuar elija una opcion: \n 0- Salir \n 1- Generar salto \n 2- Generar 10 saltos \n 3- Generar multiples saltos \n 4- Exportar saltos";
    const string OPCION_INVALIDA = "Opcion invalida, por favor elija otra";

    bool salida;
    int opcion_elegida;
public:

    menu();

    // Pre: -
    // Post: Ejecuta la opcion elegida, que puede ser generar salto, generar diez saltos, generar multiples saltos, exportar la totalidad de saltos o finalizar programa
    void elegir_opcion_menu();

};

#endif //AYED_TP2_1C2024_MENU_HPP
