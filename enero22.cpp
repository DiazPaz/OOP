#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

  string frase; int pos; 

  ifstream archEntrada;
  ofstream archSalida; 
  
  archEntrada.open("frasesEntrada.txt");
  archSalida.open("frasesSalida.txt");

  while(!archEntrada.eof()){
    getline(archEntrada, frase);
    pos = frase.rfind(" ");
    do{
      cout << frase.substr(pos+1) << " ";
      archSalida << frase.substr(pos+1) << " "; 
      frase.erase(pos);
      pos = frase.rfind(" ");
    } while(pos!=-1);
  cout << frase << endl;   
  archSalida << frase << endl;
  } 

  archEntrada.close();
  archSalida.close(); 

  return 0; 
}
