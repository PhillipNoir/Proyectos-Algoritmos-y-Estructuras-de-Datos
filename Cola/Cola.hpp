/**
 * @file Cola.hpp
 * @brief Definición de la clase Cola para una cola genérica.
 * Esta clase implementa una cola utilizando punteros inteligentes para manejar la memoria de manera segura.
 * Permite operaciones básicas como encolar, desencolar y verificar si la cola está vacía
 */
#ifndef COLA_HPP
#define COLA_HPP
#include "Nodo.hpp"
#include <memory>
#include <iostream>

template<typename T>

/**
 * @class Cola
 * @brief Clase que representa una cola genérica.
 */
class Cola {
    private:
        std::unique_ptr<Nodo<T>> frente;
        Nodo<T>* final;
    public:
        /**
         * @brief Constructor de la clase Cola.
         * Inicializa una cola vacía.
         */
        Cola() : frente(nullptr), final(nullptr) {}

        /**
         * @brief Encola un nuevo elemento al final de la cola.
         * @param valor El valor a encolar.
         * Esta función crea un nuevo nodo con el valor proporcionado y lo agrega al final de la cola.
         * Si la cola está vacía, el nuevo nodo se convierte en el frente y el final de la cola.
         * Si la cola no está vacía, el nuevo nodo se agrega al final y se actualiza el puntero final.
         */
        void encolar(const T& valor) {
            auto nuevoNodo = std::make_unique<Nodo<T>>(valor);
            Nodo<T>* nuevoPtr = nuevoNodo.get();
            if (!frente) {
                frente = std::move(nuevoNodo);
                final = frente.get();
            } else {
                final->siguiente = std::move(nuevoNodo);
                final = nuevoPtr;
            }
        }

        /**
         * @brief Desencola el elemento del frente de la cola.
         * Esta función elimina el nodo del frente de la cola.
         * Si la cola está vacía, no realiza ninguna acción.
         */
        void desencolar() {
            if (!frente) {
                std::cout << "La cola está vacía. No se puede desencolar." << std::endl;
                return;
            }
            frente = std::move(frente->siguiente);
            if (!frente) {
                final = nullptr; // Si la cola queda vacía, actualizamos el puntero final
            }
        }

        /**
         * @brief Devuelve el valor del elemento en el frente de la cola.
         * @return El valor del elemento en el frente de la cola.
         */
        T& primer() const {
            if (!frente) {
                throw std::runtime_error("La cola está vacía. No hay elementos para mostrar.");
            }
            return frente->dato;
        }

        /**
         * @brief Verifica si la cola está vacía.
         * @return true si la cola está vacía, false en caso contrario.
         */
        bool estaVacia() const {
            return !frente;
        }
};

#endif