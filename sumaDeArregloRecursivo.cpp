#include <iostream>
#include <memory>
int long long suma(const std::unique_ptr<int[]>& arreglo, int indice, int n){
    if (indice==n)
    {
        return 0;
    }
    else
    {
        return arreglo[indice] + suma(arreglo, indice + 1, n);
    }
    
}

int main(){
    int tamanio{0};
    std::cout<<"Ingrese el tamaño del arreglo: \n";
    std::cin>>tamanio;
    std::unique_ptr<int[]> arreglo = std::make_unique<int[]>(tamanio);
    std::cout << "Ingrese " << tamanio << " valores enteros:\n";
    for (int i = 0; i < tamanio; ++i) {
        std::cout << "Elemento [" << i << "]: ";
        std::cin >> arreglo[i];
    }
    std::cout<<"La sumatoria es: "<<suma(arreglo, 0, tamanio);
}