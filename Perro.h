#include "Animal.h"

class Perro : public Animal
{

    public: 
        Perro(string, int);
        void muestra();
        void habla();

};

Perro::Perro(string name, int edad) : Animal(name, edad)
{
}

void Perro::habla()
{
    cout << " GUAU \n";
}

void Perro::muestra()
{
    cout << "Soy el	perro " << sNombre << " y tengo " << calculaEdad() << " anos. \n";
}