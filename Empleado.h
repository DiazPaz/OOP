class Empleado{

    public: 

        Empleado();

        void setId(int);
        void setSueldoFijo(double);
        void setSueldoHora(double);
        void setHoras(int);

        int getId();
        double getSueldoFijo();
        double getSueldoHora();
        int getHoras();

        void registraHoras(int);
        double calculaPago();

    private: 

        int id; 
        double sueldoFijo; 
        double sueldoHora; 
        int horas; 

};

Empleado::Empleado(){
    id = 0; 
    sueldoFijo = 0; 
    sueldoHora = 0; 
    horas = 0; 
}

void Empleado::setId(int x){
    id = x; 
}

void Empleado::setSueldoFijo(double y){
    sueldoFijo = y; 
}

void Empleado::setSueldoHora(double z){
    sueldoHora = z; 
}

void Empleado::setHoras(int x){
    horas = x; 
}

int Empleado::getId(){
   return id; 
}

double Empleado::getSueldoFijo(){
    return sueldoFijo; 
}

double Empleado::getSueldoHora(){
    return sueldoHora; 
}

int Empleado::getHoras(){
    return horas; 
}

void Empleado::registraHoras(int y){
    horas += y; 
}

double Empleado::calculaPago(){
    return sueldoFijo + (horas * sueldoHora);
}