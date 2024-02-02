class Rectangulo{

  public:

    Rectangulo();
    Rectangulo(int, int);

    // puede jalar con solo el tipo
    // o también con el nombre de variable
    void setLargo(int);
    void setAncho(int);
    double calculaArea();

    int getLargo();
    int getAncho();

  private:
    int largo;
    int ancho;

};

// esta es una sobrecarga
// debido a que tenemos dos metodos con el mismo constructor

Rectangulo :: Rectangulo(){
  largo = 0;
  ancho = 0;
}

Rectangulo :: Rectangulo(int l, int w){
  largo = l;
  ancho = w;
}

double Rectangulo :: calculaArea(){
  return largo * ancho;
}

void Rectangulo :: setLargo(int l){
  largo = l;
}

void Rectangulo :: setAncho(int w){
  ancho = w;
}

int Rectangulo :: getLargo(){
  return largo;
}

int Rectangulo :: getAncho(){
  return ancho;
}
