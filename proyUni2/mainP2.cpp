#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Edificios.h"


void asignarLaboratoriosID(int contador, int pos1, int &pos2, string lin, Edificio ed[], Laboratorios lab[], int contEdificios){
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

void asignarSalonesID(int contador, int pos1, int &pos2, string lin, Edificio ed[], Salones sal[], int contEdificios){
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

void asignarLaboratoriosName(int contador, Edificio ed[], Laboratorios lab[], int contEdificios, int numLineas, string arrInfo[], int idComps[], int longIdComps, Computadora comps[], string arrInfoComps[]){

    int aux1, aux2, aux3, aux4; 
    int idComp; 
    bool bandera; 

    for(int i = 0; i < numLineas; i++){

        aux1 = 0; 
        while(!isspace(arrInfo[i][aux1]))
            aux1++; 

        for(int j = 0; j < contador; j++){
            if(ed[contEdificios].getArrLabs(j) == stoi(arrInfo[i].substr(0, aux1))){

                aux2 = aux1; 
                while(!isspace(arrInfo[i][aux2+1]))
                    aux2++; 
                
                lab[ed[contEdificios].getArrLabs(j)-1].setNameLab(arrInfo[i].substr(aux1, aux2));

                aux3 = 0; 
                while(!isspace(arrInfo[i][aux2+2])){
                    aux2++;
                    aux3++; 
                }

                lab[ed[contEdificios].getArrLabs(j)-1].setCapacidadLab(stoi(arrInfo[i].substr(aux2+2-aux3, aux3))); 

                aux4 = 0; 
                while(!isspace(arrInfo[i][aux2+aux3+1])){
                    aux2++;
                    aux4++; 
                }

                idComp = stoi(arrInfo[i].substr(aux2+aux3+1-aux4, aux4)); 

                for(int k = 0; k < longIdComps; k++){
                    if(idComps[k] == idComp){

                        int before = 0, after = 0, after2 = 0;

                        while(!isspace(arrInfoComps[k][before])){
                            after++;
                            before++; 
                        }

                        comps[k].setIdComputadora(stoi(arrInfoComps[k].substr(0, after)));

                        while(!isspace(arrInfoComps[k][after+2])){
                            after++;
                            after2++; 
                        }

                        comps[k].setBrand(arrInfoComps[k].substr(after-after2, after2+2));

                        after2 = 0; 
                        while(!isspace(arrInfoComps[k][after+3])){
                            after++;
                            after2++; 
                        }

                        comps[k].setOs(arrInfoComps[k].substr(after+3-after2, after2));

                        after2 = 0; 
                        while(!isspace(arrInfoComps[k][after+4])){
                            after++;
                            after2++; 
                        }

                        comps[k].setRam(arrInfoComps[k].substr(after+4-after2, after2));

                        lab[ed[contEdificios].getArrLabs(j)-1].setCompLab(comps[k]);
                    }
                }
            }  
        }
    } 
    
}         

void asignarSalonesName(int contador, Edificio ed[], Salones sal[], int contEdificios, int numLineas, string arrInfo[], int idComps[], int longIdComps, Computadora comps[], string arrInfoComps[]){

    int aux1, aux2, aux3, aux4; 
    int idComp;

    for(int i = 0; i < numLineas; i++){

        aux1 = 0; 
        while(!isspace(arrInfo[i][aux1]))
            aux1++; 

        for(int j = 0; j < contador; j++){
            if(ed[contEdificios].getArrSal(j) == stoi(arrInfo[i].substr(0, aux1))){

                aux2 = aux1; 
                while(!isspace(arrInfo[i][aux2+1]))
                    aux2++; 
                
                sal[ed[contEdificios].getArrSal(j)-1].setNameSal(arrInfo[i].substr(aux1, aux2));

                aux3 = 0; 
                while(!isspace(arrInfo[i][aux2+2])){
                    aux2++;
                    aux3++; 
                }

                sal[ed[contEdificios].getArrSal(j)-1].setCapacidadSal(stoi(arrInfo[i].substr(aux2+2-aux3, aux3))); 
                
                aux4 = 0; 
                while(!isspace(arrInfo[i][aux2+aux3+1])){
                    aux2++;
                    aux4++; 
                }

                idComp = stoi(arrInfo[i].substr(aux2+aux3+1-aux4, aux4));

                for(int k = 0; k < longIdComps; k++){
                    if(idComps[k] == idComp){

                        int before = 0, after = 0, after2 = 0;

                        while(!isspace(arrInfoComps[k][before])){
                            after++;
                            before++; 
                        }

                        comps[k].setIdComputadora(stoi(arrInfoComps[k].substr(0, after)));

                        while(!isspace(arrInfoComps[k][after+2])){
                            after++;
                            after2++; 
                        }

                        comps[k].setBrand(arrInfoComps[k].substr(after-after2, after2+2));

                        after2 = 0; 
                        while(!isspace(arrInfoComps[k][after+3])){
                            after++;
                            after2++; 
                        }

                        comps[k].setOs(arrInfoComps[k].substr(after+3-after2, after2));

                        after2 = 0; 
                        while(!isspace(arrInfoComps[k][after+4])){
                            after++;
                            after2++; 
                        }

                        comps[k].setRam(arrInfoComps[k].substr(after+4-after2, after2));

                        sal[ed[contEdificios].getArrSal(j)-1].setCompSal(comps[k]);
                    }
                }
            }
        }
    } 

}

int main(void){
    
    Salones salon[20]; Laboratorios laboratorio[20]; Computadora computadoras[30]; Edificio edificios[4];

    ifstream inEdificios; inEdificios.open("edificios.txt"); 
    ifstream inLabs; inLabs.open("laboratorios.txt");
    ifstream inSals; inSals.open("salones.txt");
    ifstream inComp; inComp.open("computadora.txt");

    string linea, linea2, linea3, arrLabsInfo[20], arrSalInfo[20], arrCompInfo[30]; 
    int x = 0, y = 0, z = 0, w = 0; 
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

/////////////////////////////////////////

                    contLaboratorios = linea[j+1]-'0';
                    int k = 0; 
                    asignarLaboratoriosID(contLaboratorios, j, k, linea, edificios, laboratorio, x);

/////////////////////////////////////////

                    contSalones = linea[k]-'0';
                    int m; 
                    asignarSalonesID(contSalones, k, m, linea, edificios, salon, x);

                }   
            }
        }

///////////////////////////////////////// 

        if(w == 0){
            while(getline(inComp, linea3)){
                arrCompInfo[w] = linea3; 
                w++; 
            }
        }

        int contDig, j, idComp[w]; 
        for(int i = 0; i < w; i++){

            j = 0; contDig = 0; 
            while(!isspace(arrCompInfo[i][j])){
                contDig++; 
                j++;
            }
            
            idComp[i] = stoi(arrCompInfo[i].substr(0, contDig));

        }

/////////////////////////////////////////

        if(y == 0){
            while(getline(inLabs, linea2)){
                arrLabsInfo[y] = linea2; 
                y++; 
            }
        }
        int idCompL; 
        asignarLaboratoriosName(contLaboratorios, edificios, laboratorio, x, y, arrLabsInfo, idComp, w, computadoras, arrCompInfo);
        
/////////////////////////////////////////
  
        if(z == 0){
            while(getline(inSals, linea2)){
                arrSalInfo[z] = linea2; 
                z++; 
            }
        }
        int idCompS;
        asignarSalonesName(contSalones, edificios, salon, x, z, arrSalInfo, idComp, w, computadoras, arrCompInfo);

///////////////////////////////////////// 

        x++;
    } 

    char input; 
    do{

        cout << "\na. Consulta de todos los laboratorios que están en la lista.\nb. Consulta de todos los salones que están en la lista.\nc. Consulta de todos los edificios que están en la lista.\nd. Consulta de todas las computadoras disponibles.\ne. Consulta de computadoras por edificio.\nf. Consulta por clave de computadora.\ng. Consulta la lista de labs y salones en las que se tiene una marca de computadora\nh. Terminar\n";
        cin >> input; 
        
        switch(input){

            case 'a': 
                for(Laboratorios lab: laboratorio)
                    lab.muestraLab();
                break; 

            case 'b': 
                for(Salones sal: salon)
                    sal.muestraSal();
                break;

            case 'c': 
                for(Edificio ed: edificios){
                    ed.muestraLabEdificio();
                    cout << endl;  
                    ed.muestraSalEdificio();
                    cout << endl;
                }
                break; 

            case 'd': 
                for(Laboratorios lab: laboratorio){
                    cout << "ID de Computadora: " << lab.getCompLab().getIdComputadora() << endl;
                    lab.getCompLab().muestraComputadora(); 
                    cout << "Laboratorio correspondiente: "; cout << lab.getIdLab() << ", "; cout << lab.getNameLab() << endl;  
                    cout << endl; 
                }
                cout << "=====================\n";
                for(Salones sal: salon){
                    cout << "ID de Computadora: " << sal.getCompSal().getIdComputadora() << endl;
                    sal.getCompSal().muestraComputadora(); 
                    cout << "Salon correspondiente: "; cout << sal.getIdSal() << ", "; cout << sal.getNameSal() << endl;  
                    cout << endl; 
                }
                
                break; 

            case 'e': 
                break; 

            case 'f': 
                break; 

            case 'g': 
                break; 

            case 'h': cout << "\nPrograma terminado...\nDoy mi palabra que he realizado esta actividad con integridad academica.\n"; return false;

        }

    }while(true); 

    inEdificios.close();
    inSals.close();
    inLabs.close();
    inComp.close();

    return 0; 
}