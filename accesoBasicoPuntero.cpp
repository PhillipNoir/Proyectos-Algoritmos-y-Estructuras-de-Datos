#include<iostream>
 int main(){
    int x{10}; //Se declara una variable inicializada en 10
    int* p{&x}; //Se declara un puntero que apunta a la dirección de x
    std::cout<<"El valor de x es: "<<*p<<"\n"; //Se imprime el valor de la dirección a la que apunta el puntero
    *p=20; //Se modifica el valor de la dirección a la que apunta el puntero
    std::cout<<"El valor de x ahora es: "<<x<<"\n"; //Se imprime el nuevo valor desde la variable
    return 0;
 }