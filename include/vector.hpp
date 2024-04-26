#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <exception>
#include <iostream>

class vector_exception : public std::exception {
    // Excepción especifica y exclusiva para errores dentro del vector.
    // Usar de la forma "throw vector_exception();" cuando una precondición no se cumpla.

    // Ejemplo:
    //     if (condición_de_error){
    //         throw vector_exception();
    //     }
};

template<typename T>
class vector {
private:
    T* datos;
    // Tamaño del arreglo "datos".
    size_t cantidad_datos;
    //cant de memoria reservada
    size_t tamanio_maximo;

    const size_t MAXIMO_TAMANIO_INICIAL = 1;

    // Pre: El nuevo tamanio debe ser mayor que 0
    // Post: Reserva memoria para el nuevo tamanio del vector, en caso de no tener elementos reserva con MAXIMO_TAMANIO_INICIAL
    void redimensionar(size_t nuevo_tamanio);

    // Pre: La nueva capacidad debe ser mayor que 0
    // Post: Reubica al vector reservando nueva capacidad de memoria, tanto baja como alta, y borra la memoria que no se utiliza mas
    void reubicar_vector(size_t nueva_capacidad);

public:
    // Constructor.
    vector();

    // Pre: El índice debe ser menor o igual que la cantidad de datos.
    // Post: Agrega el dato antes del dato en la posición indicada, moviendo todos los elementos siguientes.
    void alta(T dato, size_t indice);

    // Pre: -
    // Post: Agrega el dato al final del vector. Equivale a alta(dato, cantidad_datos).
    void alta(T dato);

    // Pre: El vector no puede estar vacío. El índice debe ser menor que la cantidad de datos.
    // Post: Elimina el dato en la posición indicada, moviendo todos los elementos siguientes, y lo devuelve.
    T baja(size_t indice);

    // Pre: El vector no puede estar vacío.
    // Post: Elimina el ultimo dato y lo devuelve. Equivale a baja(cantidad_datos - 1).
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
    vector(const vector<T>& vector);

    // Operador de asignación (ya implementado).
    vector<T>& operator=(const vector<T>& vector);

    // Destructor.
    ~vector();
};

template<typename T>
void vector<T>::reubicar_vector(size_t nueva_capacidad) {
    if(datos != nullptr || cantidad_datos != 0){
        T *datos_aux = new T[nueva_capacidad];                              //creo un auxiliar
        for(size_t i = 0; i < tamanio_maximo && i < nueva_capacidad; i++){ //itero hasta el minimo, nueva capacidad o tamanio maximo
            datos_aux[i] = datos[i];
        }
        delete[] datos;
        datos = datos_aux;                                                //reubico el vector con el nuevo tamanio
    }else{
        throw vector_exception();
    }
}

template<typename T>
void vector<T>::redimensionar(size_t nuevo_tamanio) {
    if(datos == nullptr || cantidad_datos == 0){
        delete[] datos;
        datos = new T[MAXIMO_TAMANIO_INICIAL];
        tamanio_maximo = MAXIMO_TAMANIO_INICIAL;
    }else{
        reubicar_vector(nuevo_tamanio);
        tamanio_maximo = nuevo_tamanio;
    }
}

template<typename T>
vector<T>::vector() {
    datos = nullptr;
    tamanio_maximo = 0;
    cantidad_datos = 0;
}

template<typename T>
void vector<T>::alta(T dato, size_t indice) {
    if(indice <= cantidad_datos){
        if(cantidad_datos >= tamanio_maximo){
            redimensionar(cantidad_datos + 1 );
        }
        if(indice != cantidad_datos){
            for(size_t i = cantidad_datos; i > indice; i--){   //voy corriendo los elementos hasta dejar el espacio del indice libre
                datos[i] = datos[i -1];
            }
        }
        datos[indice] = dato;
        cantidad_datos++;
    }else{
        throw vector_exception();
    }
}

template<typename T>
void vector<T>::alta(T dato) {
    alta(dato, cantidad_datos);
}

template<typename T>
T vector<T>::baja(size_t indice) {
    if(datos == nullptr || cantidad_datos == 0 || indice >= cantidad_datos){
        throw vector_exception();
    }
    T elemento_eliminado = datos[indice];
    if(indice != (cantidad_datos - 1)){
        datos[indice] = datos[cantidad_datos - 1];
    }
    cantidad_datos--;
    redimensionar(cantidad_datos);
    return elemento_eliminado;

}

template<typename T>
T vector<T>::baja() {
    return baja(cantidad_datos - 1);
}

template<typename T>
bool vector<T>::vacio() {
    return cantidad_datos == 0;
}

template<typename T>
size_t vector<T>::tamanio() {
    return cantidad_datos;
}

template<typename T>
T& vector<T>::operator[](size_t indice) {
    if(cantidad_datos == 0 || indice >= cantidad_datos){
        throw vector_exception();
    }else{
        return datos[indice];
    }
}

template<typename T>
vector<T>::~vector() {
    delete[] datos;
}

// Estos dos métodos ya están implementados. No hace falta modificarlos.
template<typename T>
vector<T>::vector(const vector& vector) {
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
vector<T>& vector<T>::operator=(const vector& vector) {
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