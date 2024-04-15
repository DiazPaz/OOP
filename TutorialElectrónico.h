#include "MaterialDeLectura.h"

class TutorialElectronico : public MaterialDeLectura
{

    private: 
        string url; 
        string fecha; 

    public:
        TutorialElectronico();
        TutorialElectronico(string, string, string, string);

        void setUrl(string e){ url = e; }
        void setFecha(string n){ fecha = n; }
        
        string getUrl(){ return url; }
        string getFecha(){ return fecha; }

        void muestra(){
            cout << "url: " << url << endl; 
            cout << "fecha: " << fecha << endl; 
        }

};

TutorialElectronico::TutorialElectronico() : MaterialDeLectura()
{
    url = "";
    fecha = ""; 
}

TutorialElectronico::TutorialElectronico(string titulo, string autor, string u, string f) : MaterialDeLectura(titulo, autor)
{
    url = u; 
    fecha = f;
}