#include "Servicio.h"

class Aparato : public Servicio
{
    
    protected: 
        double costoX15min;
        bool conInstructor; 
        string descripcion; 

    public: 

        Aparato():Servicio(){};
        Aparato(string code, int timeMax, char type, double cost, bool instructor, string descp):Servicio(code, timeMax, type)
        {
            costoX15min = cost; 
            conInstructor = instructor; 
            descripcion = descp; 
        }

        void setCostoX15min(double costo){ costoX15min = costo; }
        void setInstructor(bool instrutctor){ conInstructor = instrutctor; }
        void setDescripcion(string descp){ descripcion = descp; }
        
        double getCostoX15min(){ return costoX15min; }
        bool getInstructor(){ return conInstructor; }
        string getDescripcion(){ return descripcion; }

        void muestra()
        {
            cout << "Descripcion: " << descripcion << endl << "Costo por cada 15 min: " << costoX15min << endl << "Instructor: ";
            if(conInstructor)
                cout << "SI" << endl; 
            else
                cout << "NO" << endl;  
        }

        double calculaCosto(int tiempo)
        {
            double costoFinal = 0; 
            if(tiempo >= 15)
                return costoFinal = (tiempo / 15) * costoX15min; 
            else 
                return costoFinal = costoX15min;
        }

};