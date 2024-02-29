/* Escribe la clase Computadora que tenga los siguientes elementos:

Atributos:
Marca
Sistema Operativo
RAM
Constructor default
Métodos de acceso y modificación para cada uno de los atributos
*/

class Computadora{

    public: 
        Computadora();
        string getRam();
        string getBrand();
        string getOs();
        void setRam(string);
        void setBrand(string);
        void setOs(string);

    private: 
        string ram;
        string marca;
        string so;

};

Computadora::Computadora(){
    ram = "";
    marca = "";
    so = "";
}

string Computadora::getRam(){
    return ram; 
}

string Computadora::getBrand(){
    return marca; 
}

string Computadora::getOs(){
    return so; 
}

void Computadora::setRam(string iRam){
    ram = iRam; 
}

void Computadora::setBrand(string iBrand){
    marca = iBrand; 
}

void Computadora::setOs(string iOs){
    so = iOs; 
}