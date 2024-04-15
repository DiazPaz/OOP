#include <iostream>
using namespace std; 

int main(void){

    char unit[3] = {'i', 'j', 'k'};
    double vR[3], vF[3], res[3] = {0,0,0}; 
    int cantProductos; 
    cout << "Num de productos cruz que sumar: "; cin >> cantProductos;

    for(int i = 0; i < cantProductos; i++){

        cout << "Vector posicion " << i+1 << ": \n"; 
        for(int i = 0; i < 3; i++)
            cin >> vR[i];  
        cout << "Vector fuerza " << i+1 << ": \n"; 
        for(int i = 0; i < 3; i++)
            cin >> vF[i];  

        // i
        res[0] += (vR[1] * vF[2]) - (vR[2] * vF[1]);

        // j 
        res[1] += (vR[2] * vF[0]) - (vR[0] * vF[2]);

        // k 
        res[2] += (vR[0] * vF[1]) - (vR[1] * vF[0]);

    }

    cout << endl; 
    for(int i = 0; i < 3; i++){
        if(i < 2)
            cout << res[i] << unit[i] << " + "; 
        else
            cout << res[i] << unit[i] << endl;
    }

    system("pause");

    return 0;
}