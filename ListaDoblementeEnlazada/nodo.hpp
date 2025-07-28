/**
 * 
 * @file nodo.hpp
 * @brief Definicion de la estructura Nodo para una lista doblemente enlazada.
 * Esta estructura es utilizada para almacenar datos de tipo T y referencias
 * a los nodos siguiente y anterior.
 *  
 **/

#ifndef NODO_HPP
#define NODO_HPP

#include <memory>

/**
 * @brief Estructura Nodo para una lista doblemente enlazada.
 * Esta estructura almacena un dato de tipo T, un puntero inteligente
 * al siguiente nodo y un puntero al nodo anterior.
 *  
 **/
template <typename T>
struct Nodo {
    // Tipo de dato almacenado en el nodo
    T dato;
    // Puntero inteligente al siguiente nodo
    // Utilizamos std::unique_ptr para manejar la memoria automáticamente
    std::unique_ptr<Nodo<T>> siguiente;
    // Puntero al nodo anterior
    Nodo<T>* anterior;

    /**
     * @brief Constructor por defecto que inicializa el nodo sin datos.
     */
    Nodo(const T& d) : dato(d), siguiente(nullptr), anterior(nullptr) {}
};

#endif