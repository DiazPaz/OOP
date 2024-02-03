#include <iostream>
#include <string>

using namespace std;

int main(void){

  string frase = "Hola mundo. Espero que estes bien.   ";
  int letras = 0, palabras = 0, aux;

  for(int i = 0; i < frase.length(); i++){
    if((frase[i] <= 90 && frase[i] >= 65) || (frase[i] >= 97 && frase[i] <= 122)){
      letras++;
    }
  }

  for(int i = 0; i < frase.length(); i++){
    if(!((frase[i] <= 90 && frase[i] >= 65) || (frase[i] >= 97 && frase[i] <= 122))){
      if(frase[i+2] != '\0'){
        palabras++;
      }
    }
  }

  aux = letras%palabras;

  cout << aux << "\n";
  cout << "Letras: " << letras << "\n";
  cout << "Palabras: " << palabras << "\n";
  getchar();
  return 0;
}
