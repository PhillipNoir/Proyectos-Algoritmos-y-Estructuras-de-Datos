/**
 * @file Nodo.hpp
 * @brief Definición de la clase Nodo para una cola.
 * Esta clase es parte de una implementación de una cola genérica.
 * Utiliza punteros inteligentes para manejar la memoria de manera segura.
 */
#ifndef NODO_HPP
#define NODO_HPP

#include <memory>

template<typename T>
class Nodo {
public:
    T dato;
    std::unique_ptr<Nodo<T>> siguiente;

    Nodo(const T& valor) : dato(valor), siguiente(nullptr) {}
};

#endif
