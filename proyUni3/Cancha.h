#include "Servicio.h"

class Cancha : public Servicio
{

    protected: 
        double costoXHr; 
        int cantMaxPers;
        string deporte; 

    public: 

        Cancha():Servicio(){};
        Cancha(string code, int timeMax, char type, double costo, int cantPers, string dep):Servicio(code, timeMax, type)
        {
            costoXHr = costo; 
            cantMaxPers = cantPers; 
            deporte = dep; 
        }

        void setCostoXHr(double costo){ costoXHr = costo; }
        void setCantMaxPers(int cantPers){ cantMaxPers = cantPers; }
        void setDeporte(string dep){ deporte = dep; }
        
        double getCostoXHr(){ return costoXHr; }
        int getCantMaxPers(){ return cantMaxPers; }
        string getDeporte(){ return deporte; }

        void muestra()
        {
            cout << "Deporte: " << deporte << endl << "Costo por hora: " << costoXHr << endl << "Cantidad de Personas: " << cantMaxPers << endl;
        }

        double calculaCosto(int tiempo)
        {
            double costoFinal = 0; 
            if(tiempo > 1)  
                return costoFinal = tiempo * costoXHr; 
            else 
                return costoFinal = costoXHr;
        }

};