#include "Recompensa.hpp"
#include <ostream>

const std::string Recompensa::ELEMENTOS[8] = {"Viento",
                                              "Fuego",
                                              "Electrico",
                                              "Cuantico",
                                              "Fisico",
                                              "Imaginario",
                                              "Hielo",
                                              "N/A"};

const std::string Recompensa::VIAS[7] = {"Nihilidad",
                                         "Destruccion",
                                         "Abundancia",
                                         "Erudicion",
                                         "Caceria",
                                         "Conservacion",
                                         "Armonia"};

const std::string Recompensa::TIPOS[2] = {"Personaje",
                                          "Cono de Luz"};

Recompensa::Recompensa(std::string nombre, int tipo, int elemento, int via) {
    this->nombre = std::move(nombre);
    this->tipo = tipo;
    this->elemento = elemento;
    this->via = via;
}

std::ostream& operator<<(std::ostream& os, const Recompensa& recompensa) {
    os << recompensa.nombre << ','
       << Recompensa::TIPOS[recompensa.tipo] << ','
       << Recompensa::ELEMENTOS[recompensa.elemento] << ','
       << Recompensa::VIAS[recompensa.via];
    return os;
}