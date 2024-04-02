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

    void dibuja() { 
      for (int r = 1; r <= ancho; r++) { // dibujo completo el primero y el ultimo renglon
        if (r == 1 || r == ancho) { 
          for (int c = 1; c <= largo; c++)
          cout<<"*";
          cout<<endl;
        } else {
        // dibujo solo los caracteres de los extremos en los renglones del medio
          cout<<"*";
          for (int c = 2; c < largo; c++)
            cout<<" ";
          cout<<"*"<<endl;
        }
      }
    }

  protected:
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
