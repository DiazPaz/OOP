#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Edificios.h"

int main(void){
    
    Salones salon[20]; Laboratorios laboratorio[20]; Computadora computadoras[30]; Edificio edificios[4];

    ifstream inEdificios;

    inEdificios.open("edificios.txt"); 

    string linea; int x = 0; 
    while(!inEdificios.eof()){

        getline(inEdificios, linea);

        edificios[x].setId(linea[0] - '0');

        int len = linea.length(), contLaboratorios = 0, contSalones = 0, contEspacios = 0;

        int listaLabs[10]; 

        for(int i = 2; i < len; i++){

            for(int j = i+1; j < len; j++){
                if(linea[j] == ' ')
                    contEspacios++; 
                if(contEspacios == 1 && linea[j] == ' '){

                    edificios[x].setName(linea.substr(i, j-1)); 
                    
                    contLaboratorios = linea[j+1]-'0'; int cont = 0;
                    int k = j+2, u = 0, aux = 1; 
                    bool bandera;

                    while(cont < contLaboratorios){

                        /* if(linea[k+1] == ' '){
                            if(u == 0){
                                if(edificios[x].agregarLab(linea[k]-'0'))
                                    laboratorio[(linea[k]-'0')-1].setIdLab(linea[k]-'0'); 
                                else
                                    cout << "Error, laboratorio " << linea[k] << " no anadido. " << endl;  
                            } else{
                                if(edificios[x].agregarLab(stoi(linea.substr(u+2,k-u-1))))
                                    laboratorio[stoi(linea.substr(u+2,k-u-1))-1].setIdLab(stoi(linea.substr(u+2,k-u-1)));
                                else 
                                    cout << "Error, laboratorio " << linea.substr(u+2,k-u-1) << " no anadido. " << endl; 
                            }
                            u = k;
                            cont++;
                        } 
                        k++; */



                        bandera = false; aux = 0; 

                        while(!isspace(linea[k])){
                            bandera = true; 
                            aux++;
                            k++;
                        } 

                        if(edificios[x].agregarLab(stoi(linea.substr(k-aux, aux)))){
                            laboratorio[stoi(linea.substr(k-aux, aux))].setIdLab(stoi(linea.substr(k-aux, aux))); 
                        }

                        if(bandera){
                            cont++; 
                        }
                        
                        k++; 

                    } 

                    contSalones = linea[k+1]-'0'; cont = 0; 
                    int m = k+3; 

                    while(cont < contSalones){

                        bandera = false; aux = 0; 

                        while(!isspace(linea[m])){
                            bandera = true; 
                            aux++;
                            m++;
                        } 
                        
                        if(edificios[x].agregarSal(stoi(linea.substr(m-aux, aux)))){
                            salon[stoi(linea.substr(m-aux, aux))].setIdSal(stoi(linea.substr(m-aux, aux))); 
                        }

                        if(bandera){
                            cont++; 
                        }
                        
                        m++; 

                    } 

                }   
            }
        }
        x++;
    } 

/*     for(Edificio c: edificios){
        c.muestraLabEdificio();
        cout << endl;  
    }

*/
    cout << endl; 

    for(auto labs: laboratorio){
        labs.muestraLab();
        cout << endl; 
    } 

    cout << endl; 

    for(auto sals: salon){
        sals.muestraSal();
        cout << endl; 
    }

    /* salon[0].setIdSal(1); salon[0].setNameSal("uno"); salon[0].setCapacidadSal(20); salon[1].setCompSal(c);

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
    cout << endl; */  

    inEdificios.close();

    // cin.get();
    return 0; 
}