#include <iostream>
using namespace std; 

#include "Perro.h"
#include "Gato.h"

int main(void)
{

    Animal *arr[4];
    arr[0] = new Perro("Luna", 2018);
    arr[1] = new Gato("Ito", 2014);
    arr[2] = new Perro("Troy", 2020);
    arr[3] = new Gato("Nina", 2014);

    for(Animal i: arr){
        i->muestra(); 
        i->habla();
    }

    return 0; 
}