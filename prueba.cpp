#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    int max = 0, seg = 0, ter = 0, j, k = 0, contador, palabras = 0;
    bool aux;
    std::string masRepetida = "", segRepetida = "", terRepetida = "";
    std::ifstream inArch("archivo.txt");
    
    if (!inArch.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    std::vector<std::string> lineas;
    std::string frase;

    while (getline(inArch, frase)) {
        lineas.push_back(frase);
    }

    // Ahora 'lineas' contiene todas las líneas del archivo.

    // Puedes hacer algo con el contenido almacenado en 'lineas', por ejemplo, imprimirlo:
    for (int i = 0; i < lineas.size(); i++) {
        std::cout << lineas[i] << std::endl;
    }

    for(int i = 0; i < frase.length(); i++){
      // conteo de palabras
      aux = false;
      while(isalpha(frase[i])){
        aux = true;
        i++;
      }
      if(aux == true){
        palabras++;
      }

    }


  while(k < 3){
    for(int i = 0; i < lineas.size(); i++){
      contador = 1;
      if(k == 1 && masRepetida == lineas[i]){
        i++;
      } else if(k == 2 && segRepetida == lineas[i] || masRepetida == lineas[i]){
        i++;
      }
      for(j = i + 1; j < palabras; j++){
        std::string lowerJ = lineas[j], lowerI = lineas[i];
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

      if(contador > max && k == 0){
        max = contador;
        masRepetida = lineas[i];
      } else if(contador > seg && k == 1){
        seg = contador;
        segRepetida = lineas[i];
      } else if(contador > ter && k == 2){
        ter = contador;
        terRepetida = lineas[i];
      }

    }
    k++;
  }

  if (masRepetida != "") {
    std::cout << "La palabra más repetida es: " << masRepetida << " (" << max << " veces)" << std::endl;
  } if (segRepetida != "" && segRepetida != masRepetida) {
    std::cout << "La segunda palabra más repetida es: " << segRepetida << " (" << seg << " veces)" << std::endl;
  } if (terRepetida != "" && terRepetida != masRepetida && terRepetida != segRepetida) {
    std::cout << "La tercera palabra más repetida es: " << terRepetida << " (" << ter << " veces)"  << std::endl;
  }
    

    inArch.close(); // No olvides cerrar el archivo cuando hayas terminado de usarlo.

    return 0;
}
