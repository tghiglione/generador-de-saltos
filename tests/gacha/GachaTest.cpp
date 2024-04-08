#include "gtest/gtest.h"
#include "Gacha.hpp"

class GachaTest : public ::testing::Test {
protected:
    Gacha gacha{};
    Vector<Salto> salto_multiple;
    Salto salto{};
    bool cinco_estrellas{};
    bool cuatro_estrellas{};
    bool tres_estrellas{};

    void determinar_rareza(Salto salto1);

    void SetUp() override;
};

void GachaTest::determinar_rareza(Salto salto1) {
    switch (salto1.obtener_rareza()) {
        case CINCO_ESTRELLAS:
            cinco_estrellas = true;
            break;
        case CUATRO_ESTRELLAS:
            cuatro_estrellas = true;
            break;
        case TRES_ESTRELLAS:
            tres_estrellas = true;
            break;
    }
}

void GachaTest::SetUp() {
    cinco_estrellas = false;
    cuatro_estrellas = false;
    tres_estrellas = false;
}

TEST_F(GachaTest, EnNoventaSaltosSimplesSeDebenGenerarTodasLasRarezas) {
    for (int i = 0; i < 90; i++) {
        salto = gacha.generar_salto();
        determinar_rareza(salto);
    }
    while (salto.obtener_rareza() == CUATRO_ESTRELLAS) {
        salto = gacha.generar_salto();
        determinar_rareza(salto);
    }
    ASSERT_TRUE(cinco_estrellas && cuatro_estrellas && tres_estrellas);
}

TEST_F(GachaTest, EnNueveSaltosMultiplesSeDebenGenerarTodasLasRarezas) {
    for (int i = 0; i < 9; i++) {
        salto_multiple = gacha.generar_salto_multiple();
        for (size_t j = 0; j < salto_multiple.tamanio(); j++) {
            salto = salto_multiple[j];
            determinar_rareza(salto);
        }
    }
    while (salto.obtener_rareza() == CUATRO_ESTRELLAS) {
        salto = gacha.generar_salto();
        determinar_rareza(salto);
    }
    ASSERT_TRUE(cinco_estrellas && cuatro_estrellas && tres_estrellas);
}

TEST_F(GachaTest, EnUnSaltoMultipleSeDebenGenerarTodasLasRarezas) {
    salto_multiple = gacha.generar_salto_multiple(90);
    for (size_t j = 0; j < salto_multiple.tamanio(); j++) {
        salto = salto_multiple[j];
        determinar_rareza(salto);
    }
    while (salto.obtener_rareza() == CUATRO_ESTRELLAS) {
        salto = gacha.generar_salto();
        determinar_rareza(salto);
    }
    ASSERT_TRUE(cinco_estrellas && cuatro_estrellas && tres_estrellas);
}

TEST_F(GachaTest, EnDiezSaltosSimplesSeDebeGenerarUnCuatroEstrellasOMejor) {
    for (int i = 0; i < 10; i++) {
        determinar_rareza(gacha.generar_salto());
    }
    ASSERT_TRUE(cinco_estrellas || cuatro_estrellas);
}

TEST_F(GachaTest, EnUnSaltoMultipleSeDebeGenerarUnCuatroEstrellasOMejor) {
    salto_multiple = gacha.generar_salto_multiple();
    for (size_t j = 0; j < salto_multiple.tamanio(); j++) {
        determinar_rareza(salto_multiple[j]);
    }
    ASSERT_TRUE(cinco_estrellas || cuatro_estrellas);
}

TEST_F(GachaTest, EnUnSaltoMultipleCantidadSeDebeGenerarUnCuatroEstrellasOMejor) {
    salto_multiple = gacha.generar_salto_multiple(10);
    for (size_t j = 0; j < salto_multiple.tamanio(); j++) {
        determinar_rareza(salto_multiple[j]);
    }
    ASSERT_TRUE(cinco_estrellas || cuatro_estrellas);
}