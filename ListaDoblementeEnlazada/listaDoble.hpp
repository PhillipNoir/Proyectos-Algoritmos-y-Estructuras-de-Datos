/** *
 * @file listaDoble.hpp
 * @brief Definición de la clase ListaDoble.
 * Esta clase implementa una lista doblemente enlazada utilizando punteros inteligentes.
 * Permite insertar elementos al final, mostrar los elementos hacia adelante y hacia atrás.
*/
#ifndef LISTADOBLE_HPP
#define LISTADOBLE_HPP

#include "nodo.hpp"
#include <iostream>

/**
 * @class ListaDoble
 * @brief Clase que representa una lista doblemente enlazada.
 * 
 * Esta clase permite insertar elementos al final de la lista, mostrar los elementos hacia adelante
 * y hacia atrás. Utiliza punteros inteligentes para gestionar la memoria de manera eficiente.
 */
template <typename T>
class ListaDoble {
        private:
            std::unique_ptr<Nodo<T>> cabeza; // Puntero inteligente al primer nodo de la lista
            Nodo<T>* cola;   // Puntero al último nodo de la lista
        public:
            /**
            * @brief Constructor de la clase ListaDoble.
            * Inicializa la lista doblemente enlazada estableciendo los punteros cabeza y cola a nullptr.
            */
            ListaDoble() : cabeza(nullptr), cola(nullptr) {}

            /**
            * @brief Inserta un nuevo nodo al inicio de la lista.
            * 
            * @param valor El valor del nuevo nodo a insertar.
            * 
            * Este método crea un nuevo nodo con el valor proporcionado y lo inserta al inicio de la lista.
            * Si la lista está vacía, el nuevo nodo se convierte en la cabeza y la cola de la lista.
             */
            void insertarAlInicio(const T& valor) {
                auto nuevoNodo = std::make_unique<Nodo<T>>(valor);
                // Si la lista está vacía, asignamos el nuevo nodo a cabeza y cola
                if (!cabeza) {
                    cola = nuevoNodo.get();
                    cabeza = std::move(nuevoNodo);
                } 
                // Si la lista no está vacía, enlazamos el nuevo nodo al inicio
                else {
                    Nodo<T>* nodoActual = cabeza.get(); //Guardamos el puntero antes de mover
                    nuevoNodo->siguiente = std::move(cabeza);
                    nodoActual->anterior = nuevoNodo.get(); // Enlazamos el nodo actual como anterior del nuevo nodo
                    cabeza = std::move(nuevoNodo);
                }
            }


            /**
             * @brief Inserta un nuevo nodo al final de la lista.
             * 
             * @param valor El valor del nuevo nodo a insertar.
             * 
             * Este método crea un nuevo nodo con el valor proporcionado y lo inserta al final de la lista.
             * Si la lista está vacía, el nuevo nodo se convierte en la cabeza y la cola de la lista.
             */
            void insertarAlFinal(const T& valor){
                // Crear un nuevo nodo con el valor proporcionado
                // Utilizamos std::make_unique para crear un nodo con puntero inteligente
                auto nuevoNodo = std::make_unique<Nodo<T>>(valor);
                // Si la lista está vacía, el nuevo nodo se convierte en la cabeza y la cola
                // Si la lista no está vacía, se enlaza el nuevo nodo al final de la lista
                if(!cabeza){
                    // Si la lista está vacía, asignamos el nuevo nodo a cabeza y cola
                    cola = nuevoNodo.get();
                    cabeza = std::move(nuevoNodo);
                }
                else{
                    // Si la lista no está vacía, enlazamos el nuevo nodo al final
                    // El nuevo nodo se convierte en el siguiente de la cola actual
                    nuevoNodo->anterior = cola;
                    cola->siguiente = std::move(nuevoNodo);
                    cola = cola->siguiente.get();
                }
            }

            void insertarEnPosicion(int posicion, T valor) {
                // Verifica si la posición es válida
                if (posicion < 0) {
                    std::cout << "Posición inválida." << std::endl;
                    return;
                }
                // Si la posición es 0, inserta al inicio
                if (posicion == 0) {
                    insertarAlInicio(valor);
                    return;
                }
                // Crea un nuevo nodo con el valor proporcionado
                auto nuevo = std::make_unique<Nodo<T>>(valor);
                Nodo<T>* actual = cabeza.get();
                int indice = 0;

                // Recorre la lista hasta encontrar la posición deseada
                while (actual && indice < posicion - 1) {
                    actual = actual->siguiente.get();
                    indice++;
                }

                // Si se llegó al final de la lista, inserta al final
                if (!actual) {
                    insertarAlFinal(valor);
                    return;
                }

                // Enlaza el nuevo nodo en la posición deseada
                nuevo->siguiente = std::move(actual->siguiente);
                nuevo->anterior = actual;

                if (nuevo->siguiente) {
                    nuevo->siguiente->anterior = nuevo.get();
                } else {
                    cola = nuevo.get(); // Actualiza la cola si se inserta al final
                }

                actual->siguiente = std::move(nuevo);
            }

            /**
             * @brief Muestra los elementos de la lista hacia adelante.
             * 
             * Este método recorre la lista desde la cabeza hasta la cola, imprimiendo los valores de cada nodo.
             * Si la lista está vacía, no se mostrará ningún elemento.
             */
            void mostrarAdelante() const {
                // Verifica si la lista está vacía
                if(!cabeza) {
                    std::cout << "La lista está vacía." << std::endl;
                    return;
                }
                // Recorre la lista e imprime los valores de cada nodo
                std::cout << "Elementos de la lista (adelante): ";
                Nodo<T>* actual = cabeza.get();
                while(actual) {

                    std::cout << actual->dato << " ";
                    actual = actual->siguiente.get();
                }

                std::cout << std::endl;
            }

            /**
             * @brief Muestra los elementos de la lista hacia atrás.
             * 
             * Este método recorre la lista desde la cola hasta la cabeza, imprimiendo los valores de cada nodo.
             * Si la lista está vacía, no se mostrará ningún elemento.
             */
            void mostrarAtras() const {
                // Verifica si la lista está vacía
                if(!cola) {
                    std::cout << "La lista está vacía." << std::endl;
                    return;
                }
                // Recorre la lista e imprime los valores de cada nodo hacia atrás
                std::cout << "Elementos de la lista (atrás): ";
                Nodo<T>* actual = cola;
                while(actual) {
                    std::cout << actual->dato << " ";
                    actual = actual->anterior;
                }
                std::cout << std::endl;
            }

            /**
             * @brief Elimina un nodo con un valor específico de la lista.
             * 
             * @param valor El valor del nodo a eliminar.
             * 
             * Este método busca un nodo con el valor especificado y lo elimina de la lista.
             * Si el nodo es encontrado, se actualizan los punteros del nodo anterior y siguiente.
             * Si no se encuentra el nodo, muestra un mensaje.
             */
            void eliminarEnPosicion(int posicion) {
                // Verifica si la posición es válida
                if (posicion < 0 || !cabeza) {
                    std::cout << "Posición inválida o lista vacía." << std::endl;
                    return;
                }
                Nodo<T>* actual = cabeza.get();
                int indice = 0;

                // Recorre la lista hasta encontrar el nodo en la posición deseada
                while (actual && indice < posicion) {
                    actual = actual->siguiente.get();
                    indice++;
                }

                // Si no se encontró el nodo, muestra un mensaje
                if (!actual) {
                    std::cout << "No se encontró un nodo en la posición " << posicion << "." << std::endl;
                    return;
                }

                // Si el nodo a eliminar es la cabeza
                if (actual == cabeza.get()) {
                    cabeza = std::move(actual->siguiente);
                    if (cabeza) {
                        cabeza->anterior = nullptr;
                    } else {
                        cola = nullptr; // Si la lista queda vacía, actualiza la cola
                    }
                } else if (actual == cola) { // Si el nodo a eliminar es la cola
                    cola = actual->anterior;
                    if (cola) {
                        cola->siguiente.reset();
                    } else {
                        cabeza = nullptr; // Si la lista queda vacía, actualiza la cabeza
                    }
                } else { // Si el nodo a eliminar está en medio de la lista
                    actual->anterior->siguiente = std::move(actual->siguiente);
                    if (actual->siguiente) {
                        actual->siguiente->anterior = actual->anterior;
                    }
                }
            }

            /**
             * @brief Busca un valor en la lista.
             * 
             * @param valor El valor a buscar en la lista.
             * 
             * Este método recorre la lista y busca un nodo con el valor especificado.
             * Si se encuentra el nodo, muestra un mensaje indicando que el valor fue encontrado y especifica la posición en la que se encuentra.
             * Si no se encuentra, muestra un mensaje indicando que el valor no está en la lista.
             */
            void buscar(const T& valor) const {
                Nodo<T>* actual = cabeza.get();
                int posicion = 0;

                // Recorre la lista buscando el valor
                while (actual) {
                    if (actual->dato == valor) {
                        std::cout << "Valor " << valor << " encontrado en la posición " << posicion << "." << std::endl;
                        return;
                    }
                    actual = actual->siguiente.get();
                    posicion++;
                }

                // Si no se encontró el valor, muestra un mensaje
                std::cout << "Valor " << valor << " no encontrado en la lista." << std::endl;
            }
        
};
#endif