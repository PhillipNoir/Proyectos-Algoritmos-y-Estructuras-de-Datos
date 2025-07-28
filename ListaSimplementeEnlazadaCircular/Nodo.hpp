/**
 * @file Nodo.hpp
 * @brief Definición de la estructura Nodo para una lista enlazada circular.
 * @tparam T Tipo de dato almacenado en el nodo.
 * @details Esta estructura define un nodo que contiene un dato de tipo T y un puntero único al siguiente nodo.
 * El nodo es utilizado en la implementación de una lista enlazada circular.
 */

#ifndef NODO_HPP
#define NODO_HPP


template <typename T>
struct Nodo {
    T dato; // Dato almacenado en el nodo
    // Puntero único al siguiente nodo, permite la gestión automática de memoria
    std::unique_ptr<Nodo<T>> siguiente;

    // Constructor para inicializar el nodo con un valor
    Nodo(const T& valor) : dato(valor), siguiente(nullptr) {}
};

#endif
