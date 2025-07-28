#include <iostream>
using namespace std;

int main() {
    int n;

    // Paso 1: Pedir al usuario cuántos elementos desea
    cout << "¿Cuántos elementos deseas guardar?: ";
    cin >> n;

    // Paso 2: Crear arreglo dinámico
    int* arreglo = new int[n]; //Un arreglo normal debe conocerse antes de la ejecución para funcionar correctamente, este permite hacerlo en la ejecución

    // Paso 3: Llenar el arreglo
    cout << "Ingresa " << n << " números:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    // Paso 4: Imprimir los valores
    cout << "Los valores ingresados son:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    // Paso 5: Liberar la memoria
    delete[] arreglo; //Siempre al terminar de usarlo para evitar fugas de memoria

    return 0;
}
