#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/* Cree un programa que lea texto de un archivo (10 pts) ----OK
y lo analice, generando un archivo llamado Reporte.txt (10 pts). ----OK
Deberá pedir al usuario el nombre del archivo .txt (10 pts) ----OK
Implemente las funciones: (10 pts c/u)
1. contar la cantidad de palabras ----OK

2. contar oraciones ----OK
3. contar párrafos ----OK
4. calcular la longitud promedio de las palabras ----OK
5. identificar las 3 palabras más comunes ----OK  */

int main(void){
  
  int letras = 0, palabras = 0, oraciones = 0, parrafos = 0, max = 0, seg = 0, ter = 0, j, k = 0, contador;
  string frase, masRepetida = "", segRepetida = "", terRepetida = "";
  double promPal = 0; bool aux;
  vector <string> lineas; 

  // Deberá pedir al usuario el nombre del archivo .txt (10 pts) ----OK
  ifstream inArch;
  ofstream outArch;
  string archivo; 
  cout << "Dame el nombre del archivo (.txt): "; getline(cin, archivo); 

  inArch.open(archivo); 

  if(inArch){

    // y lo analice, generando un archivo llamado Reporte.txt (10 pts). ----OK
    outArch.open("Reporte.txt");

    while(getline(inArch, frase)){
      lineas.push_back(frase);
    } 

    int k = 0;
    vector<string> vecPal; 

    // Cree un programa que lea texto de un archivo (10 pts) ----OK
    // Almacenar el texto palabra a palabra en un vector
    for(int i = 0; i < lineas.size(); i++){
      int j = 0;
      while(j < lineas[i].length()){
        
        // Saltar caracteres no alfabéticos
        while(j < lineas[i].length() && !isalpha(lineas[i][j]) && lineas[i][j] != '-'){
          
          // 2. contar oraciones ----OK
          if(lineas[i][j] == '.'){
            oraciones++;
          }

          // 3. contar párrafos ----OK
          if(lineas[i][j] == '\t'){
            parrafos++;
          }
          j++;
        }

        // Encontrar el final de la palabra
        k = j;
        while(k < lineas[i].length() && (isalpha(lineas[i][k]) || lineas[i][k] == '-')){
          if(isalpha(lineas[i][k])){
            letras++;
          }
          k++;
        }

        // Almacenar la palabra en vecPal
        if(j < k){
          vecPal.push_back(lineas[i].substr(j, k - j));
        }

        // Saltar el resto de la palabra
        j = k;
      }
    }
    
    // 1. contar la cantidad de palabras ----OK 
    int palabras  = vecPal.size();

    // 4. calcular la longitud promedio de las palabras ----OK
    promPal = (letras*1.0)/palabras;

    //5. identificar las 3 palabras más comunes ----OK  */
    k = 0; 
    while(k < 3){
      
      for(int i = 0; i < palabras; i++){

        contador = 1;

        // Evitar que la palabra anterior más repetida no se repita
        if(k == 1 && masRepetida == vecPal[i]){
          i++;
        } else if(k == 2 && segRepetida == vecPal[i] || masRepetida == vecPal[i]){
          i++;
        }

        // Hacer minúsculas a las palabras del vector y compararlas
        for(j = i + 1; j < palabras; j++){
          string lowerJ = vecPal[j], lowerI = vecPal[i];
          for(char &c: lowerI){
            c = tolower(c);
          }
          for(char &c: lowerJ){
            c = tolower(c);
          }
          if(lowerI == lowerJ){
            contador++;
          }
        }

        // contar la cantidad de veces que se repiten las palabras más repetidas
        if(contador > max && k == 0){
          max = contador;
          masRepetida = vecPal[i];
        } else if(contador > seg && k == 1){
          seg = contador;
          segRepetida = vecPal[i];
        } else if(contador > ter && k == 2){
          ter = contador;
          terRepetida = vecPal[i];
        }

      }
      k++;
    }

    outArch << "Letras: " << letras << "\n";
    outArch << "Palabras: " << palabras << "\n";
    outArch << "Oraciones: " << oraciones << "\n";
    outArch << "Parrafos: " << parrafos << "\n";
    outArch << "Longitud promedio de palabras: " << promPal << "\n\n";
    if (masRepetida != "") {
      outArch << "La palabra más repetida es: " << masRepetida << " (" << max << " veces)" << endl;
    } if (segRepetida != "" && segRepetida != masRepetida) {
      outArch << "La segunda palabra más repetida es: " << segRepetida << " (" << seg << " veces)" << endl;
    } if (terRepetida != "" && terRepetida != masRepetida && terRepetida != segRepetida) {
      outArch << "La tercera palabra más repetida es: " << terRepetida << " (" << ter << " veces)";
    } 

    inArch.close();
    outArch.close(); 
  
  } else {
  
    cout << "\nArchivo no encontrado\n";
  
  }
  
  return 0;

}