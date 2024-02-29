/* Escribe la clase Salón que tenga los siguientes elementos:

Atributos:
Número salón - que es un número entero de 4 dígitos (el primer dígito es el aula, el segundo el piso y los otros dos el número de salón). 
Por ejemplo: Aulas 3, 2do piso, salón 10 = 3210. Vamos a suponer que es así, no requieres validar el formato)

Computadora - que es un objeto de tipo Computadora que representa la computadora que hay disponible en el salón.

Constructor default

Y... Métodos de acceso y modificación para cada uno de los atributos
*/

#include "Computadora.h"

class Salon{

    public: 
        Salon();
        void setNumSalon(int);
        void setComp(Computadora);
        int getNumSalon();
        Computadora getComp();

    private: 
        int numSalon; 
        Computadora comp; 

};

Salon::Salon(){
    numSalon = 0;
    Computadora c;
}

int Salon::getNumSalon(){
    return numSalon; 
}

Computadora Salon::getComp(){
    return comp; 
}

void Salon::setNumSalon(int iNum){
    numSalon = iNum; 
}

void Salon::setComp(Computadora iComp){
    comp = iComp; 
}