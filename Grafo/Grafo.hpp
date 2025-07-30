/**
 * @file Grafo.hpp
 * @brief Declaracion de la clase Grafo
 * @details Esta clase representa un grafo no dirigido, que contiene una lista de vertices.
 * Esta clase es un contenedor para los vertices y permite operaciones sobre el grafo.
 */
#ifndef GRAFO_HPP
#define GRAFO_HPP
#include <vector>
#include "Vertice.hpp"
#include <iostream>
#include <queue>
#include <unordered_set>
#include <memory>
#include <algorithm>
template<typename T>
class Grafo {
private:

    // Vector de punteros inteligentes a Vertice, para manejar la memoria automáticamente
    std::vector<std::unique_ptr<Vertice<T>>> vertices;

public:
    /**
     * @brief Agrega un vertice al grafo
     * @param valor El valor del vertice a agregar
     * Agrega a la lista la dirección de memoria del nuevo vertice que almacena un valor y una lista de adyacentes.
     */
    void agregarVertice(T valor) {
        vertices.push_back(std::make_unique<Vertice<T>>(valor));
    }

    /**
     * @brief Encuentra un vertice por su valor
     * @param valor El valor del vertice a buscar
     * @return Puntero al vertice encontrado, o nullptr si no se encuentra
     */
    Vertice<T>* encontrarVertice(T valor) {
        for (const auto& v : vertices) {
            if (v->valor == valor)
                return v.get();
        }
        return nullptr;
    }

    /**
     * @brief Agrega una arista entre dos vertices
     * @param origen El valor del vertice de origen
     * @param destino El valor del vertice de destino
     * Agrega una arista entre los vertices de origen y destino, si ambos existen.
     */
    void agregarArista(T origen, T destino) {
        Vertice<T>* vOrigen = encontrarVertice(origen);
        Vertice<T>* vDestino = encontrarVertice(destino);

        if (vOrigen && vDestino) {
            vOrigen->adyacentes.push_back(vDestino);
            vDestino->adyacentes.push_back(vOrigen); // porque es no dirigido
        }
    }

    /**
     * @brief Muestra los vertices y sus adyacentes
     * Imprime en consola los valores de los vertices y sus adyacentes.
     */
    void mostrar() {
        for (const auto& v : vertices) {
            std::cout << v->valor << ": ";
            for (const auto& vecino : v->adyacentes)
                std::cout << vecino->valor << " ";
            std::cout << "\n";
        }
    }

    /**
     * @brief Elimina una arista entre dos vertices
     * @param origen El valor del vertice de origen
     * @param destino El valor del vertice de destino
     * Elimina la arista entre los vertices de origen y destino, si ambos existen.
     */
    void eliminarArista(T origen, T destino) {
        Vertice<T>* vOrigen = encontrarVertice(origen);
        Vertice<T>* vDestino = encontrarVertice(destino);

        if (vOrigen && vDestino) {
            auto& adyacentesOrigen = vOrigen->adyacentes;
            adyacentesOrigen.erase(std::remove(adyacentesOrigen.begin(), adyacentesOrigen.end(), vDestino), adyacentesOrigen.end());
        }
    }

    /**
     * @brief Elimina un vertice del grafo
     * @param valor El valor del vertice a eliminar
     * Elimina el vertice y todas sus aristas asociadas del grafo.
     * Si el vertice existe, se eliminan todas las aristas que apuntan a él y luego se elimina el vertice de la lista.
     * Si el vertice no existe, no hace nada.
     */
    void eliminarVertice(T valor) {
        // Buscar el vértice a eliminar
        typename std::vector<std::unique_ptr<Vertice<T>>>::iterator it = vertices.begin();
        Vertice<T>* verticeAEliminar = nullptr;

        while (it != vertices.end()) {
            if ((*it)->valor == valor) {
                verticeAEliminar = it->get();
                break;
            }
            ++it;
        }

        // Si no lo encontramos, no hacemos nada
        if (verticeAEliminar == nullptr) return;

        // Eliminar aristas que apuntan al vértice que vamos a borrar
        for (auto& v : vertices) {
            auto& ady = v->adyacentes;
            for (auto aIt = ady.begin(); aIt != ady.end();) {
                if (*aIt == verticeAEliminar) {
                    aIt = ady.erase(aIt);  // Borra la arista
                } else {
                    ++aIt;
                }
            }
        }

        // Finalmente eliminamos el vértice del vector
        vertices.erase(it);
    }

    /**
     * @brief Realiza una búsqueda en anchura (BFS) desde un vértice dado
     * @param inicio El valor del vértice desde el cual iniciar la búsqueda
     * Realiza una búsqueda en anchura e imprime los valores de los vértices visitados.
     */
    void BFS(T inicio) {
        Vertice<T>* verticeInicio = encontrarVertice(inicio);
        if (!verticeInicio) {
            std::cout << "Vértice no encontrado.\n";
            return;
        }

        std::queue<Vertice<T>*> cola;
        std::unordered_set<Vertice<T>*> visitados;

        cola.push(verticeInicio);
        visitados.insert(verticeInicio);

        while (!cola.empty()) {
            Vertice<T>* actual = cola.front();
            cola.pop();
            std::cout << actual->valor << " ";

            for (Vertice<T>* vecino : actual->adyacentes) {
                if (visitados.find(vecino) == visitados.end()) {
                    cola.push(vecino);
                    visitados.insert(vecino);
                }
            }
        }
        std::cout << "\n";
    }

    void DFS(T inicio) {
        Vertice<T>* verticeInicio = encontrarVertice(inicio);
        if (!verticeInicio) {
            std::cout << "Vértice no encontrado.\n";
            return;
        }

        std::unordered_set<Vertice<T>*> visitados;
        DFSRecursivo(verticeInicio, visitados);
        std::cout << "\n";
    }

    void DFSRecursivo(Vertice<T>* actual, std::unordered_set<Vertice<T>*>& visitados) {
        if (!actual || visitados.count(actual)) return;

        std::cout << actual->valor << " ";
        visitados.insert(actual);

        for (Vertice<T>* vecino : actual->adyacentes) {
            DFSRecursivo(vecino, visitados);
        }
    }
    
};

#endif