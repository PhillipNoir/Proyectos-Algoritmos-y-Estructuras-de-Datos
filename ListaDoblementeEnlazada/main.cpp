#include "listaDoble.hpp"
#include <string>

int main() {
    // Crear una lista doblemente enlazada de enteros
    ListaDoble<int> listaEnteros;

    // Insertar algunos valores al final de la lista
    listaEnteros.insertarAlFinal(10);
    listaEnteros.insertarAlFinal(20);
    listaEnteros.insertarAlFinal(30);

    // Mostrar los elementos de la lista hacia adelante
    std::cout << "Elementos de la lista (adelante): ";
    listaEnteros.mostrarAdelante();

    // Mostrar los elementos de la lista hacia atrás
    std::cout << "Elementos de la lista (atrás): ";
    listaEnteros.mostrarAtras();

    // Insertar un valor al inicio de la lista
    listaEnteros.insertarAlInicio(5);
    std::cout << "Después de insertar 5 al inicio:" << std::endl;
    listaEnteros.mostrarAdelante();
    listaEnteros.mostrarAtras();
    

    // Eliminar un nodo especificado por su posición
    listaEnteros.eliminarEnPosicion(3);
    std::cout << "Después de eliminar el nodo en la posición 3:" << std::endl;
    listaEnteros.mostrarAdelante();
    listaEnteros.mostrarAtras();

    // Insertar un nuevo nodo después de un nodo con un valor específico
    listaEnteros.insertarEnPosicion(2, 25);
    std::cout << "Después de insertar 25 después del nodo con posicion 1:" << std::endl;
    listaEnteros.mostrarAdelante();
    listaEnteros.mostrarAtras();

    // Buscar un valor en la lista
    listaEnteros.buscar(20);

    return 0;
}