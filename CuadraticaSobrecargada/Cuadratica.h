class Cuadratica{
public:

    bool operator==(Cuadratica);
    Cuadratica operator+(Cuadratica);
    friend Cuadratica operator-(Cuadratica, Cuadratica);
    friend void operator+=(Cuadratica &c1, Cuadratica);
    Cuadratica operator*(int); 
    friend void operator++(Cuadratica &c){ c.iCoefC++; }

  Cuadratica();
  Cuadratica(int, int, int);
  void muestra();
private:
  int iCoefA, iCoefB, iCoefC;
};

Cuadratica::Cuadratica(){
  iCoefA = 1;
  iCoefB = 1;
  iCoefC = 1;
}

Cuadratica::Cuadratica(int iA, int iB, int iC){
  iCoefA = iA;
  iCoefB = iB;
  iCoefC = iC;
}

bool Cuadratica::operator==(Cuadratica c){
    if(iCoefA ==c.iCoefA && iCoefB ==c.iCoefB && iCoefC ==c.iCoefC)
        return true;
    else
        return false;
}

void operator+=(Cuadratica &c1, Cuadratica c2){
    c1.iCoefA += c2.iCoefA;
    c1.iCoefB += c2.iCoefB;
    c1.iCoefC += c2.iCoefC;
}

Cuadratica Cuadratica::operator+(Cuadratica c){
    Cuadratica res; 
    res.iCoefA = iCoefA + c.iCoefA; 
    res.iCoefB = iCoefB + c.iCoefB; 
    res.iCoefC = iCoefC + c.iCoefC; 
    return res;
}

Cuadratica operator-(Cuadratica c1, Cuadratica c2){ //friend
    Cuadratica res; 
    res.iCoefA = c1.iCoefA - c2.iCoefA; 
    res.iCoefB = c1.iCoefB - c2.iCoefB; 
    res.iCoefC = c1.iCoefC - c2.iCoefC; 
    return res;
}

Cuadratica Cuadratica::operator*(int i){
    Cuadratica res; 
    res.iCoefA = i * iCoefA; 
    res.iCoefB = i * iCoefB; 
    res.iCoefC = i * iCoefC; 
    return res;
}

void Cuadratica::muestra(){
  if (iCoefA != 0){
     cout << iCoefA;
     cout << "x^2 ";
  }
  if (iCoefB != 0){
     if (iCoefB > 0)
        cout << " + ";
     cout << iCoefB;
     cout << "x ";
  }
  if (iCoefC != 0){
     if (iCoefC > 0)
        cout << " + ";
     cout << iCoefC << endl;
  }
}