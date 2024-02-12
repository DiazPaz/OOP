#include <iostream>
#include <string>

using namespace std;

#include "CtaBanc.h"

int main(void){

    string nombre; 
    double saldo; 

    int numCtas; 
    cout << "Dime cuantas cuentas quieres: "; cin >> numCtas; 
    
    CtaBanc arrCuentas[numCtas];

    for(int i = 0; i < numCtas; i++){
        arrCuentas[i].setNumCta(i);
        cin.ignore();
        cout << "Dime el nombre de la cuenta " << i+1 << ": ";
        // cin.ignore();
        getline(cin, nombre);
        arrCuentas[i].setNombre(nombre);
        cout << "Dame el saldo de la cuenta " << i+1 << ": ";
        cin >> saldo; 
        arrCuentas[i].setSaldo(saldo);
    }

    int salir, cta = 0; 
    do{
        cout << "1) Selecciona cuenta \n";
        cout << "2) Deposita \n";
        cout << "3) Retira \n";
        cout << "4) Consulta saldo \n";
        cout << "5) Terminar \n";
        cin >> salir; 
        switch(salir){
            case 1: 
                do{
                    cout << "Dame la cuenta: "; 
                    cin >> cta; 
                    if(cta<0 || cta>=numCtas){
                        cout << "Cuenta no encontrada.\n";
                    }
                }while(cta<0 || cta>=numCtas);
                cout << "La cuenta " << cta << " pertenece a " << arrCuentas[cta].getNombre() << endl;
                break; 
            case 2: 
                cout << "Cantidad a depositar: ";
                cin >> saldo; 
                arrCuentas[cta].deposita(saldo);
                break;
            case 3: 
                cout << "Cantidad a retirar: ";
                cin >> saldo; 
                if(arrCuentas[cta].retira(saldo)){
                    cout << "Retiro con exito\n";
                } else{
                    cout << "Retiro no creado\n";
                }
            case 4: 
                cout << "El saldo de la cuenta " << cta << " es " << arrCuentas[cta].getSaldo() << endl;
                break; 
            case 5: 
                break; 
            default: 
                cout << "Opción no disponible." << "\n";
                break;
        }
    }while(salir != 5);

    return 0; 
}