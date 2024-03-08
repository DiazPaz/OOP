#include "Salones.h"
#include "Laboratorios.h"

class Edificio{

    public: 

        Edificio(); 
        Edificio(int, std::string, std::string, int, int, int arrSal[], int arrLabs[]);

        void setId(int ID) { id = ID; }
        void setName(std::string NAME) { name = NAME; }
        void setResponsable(std::string resp) { responsable = resp; }

        int getId() { return id; }
        std::string getName() { return name; }
        std::string getResponsable() { return responsable; }
        int getCantLabs() { return cantLabs; }
        int getCantSal() { return cantSal; }

        int getArrLabs(int i) { return arrLabs[i]; }
        int getArrSal(int i) { return arrSal[i]; }

        bool agregarLab(int);
        bool agregarSal(int);

        void muestraLabEdificio();
        void muestraSalEdificio();

        private: 
            
            int id; 
            std::string name; 
            std::string responsable; 
            int cantLabs = 0; 
            int cantSal = 0; 
            int arrLabs[10] = {};
            int arrSal[10] = {};

};

Edificio::Edificio(){
    id = 0; 
    name = "";
    responsable = ""; 
    cantLabs = 0; 
    cantSal = 0;
    for(int i = 0; i < 10; i++){
        arrLabs[i] = 0; 
        arrSal[i] = 0; 
    }
}

Edificio::Edificio(int ID, std::string NAME, std::string RESP, int CANTS, int CANTL, int arrSalones[10], int arrLaboratorios[10]){
    id = ID; 
    name = NAME;
    responsable = RESP; 
    cantLabs = CANTL; 
    cantSal = CANTS;
    for(int i = 0; i < 10; i++){
        arrSal[i] = arrSalones[i]; 
        arrLabs[i] = arrLaboratorios[i]; 
    }
}

bool Edificio::agregarLab(int ID){
    int cont = 0; 

    for(int i = 0; i < 10; i++){
        if(arrLabs[i] != '\0')
            cont++;
    }

    for(int i = 0; i < cont; i++){
        if(arrLabs[i] == ID)
            return true; 
    } 
    
    if(cont < 10){
        arrLabs[cont] = ID; 
    }

    return false; 
        
}

bool Edificio::agregarSal(int ID){
    int cont = 0; 

    for(int i = 0; i < 10; i++){
        if(arrSal[i] != '\0')
            cont++;
    }

    for(int i = 0; i < cont; i++){
        if(arrSal[i] == ID)
            return true; 
    } 
    
    if(cont < 10){
        arrSal[cont] = ID; 
    }

    return false; 
        
}

void Edificio::muestraLabEdificio(){
    std::cout << "ID de Edificio: " << id << "\n";
    std::cout << "Nombre de Edificio: " << name << "\n";
    std::cout << "Responsable de Edificio: " << responsable << "\n";
    std::cout << "IDs de Laboratorios:\n";
    for(int i = 0; i < 10; i++){
        std::cout << " - " << arrLabs[i] << "\n";
    }
    std::cout << "Cantidad de Laboratorios: " << cantLabs << "\n";
}

void Edificio::muestraSalEdificio(){
    std::cout << "ID de Edificio: " << id << "\n";
    std::cout << "Nombre de Edificio: " << name << "\n";
    std::cout << "Responsable de Edificio: " << responsable << "\n";
    std::cout << "IDs de Salones:\n";
    for(int i = 0; i < 10; i++){
        std::cout << " - " << arrSal[i] << "\n";
    }
    std::cout << "Cantidad de Salones: " << cantSal << "\n";
}