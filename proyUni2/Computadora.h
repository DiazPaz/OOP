#ifndef COMPUTADORA_H_
#define COMPUTADORA_H_

class Computadora{

    public: 
        Computadora();

        Computadora(int ID, std::string MARCA, std::string SO, std::string RAM)
        {
            ram = RAM; marca = MARCA; so = SO; idComputadora = ID; 
        }

        std::string getRam();
        std::string getBrand();
        std::string getOs();
        void setRam(std::string);
        void setBrand(std::string);
        void setOs(std::string);
        
        void setIdComputadora(int id) { idComputadora = id; }
        int getIdComputadora() { return idComputadora; }

        void muestraComputadora(){
            std::cout << "Computadora: " << "\n" << "  - Marca: " << marca << "\n" << "  - OS: " << so << "\n" <<"  - Ram: " << ram<< "\n";
        }

    private: 
        std::string ram;
        std::string marca;
        std::string so;

        int idComputadora; 

};

Computadora::Computadora(){
    ram = "";
    marca = "";
    so = "";
    idComputadora = 0; 
}

std::string Computadora::getRam(){
    return ram; 
}

std::string Computadora::getBrand(){
    return marca; 
}

std::string Computadora::getOs(){
    return so; 
}

void Computadora::setRam(std::string iRam){
    ram = iRam; 
}

void Computadora::setBrand(std::string iBrand){
    marca = iBrand; 
}

void Computadora::setOs(std::string iOs){
    so = iOs; 
}

#endif