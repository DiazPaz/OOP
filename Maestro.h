#include "Persona.h"

class Maestro : public Persona{

    private: 
        string departamento; 

    public: 
        Maestro();
        Maestro(string, string, string);

        void setDepartamento(string);
        string getDepartamento();
        void muestra();

};


Maestro::Maestro(): Persona(){
    departamento = "N/A";
}

Maestro::Maestro(string nombre, string cel, string dpto): Persona(nombre, cel){
    departamento = dpto; 
}

void Maestro::setDepartamento(string dpto){
    departamento = dpto; 
}

string Maestro::getDepartamento(){
    return departamento; 
}

void Maestro::muestra(){
    cout << "Nombre: " << nombre << endl << "Celular: " << numCel << endl << "Departamento: " << departamento; 
}