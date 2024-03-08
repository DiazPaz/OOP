#ifndef COMPUTADORA_H_
#define COMPUTADORA_H_

class Computadora{

    public: 
        Computadora();
        std::string getRam();
        std::string getBrand();
        std::string getOs();
        void setRam(std::string);
        void setBrand(std::string);
        void setOs(std::string);

    private: 
        std::string ram;
        std::string marca;
        std::string so;

};

Computadora::Computadora(){
    ram = "";
    marca = "";
    so = "";
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