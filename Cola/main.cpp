/**
 * @file main.cpp
 * @brief Archivo principal que utiliza la clase Cola.
 * Este archivo contiene un ejemplo de uso de la clase Cola para demostrar su funcionalidad.
 */
#include "Cola.hpp"

int main() {
    Cola<int> miCola;

    miCola.encolar(10);
    miCola.encolar(20);
    miCola.encolar(30);

    std::cout << "Frente de la cola: " << miCola.primer() << "\n";

    miCola.desencolar();
    std::cout << "Frente de la cola después de desencolar: " << miCola.primer() << "\n";

    return 0;
}
