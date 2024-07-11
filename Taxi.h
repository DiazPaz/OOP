#include "Persona.h"

class Taxi{

    public: 
        Taxi();
        Taxi(Persona, int);
        void setResponsable(Persona);
        void setId(int);
        Persona getResponsable(); 
        int getId(); 

    private: 
        Persona responsable; 
        int id; 

};

Taxi::Taxi(){
    Persona p; 
    id = 0; 
}

Taxi::Taxi(Persona p, int ident){
    responsable = p; 
    id = ident; 
}
        
void Taxi::setResponsable(Persona p){
    responsable = p;
}

void Taxi::setId(int ident){
    id = ident; 
}

Persona Taxi::getResponsable(){
    return responsable; 
} 

int Taxi::getId(){
    return id; 
}