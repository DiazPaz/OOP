#include <iostream>
#include <string> 

using namespace std; 
#include "Triangulo.h"
#include "Cuadrado.h"

int main(void)
{

    Figura *arr[5];
    arr[0] = new Triangulo();
    arr[1] = new Cuadrado();
    arr[2] = new Triangulo();
    arr[3] = new Cuadrado();
    arr[4] = new Triangulo();

    for(auto &i: arr)
        i->dibuja(); 

    for(auto &i: arr)
        delete[] i;

    return 0; 
}