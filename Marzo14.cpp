#include <iostream>

using namespace std; 

int main(void){

    int inMin, minutos = 55, horas = 23; 

    cin >> inMin; 

    horas = (((horas * 60) + minutos + inMin) / 60) % 24; 
    minutos = ((horas * 60) + minutos + inMin) % 60; 
    
    cout << horas << ":" << minutos << endl;
 
/*     if(!((inMin + minutos) > 59))
        minutos += inMin;
    else {
        minutos = (minutos + (inMin%60)) - 60; 
        horas = (inMin / 60) % 24;
    }
    cout << horas << ":" << minutos; 

    if (inMin > 0) {
        minutos += inMin;
        if (minutos >= 60) {
            horas += minutos / 60;
            minutos %= 60;
        }
        horas %= 24;
    }
    cout << horas << ":" << minutos;  */

    cin.get();

    return 0; 
}