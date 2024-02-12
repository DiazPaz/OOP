#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std; 

/* Cree un programa que lea un archivo de resultados y lo analice, (5 pts) ----OK
generando un archivo llamado Reporte.txt (5 pts). ----OK
Implemente las funciones:
1. contar la cantidad de estudiantes hombres y cuantas mujeres (10 pts) ----OK 
2. contar cuantos para cada edad (en rangos de 3 años) (10 pts) ----OK
3. contar cuantos por rendimiento académico (10) ----OK
4. contar cuantos que si toman notas (10) ----OK
5. reportar si hay relación entre tomar notas y el logro en calificaciones (10) ----OK
6. reportar si las horas que duermen tiene relación con el logro en calificaciones (10) ----OK*/

int main(void){

    string linea; 
    vector<string> lineas; 
    ifstream archIn("resultados.txt"); 
    ofstream archOut; 

    if(archIn){

        archOut.open("Reporte.txt");

        while(!archIn.eof()){
            getline(archIn, linea);
            lineas.push_back(linea);
        } 

        string genero = ""; bool gen; int male = 0, female = 0;

        int edad; bool ed; int men = 0, may = 0; 

        string rendimiento = ""; bool rend; int excellent = 0, good = 0, average = 0, belowAverage = 0;  

        string apuntes = ""; bool apunt; int apuntesYes = 0, apuntesNo = 0, apuntesSome = 0; 

        string apuntesCalificaciones[lineas.size()][2]; bool apuCalif; 

        string rendSueno[lineas.size()][2]; bool reSu; int contadorTabs;

        for(int i = 0; i < lineas.size(); i++){
            gen = true; ed = true; rend = true; apunt = true; reSu = true; 
            for(int j = 0; j < lineas[i].length(); j++){
                if(lineas[i][j] == '\t'){
                    for(int k = j + 1; k < lineas[i].length(); k++){
                        if(lineas[i][k] == '\t' && gen == true){
                            genero = lineas[i].substr(j+1, k-j-1);
                            if(genero == "Male")
                                male++;
                            if(genero == "Female")
                                female++; 
                            gen = false; 
                            for(int m = k + 1; m < lineas[i].length(); m++){
                                if(lineas[i][m] == '\t' && rend == true){
                                    rendimiento = lineas[i].substr(k+1, m-k-1);
                                    apuntesCalificaciones[i][0] = rendimiento; 
                                    rendSueno[i][0] = rendimiento;
                                    if(rendimiento == "Excellent")
                                        excellent++;
                                    if(rendimiento == "Good")
                                        good++; 
                                    if(rendimiento == "Average")
                                        average++; 
                                    if(rendimiento == "Below average")
                                        belowAverage++; 
                                    rend = false; 
                                    for(int n = m + 1; n < lineas[i].length(); n++){
                                        if(lineas[i][n] == '\t' && apunt == true){
                                            apuntes = lineas[i].substr(m+1, n-m-1);
                                            apuntesCalificaciones[i][1] = apuntes;
                                            if(apuntes == "Yes")
                                                apuntesYes++;
                                            if(apuntes == "No")
                                                apuntesNo++; 
                                            if(apuntes == "Sometimes")
                                                apuntesSome++; 
                                            apunt = false;
                                            contadorTabs = 0; 
                                            for(int l = n + 1; l < lineas[i].length(); l++){
                                                if(lineas[i][l] == '\t'){
                                                    contadorTabs++; 
                                                    if(contadorTabs == 3){
                                                        for(int o = l + 1; o < lineas[i].length(); o++){
                                                            if(lineas[i][o] == '\t' && reSu == true){
                                                                rendSueno[i][1] = lineas[i].substr(l+1, o-l-1);
                                                                reSu = false; 
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } 
                    if(ed == true){
                        edad = stoi(lineas[i].substr(0,j));
                        if(edad <= 22)
                            men++;
                        if(edad > 22)
                            may++; 
                        ed = false; 
                    }
                }
            }
        }  

        archOut << "-----------GENERO------------" << endl;
        archOut << "Male: " << male << " | " << "Female: " << female << endl;

        archOut << "\n------------EDAD-------------" << endl;
        archOut << "(20-22): " << men << " | " << "(23-25): " << may << endl;

        archOut << "\n----RENDIMIENTO ACADEMICO----" << endl;
        vector<int> rendimientos = {excellent, good, average, belowAverage};
        const string categorias[4] = {"Excellent", "Good", "Average", "Below average"};
        archOut << "Rendimiento académico: " << endl;
        for(int i = 0; i < rendimientos.size(); i++){
            archOut << categorias[i] << " (" << rendimientos[i] << " alumnos)" << endl;
        }
        
        archOut << "\n----------APUNTES------------" << endl;
        vector<int> vecApuntes = {apuntesYes, apuntesNo, apuntesSome};
        const string arrApuntes[3] = {"si", "no", "a veces"};
        for(int i = 0; i < vecApuntes.size(); i++){
            archOut << " -> " << vecApuntes[i] << " alumnos " << arrApuntes[i] << " toman apuntes. " << endl;
        }

        archOut << "\n----------REPORTE 1-----------" << endl << "RENDIMIENTO" << "\t\t" << "HORAS DE SUEÑO" << endl << "- - - - - - - - - - - - - - -" << endl;
        for(int i = 0; i < lineas.size(); i++){
            for(int j = 0; j < 2; j++){
                archOut << rendSueno[i][j] << "\t\t\t";
            }
            archOut << endl;
        } archOut << "- - - - - - - - - - - - - - -" << endl;
        int masRepetido = 0; int max = 0; 
        for(int i = 0; i < rendimientos.size(); i++){
            if(rendimientos[i] > max){
                max = rendimientos[i];
                masRepetido = i; 
            }
        }
        archOut << "El rendimiento más repetido es "<< categorias[masRepetido] << " con " << max << " repeticiones. \n";
        archOut << "- - - - - - - - - - - - - - -" << endl;
        int suma = 0; 
        for(int a = 0; a < 4; a++){
            for(int i = 0; i < lineas.size(); i++){
                if(rendSueno[i][0] == categorias[a]){
                    suma += stoi(rendSueno[i][1]);
                }
            } archOut << "El promedio de horas de sueño del rendimiento " << categorias[a] << " es de " << (suma*1.0)/rendimientos[a] << endl;
            suma = 0; 
        }
        archOut << "------------------------------" << endl;
        
        archOut << "\n----------REPORTE 2-----------" << endl << "RENDIMIENTO" << "\t\t" << "APUNTES" << endl << "- - - - - - - - - - - - - - -" << endl;
        for(int i = 0; i < lineas.size(); i++){
            for(int j = 0; j < 2; j++){
                archOut << apuntesCalificaciones[i][j] << "\t\t\t";
            }
            archOut << endl;
        } 
        for(int i = 0; i < (sizeof(categorias)/sizeof(categorias[0])); i++){
            archOut << categorias[i] << endl;
            apuntesYes = 0; apuntesNo = 0; apuntesSome = 0; 
            for(int j = 0; j < lineas.size(); j++){
                if(apuntesCalificaciones[j][0] == categorias[i]){
                    if(apuntesCalificaciones[j][1] == "Yes")
                        apuntesYes++;
                    if(apuntesCalificaciones[j][1] == "No")
                        apuntesNo++; 
                    if(apuntesCalificaciones[j][1] == "Sometimes")
                        apuntesSome++;
                }
            } archOut << "- - - - - - - - - - - - - - -" << endl;
            archOut << "-> " << apuntesYes << " alumnos " << arrApuntes[0] << " tomaban apuntes. " << endl;
            archOut << "-> " << apuntesNo << " alumnos " << arrApuntes[1] << " tomaban apuntes. " << endl;
            archOut << "-> " << apuntesSome << " alumnos " << arrApuntes[2] << " tomaban apuntes. \n" << endl;
        } archOut << "------------------------------" << endl;
        
    } else {
        cout << "Archivo no existente. \n";
    }

    return 0; 
}