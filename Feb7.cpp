#include <iostream>

using namespace std; 

#include "Complejo.h"

int main(void){

    Complejo c1;
    double r, i;
    cout<<"El numero complejo 1 con valores default: "<<endl;
    c1.muestra();
    cout<<"Teclea el valor para la parte real ";
    cin>>r;
    cout<<"Teclea el valor para la parte imaginaria ";
    cin>>i;
    Complejo c2(r,i);
    cout<<"El numero complejo 2 con valores tecleados por el usuario: "<<endl;
    c2.muestra();
    Complejo c3(5, 3);
    cout<<"El numero complejo 3 con valores fijos: "<<endl;
    c3.muestra();
    c1 = c2 + c3;
    cout<<"La suma de los numeros complejos 2 y 3 es: "<<endl;
    c1.muestra();
    c1 = c2 * c3;
    cout<<"El producto de los numeros complejos 2 y 3 es: ";
    cout<<"("<<c1.getReal()<<", "<<c1.getImaginario()<<")"<<endl;
    if (c2 == c3)
    cout<<"Los numeros c2 y c3 son iguales "<<endl;
    else
    cout<<"Los numeros c2 y c3 no son iguales "<<endl; 

    return 0; 
}