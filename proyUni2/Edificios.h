#include "Salones.h"
#include "Laboratorios.h"

class Edificio{

    public: 

        Edificio(); 
        Edificio(int idEdificio, std::string nombreEd, int cantLaboratorios, int arrLabs[], int cantSalones, int arrSal[], std::string nameResponsable);

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
        // void getArrLabs() { 
        //     for(int i = 0; i < 10; i++)
        //         cout << arrLabs[i] << " "; 
        // }
        // void getArrSal() { 
        //     for(int i = 0; i < 10; i++)
        //         cout << arrSal[i] << " "; 
        // }

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
            // habrá una lista de 10 salones y 10 laboratorios por edifico
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

Edificio::Edificio(int ID, std::string NAME, int CANTL, int arrLaboratorios[10], int CANTS, int arrSalones[10], std::string RESP){
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
            return false; 
    } 
    
    if(cont < 10){
        arrLabs[cont] = ID; 
    }

    cantLabs = cont+1; 
    return true; 
        
}

bool Edificio::agregarSal(int ID){
    int cont = 0; 

    for(int i = 0; i < 10; i++){
        if(arrSal[i] != '\0')
            cont++;
    }

    for(int i = 0; i < cont; i++){
        if(arrSal[i] == ID)
            return false; 
    } 
    
    if(cont < 10){
        arrSal[cont] = ID; 
    }

    cantSal = cont+1; 
    return true; 
        
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