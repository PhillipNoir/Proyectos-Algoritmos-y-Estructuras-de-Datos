/**
 * @file main.cpp
 * @brief Programa principal que utiliza la clase Arbol para crear un árbol binario y realizar operaciones sobre él.
 * Este programa crea un árbol binario, inserta varios datos y los imprime en orden.
 */
// main.cpp
#include "Arbol.hpp"

int main() {
    Arbol<int> arbol;
    arbol.insertar(10);
    arbol.insertar(5);
    arbol.insertar(15);
    arbol.insertar(3);
    arbol.insertar(7);

    arbol.inOrden();  // Debería mostrar: 3 5 7 10 15
    arbol.preOrden(); // Debería mostrar: 10 5 3 7 15
    arbol.postOrden(); // Debería mostrar: 3 7 5 15 10

    int datoBuscado = 7;
    Nodo<int>* nodoEncontrado = arbol.buscar(datoBuscado);
    if (nodoEncontrado) {
        std::cout << "Dato encontrado: " << nodoEncontrado->dato << std::endl;
    } else {
        std::cout << "Dato no encontrado." << std::endl;
    }

    Nodo<int>* minimo = arbol.minimo();
    if (minimo) {
        std::cout << "Mínimo: " << minimo->dato << std::endl; // Debería mostrar: 3
    } else {
        std::cout << "El árbol está vacío." << std::endl;
    }

    Nodo<int>* maximo = arbol.maximo();
    if (maximo) {
        std::cout << "Máximo: " << maximo->dato << std::endl; // Debería mostrar: 15
    } else {
        std::cout << "El árbol está vacío." << std::endl;
    }

    std::cout << "Número de nodos: " << arbol.nodos() << std::endl; // Debería mostrar: 5

    std::cout << "Número de hojas: " << arbol.hojas() << std::endl; // Debería mostrar: 3

    arbol.limpiar(); // Limpia el árbol

    std::cout << "Árbol limpiado." << std::endl;

    // Verifica si el árbol está vacío
    if (arbol.buscar(10) == nullptr) {
        std::cout << "El árbol está vacío después de limpiar." << std::endl;
    } else {
        std::cout << "El árbol aún contiene nodos." << std::endl;
    }

    return 0;
}
