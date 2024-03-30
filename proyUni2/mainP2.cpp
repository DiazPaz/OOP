#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Edificios.h"


void asignarLaboratorios(int contador, int pos1, int &pos2, string lin, Edificio ed[], Laboratorios lab[], int contEdificios){
    bool bandera; 
    int aux; 
    int cont = 0; 
    pos2 = pos1+2; 

    while(cont < contador){

        bandera = false; aux = 0; 

        while(!isspace(lin[pos2])){
            bandera = true; 
            aux++;
            pos2++;
        } 
        
        if(!isspace(lin[pos2-aux])){
            if(ed[contEdificios].agregarLab(stoi(lin.substr(pos2-aux, aux)))){
                lab[stoi(lin.substr(pos2-aux, aux))-1].setIdLab(stoi(lin.substr(pos2-aux, aux))); 
            }
        }

        if(bandera){
            cont++; 
        }
        
        pos2++; 

    }
}
void asignarSalones(int contador, int pos1, int &pos2, string lin, Edificio ed[], Salones sal[], int contEdificios){
    bool bandera; 
    int aux; 
    int cont = 0; 
    pos2 = pos1+2; 

    while(cont < contador){

        bandera = false; aux = 0; 

        while(!isspace(lin[pos2])){
            bandera = true; 
            aux++;
            pos2++;
        } 
        
        if(!isspace(lin[pos2-aux])){
            if(ed[contEdificios].agregarSal(stoi(lin.substr(pos2-aux, aux)))){
                sal[stoi(lin.substr(pos2-aux, aux))-1].setIdSal(stoi(lin.substr(pos2-aux, aux))); 
            }
        }

        if(bandera){
            cont++; 
        }
        
        pos2++; 

    }
}



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
                    
                    contLaboratorios = linea[j+1]-'0';

/////////////////////////////////////////

                    int k = 0; 
                    asignarLaboratorios(contLaboratorios, j, k, linea, edificios, laboratorio, x);

/* 
                    int cont = 0;
                    int k = j+2, u = 0, aux; 
                    bool bandera;

                    while(cont < contLaboratorios){

                        bandera = false; aux = 0; 

                        while(!isspace(linea[k])){
                            bandera = true; 
                            aux++;
                            k++;
                        } 

                        if(!isspace(linea[k-aux])){
                            if(edificios[x].agregarLab(stoi(linea.substr(k-aux, aux)))){
                                laboratorio[stoi(linea.substr(k-aux, aux))-1].setIdLab(stoi(linea.substr(k-aux, aux))); 
                            } 
                        } 

                        if(bandera){
                            cont++; 
                        }
                        
                        k++; 

                    } */ 



/////////////////////////////////////////

                    contSalones = linea[k]-'0';
                    int m; 
                    asignarSalones(contSalones, k, m, linea, edificios, salon, x);

                    /* contSalones = linea[k]-'0'; cont = 0; 
                    int m = k+2; 

                    while(cont < contSalones){

                        bandera = false; aux = 0; 

                        while(!isspace(linea[m])){
                            bandera = true; 
                            aux++;
                            m++;
                        } 
                        
                        if(!isspace(linea[m-aux])){
                            if(edificios[x].agregarSal(stoi(linea.substr(m-aux, aux)))){
                                salon[stoi(linea.substr(m-aux, aux))-1].setIdSal(stoi(linea.substr(m-aux, aux))); 
                            }
                        }

                        if(bandera){
                            cont++; 
                        }
                        
                        m++; 

                    } */ 

                }   
            }
        }
        x++;
    } 

/*     for(Edificio c: edificios){
        c.muestraLabEdificio();
        cout << endl;  
    }

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

    for(int i = 0; i < 4; i++){
        edificios[i].getArrLabs();
        cout << " | "; 
        edificios[i].getArrSal();
        cout << endl; 
    }
*/

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++)
            cout << edificios[i].getArrLabs(j) << " | " << edificios[i].getArrSal(j) << endl;
        cout << endl;
    }  


    inEdificios.close();

    // cin.get();
    return 0; 
}