/**
 * @file ListaCircular.hpp
 * @brief Definición de la clase ListaCircular para una lista enlazada circular.
 * @tparam T Tipo de dato almacenado en la lista.
 * @details Esta clase implementa una lista enlazada circular utilizando nodos definidos por la estructura
 * Nodo. Permite insertar, mostrar, eliminar nodos y buscar posiciones de valores.
 * Utiliza punteros únicos para la gestión automática de memoria.
 */

#ifndef LISTACIRCULAR_HPP
#define LISTACIRCULAR_HPP

#include <memory>
#include <iostream>
#include "Nodo.hpp"

template <typename T>
class ListaCircular {
private:
    std::unique_ptr<Nodo<T>> cabeza;
    Nodo<T>* ultimo = nullptr;

public:

    /**
     * @brief Constructor de la lista circular.
     * Inicializa la lista como vacía.
     * @param valor Valor inicial para el nodo, si se desea agregar uno al crear la lista.
     */
    void insertar(const T& valor) {
    auto nuevo = std::make_unique<Nodo<T>>(valor);

    if (!cabeza) {
        // Primer nodo
        cabeza = std::move(nuevo);
        cabeza->siguiente.reset(cabeza.get());  // se apunta a sí mismo
        ultimo = cabeza.get();                  // actualizamos puntero al último nodo
    } else {
        nuevo->siguiente.reset(cabeza.get());   // apunta al inicio
        ultimo->siguiente = std::move(nuevo);   // último apunta al nuevo
        ultimo = ultimo->siguiente.get();       // actualizamos último nodo
    }
}


    /**
     * @brief Muestra los elementos de la lista circular.
     * @param repeticiones Número de veces que se repite la impresión de la lista.
     */
    void mostrar(int repeticiones = 1) const {
        if (!cabeza) {
            std::cout << "Lista vacía.\n";
            return;
        }

        Nodo<T>* actual = cabeza.get();
        for (int i = 0; i < repeticiones; ++i) {
            Nodo<T>* temp = actual;
            do {
                std::cout << temp->dato << " -> ";
                temp = temp->siguiente.get();
            } while (temp != cabeza.get());
            std::cout << "(repite)\n";
        }
    }

    /**
     * @brief Elimina un nodo con el valor especificado de la lista circular.
     * @param valor Valor del nodo a eliminar.
     */
    void eliminar(const T& valor) {
    if (!cabeza) return;

    Nodo<T>* actual = cabeza.get();
    Nodo<T>* anterior = nullptr;

    do {
        if (actual->dato == valor) {
            if (actual == cabeza.get()) {
                // Eliminar la cabeza
                if (actual->siguiente.get() == cabeza.get()) {
                    // Solo hay un nodo
                    cabeza.reset();
                    ultimo = nullptr;
                } else {
                    // Hay más de un nodo
                    ultimo->siguiente = std::move(actual->siguiente);
                    cabeza = std::move(ultimo->siguiente);
                }
            } else {
                // Nodo intermedio o final
                anterior->siguiente = std::move(actual->siguiente);
                if (actual == ultimo) {
                    ultimo = anterior;
                }
            }
            return;
        }
        anterior = actual;
        actual = actual->siguiente.get();
    } while (actual != cabeza.get());
}

/**
 * @brief Inserta un nuevo nodo después de un nodo con un valor específico.
 * @param valorExistente Valor del nodo después del cual se insertará el nuevo nodo.
 * @param nuevoValor Valor del nuevo nodo a insertar.
 */
void insertarDespuesDe(const T& valorExistente, const T& nuevoValor) {
    if (!cabeza) return;

    Nodo<T>* actual = cabeza.get();

    do {
        if (actual->dato == valorExistente) {
            auto nuevoNodo = std::make_unique<Nodo<T>>(nuevoValor);
            nuevoNodo->siguiente = std::move(actual->siguiente);
            actual->siguiente = std::move(nuevoNodo);

            if (actual == ultimo) {
                ultimo = actual->siguiente.get();
            }
            return;
        }
        actual = actual->siguiente.get();
    } while (actual != cabeza.get());
}

/**
 * @brief Busca la posición de un valor en la lista circular.
 * @param valor Valor a buscar.
 * @return La posición del valor en la lista, o -1 si no se encuentra.
 */
int buscarPosicion(const T& valor) const {
    if (!cabeza) return -1;

    Nodo<T>* actual = cabeza.get();
    int posicion = 0;

    do {
        if (actual->dato == valor) {
            return posicion;
        }
        actual = actual->siguiente.get();
        posicion++;
    } while (actual != cabeza.get());

    return -1; // No encontrado
}

};

#endif
