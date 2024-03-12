//
//  Fraccion.h
//  CascaronFraccion
//


#ifndef CascaronFraccion_Fraccion_h
#define CascaronFraccion_Fraccion_h

class Fraccion
{
	friend double operator !(Fraccion f);
	friend Fraccion operator -(Fraccion f1, Fraccion f2);
public:
	// Constructores
	Fraccion();
	Fraccion(int n, int d);
	// metodos de acceso
	int getNum();
	int getDen();
	// metodos de modificacion
	void setNum(int n);
	void setDen(int d);
	// metodos
	Fraccion operator + (Fraccion f);
	Fraccion operator * (Fraccion f);
	bool operator > (Fraccion f); 
	Fraccion operator ++();
	Fraccion operator --();
	void muestra();
	
private:
	int num, den;
};

Fraccion::Fraccion()
{
    num = 1;
    den = 2;
}

Fraccion::Fraccion(int n, int d)
{
    num = n;
    den = d;
}

int Fraccion::getNum()
{
    return num;
}

int Fraccion::getDen()
{
    return den;
}

void Fraccion::setNum(int n)
{
    num = n;
}

void Fraccion::setDen(int d)
{
    den = d;
}

void Fraccion::muestra()
{
	cout << num << "/" << den;
}

double operator !(Fraccion f)
{
    return  (double)f.num/f.den;
}

Fraccion Fraccion:: operator + (Fraccion f)
{   
	Fraccion res;
    res.num = this->num * f.den + this->den * f.num;
    res.den = this->den * f.den;
    return res;
}

Fraccion operator - (Fraccion f1, Fraccion f2)
{   
	Fraccion res = f1 + (--f2);
    return res;
}

Fraccion Fraccion:: operator * (Fraccion f)
{   
	Fraccion res;
    res.num = num * f.num; 
    res.den = den * f.den;
    return res;
}

Fraccion Fraccion:: operator ++()
{   
	Fraccion res;
	res.num = num+den;
	res.den = den;
    return res;
}

Fraccion Fraccion:: operator --()
{   
	Fraccion res;
	res.num = num*-1;
	res.den = den;
    return res;
}

bool Fraccion:: operator > (Fraccion f)
{   
	if(!this > !f)
		return true; 
	else
		return false; 
}

#endif
