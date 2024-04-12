#include "gtest/gtest.h"
#include "vector.hpp"

class vector_test : public ::testing::Test {
protected:
    vector<int> vector{};
    int dato{};
};

TEST_F(vector_test, Alta) {
    vector.alta(1);
    EXPECT_EQ(vector[0], 1);

    vector.alta(2);
    EXPECT_EQ(vector[1], 2);

    vector.alta(3);
    EXPECT_EQ(vector[2], 3);
}

TEST_F(vector_test, AltaIndice) {
    vector.alta(1, 0);
    EXPECT_EQ(vector[0], 1);

    vector.alta(2, 0);
    EXPECT_EQ(vector[0], 2);

    vector.alta(3, 1);
    EXPECT_EQ(vector[1], 3);

    vector.alta(4, 3);
    EXPECT_EQ(vector[3], 4);
}

TEST_F(vector_test, AltaIndiceManejaIndiceMayorACantidadDeDatos) {
    EXPECT_THROW(vector.alta(1, 1), vector_exception);

    vector.alta(1);
    EXPECT_THROW(vector.alta(2, 2), vector_exception);
}

TEST_F(vector_test, OperadorAcceso) {
    vector.alta(1);
    vector.alta(2, 0);
    vector.alta(3);

    EXPECT_EQ(vector[0], 2);
    EXPECT_EQ(vector[1], 1);
    EXPECT_EQ(vector[2], 3);
}

TEST_F(vector_test, OperadorAccesoManejaVectorVacio) {
    EXPECT_THROW(vector[0], vector_exception);
}

TEST_F(vector_test, OperadorAccesoManejaIndiceMayorOIgualACantidadDeDatos) {
    vector.alta(1);

    EXPECT_NO_THROW(vector[0]);
    EXPECT_THROW(vector[1], vector_exception);
    EXPECT_THROW(vector[2], vector_exception);
}

TEST_F(vector_test, Baja) {
    vector.alta(1);
    vector.alta(2);

    dato = vector.baja();
    EXPECT_EQ(dato, 2);

    dato = vector.baja();
    EXPECT_EQ(dato, 1);
}

TEST_F(vector_test, BajaIndice) {
    vector.alta(1);
    vector.alta(2);
    vector.alta(3);
    vector.alta(4);

    dato = vector.baja(1);
    EXPECT_EQ(dato, 2);

    dato = vector.baja(0);
    EXPECT_EQ(dato, 1);

    dato = vector.baja(1);
    EXPECT_EQ(dato, 4);

    dato = vector.baja(0);
    EXPECT_EQ(dato, 3);
}

TEST_F(vector_test, BajaManejaVectorVacio) {
    EXPECT_THROW(vector.baja(), vector_exception);
}


TEST_F(vector_test, BajaIndiceManejaVectorVacio) {
    EXPECT_THROW(vector.baja(0), vector_exception);
}

TEST_F(vector_test, BajaIndiceManejaIndiceMayorOIgualACantidadDeDatos) {
    vector.alta(1);
    EXPECT_THROW(vector.baja(1), vector_exception);
    EXPECT_THROW(vector.baja(2), vector_exception);
    EXPECT_NO_THROW(vector.baja(0));
}

TEST_F(vector_test, Vacio) {
    EXPECT_TRUE(vector.vacio());

    vector.alta(1);
    EXPECT_FALSE(vector.vacio());

    vector.baja();
    EXPECT_TRUE(vector.vacio());
}

TEST_F(vector_test, Tamanio) {
    EXPECT_EQ(vector.tamanio(), 0);

    vector.alta(1);
    vector.alta(2);
    vector.alta(3);
    EXPECT_EQ(vector.tamanio(), 3);

    vector.baja();
    EXPECT_EQ(vector.tamanio(), 2);
}