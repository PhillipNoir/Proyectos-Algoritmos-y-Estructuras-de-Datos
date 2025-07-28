#include<iostream>
void caudruplicar(int* ptr){
    *ptr *= 4;
} //Sin punteros tendríamos que retornar el valor

int main(){
    int x{10};
    int* p{&x}; //Puntero que apunta a la dirección de memoria en x
    std::cout<<"x: "<<x<<"\n"; //Imprime 10
    std::cout<<"&x: "<<&x<<"\n"; //Imprime la dirección de x en la memoria
    std::cout<<"p: "<<p<<"\n"; //Imprime la dirección de memoria a la que apunta p, en este caso, la direccion de x
    std::cout<<"*p: "<<*p<<"\n"; //Imprime el valor dentro de la dirección a la que apunta, en este caso 10
    *p = 25; //Cambia el valor de x usando el puntero
    std::cout<<"x: "<<x<<"\n"; //Imprime el nuevo valor de x
    std::cout<<"*p: "<<*p<<"\n"; //Imprime el nuevo valor de x mediante el puntero
    /* nullptr sirve para inicializar punteros seguros que no usaremos aun, de esta forma evitamos errores de acceso a memoria aleatoria */
    int* ptr{nullptr}; //Este puntero no apunta a nada
    if (p==nullptr)
    {
        std::cout<<"El puntero ptr no apunta a nada"<<"\n";
    }
    int n{5}    ;
    caudruplicar(&n);
    std::cout<<"n: "<<n<<"\n"; //Imprime 20
    
    //Esto crea un int dinámico, que se almacena en el heap, el heap es una región de memoria que se utiliza para almacenar datos dinámicos, como objetos y arreglos, que pueden crecer o decrecer en tamaño durante la ejecución del programa.
    //ptr es un puntero que apunta a la dirección de memoria donde se almacena el entero dinámico.
    int* ptr = new int(99); // crea una variable dinámica
    std::cout << "Valor de ptr: " << *ptr << "\n"; // Imprime 99
    delete ptr; // libera la memoria dinámica
    return 0;

}