#include <iostream> 
#include <string> 
#include <fstream>

using namespace std; 

#include "Empleado.h"

bool validaEmpleado(Empleado arrE[], int id, int &pos){
    bool validado = false; 
    int i = 0; 
    while(validado == false && i < 5){
        if(arrE[i].getId() == id){
            validado = true; 
            pos = i; 
        } else {
            i++; 
        }
    } return validado; 
}

int main(void){

    ifstream fIn("datosEntrada.txt");
    Empleado emp[5];

    int i = 0; 
    int id;     
    double sueldoFijo; 
    double sueldoHora; 
    int horas; 
    int cont; 
    int pos; 

    while(fIn >> id >>sueldoFijo >> sueldoHora >> horas){
        emp[i].setId(id);
        emp[i].setSueldoFijo(sueldoFijo);
        emp[i].setSueldoHora(sueldoHora);
        emp[i].setHoras(horas);
        i++;
    }

    do{

        cout << "1. Modificar sueldo fijo\n";
        cout << "2. Modificar sueldo por horas\n";
        cout << "3. Registrar horas trabajadas\n";
        cout << "4. Calcular el sueldo\n";
        cout << "5. Ver empleados\n";
        cout << "6. Salir\n";
        cin >> cont; 

        switch(cont){
            
            case 1: 
                do{
                    cout << "Dame el ID del empleado: "; cin >> id; 
                }while(!validaEmpleado(emp, id, pos));

                do{
                    cout << "Dame el sueldo fijo nuevo: "; cin >> sueldoFijo;
                    if(sueldoFijo > 0){
                        emp[pos].setSueldoFijo(sueldoFijo);
                        cout << "\n\n" << pos << "\n\n";
                    } else {
                        cout << "Sueldo tiene que ser mayor a 0. \n";
                    }
                }while(sueldoFijo < 0);
                break; 

            case 2:
                do{
                    cout << "Dame el ID del empleado: "; cin >> id; 
                }while(!validaEmpleado(emp, id, pos));

                do{
                    cout << "Dame el sueldo por horas nuevo: "; cin >> sueldoHora;
                    if(sueldoHora > 0){
                        emp[pos].setSueldoHora(sueldoHora);
                        cout << "\n\n" << pos << "\n\n"; 
                    } else {
                        cout << "Sueldo tiene que ser mayor a 0. \n";
                    }
                }while(sueldoHora < 0); 
                break; 

            case 3: 
                do{
                    cout << "Dame el ID del empleado: "; cin >> id; 
                }while(!validaEmpleado(emp, id, pos));

                do{
                    cout << "Dame las horas: "; cin >> horas;
                    if(horas > 0){
                        emp[pos].setHoras(horas);
                        cout << "\n\n" << pos << "\n\n";
                    } else {
                        cout << "Introduzca una cantidad de horas valida. \n";
                    }
                }while(horas < 0);
                break; 

            case 4: 
                do{
                    cout << "Dame el ID del empleado: "; cin >> id; 
                }while(!validaEmpleado(emp, id, pos));

                cout << "El sueldo es: " << emp[pos].calculaPago() << endl;
                cout << "\n\n" << pos << "\n\n";
                break; 
                
            case 5:
                for(int j = 0; j < 5; j++){
                    cout << emp[j].getId() << " " << emp[j].getSueldoFijo() << " " << emp[j].getSueldoHora() << " " << emp[j].getHoras() << "\n";
                }
                break; 

            default: 
                if(cont < 0 || cont > 6)
                    cout << "Opcion no disponible\n";
                break; 
        }

    }while(cont != 6);

    fIn.close();

    return 0; 
}