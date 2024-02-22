#include <string>

class CtaBanc{

    public: 
        void setNumCta(int);
        void setNombre(string);
        void setSaldo(double);
        
        int getNumCta();
        string getNombre(); 
        double getSaldo();

        bool retira(double);
        void deposita(double);

    private:
        int numeroDeCuenta;
        string nombre; 
        double saldo;

};

void CtaBanc::setNumCta(int nc){
    numeroDeCuenta = nc; 
}
void CtaBanc::setNombre(string nom){
    nombre = nom; 
}
void CtaBanc::setSaldo(double cant){
    saldo = cant; 
}

int CtaBanc::getNumCta(){
    return numeroDeCuenta; 
}
string CtaBanc::getNombre(){
    return nombre;
}
double CtaBanc::getSaldo(){
    return saldo; 
}

void CtaBanc::deposita(double cant){
    saldo += cant; 
}
bool CtaBanc::retira(double cant){
    if(saldo - cant >= 0){
        saldo -= cant;
        return true;  
    } else {
        return false;  
    }
}