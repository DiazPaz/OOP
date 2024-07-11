#include "Persona.h"

class Estudiante : public Persona{

    private: 
        string carrera; 

    public: 
        Estudiante();
        Estudiante(string, string, string);

        void setCarrera(string);
        string getCarrera();
        void muestra();

};


Estudiante::Estudiante(): Persona(){
    carrera = "N/A";
}

Estudiante::Estudiante(string nombre, string cel, string carr): Persona(nombre, cel){
    carrera = carr; 
}

void Estudiante::setCarrera(string carr){
    carrera = carr; 
}

string Estudiante::getCarrera(){
    return carrera; 
}

void Estudiante::muestra(){
    cout << "Nombre: " << nombre << endl << "Celular: " << numCel << endl << "Carrera: " << carrera; 
}