/**
 * @file Lista.hpp
 * @brief Definición de la clase Lista para una lista enlazada.
 * Esta clase es parte de una implementación de una lista enlazada simple.
 * Utiliza punteros inteligentes para manejar la memoria de manera segura.
 */
#ifndef LISTA_HPP
#define LISTA_HPP
#include "Nodo.hpp"
#include <iostream>

template <typename T>

/**
 * @class Lista
 * @brief Clase que representa una lista enlazada simple.
 * Permite insertar, eliminar y buscar elementos en la lista.
 * Utiliza `std::unique_ptr` para gestionar la memoria de los nodos, lo que evita fugas de memoria y facilita la gestión de la lista enlazada.
 * Esta clase proporciona operaciones básicas como inserción al inicio, eliminación de un elemento, búsqueda de un elemento y visualización de la lista.
 * Una lista enlazada es una estructura de datos que consiste en punteros que conectan nodos, donde cada nodo contiene un valor y un puntero al siguiente nodo.
 * Recuerda, una lista no contiene nodos, contiene un puntero al primer nodo, y los nodos contienen los datos y un puntero al siguiente nodo.
 */
class Lista {
    private:
        // Puntero al primer nodo de la lista
        std::unique_ptr<Nodo<T>> cabeza;
    public:
        Lista() : cabeza(nullptr) {} //Constructor que inicializa la lista vacía
        /**
         * @brief Inserta un nuevo elemento al inicio de la lista.
         * @param valor El valor a insertar en la lista.
         */
        void insertarAlInicio(const T& valor) {
            //Si cabeza es nulo, significa que la lista está vacía.
            //En ese caso, cabeza apunta a un nuevo nodo con el valor, dado a que este nuevo nodo se construye con un puntero a nullptr, se vuelve la cabeza y cola de la lista.
            //Si cabeza no es nulo, significa que ya hay nodos en la lista.
            //En ese caso, creamos un nuevo nodo, se le asigna el valor y el parametro siguiente del nuevo nodo ahora sera la dirección donde apuntaba cabeza, cabeza ahora apunta al nuevo nodo.
            if(!cabeza){
                //Envolvemos el constructor de Nodo en std::make_unique para crear un nuevo nodo con el valor proporcionado.
                //Esto asegura que el nuevo nodo se convierte en la cabeza de la lista.
                cabeza = std::make_unique<Nodo<T>>(valor);
            } else {
                //Envolcemos el constructor de Nodo en std::make_unique para crear un nuevo nodo con el valor proporcionado.
                //El nuevo nodo se convierte en la cabeza de la lista, y su siguiente apunta al nodo que antes era la cabeza.
                //Esto asegura que el nuevo nodo se convierte en el primer nodo de la lista.
                //nuevoNodo es un puntero inteligente que apunta a un nuevo nodo con el valor proporcionado.
                //nuevoNodo no es un nodo, es un puntero inteligente que apunta a un nodo.
                auto nuevoNodo = std::make_unique<Nodo<T>>(valor);
                nuevoNodo->siguiente = std::move(cabeza);
                cabeza = std::move(nuevoNodo);
            }
        }

        /**
         * @brief Inserta un nuevo elemento al final de la lista.
         * @param valor El valor a insertar en la lista.
         */
        void insertarAlFinal(const T& valor) {
            //Si cabeza es nulo, significa que la lista está vacía.
            //En ese caso, se llama a insertarAlInicio para agregar el primer nodo.
            //Si cabeza no es nulo, significa que ya hay nodos en la lista.
            //En ese caso, recorremos la lista hasta el último nodo y agregamos el nuevo nodo al final, el parametro siguiente del nodo al que apunta actual ahora apunta al nuevo nodo, y el nuevo nodo se construye con un puntero a nullptr.
            //Esto asegura que el nuevo nodo se convierte en el último nodo de la lista.
            //Recuerda que el último nodo tiene su puntero siguiente apuntando a nullptr.
            if(!cabeza){
                insertarAlInicio(valor);
            } else {
                Nodo<T>* actual = cabeza.get();
                while(actual->siguiente){
                    actual = actual->siguiente.get();
                }
                auto nuevoNodo = std::make_unique<Nodo<T>>(valor);
                actual->siguiente = std::move(nuevoNodo);
            }
        }
        
        /**
         * @brief Imprime los elementos de la lista.
         * Recorre la lista desde la cabeza hasta el final, imprimiendo cada valor
         */
        void imprimir() const {
            if (!cabeza) {
                std::cout << "La lista está vacía.\n";
            } else {
                Nodo<T>* actual = cabeza.get();
                while (actual) {
                    std::cout << actual->dato;
                    if (actual->siguiente) {
                        std::cout << " -> ";
                    }
                    actual = actual->siguiente.get();
                }
                std::cout << std::endl;
            }
        }

        /**
         * @brief Elimina un elemento de la lista.
         * @param posicion La posición del elemento a eliminar (0 es el primer elemento).
         * Recorre la lista hasta la posición indicada y elimina el nodo en esa posición.
         * Si la posición es 0, se elimina el nodo cabeza y se actualiza cabeza.
         * Si la posición es inválida, no se realiza ninguna acción.
         */
        void eliminar(int posicion) {
            if (posicion < 0 || !cabeza) {
                std::cout << "Posición inválida o lista vacía.\n";
                return;
            }
            if (posicion == 0) {
                // Si la posición es 0, eliminamos el nodo cabeza
                cabeza = std::move(cabeza->siguiente);
                return;
            } else {
                Nodo<T>* actual = cabeza.get();
                Nodo<T>* anterior = nullptr;
                int indice = 0;

                // Recorremos la lista hasta encontrar la posición indicada
                while (actual && indice < posicion) {
                    anterior = actual;
                    actual = actual->siguiente.get();
                    indice++;
                }

                // Si llegamos al final de la lista o la posición es inválida, no hacemos nada
                if (!actual) {
                    std::cout << "Posición fuera de rango.\n";
                    return;
                }

                // Si encontramos el nodo a eliminar, lo eliminamos
                if (anterior) {
                    anterior->siguiente = std::move(actual->siguiente);
                    //Ahora el atributo siguiente del nodo anterior apunta al siguiente nodo del nodo actual, eliminando automáticamente el nodo actual gracias a la gestión de memoria de std::unique_ptr.
                }
            }
        }

        /**
         * @brief Busca un elemento en la lista.
         * @param valor El valor a buscar en la lista.
         * Recorre la lista desde la cabeza hasta el final, comparando cada valor con el valor buscado.
         * Si encuentra el valor, imprime un mensaje indicando que el valor fue encontrado, de lo contrario, indica que el valor no se encuentra en la lista.
         */
        void buscar(const T& valor){
            Nodo<T>* actual = cabeza.get();
            int indice = 0;
            //Recorremos la lista desde la cabeza hasta el final, comparando cada valor con el valor buscado.
            //Si encontramos el valor, imprimimos un mensaje indicando que el valor fue encontrado, de lo contrario, indicamos que el valor no se encuentra en la lista.
            //El indice se incrementa en cada iteración para indicar la posición del nodo actual.
            while (actual) {
                if (actual->dato == valor) {
                    std::cout << "Valor " << valor << " encontrado en la posición " << indice << ".\n";
                    return;
                } else {
                    actual = actual->siguiente.get();
                    indice++;
                }
            }
            //Si llegamos al final de la lista y no encontramos el valor, imprimimos un mensaje indicando que el valor no se encuentra en la lista.
            std::cout << "Valor " << valor << " no encontrado en la lista.\n";      
        }

        /**
         * @brief Añade un elemento en la posición indicada.
         * @param valor El valor a añadir en la lista.
         * @param posicion La posición donde se añadirá el nuevo elemento (0 es el primer elemento).
         * Recorre la lista hasta la posición indicada y añade el nuevo nodo en esa posición
         */
        void anadirEnPosicion(const T& valor, int posicion) {
            if (posicion < 0) {
                std::cout << "Posición inválida.\n";
                return;
            }
            if (posicion == 0) {
                insertarAlInicio(valor);
                return;
            }
            Nodo<T>* actual = cabeza.get();
            Nodo<T>* anterior = nullptr;
            int indice = 0;

            // Recorremos la lista hasta encontrar la posición indicada
            while (actual && indice < posicion) {
                anterior = actual;
                actual = actual->siguiente.get();
                indice++;
            }

            // Creamos un nuevo nodo con el valor
            auto nuevoNodo = std::make_unique<Nodo<T>>(valor);

            // Si llegamos al final de la lista o la posición es válida, insertamos el nuevo nodo
            if (!anterior) {
                std::cout << "Posición fuera de rango.\n";
                return;
            }

            // Enlazamos el nuevo nodo en la posición indicada
            nuevoNodo->siguiente = std::move(anterior->siguiente);
            anterior->siguiente = std::move(nuevoNodo);
        }

        /**
         * @brief Invertir el orden de los elementos en la lista.
         * Recorre la lista y cambia el orden de los nodos, de modo que el último nodo se convierte en el primero y viceversa.
         * Utiliza un puntero temporal para almacenar el nodo actual y otro puntero para construir la nueva lista invertida.
         * Al final, actualiza la cabeza de la lista para que apunte al nuevo primer nodo.
         * Esta operación es útil para revertir el orden de los elementos en la lista enlazada
         */
        void invertir() {
            std::unique_ptr<Nodo<T>> nuevaCabeza = nullptr;
            while (cabeza) {
                // Tomamos el primer nodo de la lista original
                std::unique_ptr<Nodo<T>> temp = std::move(cabeza);
                // Avanzamos la cabeza al siguiente nodo
                cabeza = std::move(temp->siguiente);
                // Conectamos el nodo al principio de la nueva lista
                temp->siguiente = std::move(nuevaCabeza);
                nuevaCabeza = std::move(temp);
            }
            cabeza = std::move(nuevaCabeza);
        }

        /**
         * @brief Obtiene el tamaño de la lista.
         * Recorre la lista y cuenta el número de nodos presentes.
         */
        int obtenerTamano() const {
            int tamano = 0;
            Nodo<T>* actual = cabeza.get();
            while (actual) {
                tamano++;
                actual = actual->siguiente.get();
            }
            return tamano;
        }

        /**
         * @brief Limpia la lista.
         * Elimina todos los nodos de la lista, liberando la memoria ocupada por ellos.
         * Esto se logra al reasignar el puntero cabeza a nullptr, lo que automáticamente libera la memoria de los nodos gracias a `std::unique_ptr`.
         */
        void limpiar() {
            cabeza = nullptr; // Al reasignar a nullptr, se liberan automáticamente los nodos gracias a std::unique_ptr
        }

};

#endif