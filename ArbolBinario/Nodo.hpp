/**
 * @file Nodo.hpp
 * @brief Declaracion de la clase Nodo para la estructura de datos de un árbol binario.
 */
#ifndef NODO_HPP
#define NODO_HPP

#include <iostream>
#include <memory>

template <typename T>

/**
 * @class Nodo
 * @brief Clase que representa un nodo en un árbol binario.
 * 
 * Esta clase es una plantilla que permite crear nodos con cualquier tipo de dato.
 */
class Nodo {
    public:
        T dato;  ///< Dato almacenado en el nodo.
        std::unique_ptr<Nodo<T>> izquierdo;  // Puntero al hijo izquierdo.
        std::unique_ptr<Nodo<T>> derecho;    // Puntero al hijo derecho.

        /**
         * @brief Constructor del nodo.
         * @param d Dato a almacenar en el nodo.
         */
        Nodo(T d) : dato(d), izquierdo(nullptr), derecho(nullptr) {}
    
};

#endif