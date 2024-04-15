#ifndef ANIMAL_H
#define ANIMAL_H 

class Animal	
{	
    public:
        Animal(string,	int);	
        int	calculaEdad();
        virtual	void habla() = 0;			//Nota	que	son	funciones	virtual	pura.
        virtual	void muestra() = 0;			//	ENTONCES	la	clase	es	abstracta.	
    protected:
        string sNombre;	
        int	iAnioNacim;	
};

Animal::Animal(string	sNom,	int	iANac)	
{	
    sNombre	=	sNom;	
    iAnioNacim	=	iANac;	
}	

int	Animal::calculaEdad()	
{	
    return	2024 - 	iAnioNacim;	
}	

#endif