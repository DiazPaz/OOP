#include "Computadora.h"

class Salones{

    public:

        Salon();
        Salon(int, std::string, int, Computadora);

        void setIdSal(int ID) { id = ID; }
        void setNameSal(std::string NAME) { name = NAME; }
        void setCapacidadSal(int cap) { capacidad = cap; }
        void setIdSal(Computadora comp) { computadora = comp; }
        
        int getIdSal() { return id; }
        std::string getNameSal() { return name; }
        int getCapacidadSal() { return capacidad; }
        Computadora getCompSal() { return computadora; }

        void muestraSal();

    private:
     
        int id; 
        std::string name; 
        int capacidad; 
        Computadora computadora; 

}; 

Salones::Salon(){
    id = 0; 
    name = ""; 
    capacidad = 0;  
    Computadora c;
}

Salones::Salon(int i, std::string n, int cap, Computadora comp){
    id = i; 
    name = n; 
    capacidad = cap;  
    computadora = comp;
}

void Salones::muestraSal(){
    std::cout << "ID de Salon: " << id << "\n";
    std::cout << "Nombre de Salon: " << name << "\n";
    std::cout << "Capacidad de Salon: " << capacidad << "\n";
    std::cout << "Computadora: " << "\n" << "  - Marca: " << computadora.getBrand() << "\n" << "  - OS: " << computadora.getOs() << "\n" <<"  - Ram: " << computadora.getRam() << "\n";
}