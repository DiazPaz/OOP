#include <iostream>
#include <string>
using namespace std;
#include "Persona.h"


int main(void){
    Persona p1; 
    cout << "Despues de la persona 1: " << p1.getContadorPersonas() << endl; 
    Persona p2("Maria", "123456"); 
    cout << "Despues de la persona 2: " << p2.getContadorPersonas() << endl; 
    Persona arr[5]; 
    cout << "Despues del arreglo: " << arr[5].getContadorPersonas() << endl; 
    getchar();
    return 0;
}