/**
 * @file Pila.hpp
 * @brief Definición de la clase Pila.
 * Esta clase implementa una pila.
 * Utiliza punteros inteligentes para manejar la memoria de manera segura. 
 */

#ifndef PILA_HPP
#define PILA_HPP
#include "Nodo.hpp"
#include <memory>
#include <iostream>

/**
 * @class Pila
 * @brief Clase que representa una pila.
 * Implementa las operaciones básicas de una pila: push, pop, top, isEmpty, size, clear y mostrar.
 * Utiliza `std::unique_ptr` para gestionar la memoria de los nodos de manera segura.
 * @tparam T Tipo de dato almacenado en la pila.
 */
template <typename T>
class Pila {
    private:
        std::unique_ptr<Nodo<T>> cima; ///< Puntero al nodo superior de la pila.
        size_t tamano; ///< Tamaño actual de la pila.

    public:
        Pila() : cima(nullptr), tamano(0) {} ///Constructor por defecto que inicializa la pila vacía.

        /**
         * @brief Inserta un elemento en la parte superior de la pila.
         * @param valor Valor a insertar en la pila.
         */
        void push(const T& valor) {
            // Ej: [cima] -> [30] -> [20] -> [10] -> nullptr
            auto nuevoNodo = std::make_unique<Nodo<T>>(valor);
            //El nuevo nodo apunta a donde antes apuntaba la cima
            nuevoNodo->siguiente = std::move(cima);
            cima = std::move(nuevoNodo);
            tamano++;
        }

        /**
         * @brief Elimina el elemento en la parte superior de la pila.
         * @throws std::runtime_error Si la pila está vacía.
         */
        void pop() {
            if (!cima) {
                std::cout << "La pila está vacía. No se puede eliminar el elemento superior." << std::endl;
                return;
            }
            cima = std::move(cima->siguiente);
            tamano--;
        }

        /**
         * @brief Devuelve el valor del elemento en la parte superior de la pila sin eliminarlo.
         * @return Valor del elemento superior.
         * @throws std::runtime_error Si la pila está vacía.
         */
        T* top() const {
            if (!cima) {
                std::cout << "La pila está vacía. No hay elemento superior." << std::endl;
                return nullptr;
            }
            return &cima->dato;
        }

        /**
         * @brief Verifica si la pila está vacía.
         * @return true si la pila está vacía, false en caso contrario.
         */
        bool isEmpty() const {
            return tamano == 0;
        }

        /**
         * @brief Devuelve el tamaño actual de la pila.
         * @return Tamaño de la pila.
         */
        size_t size() const {
            return tamano;
        }

        /**
         * @brief Limpia la pila, eliminando todos los elementos.
         */
        void clear() {
            cima == nullptr;
            tamano = 0;
        }
};

#endif