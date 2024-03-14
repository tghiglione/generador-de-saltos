#include "Salto.hpp"
#include <chrono>
#include <ostream>

Salto::Salto(Rareza rareza, Recompensa recompensa) {
    auto hora_actual = std::chrono::system_clock::now();
    this->hora_obtencion = std::chrono::system_clock::to_time_t(hora_actual);
    this->rareza = rareza;
    this->recompensa = std::move(recompensa);
}

Rareza Salto::obtener_rareza() {
    return rareza;
}

std::ostream& operator<<(std::ostream& os, const Salto& salto) {
    std::string hora = std::ctime(&salto.hora_obtencion);
    hora.pop_back();
    os << hora << ','
       << salto.rareza << " Estrellas,"
       << salto.recompensa;
    return os;
}