#include "gtest/gtest.h"
#include "Vector.hpp"

class VectorTest : public ::testing::Test {
protected:
    Vector<int> vector{};
    int dato{};
};

TEST_F(VectorTest, Alta) {
    vector.alta(1);
    EXPECT_EQ(vector[0], 1);

    vector.alta(2);
    EXPECT_EQ(vector[1], 2);

    vector.alta(3);
    EXPECT_EQ(vector[2], 3);
}

TEST_F(VectorTest, AltaIndice) {
    vector.alta(1, 0);
    EXPECT_EQ(vector[0], 1);

    vector.alta(2, 0);
    EXPECT_EQ(vector[0], 2);

    vector.alta(3, 1);
    EXPECT_EQ(vector[1], 3);

    vector.alta(4, 3);
    EXPECT_EQ(vector[3], 4);
}

TEST_F(VectorTest, AltaIndiceManejaIndiceMayorACantidadDeDatos) {
    EXPECT_THROW(vector.alta(1, 1), VectorException);

    vector.alta(1);
    EXPECT_THROW(vector.alta(2, 2), VectorException);
}

TEST_F(VectorTest, OperadorAcceso) {
    vector.alta(1);
    vector.alta(2, 0);
    vector.alta(3);

    EXPECT_EQ(vector[0], 2);
    EXPECT_EQ(vector[1], 1);
    EXPECT_EQ(vector[2], 3);
}

TEST_F(VectorTest, OperadorAccesoManejaVectorVacio) {
    EXPECT_THROW(vector[0], VectorException);
}

TEST_F(VectorTest, OperadorAccesoManejaIndiceMayorOIgualACantidadDeDatos) {
    vector.alta(1);

    EXPECT_NO_THROW(vector[0]);
    EXPECT_THROW(vector[1], VectorException);
    EXPECT_THROW(vector[2], VectorException);
}

TEST_F(VectorTest, Baja) {
    vector.alta(1);
    vector.alta(2);

    dato = vector.baja();
    EXPECT_EQ(dato, 2);

    dato = vector.baja();
    EXPECT_EQ(dato, 1);
}

TEST_F(VectorTest, BajaIndice) {
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

TEST_F(VectorTest, BajaManejaVectorVacio) {
    EXPECT_THROW(vector.baja(), VectorException);
}


TEST_F(VectorTest, BajaIndiceManejaVectorVacio) {
    EXPECT_THROW(vector.baja(0), VectorException);
}

TEST_F(VectorTest, BajaIndiceManejaIndiceMayorOIgualACantidadDeDatos) {
    vector.alta(1);
    EXPECT_THROW(vector.baja(1), VectorException);
    EXPECT_THROW(vector.baja(2), VectorException);
    EXPECT_NO_THROW(vector.baja(0));
}

TEST_F(VectorTest, Vacio) {
    EXPECT_TRUE(vector.vacio());

    vector.alta(1);
    EXPECT_FALSE(vector.vacio());

    vector.baja();
    EXPECT_TRUE(vector.vacio());
}

TEST_F(VectorTest, Tamanio) {
    EXPECT_EQ(vector.tamanio(), 0);

    vector.alta(1);
    vector.alta(2);
    vector.alta(3);
    EXPECT_EQ(vector.tamanio(), 3);

    vector.baja();
    EXPECT_EQ(vector.tamanio(), 2);
}