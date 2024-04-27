#include <iostream>
using namespace std; 

#include "Hora.h"

int main(void)
{

    Hora h1(10, 30), h2(10,40), h3, h4;

    h3 = h1 + 50; 
    cout << h3 << endl; 
    cout << "dame la hora cuatro (hh mm): \n";
    cin >> h4; 
    cout << h4; 
        
    return 0; 
}