#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

int main(void){
  system("clear"); 
  ifstream entrada("entrada2.txt");
  ofstream salida; 
  string frase, palabra; 
  int pos; 
  if(entrada){
    salida.open("salida2.txt"); 
    while(!entrada.eof()){
      getline(entrada, palabra);
      getline(entrada, frase); 
      pos = frase.find(palabra); 
      while(pos != -1){
        frase.replace(pos, palabra.length(), "*"); 
        pos = frase.find(palabra);
      }
      cout << frase << "\n";
      salida << frase << "\n";
    }
    entrada.close();
    salida.close();
  } else {
    cout << "\nArchivo no encontrado\n";
  }
}
