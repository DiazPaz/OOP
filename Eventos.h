#include "Reloj.h"

class Eventos{

    private: 
        Reloj horaInicio;
        int duracion; 
        string asunto; 

    public: 
        Eventos();
        Eventos(Reloj, int, string);

        void setHoraInicio(Reloj);
        void setDuracion(int);
        void setAsunto(string);
        
        Reloj getHoraInicio();
        int getDuracion();
        string getAsunto();

};

Eventos::Eventos(){
    Reloj r; 
    horaInicio = r;
    duracion = 0; 
    asunto = "";
}

Eventos::Eventos(Reloj r, int d, string a){
    horaInicio = r; 
    duracion = d; 
    asunto = a; 
}

void Eventos::setHoraInicio(Reloj r){
    horaInicio = r; 
}

void Eventos::setDuracion(int d){
    duracion = d; 
}

void Eventos::setAsunto(string a){
    asunto = a; 
}

Reloj Eventos::getHoraInicio(){
    return horaInicio;
}
int Eventos::getDuracion(){
    return duracion; 
}
string Eventos::getAsunto(){
    return asunto;
}