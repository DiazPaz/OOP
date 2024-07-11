#include <iostream>
#include <string>
using namespace std; 

#include "Estudiante.h"

int main(void){

    Persona p1("Juan", "123456789");
    Estudiante e1("Pedro", "987654321", "IRSI");
    cout << "Persona 1: \n";
    p1.muestra();
    cout << "Estudiante 1: \n";
    e1.muestra();

    return 0;
}