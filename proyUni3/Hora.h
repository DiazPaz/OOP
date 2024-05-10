#ifndef HORA_H
#define HORA_H
#include <iostream> 

class Hora
{

    private: 
        int hh, mm; 
    
    public: 
        Hora(){ hh = 0; mm = 0; }
        Hora(int hora, int min){ hh = hora; mm = min; }

        void setHora(int hora){ hh = hora; }
        void setMin(int min){ mm = min; }
        int getHora(){ return hh; }
        int getMin(){ return mm; }

        bool operator==(Hora h)
        { 
            if(hh == h.hh && mm == h.mm)
                return true;
            return false;  
        }

        bool operator>=(Hora h)
        { 
            int minutos1 = hh*60 + mm;
            int minutos2 = h.hh*60 + h.mm;
            if(minutos1>=minutos2)
                return true; 
            return false; 
        }

        bool operator<=(Hora h)
        { 
            int minutos1 = hh*60 + mm;
            int minutos2 = h.hh*60 + h.mm;
            if(minutos1<=minutos2)
                return true; 
            return false; 
        }

        Hora operator+(int min)
        { 
            int aux = hh*60 + mm + min;
            int hora = aux / 60; 
            int minutos = aux % 60; 
            if(hora >= 24)
                hora -= 24; 
            Hora h(hora, minutos);
            return h; 
        }

        friend istream& operator>>(istream &is, Hora &dato)
        {
            cout << "\nHora: ";
            is >> dato.hh;
            cout << "Minutos: ";
            is >> dato.mm;
            return is;  
        }

        friend ostream& operator<<(ostream &os, Hora &dato)
        {
            if(dato.mm < 10 && dato.hh < 10)
                os << "0" << dato.hh << ":" << "0" << dato.mm;
            else if(dato.hh < 10)
                os << "0" << dato.hh << ":" << dato.mm; 
            else if(dato.mm < 10)
                os << dato.hh << ":" << "0" << dato.mm; 
            else
                os << dato.hh << ":" << dato.mm;
            return os; 
        }
};

#endif