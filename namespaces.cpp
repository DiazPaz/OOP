#include <iostream>

int valor = 10; 

namespace Ejemplo
{
    int valor = 99; 
    void muestra();
}

void Ejemplo::muestra()
{
    std::cout << valor << std::endl; 
}

void muestra(){
    std::cout << valor << std::endl; 
}

int main(void)
{

    std::cout << "Valor global: "; muestra(); 
    std::cout << "Valor namespace: "; Ejemplo::muestra();

    getchar();
    return 0; 

}