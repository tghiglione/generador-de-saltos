#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <exception>

class VectorException : public std::exception {
    // Excepción especifica y exclusiva para errores dentro del Vector.
    // Usar de la forma "throw VectorException();" cuando una precondición no se cumpla.

    // Ejemplo:
    //     if (condición_de_error){
    //         throw VectorException();
    //     }
};

template<typename T>
class Vector {
private:
    T* datos;
    size_t cantidad_datos;
    // Tamaño del arreglo "datos".
    size_t tamanio_maximo;
public:
    // Constructor.
    Vector();

    // Pre: El índice debe ser menor o igual que la cantidad de datos.
    // Post: Agrega el dato antes del dato en la posición indicada, moviendo todos los elementos siguientes.
    void alta(T dato, size_t indice);

    // Pre: -
    // Post: Agrega el dato al final del vector. Equivale a alta(dato, cantidad_datos).
    void alta(T dato);

    // Pre: El vector no puede estar vacío. El índice debe ser menor que la cantidad de datos.
    // Post: Elimina el dato en la posición indicada, moviendo todos los elementos siguientes.
    T baja(size_t indice);

    // Pre: El vector no puede estar vacío.
    // Post: Elimina el ultimo dato. Equivale a baja(cantidad_datos - 1).
    T baja();

    // Pre: -
    // Post: Devuelve true si el vector está vacío (es decir, si no hay datos).
    bool vacio();

    // Pre: -
    // Post: Devuelve la cantidad de datos del vector.
    size_t tamanio();

    // Pre: El vector no puede estar vacío. El índice debe ser menor que la cantidad de datos.
    // Post: Devuelve una referencia al dato deseado.
    T& operator[](size_t indice);

    // Constructor de copia (ya implementado).
    Vector(const Vector<T>& vector);

    // Operador de asignación (ya implementado).
    Vector<T>& operator=(const Vector<T>& vector);

    // Destructor.
    ~Vector();
};

template<typename T>
Vector<T>::Vector() {

}

template<typename T>
void Vector<T>::alta(T dato, size_t indice) {

}

template<typename T>
void Vector<T>::alta(T dato) {

}

template<typename T>
T Vector<T>::baja(size_t indice) {
    return nullptr;
}

template<typename T>
T Vector<T>::baja() {
    return nullptr;
}

template<typename T>
bool Vector<T>::vacio() {
    return false;
}

template<typename T>
size_t Vector<T>::tamanio() {
    return 0;
}

template<typename T>
T& Vector<T>::operator[](size_t indice) {
    return <#initializer#>;
}

template<typename T>
Vector<T>::~Vector() {

}

template<typename T>
Vector<T>::Vector(const Vector& vector) {
    datos = nullptr;
    cantidad_datos = vector.cantidad_datos;
    tamanio_maximo = vector.tamanio_maximo;
    if (tamanio_maximo) {
        datos = new T[tamanio_maximo];
        for (size_t i = 0; i < cantidad_datos; i++) {
            datos[i] = vector.datos[i];
        }
    }
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& vector) {
    if (this != &vector) {
        delete[] datos;
        datos = nullptr;
        cantidad_datos = vector.cantidad_datos;
        tamanio_maximo = vector.tamanio_maximo;
        if (tamanio_maximo) {
            datos = new T[tamanio_maximo];
            for (size_t i = 0; i < cantidad_datos; i++) {
                datos[i] = vector.datos[i];
            }
        }
    }
    return *this;
}

#endif