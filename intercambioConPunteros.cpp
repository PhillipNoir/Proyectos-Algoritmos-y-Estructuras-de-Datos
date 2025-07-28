//Escribe una función void intercambiar(int* a, int* b) que reciba dos enteros por puntero e intercambie sus valores.
//En el main, prueba con dos variables x = 5 y y = 9 e imprime el resultado antes y después.
#include <iostream>
//Función que intercambia los valores de  x con y
void intercambiar(int* a, int* b){ //a y b apuntan a la dirección introducida como argumento en la en la función, no al valor del argumento en sí
    int temp = *a; //Variable que almacena temporalmente el valor que contiene la dirección de memoria a la que apunta a
    *a = *b; //Ahora la dirección a la que apunta a se va a modificar por el valor de la dirección a la que apunta b
    *b = temp; //Ahora el valor del puntero b es igual al valor de la variable temporal
}

int main(){
    int x{5};
    int y{9};
    std::cout<<"El valor de x es "<<x<<"\n";
    std::cout<<"El valor de y es "<<y<<"\n";
    intercambiar(&x, &y); //Se da la dirección de las variables, no los valores
    std::cout << "Después del intercambio:\n";
    std::cout << "x = " << x << "\n";
    std::cout << "y = " << y << "\n";
    return 0;
}