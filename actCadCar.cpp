#include <cstring>
#include <iostream>
using namespace std; 

int main(void)
{

    char nombre[50];
    char presentacion[10] = "Hola ";
    char exclamaciones[10] = "!!!";

    cout << "Dame tu nombre completo: "; cin.getline(nombre, 50);
    
    strcat(presentacion, nombre);
    strcat(presentacion, exclamaciones);
    
    for(int i = 0; i < strlen(presentacion); i++)
        cout << presentacion[i]; 
    cout << endl; 
    
    for(int i = 0; i < strlen(nombre); i++)
        cout << nombre[i]; 
    cout << endl; 

    int i = 0; 
    do
    {
        cout << nombre[i];
        i++;
    } while (nombre[i] != ' ');
    

    return 0; 
}