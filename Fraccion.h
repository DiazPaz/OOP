class Fraccion{

    public:
      Fraccion();
      Fraccion(int, int);
      int getNum();
      int getDen();
      void setNum(int);
      void setDen(int);
      double calcValorReal();

      ~Fraccion();

    private:
      int num, den;

};

Fraccion::Fraccion(){
  num = 1;
  den = 2;
}

Fraccion::Fraccion(int numP, int denP){
  num = numP;
  den = denP;
}

void Fraccion::setNum(int numP){
  num = numP;
}

void Fraccion::setDen(int denP){
  den = denP;
}

int Fraccion::getNum(){
  return num;
}

int Fraccion::getDen(){
  return den;
}

double Fraccion::calcValorReal(){
  return double(num)/den;
}

void Fraccion::~Fraccion(){
}

