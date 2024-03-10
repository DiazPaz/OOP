#include <iostream>
using namespace std;

#include "Edificios.h"

int main(void){
    
    Salones salon[20]; Laboratorios laboratorio[20]; Computadora c;
    salon[0].setIdSal(1); salon[0].setNameSal("uno"); salon[0].setCapacidadSal(20); salon[1].setCompSal(c);

    salon[0].muestraSal();

    int cantSal = 4, cantLabs = 6; 
    // En estos arreglos se almacenarán los IDs de los salones/laboratorios. 
    int arrSal[10] = {}, arrLabs[10] = {10};
    Edificio ed1(650794, "CUATRO", cantLabs, arrLabs, cantSal, arrSal, "David"), ed2;

    cout << ed1.getId() << endl;
    cout << ed1.getName() << endl;
    cout << ed1.getResponsable() << endl;
    cout << ed1.getCantLabs() << endl;
    cout << ed1.getCantSal() << endl << endl;

    for(int i = 0; i < 10; i++){
        cout << "Lab " << i << ": "; 
        cout << ed1.getArrLabs(i) << endl;  
    } cout << endl; 

    if(ed1.agregarLab(10))
        cout << "se repite Lab ID" << endl;
    else    
        cout << "No se repite Lab ID; ID anadido" << endl; 

    for(int i = 0; i < 10; i++)
        cout << ed1.getArrLabs(i) << " ";  
    cout << endl << endl;  

    for(int i = 0; i < 10; i++){
        cout << "Sal " << i << ": "; 
        cout << ed1.getArrSal(i) << endl; 
    } cout << endl; 

    if(ed1.agregarSal(9))
        cout << "se repite Sal ID" << endl;
    else
        cout << "No se repite Sal ID; ID anadido" << endl; 

    for(int i = 0; i < 10; i++)
        cout << ed1.getArrSal(i) << " "; 
    cout << endl;  

    cin.get();
    return 0; 
}