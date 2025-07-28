#include <iostream>
#include "TDAContador.h"

int main() {
    Contador c1(5); // Inicia en 5

    std::cout << "Valor inicial: " << c1.obtenerValor() << "\n";

    c1.incrementar();
    std::cout << "Después de incrementar: " << c1.obtenerValor() << "\n";

    c1.decrementar();
    c1.decrementar();
    std::cout << "Después de decrementar dos veces: " << c1.obtenerValor() << "\n";

    c1.reiniciar();
    std::cout << "Después de reiniciar: " << c1.obtenerValor() << "\n";

    return 0;
}