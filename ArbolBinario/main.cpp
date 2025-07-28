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

    return 0;
}
