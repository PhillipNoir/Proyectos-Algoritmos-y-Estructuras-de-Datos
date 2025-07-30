/**
 * @file main.cpp
 * @brief Programa principal para probar la clase Grafo
 * @details Este archivo contiene el punto de entrada del programa y ejemplos de uso de la clase Grafo.
 */
#include "Grafo.hpp"
#include <iostream>

int main() {
    Grafo<int> grafo;

    // Agregar vértices
    grafo.agregarVertice(1);
    grafo.agregarVertice(2);
    grafo.agregarVertice(3);
    grafo.agregarVertice(4);

    // Agregar aristas
    grafo.agregarArista(1, 2);
    grafo.agregarArista(1, 3);
    grafo.agregarArista(2, 4);
    grafo.agregarArista(3, 4);

    // Mostrar el grafo
    std::cout << "Grafo:\n";
    grafo.mostrar();

    // Eliminar una arista
    grafo.eliminarArista(1, 2);
    std::cout << "Después de eliminar la arista entre 1 y 2:\n";
    grafo.mostrar();

    // Eliminar un vértice
    grafo.eliminarVertice(3);
    std::cout << "Después de eliminar el vértice 3:\n";
    grafo.mostrar();

    // Buscar un vértice
    Vertice<int>* vertice = grafo.encontrarVertice(4);
    if (vertice) {
        std::cout << "Vértice encontrado: " << vertice->valor << "\n";
    } else {
        std::cout << "Vértice no encontrado.\n";
    }


    // Realizar BFS desde el vértice 1
    std::cout << "BFS desde el vértice 1: ";
    grafo.BFS(1);

    // Realizar DFS desde el vértice 1
    std::cout << "DFS desde el vértice 1: ";
    grafo.DFS(1);

    return 0;
}