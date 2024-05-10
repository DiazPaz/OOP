#include <string>
#include "Hora.h"

class Reserva
{

    public: 
        Reserva()
        {
            claveServicio = "";
            idCliente = 0; 
            Hora h(0,0); 
            horaInicio = h; 
            duracion = 0; 
        }

        Reserva(string clave, int id, Hora inicio, int dura)
        {
            claveServicio = clave; 
            idCliente = id; 
            horaInicio = inicio; 
            duracion = dura; 
        }

        Hora calculaHoraFinReservacion()
        {
            Hora fin; 
            return fin = horaInicio + duracion; 
        }

        void setClaveServicio(string clave){ claveServicio = clave; }
        void setIdCliente(int id){ idCliente = id; }
        void setHoraInicio(Hora inicio){ horaInicio = inicio; }
        void setDuracion(int dura){ duracion = dura; }

        string getClaveServicio(){ return claveServicio; }
        int getIdCliente(){ return idCliente; }
        Hora getHoraInicio(){ return horaInicio; }
        int getDuracion(){ return duracion; }

    protected:
        string claveServicio; 
        int idCliente; 
        Hora horaInicio; 
        int duracion; 

};