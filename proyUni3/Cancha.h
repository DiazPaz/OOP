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
            cout << "Deporte: " << deporte << endl << "Costo ( $50 / 1 hora ): " << costoXHr << endl << "Cantidad de Personas: " << cantMaxPers;
        }

        double calculaCosto(int tiempo)
        {
            // costo: $50 por cada hora
            if(tiempo > 1)
                return costoXHr = tiempo * 50; 
            else 
                return costoXHr = 50;
        }

};