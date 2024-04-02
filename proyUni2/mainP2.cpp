#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
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

                        comps[k].setBrand(arrInfoComps[k].substr(after-after2+1, after2+1));

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

                        comps[k].setBrand(arrInfoComps[k].substr(after-after2+1, after2+1));

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
    int x = 0, y = 0, z = 0, w = 0, k = 0, m; 
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
                    asignarLaboratoriosID(contLaboratorios, j, k, linea, edificios, laboratorio, x);

/////////////////////////////////////////

                    contSalones = linea[k]-'0';
                    asignarSalonesID(contSalones, k, m, linea, edificios, salon, x);

                }   
            }
        }

/////////////////////////////////////////

        edificios[x].setResponsable(linea.substr(m)); 

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

///////////////////////////////////////// 

    int contadorLaboratoriosComp; 
    int contadorSalonesComp; 
    int contadorCompEd[4] = {0,0,0,0};
    char input; 
    string marcas[4] = {"hp", "lenovo", "apple", "dell"};
    string nombreEdificio;
    string marcaLabs;
    string marcaSal;
    bool continua = true;
    bool bandera = false; 
    string marca;
    do{

        system("cls");
        cout << "\na. Consulta de todos los laboratorios que estan en la lista.\nb. Consulta de todos los salones que estan en la lista.\nc. Consulta de todos los edificios que estan en la lista.\nd. Consulta de todas las computadoras disponibles.\ne. Consulta de computadoras por edificio.\nf. Consulta por clave de computadora.\ng. Consulta la lista de labs y salones en las que se tiene una marca de computadora\nh. Terminar\n";
        cin >> input; 
        cout << endl; 
        
        switch(input){

            case 'a': 
                for(Laboratorios lab: laboratorio){
                    if(lab.getIdLab() != 0)
                        lab.muestraLab();
                }
                getch(); 
                break; 

            case 'b': 
                for(Salones sal: salon){
                    if(sal.getIdSal() != 0)
                        sal.muestraSal();
                }
                getch(); 
                break;

            case 'c': 
                for(Edificio ed: edificios){
                    ed.muestraLabEdificio();
                    cout << endl;  
                    ed.muestraSalEdificio();
                    cout << endl;
                }
                getch(); 
                break; 

            case 'd': 

                for(Laboratorios lab: laboratorio){
                    if(lab.getCompLab().getIdComputadora() != 0){
                        cout << "ID de Computadora: " << lab.getCompLab().getIdComputadora() << endl;
                        lab.getCompLab().muestraComputadora(); 
                        cout << "Laboratorio correspondiente: "; cout << lab.getIdLab() << ", "; cout << lab.getNameLab() << endl;  
                    }
                    for(int i = 0; i < 4; i++){
                        for(int j = 0; j < 10;j++){
                            if(edificios[i].getArrLabs(j) == lab.getIdLab() && lab.getCompLab().getIdComputadora() != 0)
                                cout << "Edificio correspondiente: " << edificios[i].getId() << ", " << edificios[i].getName() << endl;
                        }
                    }
                cout << endl; 
                }
                cout << "=====================\n\n";
                for(Salones sal: salon){
                    if(sal.getCompSal().getIdComputadora() != 0){
                        cout << "ID de Computadora: " << sal.getCompSal().getIdComputadora() << endl;
                        sal.getCompSal().muestraComputadora(); 
                        cout << "Salon correspondiente: "; cout << sal.getIdSal() << ", "; cout << sal.getNameSal() << endl;  
                    }
                    for(int i = 0; i < 4; i++){
                        for(int j = 0; j < 10;j++){
                            if(edificios[i].getArrSal(j) == sal.getIdSal() && sal.getCompSal().getIdComputadora() != 0)
                                cout << "Edificio correspondiente: " << edificios[i].getId() << ", " << edificios[i].getName() << endl;
                        }
                    }
                cout << endl; 
                }
                getch(); 
                break; 

            case 'e': 
                int idEdificio; 
                do{
                    cout << "ID de Edificio: "; cin >> idEdificio; 
                    if(idEdificio < 1 || idEdificio > 4)
                        cout << "ID no valido\n";
                }while(idEdificio < 1 || idEdificio > 4); 
                
                for(int i = 0; i < 4; i++){
                    if(idEdificio == edificios[i].getId()){

                        for(int j = 0; j < edificios[i].getCantLabs(); j++){
                            if(laboratorio[j].getCompLab().getIdComputadora() != 0){
                                cout << "ID de Computadora: " << laboratorio[j].getCompLab().getIdComputadora() << endl;
                                laboratorio[j].getCompLab().muestraComputadora(); 
                                cout << "Laboratorio correspondiente: "; cout << laboratorio[j].getIdLab() << ", "; cout << laboratorio[j].getNameLab() << endl;  
                            }
                            cout << endl; 
                        }
                        
                        for(int j = 0; j < edificios[i].getCantSal(); j++){
                            if(salon[j].getCompSal().getIdComputadora() != 0){
                                cout << "ID de Computadora: " << salon[j].getCompSal().getIdComputadora() << endl;
                                salon[j].getCompSal().muestraComputadora(); 
                                cout << "Salon correspondiente: "; cout << salon[j].getIdSal() << ", "; cout << salon[j].getNameSal() << endl;  
                            }
                            cout << endl; 
                        }
                    }
                    cout << endl; 
                }
                getch(); 
                break; 

            case 'f': 
                int idComputadora; 
                do{
                    cout << "ID de Computadora: "; cin >> idComputadora; 
                    if(idComputadora < 1 || idComputadora > 22)
                        cout << "ID no valido\n";
                }while(idComputadora < 1 || idComputadora > 22);

                for(int j = 0; j < 10; j++){
                    if(idComputadora == laboratorio[j].getCompLab().getIdComputadora()){
                        laboratorio[j].muestraLab();
                        for(int i = 0; i < 4; i++){
                            for(int k = 0; k < edificios[i].getCantLabs(); k++){
                                if(laboratorio[j].getIdLab() == edificios[i].getArrLabs(k)){
                                    cout << "Edificio correspondiente: " << edificios[i].getId() << ", " << edificios[i].getName() << endl;
                                }
                            }
                        } 
                    }
                } cout << endl; 
                for(int j = 0; j < 12; j++){
                    if(idComputadora == salon[j].getCompSal().getIdComputadora()){
                        salon[j].muestraSal(); 
                    }
                } cout << endl;
                getch(); 
                break; 

            case 'g': 

                bandera = false;  
                do{

                    cout << "Marca de computadora: "; cin >> marca; cout << endl; 

                    for(char &c: marca)
                        c = tolower(c);

                    for(int i = 0; i < 4; i++){
                        if(marca == marcas[i])
                            bandera = true; 
                    }

                    if(bandera == false)
                        cout << "Marca inexistente..." << endl; 
                        
                }while(bandera == false);

                contadorLaboratoriosComp = 0; 
                contadorSalonesComp = 0; 
                
                for(int i = 0; i < 4; i++){
                    contadorCompEd[i] = 0; 
                }
                for(int i = 0; i < 22; i++){
                    marcaLabs = computadoras[i].getBrand();
                    for(char &c: marcaLabs)
                        c = tolower(c);
                    if(marcaLabs == marca){

                        for(int j = 0; j < 10; j++){
                            if(computadoras[i].getIdComputadora() == laboratorio[j].getCompLab().getIdComputadora()){
                                contadorLaboratoriosComp++;       
                                for(int k = 0; k < 4; k++){
                                    for(int l = 0; l < 10; l++){
                                        if(edificios[k].getArrLabs(l) == laboratorio[j].getIdLab()){
                                            contadorCompEd[k]++;
                                        }
                                    }
                                }
                            }
                        } 

                        for(int j = 0; j < 12; j++){
                            if(computadoras[i].getIdComputadora() == salon[j].getCompSal().getIdComputadora()){
                                contadorSalonesComp++;       
                                for(int k = 0; k < 4; k++){
                                    for(int l = 0; l < 10; l++){
                                        if(edificios[k].getArrSal(l) == salon[j].getIdSal()){
                                            contadorCompEd[k]++;
                                        }
                                    }
                                }
                            }
                        } 
                    }
                } 

                cout << endl << "Cantidad de computadoras " << marca << " en laboratorios: " << contadorLaboratoriosComp << endl; 
                cout << "Cantidad de computadoras " << marca << " en salones: " << contadorSalonesComp << endl << endl; 

                for(int i = 0; i < 4; i++){
                    cout << "Edificio correspondiente: \n";
                    cout << "Nombre: " << edificios[i].getName() << endl << "ID: " << edificios[i].getId() << endl; 
                    cout << "Cantidad computadoras " << marca << " en Edificio " << i+1 << ": " << contadorCompEd[i] << endl << endl;
                } 
                getch(); 
                break; 

            case 'h': 
                cout << "\nPrograma terminado...\nDoy mi palabra que he realizado esta actividad con integridad academica.\n"; 
                return continua = false;
                break; 

            default: 
                cout << "Opcion no valida...\n"; 
                getch(); 
                break; 

        }

    }while(continua == true); 

    inEdificios.close();
    inSals.close();
    inLabs.close();
    inComp.close();

    return 0; 
}