/**
 * @file nodo.hpp
 * @brief Definición de la clase Nodo para una lista enlazada.
 * Esta clase es parte de una implementación de una lista enlazada simple.
 * Utiliza punteros inteligentes para manejar la memoria de manera segura.
 */
#ifndef NODO_HPP
#define NODO_HPP

#include <memory>

template <typename T>

/**
 * @class Nodo
 * @brief Clase que representa un nodo en una lista enlazada.
 * Cada nodo contiene un valor de tipo T y un puntero al siguiente nodo.
 * Utiliza `std::unique_ptr` para gestionar la memoria del siguiente nodo,
 * lo que evita fugas de memoria y facilita la gestión de la lista enlazada.
 * @tparam T Tipo de dato almacenado en el nodo.
 */
class Nodo {
    public:
        T dato;
        std::unique_ptr<Nodo<T>> siguiente;
        Nodo(const T& valor) : dato(valor), siguiente(nullptr) {}
};
#endif