#include <iostream>
#include <string>
using namespace std;
#include "FraccionS.h"

template<typename T>
T suma(T v1, T v2, T v3)
{
    return v1 + v2 + v3; 
}


int main(void)
{
    double d1 = 1.2, d2 = 2.2, d3 = 3.3, d4; 
    int e1 = 1.2, e2 = 2.2, e3 = 3.3, e4;
    string s1 = "Hola ", s2 = "lola ", s3 = "!!!\n", s4;  
    Fraccion f1(1,2), f2(3,4), f3(2,5), f4; 

    d4 = suma(d1,d2,d3);
    e4 = suma(e1,e2,e3);
    s4 = suma(s1,s2,s3);
    f4 = suma(f1,f2,f3);

    cout << "La suma de doubles es: " << d4 << endl; 
    cout << "La suma de enteros es: " << e4 << endl; 
    cout << "La suma de strings es: " << s4 << endl; 
    f4.muestra();

    return 0; 
}