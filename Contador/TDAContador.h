// Contador.h
#pragma once
#include <iostream>

class Contador {
private:
    int valor; // Estado interno del contador: solo accesible desde dentro

protected:
    int maximo = 1000; // Solo accesible desde clases derivadas

public:
    // Constructor con valor inicial personalizado
    Contador(int inicial = 0) : valor(inicial) {}

    // Incrementa el contador en 1
    void incrementar() {
        if (valor < maximo) {
            valor++;
        } else {
            std::cout << "Ya alcanzaste el valor máximo.\n";
        }
    }

    // Decrementa el contador en 1
    void decrementar() {
        if (valor > 0) {
            valor--;
        } else {
            std::cout << "Ya alcanzaste el valor mínimo (0).\n";
        }
    }

    // Obtiene el valor actual (sin permitir modificarlo desde fuera)
    int obtenerValor() const {
        return valor;
    }

    // Reinicia el contador a 0
    void reiniciar() {
        valor = 0;
    }
};