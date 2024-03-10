#include "Computadora.h"

class Salones{

    public:

        Salones();
        Salones(int, std::string, int, Computadora);

        void setIdSal(int ID) { idSal = ID; }
        void setNameSal(std::string NAME) { nameSal = NAME; }
        void setCapacidadSal(int cap) { capacidadSal = cap; }
        void setCompSal(Computadora comp) { compSal = comp; }
        
        int getIdSal() { return idSal; }
        std::string getNameSal() { return nameSal; }
        int getCapacidadSal() { return capacidadSal; }
        Computadora getCompSal() { return compSal; }

        void muestraSal();

    private:
     
        int idSal; 
        std::string nameSal; 
        int capacidadSal; 
        Computadora compSal; 

}; 

Salones::Salones(){
    idSal = 0; 
    nameSal = ""; 
    capacidadSal = 0;  
    Computadora c;
}

Salones::Salones(int i, std::string n, int cap, Computadora comp){
    idSal = i; 
    nameSal = n; 
    capacidadSal = cap;  
    compSal = comp;
}

void Salones::muestraSal(){
    std::cout << "ID de Salon: " << idSal << "\n";
    std::cout << "Nombre de Salon: " << nameSal << "\n";
    std::cout << "Capacidad de Salon: " << capacidadSal << "\n";
    std::cout << "Computadora: " << "\n" << "  - Marca: " << compSal.getBrand() << "\n" << "  - OS: " << compSal.getOs() << "\n" <<"  - Ram: " << compSal.getRam() << "\n";
}