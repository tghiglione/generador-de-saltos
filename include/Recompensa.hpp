#ifndef AYED_TP2_1C2024_RECOMPENSA_HPP
#define AYED_TP2_1C2024_RECOMPENSA_HPP

#include <string>

class Recompensa {
private:
    static const std::string ELEMENTOS[8];
    static const std::string VIAS[7];
    static const std::string TIPOS[2];

    std::string nombre;
    int tipo{};
    int elemento{};
    int via{};
public:
    Recompensa() = default;

    Recompensa(std::string nombre, int tipo, int elemento, int via);

    friend std::ostream& operator<<(std::ostream& os, const Recompensa& recompensa);
};

#endif