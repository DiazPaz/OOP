#include "MaterialDeLectura.h"

class Libro : public MaterialDeLectura
{

    private: 
        string editorial; 
        int numPags; 

    public:
        Libro();
        Libro(string, string, string, int);

        void setEditorial(string e){ editorial = e; }
        void setNum(int n){ numPags = n; }
        
        string getEditorial(){ return editorial; }
        int getNum(){ return numPags; }

        void muestra(){
            cout << "editorial: " << editorial << endl; 
            cout << "numero de paginas: " << numPags << endl; 
        }

};

Libro::Libro() : MaterialDeLectura()
{
    editorial = "";
    numPags = 0; 
}

Libro::Libro(string titulo, string autor, string ed, int num) : MaterialDeLectura(titulo, autor)
{
    editorial = ed; 
    numPags = num;
}