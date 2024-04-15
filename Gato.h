#include "Animal.h"

class Gato : public Animal
{

    public: 
        Gato(string, int);
        void muestra();
        void habla();

};

Gato::Gato(string name, int edad) : Animal(name, edad)
{
}

void Gato::habla()
{
    cout << " MIAU \n";
}

void Gato::muestra()
{
    cout << "Soy el	gato " << sNombre << " y tengo " << calculaEdad() << " anos. \n";
}