#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona{

    public: 
        Persona();
        Persona(string, string); 
        void setNombre(string);
        void setNumCel(string);
        string getNombre();
        string getNumCel();

        static int getContadorPersonas() { return contPer; };

        virtual void muestra(){
            cout << "Nombre: " << nombre << endl << "Celular: " << numCel; 
        }

    protected: 
        string nombre; 
        string numCel; 

        static int contPer; 

}; 

int Persona::contPer = 0; 

Persona::Persona(string nom, string num){
    nombre = nom; 
    numCel = num; 
    contPer++;
}

Persona::Persona(){
    nombre = "";
    numCel = "";
    contPer++;
}

string Persona::getNombre(){
    return nombre; 
}

string Persona::getNumCel(){
    return numCel; 
}
void Persona::setNombre(string nom){
    nombre = nom;
}

void Persona::setNumCel(string num){
    numCel = num; 
}

#endif