/**
 * @file main.cpp
 * @brief Programa principal para probar la clase ListaCircular.
 * @details Este programa crea una lista circular, inserta nodos, muestra la lista,
 * elimina nodos y busca posiciones de valores en la lista.
 * Utiliza la clase ListaCircular definida en ListaCircular.hpp.
 */

#include "ListaCircular.hpp"
#include <string>

int main() {
    ListaCircular<std::string> lista;

    lista.insertar("A");
    lista.insertar("B");
    lista.insertar("C");

    lista.mostrar(2);  // Mostrar dos ciclos para ver la circularidad

    lista.eliminar("B");
    lista.mostrar();  // Mostrar después de eliminar un nodo
    lista.insertarDespuesDe("A", "D");
    lista.mostrar();  // Mostrar después de insertar un nodo después de "A"

    int posicion = lista.buscarPosicion("C");
    if (posicion != -1) {
        std::cout << "El valor 'C' se encuentra en la posición: " << posicion << "\n";
    } else {
        std::cout << "El valor 'C' no se encuentra en la lista.\n";
    }

    return 0;
}
