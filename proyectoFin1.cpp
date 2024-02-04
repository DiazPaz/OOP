#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

/* Cree un programa que lea texto de un archivo (10 pts) y lo analice, generando un archivo llamado
Reporte.txt (10 pts).
Deberá pedir al usuario el nombre del archivo .txt (10 pts)
Implemente las funciones: (10 pts c/u)
1. contar la cantidad de palabras ----OK
2. contar oraciones ----OK
3. contar párrafos ----OK
4. calcular la longitud promedio de las palabras ----OK
5. identificar las 3 palabras más comunes */

int main(void){

  string frase = "Hola mundo. Espero que estes bien. Hola. ";
  int letras = 0, palabras = 0, oraciones = 0, parrafos = 1;
  double promPal = 0; 
  bool aux; 

  for(int i = 0; i < frase.length(); i++){
    // conteo de palabras
    aux = false;
    while(isalpha(frase[i])){
      aux = true;
      letras++;
      i++;
    } 
    if(aux == true){
      palabras++;
    }

    // conteo de oraciones
    if(frase[i] == '.'){
      oraciones++;
    }

    // conteo de parrafos
    if(frase[i] == '\n'){
      parrafos++;
    }
  }

  // promedio de longitud por palabra
  promPal = (letras*1.0)/palabras; 

  cout << "Letras: " << letras << "\n";
  cout << "Palabras: " << palabras << "\n";
  cout << "Oraciones: " << oraciones << "\n";
  cout << "Parrafos: " << parrafos << "\n";
  cout << "Longitud promedio de palabras: " << promPal << "\n";

  getchar();
  return 0;
}
