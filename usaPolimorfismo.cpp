#include <iostream>
#include <string>
using namespace std; 

#include "Estudiante.h"
#include "Maestro.h"

int main(void)
{
    Persona rosa("Rosa", "123"), pedro("Pedro", "456");
    Estudiante juan("Juan", "25", "IRSI"), laura("Laura", "20", "ITC");
    Maestro luis("Luis", "35", "Matematicas"), karla("Karla", "30", "Fisica");
    Persona *arrPer[6];

    arrPer[0] = &rosa; 
    arrPer[1] = &juan; 
    arrPer[2] = &luis; 
    arrPer[3] = &pedro; 
    arrPer[4] = &laura; 
    arrPer[5] = &karla; 
    
    for(int i = 0; i < 6; i++)
    {
        cout << "\n#" << i+1 << " ";
        arrPer[i]->muestra();
        cout << endl; 
    }

    return 0; 
}