#include "ctaBancHerencia.h"

class Chequera:public CtaBanc{

    private: 
        double comision; 

    public:
        Chequera();
        Chequera(int, double, double);
        void setComision(double com){ comision = com; }
        double getComision(){ return comision; }
        bool retira(double cant);
	    void mostrar();

};

Chequera::Chequera():CtaBanc(){
    comision = 10; 
}

Chequera::Chequera(int cta, double sal, double com): CtaBanc(cta, sal){
    comision = com; 
}

bool Chequera::retira(double cant)
{	if (saldo >= cant + comision)
{	saldo -= cant+comision;
	return true;
}
else
	return false;
}

void Chequera::mostrar()
{	cout<<endl;
	cout<<"Tu cuenta "<<numCuenta<< " tiene un saldo: "<<saldo<<endl;
}