#include <iostream>

using namespace std; 

#include <string> 
#include "Taxi.h"

bool found (Taxi arr[], int size, string name, int &i){
    bool find =  false; 
    i = 0;
    while(i<size && !find){
        if(arr[i].getResponsable().getNombre() == name){
            find = true; 
        }
        i++; 
    }
    return find; 
}

int main(void){

    Taxi arrTaxi[20];

    int cont = 0, ident, opcion2, i; 
    char opcion = 's';
    string nombre, cel; 

    while(opcion == 's'){
        cout << "Dame el nombre del responsable del taxi " << cont + 1 << ": "; getline(cin, nombre);
        cout << "Dame el celular: "; cin >> cel; 

        Persona p(nombre, cel);
        
        cout << "Dame el numero identificador del taxi: "; cin >> ident; 

        arrTaxi[cont] = Taxi(p, ident);

        cont++; 

        cout << "Desea agregar otro taxi? (s/n) "; cin >> opcion; 

        cin.ignore();
    }

    do{

        cout << "Selecciona la opcion: \n";
        cout << "1. Ver lista de taxis \n";
        cout << "2. Ver taxi por responsable \n";
        cout << "3. Agregar taxi \n";
        cout << "4. Terminar \n";

        cin >> opcion2;
        cin.ignore();

        switch(opcion2){
        case 1:
            for(int i = 0; i < cont; i++){
                cout << "taxi: " << i + 1 << " identificador " << arrTaxi[i].getId() << endl; 
                cout << "responsable: " << arrTaxi[i].getResponsable().getNombre() << endl;
                cout << "celular del responsable: " << arrTaxi[i].getResponsable().getNumCel() << endl;
            }
            break;
        case 2:
            cout << "Dame el responsable: "; getline(cin, nombre); 
            if(found (arrTaxi, cont+1, nombre, i)){
                cout << "El identificador es " << arrTaxi[i-1].getId() << endl;
                cout << "El celular es: " << arrTaxi[i-1].getResponsable().getNumCel() << endl; 
            } else {
                cout << nombre << " no tiene taxis asignados. \n";
            }

            break;
        case 3:
            cin.ignore();
            cout << "Dame el nombre del responsable del taxi " << cont + 1 << ": "; getline(cin, nombre);
            cout << "Dame el celular: "; cin >> cel; 

            Persona p(nombre, cel);
            
            cout << "Dame el numero identificador del taxi: "; cin >> ident; 

            arrTaxi[cont] = Taxi(p, ident);

            cont++; 

            break;

        }

    }while(opcion2 != 4); 

    return 0; 
}