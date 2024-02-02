#include <iostream>
#include <string>

using namespace std;
int lastChar(const string str);

int main(void){

  string repeat;

  // se inicia el ciclo para que el usuario pueda ingresar tantos codigos como requiera
  do{
    string isbm;

    // se ingresan los 9 primeros digitos
    do{
      cout<<"Primeros 9 digitos del ISBM: "; getline(cin, isbm);
      if(isbm.length()!=9)
        cout<<"ISBM no vAlido\n\n";
    }while(isbm.length()!=9);

    // dependiendo de la funcion lastChar se imprime el ultimo valor del string (x o 10)
    if(lastChar(isbm) < 10){
      cout << "ISBM: " << isbm << "-" << lastChar(isbm) << "\n";
    } else {
      cout << "ISBM: " << isbm << "-X\n";
    }

    // ciclo para validar repetir el programa
    do{
      cout << "¿Tienes otro ISBM? (s/n) "; getline(cin, repeat);
      if((repeat != "s")&&(repeat != "S")&&(repeat != "n")&&(repeat != "N"))
        cout << "Opcion no valida\n\n";
    }while((repeat != "s")&&(repeat != "S")&&(repeat != "n")&&(repeat != "N"));

  }while((repeat == "s")||(repeat == "S"));
  return 0;
}

// funcion que identifica el modulo de la suma de la multiplicacion de los valores para
// asignar el ultimo valor del string
int lastChar(const string str){
  int a = 0, b;
  for(int i = 0; i < str.length(); i++){
    b = str[i] - '0';
    a += (i+1)*b;
  }
  return a%11;
}
