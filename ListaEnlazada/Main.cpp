/**
 * @file Main.cpp
 * @brief Programa principal que utiliza la clase Lista.
 * Este programa crea una lista enlazada, inserta elementos, los busca, los elimina y muestra la lista en diferentes estados.
 * Utiliza la clase Lista definida en Lista.hpp y la clase Nodo definida en Nodo.hpp.
 */
#include<iostream>
#include "Nodo.hpp"
#include "Lista.hpp"

int main() {
    Lista<int> lista;

    // Insertar elementos al inicio
    lista.insertarAlInicio(10);
    lista.insertarAlInicio(20);
    lista.insertarAlInicio(30);

    // Imprimir la lista
    std::cout << "Lista después de insertar al inicio: ";
    lista.imprimir();

    // Insertar elementos al final
    lista.insertarAlFinal(40);
    lista.insertarAlFinal(50);

    // Imprimir la lista
    std::cout << "Lista después de insertar al final: ";
    lista.imprimir();

    // Buscar un elemento
    lista.buscar(20);
    lista.buscar(60);

    // Añadir en una posición específica
    lista.anadirEnPosicion(25, 1);
    std::cout << "Lista después de añadir 25 en la posición 1: ";
    lista.imprimir();

    // Eliminar un elemento
    lista.eliminar(2);
    std::cout << "Lista después de eliminar el elemento en la posición 2: ";
    lista.imprimir();

    // Invertir la lista
    lista.invertir();

    // Imprimir la lista invertida
    std::cout << "Lista después de invertir: ";
    lista.imprimir();

    //Obtener el tamaño de la lista
    std::cout << "Tamaño de la lista: " << lista.obtenerTamano() << std::endl;

    // Limpiar la lista
    lista.limpiar();

    // Imprimir la lista después de limpiar
    std::cout << "Lista después de limpiar: ";
    lista.imprimir();

    return 0;
}