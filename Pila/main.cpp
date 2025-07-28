/**
 * @file main.cpp
 * @brief Implementación de una pila utilizando la clase Pila.
 * Esta implementación utiliza la clase Pila para realizar operaciones básicas de una pila.
 * @details Se incluyen ejemplos de uso de las operaciones push, pop, top, isEmpty, size, clear y mostrar.
 */
#include "Pila.hpp"
#include <iostream>

int main() {
    Pila<int> pila;

    // Insertar elementos en la pila
    pila.push(10);
    pila.push(20);
    pila.push(30);

    // Mostrar el tamaño de la pila
    std::cout << "Tamaño de la pila: " << pila.size() << std::endl;

    // Mostrar el elemento en la parte superior de la pila
    std::cout << "Elemento en la parte superior: " << pila.top() << std::endl;

    // Eliminar el elemento en la parte superior de la pila
    pila.pop();
    std::cout << "Después de pop, elemento en la parte superior: " << pila.top() << std::endl;

    // Limpiar la pila
    pila.clear();
    std::cout << "Tamaño de la pila después de clear: " << pila.size() << std::endl;

    // Verificar si la pila está vacía
    if (pila.isEmpty()) {
        std::cout << "La pila está vacía." << std::endl;
    } else {
        std::cout << "La pila no está vacía." << std::endl;
    }

    return 0;
}