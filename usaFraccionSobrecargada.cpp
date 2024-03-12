//
//  main.cpp
//  CascaronFraccion
//
//  Ejercicio sobrecarga //
//  *      MultiplicaciÃ³n de dos fracciones
//  > Compara si la primera fracciÃ³n es mayor que la segunda
//  ++  Suma el valor 1/1 a una fracciÃ³n y regresa la nueva fracciÃ³n
//  -   Operador unitario â€“ (negativo), regresa una fracciÃ³n que contiene la fracciÃ³n original con el numerador con el signo cambiado.
//  -   Operador resta
//  *   Operador * para multiplicar una fracciÃ³n por un valor entero y regresa la nueva fracciÃ³n.

#include <iostream>
using namespace std;

#include "FraccionS.h"

int main()
{

    Fraccion f1(1,3), f2(3,4), f3(1,5), f4, f5;

   
    // la suma de las fracciones 1/3 y 3/4
    cout << endl;
    cout << "La suma de las fracciones 1 y 2 " << endl;
    f4 = f1 + f2;
    f4.muestra();

    // el valor en decimal de la fracciÃ³n 1/3
    cout << endl;
    cout << "El valor decimal de la fraccion 1 "<< endl;
    cout << !f1;
   
    // la multiplicacion de las fracciones 1/3 y 3/4
    cout << endl;
    cout << "La multiplicacion de las fracciones 1 y 2 " << endl;
    f4 = f1 * f2;
    f4.muestra();

    // la comparación de las fracciones 1/3 y 3/4
    cout << endl;
    cout << "La comparacion de las fracciones 1 y 2 " << endl;
    if(f1 > f2)
        cout << "f1 es mayor\n";
    else 
        cout << "f2 es mayor\n";

    // incrementar en 1 la fraccione f4
    cout << endl;
    cout << "Incrementar la fraccion f4 en un entero " << endl;
    f5 = ++f4; 
    f5.muestra();

    // decrementar en 1 la fraccione f1
    cout << endl;
    cout << "Decrementar la fraccion f1 en un entero " << endl;
    f5 = --f1; 
    f5.muestra();

    // la resta de las fracciones f3 y f4
    cout << endl;
    cout << "La resta de las fracciones 3 y 4 " << endl;
    f5 = f3 - f4;
    f5.muestra();

    return 0;
}