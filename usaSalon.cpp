#include <iostream>
#include <string>

using namespace std; 

#include "Salon.h"


// Escribe ahora un programa que pregunte al usuario cuántos salones hay y luego que pida al usuario los datos de los salones. Supón que cuando mucho habrá 10 salones.

// Al pedir los datos debe pedir el número de salón y los datos (marca, sistema operativo y ram) de la computadora del salón.

// Después has un menú que permita buscar salones con las siguientes opciones:

// Buscar por marca - que muestre en la pantalla los números de los salones que tienen computadora de la marca dada
// Buscar por Sistema Operativo - que muestre en la pantalla los números de los salones que tienen computadora con ese sistema operativo
// Mostrar todos los salones - que muestre el número de salón, y la marca, sistema operativo y RAM de la computadora de ese salón.
// Terminar
 

// NOTA: Esta tarea es del tema Composición, se calificará que se resuelva el ejercicio de la manera que se describe.

int main(void){

    int opcion, n;

    do{
        cout << "\nDime el numero de salones: "; cin >> n;
        if(n<1 || n>10)
            cout << "El numero tiene que ser menor o igual que 10.\n";
    }while(n<1 || n>10);
    cout << "\n==========\n"; 

    Salon arrSalon[n];

    cout << "Registre los datos de los " << n << " salones: \n\n";

    int numSalon; string ram, marca, so;  Computadora comp;
    for(int i = 0; i < n; i++){
        cout << "====================\n";
        cout << "Dame el numero del salon " << i +1 << ": "; cin >> numSalon; 
        arrSalon[i].setNumSalon(numSalon);
        cin.ignore();
        cout << "Dame el RAM de la computadora del salon: "; getline(cin, ram);
        cout << "Dame la marca de la computadora del salon: "; getline(cin, marca);
        cout << "Dame el sistema operativo de la computadora del salon: "; getline(cin, so);
        comp.setRam(ram); comp.setBrand(marca); comp.setOs(so);
        arrSalon[i].setComp(comp);
    }

    bool bandera; 
    do{

        cout << "\n\n====================\n";
        cout << "Como deseas buscar un salon? \n";
        cout << "1. Buscar por marca \n";
        cout << "2. Buscar por Sistema Operativo \n";
        cout << "3. Mostrar todos los salones \n";
        cout << "4. Terminar \n";

        cin >> opcion;
        cin.ignore();
        bandera = false;

        switch(opcion){
        case 1:
            cout << "\n====================\n";
            cout << "Dame la marca que deseas buscar: "; getline(cin, marca);
            for(int i = 0; i < n; i++){
                if(arrSalon[i].getComp().getBrand() == marca){
                    cout << "Salon: " << arrSalon[i].getNumSalon() << endl;
                    bandera = true; 
                } 
            } if (bandera == false) {
                cout << "No se encontraron salones que tengan computadoras de esa marca. \n";
            } 
            break;
        case 2:
            cout << "\n====================\n";
            cout << "Dame el sistema operativo que deseas buscar: "; getline(cin, so);
            for(int i = 0; i < n; i++){
                if(arrSalon[i].getComp().getOs() == so){
                    cout << "Salon: " << arrSalon[i].getNumSalon() << endl;
                    bandera = true; 
                } 
            } if (bandera == false) {
                cout << "No se encontraron salones que tengan computadoras con ese sistema operativo. \n";
            }
            break;
        case 3:
            int i = 1;
            for(Salon &salon: arrSalon){
                cout << "\n====================\n";
                cout << "Salon: " << salon.getNumSalon() << "\tRam: " << salon.getComp().getBrand() << "\tMarca: " << salon.getComp().getRam() << "\tSO: " << salon.getComp().getOs();
            }
            break; 
        }
        
    }while(opcion != 4); 

    return 0; 
}