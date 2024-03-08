#include "Computadora.h"

class Laboratorios{

    public:

        Laboratorios();
        Laboratorios(int, std::string, int, Computadora);

        void setIdLab(int ID) { id = ID; }
        void setNameLab(std::string NAME) { name = NAME; }
        void setCapacidadLab(int cap) { capacidad = cap; }
        void setCompLab(Computadora comp) { computadora = comp; }
        
        int getIdLab() { return id; }
        std::string getNameLab() { return name; }
        int getCapacidadLab() { return capacidad; }
        Computadora getCompLab() { return computadora; }

        void muestraLab();

    private:
     
        int id; 
        std::string name; 
        int capacidad; 
        Computadora computadora; 

}; 

Laboratorios::Laboratorios(){
    id = 0; 
    name = ""; 
    capacidad = 0;  
    Computadora c;
}

Laboratorios::Laboratorios(int i, std::string n, int cap, Computadora comp){
    id = i; 
    name = n; 
    capacidad = cap;  
    computadora = comp;
}

void Laboratorios::muestraLab(){
    std::cout << "ID de Laboratorio: " << id << "\n";
    std::cout << "Nombre de Laboratorio: " << name << "\n";
    std::cout << "Capacidad de Laboratorio: " << capacidad << "\n";
    std::cout << "Computadora: " << "\n" << "  - Marca: " << computadora.getBrand() << "\n" << "  - OS: " << computadora.getOs() << "\n" <<"  - Ram: " << computadora.getRam() << "\n";
}