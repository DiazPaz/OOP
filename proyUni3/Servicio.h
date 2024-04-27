#ifndef SERVICIO_H
#define SERVICIO_H

#include <string>

class Servicio
{

    public: 
        Servicio(){ tipo = ' '; clave = " "; tiempoMax = 0; }
        Servicio(string code, int time, char type){ tipo = type; clave = code; tiempoMax = time; }

        void setTipo(char type){ tipo = type; }
        void setClave(string code){ clave = code; }
        void setTiempo(int time){ tiempoMax = time; }
        
        char getTipo(){ return tipo; }
        string getClave(){ return clave; }
        int getTiempo(){ return tiempoMax; }

        virtual void muestra() = 0; 
        virtual double calculaCosto(int) = 0; 

    protected: 
        string clave; 
        int tiempoMax; 
        char tipo; 

};

#endif