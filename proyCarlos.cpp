#include <iostream>
#include <string>
#include <fstream>

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

    const int cantLineas = 99;
    string linea; 
    ifstream archIn("resultados.txt"); 
    ofstream archOut; 

    if(archIn){

        archOut.open("Reporte.txt");

        string arrLineas[cantLineas]; 
        int i = 0;

        // Declaramos línea por línea del .txt en el arreglo
        while(!archIn.eof()){
            
            getline(archIn, linea);

            if(i<99){
                arrLineas[i] = linea; 
                i++; 
            }
            
        }  

        string genero = ""; bool gen; int male = 0, female = 0;

        int edad; bool ed; int men = 0, may = 0; 

        string rendimiento = ""; bool rend; int excellent = 0, good = 0, average = 0, belowAverage = 0;  

        string apuntes = ""; bool apunt; int apuntesYes = 0, apuntesNo = 0, apuntesSome = 0; 

        string apuntesCalificaciones[cantLineas][2]; bool apuCalif; 

        string rendSueno[cantLineas][2]; bool reSu; int contadorTabs;

        // inicializamos ciclo FOR para análisis línea por línea del .txt
        for(int i = 0; i < cantLineas; i++){
            // banderas que avisan cuando encuentran un valor en específico
            gen = true; ed = true; rend = true; apunt = true; reSu = true;
            // inicializamos ciclo FOR para poder detectar el primer '\t'
            for(int j = 0; j < arrLineas[i].length(); j++){
                if(arrLineas[i][j] == '\t'){
                    // inicializamos ciclo FOR para poder detectar el segundo '\t' y capturar el genero
                    for(int k = j + 1; k < arrLineas[i].length(); k++){
                        if(arrLineas[i][k] == '\t' && gen == true){
                            genero = arrLineas[i].substr(j+1, k-j-1);
                            if(genero == "Male")
                                male++;
                            if(genero == "Female")
                                female++; 
                            gen = false; 
                            // inicializamos ciclo FOR para poder detectar el tercer '\t' y capturar el rendimiento
                            for(int m = k + 1; m < arrLineas[i].length(); m++){
                                if(arrLineas[i][m] == '\t' && rend == true){
                                    rendimiento = arrLineas[i].substr(k+1, m-k-1);
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
                                    // inicializamos ciclo FOR para poder detectar el tercer '\t' y capturar si los alumnos toman apuntes 
                                    for(int n = m + 1; n < arrLineas[i].length(); n++){
                                        if(arrLineas[i][n] == '\t' && apunt == true){
                                            apuntes = arrLineas[i].substr(m+1, n-m-1);
                                            apuntesCalificaciones[i][1] = apuntes;
                                            if(apuntes == "Yes")
                                                apuntesYes++;
                                            if(apuntes == "No")
                                                apuntesNo++; 
                                            if(apuntes == "Sometimes")
                                                apuntesSome++; 
                                            apunt = false;
                                            contadorTabs = 0; 
                                            // inicializamos último ciclo FOR para poder detectar '\t' y en caso de que si contar 3 '\t' hasta llegar a la columna del registro de sueño
                                            for(int l = n + 1; l < arrLineas[i].length(); l++){
                                                if(arrLineas[i][l] == '\t'){
                                                    contadorTabs++; 
                                                    if(contadorTabs == 3){
                                                        for(int o = l + 1; o < arrLineas[i].length(); o++){
                                                            if(arrLineas[i][o] == '\t' && reSu == true){
                                                                rendSueno[i][1] = arrLineas[i].substr(l+1, o-l-1);
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
                    // condicional que permite accionar un contador para las edades de los participantes 
                    if(ed == true){
                        edad = stoi(arrLineas[i].substr(0,j));
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
        const int cats = 4;
        int rendimientos[cats] = {excellent, good, average, belowAverage};
        const string categorias[cats] = {"Excellent", "Good", "Average", "Below average"};
        archOut << "Rendimiento académico: " << endl;
        for(int i = 0; i < cats; i++){
            archOut << categorias[i] << " (" << rendimientos[i] << " alumnos)" << endl;
        }
        
        archOut << "\n----------APUNTES------------" << endl;
        const int catsApuntes = 3; 
        int arrAp[catsApuntes] = {apuntesYes, apuntesNo, apuntesSome};
        const string arrApuntes[catsApuntes] = {"si", "no", "a veces"};
        for(int i = 0; i < catsApuntes; i++){
            archOut << " -> " << arrAp[i] << " alumnos " << arrApuntes[i] << " toman apuntes. " << endl;
        }

        archOut << "\n----------REPORTE 1-----------" << endl << "RENDIMIENTO" << "\t\t" << "HORAS DE SUEÑO" << endl << "- - - - - - - - - - - - - - -" << endl;
        for(int i = 0; i < cantLineas; i++){
            for(int j = 0; j < 2; j++){
                archOut << rendSueno[i][j] << "\t\t\t";
            }
            archOut << endl;
        } archOut << "- - - - - - - - - - - - - - -" << endl;
        int masRepetido = 0; int max = 0; 
        for(int i = 0; i < cats; i++){
            if(rendimientos[i] > max){
                max = rendimientos[i];
                masRepetido = i; 
            }
        }
        archOut << "El rendimiento más repetido es "<< categorias[masRepetido] << " con " << max << " repeticiones. \n";
        archOut << "- - - - - - - - - - - - - - -" << endl;
        int suma = 0; 
        for(int a = 0; a < 4; a++){
            for(int i = 0; i < cantLineas; i++){
                if(rendSueno[i][0] == categorias[a]){
                    suma += stoi(rendSueno[i][1]);
                }
            } archOut << "El promedio de horas de sueño del rendimiento " << categorias[a] << " es de " << (suma*1.0)/rendimientos[a] << endl;
            suma = 0; 
        }
        archOut << "------------------------------" << endl;
        
        archOut << "\n----------REPORTE 2-----------" << endl << "RENDIMIENTO" << "\t\t" << "APUNTES" << endl << "- - - - - - - - - - - - - - -" << endl;
        for(int i = 0; i < cantLineas; i++){
            for(int j = 0; j < 2; j++){
                archOut << apuntesCalificaciones[i][j] << "\t\t\t";
            }
            archOut << endl;
        } archOut << endl; 
        for(int i = 0; i < cats; i++){
            archOut << categorias[i] << endl;
            apuntesYes = 0; apuntesNo = 0; apuntesSome = 0; 
            for(int j = 0; j < cantLineas; j++){
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
        
        archIn.close(); 

    } else {

        cout << "Archivo no existente. \n";
        
    }

    return 0; 
}