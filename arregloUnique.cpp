#include <iostream>
#include <memory> // Para std::unique_ptr y std::make_unique

int main() {
    int tamaño;

    std::cout << "Ingrese el tamaño del arreglo: ";
    std::cin >> tamaño;

    // Crear arreglo dinámico de enteros con unique_ptr
    std::unique_ptr<int[]> arreglo = std::make_unique<int[]>(tamaño);

    // Llenar el arreglo con datos
    std::cout << "Ingrese " << tamaño << " valores enteros:\n";
    for (int i = 0; i < tamaño; ++i) {
        std::cout << "Elemento [" << i << "]: ";
        std::cin >> arreglo[i];
    }

    // Mostrar los datos ingresados
    std::cout << "\nContenido del arreglo:\n";
    for (int i = 0; i < tamaño; ++i) {
        std::cout << "arreglo[" << i << "] = " << arreglo[i] << "\n";
    }

    // No necesitas liberar nada: unique_ptr lo hace automáticamente
    return 0;
}