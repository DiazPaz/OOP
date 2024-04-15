#include <iostream>
#include <string>
using namespace std; 

#include "Libro.h"
#include "TutorialElectrónico.h"

int main(void)
{

    MaterialDeLectura *arr[10];
    char input; 
    int contArr = 0; 
    bool cont = true; 

    do{
        string titulo, autor, editorial, url, fecha;
        int numPags;
        cout << "Elige una opcion que deseas referenciar: \n";
        cout << "1. libro\n";
        cout << "2. tutorial\n";
        cout << "3. terminar\n";
        cin >> input; 

        switch(input){
            case '1':
                cout << "Dame el titulo del libro: "; 
                cin >> titulo; 
                cout << "Dame el autor del libro: "; 
                cin >> autor; 
                cout << "Dame la editorial del libro: "; 
                cin >> editorial; 
                cout << "Dame el numero de paginas del libro: "; 
                cin >> numPags; 
                arr[contArr] = new Libro(titulo, autor, editorial, numPags);
                contArr++;
                break; 
            case '2':
                cout << "Dame el titulo del tutorial: "; 
                cin >> titulo; 
                cout << "Dame el autor del tutorial: "; 
                cin >> autor; 
                cout << "Dame la url del tutorial: "; 
                cin >> url; 
                cout << "Dame la fecha de publicacion: "; 
                cin >> fecha; 
                arr[contArr] = new TutorialElectronico(titulo, autor, url, fecha);
                contArr++;
                break; 
            case '3': 
                cont = false; 
                break; 
            default: 
                cout << "opcion no valida\n"; 
        }

    }while(cont == true);

    for(int i = 0; i < contArr; i++){
        arr[i]->muestra();
        cout << endl; 
    }

    return 0; 
}