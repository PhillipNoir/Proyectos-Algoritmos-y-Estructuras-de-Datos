/**
 * @file Vertice.hpp
 * @brief Declaracion de la clase Vertice
 * @details Esta clase representa un vertice en un grafo, con un valor y una lista de adyacentes.
 */
#ifndef VERTICE_HPP
#define VERTICE_HPP
#include <vector>

template<typename T>
class Vertice {
public:
    T valor;
    std::vector<Vertice<T>*> adyacentes;

    Vertice(T val) : valor(val) {}
};

#endif