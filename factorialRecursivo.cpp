#include <iostream>
unsigned long long factorial (unsigned int n){
    if (n==0)
    {
        return 1; // Caso base
    }
    else{
        return n * factorial(n - 1); // Caso recursivo
    }
    
}
int main() {
    unsigned int numero;

    std::cout << "Introduce un número para calcular su factorial: ";
    std::cin >> numero;

    std::cout << "El factorial de " << numero << " es: " << factorial(numero) << "\n";

    return 0;
}