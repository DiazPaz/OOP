#include <iostream>
#include <math.h>
#include <cmath>

using namespace std; 

string funcion(string);

int main(void){
    int cont; 
    string frase = "Examen de programacion orientada a objetos"; 
    cout << funcion(frase);
    /* do{
        double medido, aceptado, res = 0; 
        cout << "Medido: "; cin >> medido; 
        cout << "Real: "; cin >> aceptado; 
        res = abs((medido-aceptado)/aceptado) * 100; 
        cout << res << "\n"; 
        cin >> cont;
    }while(cont != 1); */
}

string funcion(string sFrase){
    int x = sFrase.find(' ');
    int y = sFrase.rfind(' ');
    return (sFrase.substr(0, x) + sFrase.substr(y, sFrase.length()-y));
}