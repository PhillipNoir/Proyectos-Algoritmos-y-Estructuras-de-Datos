/**
 * @file Arbol.hpp
 * @brief Declaracion de la clase Arbol para la estructura de datos de un árbol binario.
 * Nota: Esta es una herramienta que combinada con templates y sobrecarga de operadores permitiría modelar el mundo real de una manera más eficiente y organizada, es increíble cómo una estructura de datos tan simple puede ser tan poderosa.
 */
#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "Nodo.hpp"
#include <iostream>
#include <memory>

/**
 * @class Arbol
 * @brief Clase que representa un árbol binario.
 * 
 * Esta clase es una plantilla que permite crear árboles con cualquier tipo de dato.
 */
template <typename T>
class Arbol {
    private:
        std::unique_ptr<Nodo<T>> raiz;  ///Puntero a la raíz del árbol.

        /**
         * @brief Método recursivo para insertar un dato en el árbol.
         * @param nodo Puntero al nodo actual.
         * @param dato Dato a insertar en el árbol.
         * Este método se utiliza internamente para mantener la estructura del árbol.
         * Si el nodo es nulo, se crea un nuevo nodo con el dato.
         * Si el dato es menor que el dato del nodo actual, se inserta en el subárbol izquierdo.
         * Si el dato es mayor o igual, se inserta en el subárbol derecho
         */
        void insertarRecursivo(std::unique_ptr<Nodo<T>>& nodo, T& dato) {
            if (!nodo) {
                nodo = std::make_unique<Nodo<T>>(dato);
            } else if (dato < nodo->dato) {
                insertarRecursivo(nodo->izquierdo, dato);
            } else {
                insertarRecursivo(nodo->derecho, dato);
            }
        }

        /**
         * @brief Método recursivo para imprimir el árbol en orden.
         * @param nodo Puntero al nodo actual.
         * Este método se utiliza internamente para recorrer el árbol en orden.
         * Imprime los nodos del subárbol izquierdo, luego el nodo actual, y finalmente los nodos del subárbol derecho.
         * Llama recursivamente al hijo izquierdo hasta que no haya más nodos, luego imprime el dato de ese último nodo izquierdo, imprime el nodo padre y finalmente recorre el hijo derecho en busca de más nodos hijos, esto continúa hasta que todas las llamadas
         * recursivas hayan terminado y se hayan impreso todos los nodos en orden ascendente.
         */
        void inOrdenRecursivo(Nodo<T>* nodo) const {
            if (nodo) {
                inOrdenRecursivo(nodo->izquierdo.get());
                std::cout << nodo->dato << " ";
                inOrdenRecursivo(nodo->derecho.get());
            }
        }

        /**
         * @brief Método recursivo para imprimir el árbol en preorden.
         * @param nodo Puntero al nodo actual.
         * Este método se utiliza internamente para recorrer el árbol en preorden.
         * Imprime el nodo actual, luego los nodos del subárbol izquierdo, y finalmente los nodos del subárbol derecho.
         * Llama recursivamente al nodo actual, imprime su dato, luego recorre el hijo izquierdo en busca de más nodos hijos, y finalmente recorre el hijo derecho en busca de más nodos hijos.
         * Esto continúa hasta que todas las llamadas recursivas hayan terminado y se hayan impreso todos los nodos en preorden.
         */
        void preOrdenRecursivo(Nodo<T>* nodo) const {
            if (nodo) {
                std::cout << nodo->dato << " ";            // Primero imprime el nodo
                preOrdenRecursivo(nodo->izquierdo.get());  // Luego visita izquierda
                preOrdenRecursivo(nodo->derecho.get());    // Luego visita derecha
            }
        }

        /**
         * @brief Método recursivo para imprimir el árbol en postorden.
         * @param nodo Puntero al nodo actual.
         * Este método se utiliza internamente para recorrer el árbol en postorden.
         * Imprime los nodos del subárbol izquierdo, luego los nodos del subárbol derecho, y finalmente el nodo actual.
         * Llama recursivamente al hijo izquierdo en busca de más nodos hijos, luego recorre el hijo derecho en busca de más nodos hijos, y finalmente imprime el dato del nodo actual.
         */
        void postOrdenRecursivo(Nodo<T>* nodo) const {
            if (nodo) {
                postOrdenRecursivo(nodo->izquierdo.get());  // Visita izquierda
                postOrdenRecursivo(nodo->derecho.get());    // Visita derecha
                std::cout << nodo->dato << " ";             // Imprime al final
            }
        }

        /**
         * @brief Método para buscar un dato en el árbol.
         * @param nodo Puntero al nodo actual.
         * @param dato Dato a buscar en el árbol.
         * @return Devolución de un puntero al nodo que contiene el dato, o nullptr si no se encuentra.
         * Este método se utiliza internamente para buscar un dato en el árbol.
         * Si el nodo es nulo, devuelve nullptr.
         * Si el dato es igual al dato del nodo actual, devuelve un puntero al nodo
         */
        Nodo<T>* buscarNodo(Nodo<T>* nodo, const T& dato) const {
            if (!nodo) {
                return nullptr;  // Si el nodo es nulo, no se encontró el dato
            }
            if (dato == nodo->dato) {
                return nodo;  // Si el dato coincide, se devuelve el nodo
            } else if (dato < nodo->dato) {
                return buscarNodo(nodo->izquierdo.get(), dato);  // Buscar en el subárbol izquierdo
            } else {
                return buscarNodo(nodo->derecho.get(), dato);    // Buscar en el subárbol derecho
            }
        }

        /**
         * @brief Método recursivo para encontrar el nodo con el dato mínimo en el árbol.
         * @param nodo Puntero al nodo actual.
         * @return Devolución de un puntero al nodo con el dato mínimo, o nullptr si el árbol está vacío.
         * Este método se utiliza internamente para encontrar el nodo con el dato mínimo en el árbol
         * Si el nodo es nulo, devuelve nullptr.
         * Si el nodo tiene un hijo izquierdo, se llama recursivamente al hijo izquierdo hasta que no haya más hijos izquierdos.
         * Finalmente, devuelve el nodo con el dato mínimo encontrado.
         */
        Nodo<T>* encontrarMinimo(Nodo<T>* nodo) const {
            if (!nodo) {
                return nullptr;  // Si el nodo es nulo, no hay mínimo
            }
            if (!nodo->izquierdo) {
                return nodo;  // Si no hay hijo izquierdo, este es el mínimo
            }
            return encontrarMinimo(nodo->izquierdo.get());  // Buscar en el subárbol izquierdo
        }

        /**
         * @brief Método recursivo para encontrar el nodo con el dato máximo en el árbol.
         * @param nodo Puntero al nodo actual.
         * @return Devolución de un puntero al nodo con el dato máximo, o nullptr si el árbol está vacío.
         * Este método se utiliza internamente para encontrar el nodo con el dato máximo en el árbol.
         * Si el nodo es nulo, devuelve nullptr.
         * Si el nodo tiene un hijo derecho, se llama recursivamente al hijo derecho hasta que no haya más hijos derechos.
         * Finalmente, devuelve el nodo con el dato máximo encontrado.
         */
        Nodo<T>* encontrarMaximo(Nodo<T>* nodo) const {
            if (!nodo) {
                return nullptr;  // Si el nodo es nulo, no hay máximo
            }
            if (!nodo->derecho) {
                return nodo;  // Si no hay hijo derecho, este es el máximo
            }
            return encontrarMaximo(nodo->derecho.get());  // Buscar en el subárbol derecho
        }

        /** 
         * @brief Método para limpiar el árbol.
         * Este método se utiliza internamente para liberar la memoria del árbol.
         * Al asignar nullptr a la raíz, se libera la memoria de los nodos automáticamente.
         * Esto es posible gracias a la gestión automática de memoria proporcionada por std::unique_ptr
         * Esto evita fugas de memoria y asegura que todos los nodos sean eliminados correctamente.
         */
        void limpiarArbol(){
            raiz = nullptr;  // Al asignar nullptr, se libera la memoria de los nodos automáticamente
        }

    public:
        /**
         * @brief Constructor del árbol.
         * Inicializa la raíz del árbol como nula.
         */
        Arbol() : raiz(nullptr) {}

        /**
         * @brief Método para insertar un dato en el árbol.
         * @param dato Dato a insertar en el árbol.
         * Este método es público y se utiliza para insertar datos en el árbol.
         */
        void insertar(T dato) {
            insertarRecursivo(raiz, dato);
        }

        /**
         * @brief Método para imprimir el árbol en orden.
         * Este método es público y se utiliza para mostrar los datos del árbol en orden ascendente.
         */
        void inOrden() const {
            inOrdenRecursivo(raiz.get());
            std::cout << std::endl;
        }

        /**
         * @brief Método para imprimir el árbol en preorden.
         * Este método es público y se utiliza para mostrar los datos del árbol en preorden.
         */
        void preOrden() const {
            preOrdenRecursivo(raiz.get());
            std::cout << std::endl;
        }

        /**
         * @brief Método para imprimir el árbol en postorden.
         * Este método es público y se utiliza para mostrar los datos del árbol en postorden.
         */
        void postOrden() const {
            postOrdenRecursivo(raiz.get());
            std::cout << std::endl;
        }

        /**
         * @brief Método para buscar un dato en el árbol.
         * @param dato Dato a buscar en el árbol.
         * @return Devolución de un puntero al nodo que contiene el dato, o nullptr si no se encuentra.
         * Este método es público y se utiliza para buscar un dato en el árbol.
         */
        Nodo<T>* buscar(const T& dato) const {
            return buscarNodo(raiz.get(), dato);
        }

        /**
         * @brief Método para encontrar el nodo con el dato mínimo en el árbol.
         * @return Devolución de un puntero al nodo con el dato mínimo, o nullptr si el árbol está vacío.
         * Este método es público y se utiliza para encontrar el nodo con el dato mínimo en el árbol.
         */
        Nodo<T>* minimo() const {
            return encontrarMinimo(raiz.get());
        }

        /**
         * @brief Método para encontrar el nodo con el dato máximo en el árbol.
         * @return Devolución de un puntero al nodo con el dato máximo, o nullptr si el árbol está vacío.
         * Este método es público y se utiliza para encontrar el nodo con el dato máximo en el árbol.
         */
        Nodo<T>* maximo() const {
            return encontrarMaximo(raiz.get());
        }

        /**
         * @brief Destructor del árbol.
         * Limpia el árbol al asignar nullptr a la raíz, liberando la memoria de los nodos automáticamente.
         */
        void limpiar() {
            limpiarArbol();
        }
};

#endif