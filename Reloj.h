class Reloj{

  public:
    Reloj();
    Reloj(int, int);
    ~Reloj();
    void setHora(int);
    void setMinu(int);
    int getHora();
    int getMinu();
    void muestra();

  private:
    int hora;
    int minuto;

};

Reloj :: Reloj(){
  hora = 0;
  minuto = 0;
}

Reloj::Reloj(int h, int m){
  hora = h; 
  minuto = m; 
}

void Reloj::setHora(int h){
  if((hora < 0) || (hora > 23)){
    cout << "Hora invalida\n";
  }else{
    hora = h;
  }
}

void Reloj::setMinu(int m){
  if((m<0) || (m>59)){
    cout << "Minutos Invalidos\n";
  }else{
    minuto = m;
  }
}


int Reloj::getHora(){
  return hora;
}

int Reloj::getMinu(){
  return minuto;
}

void Reloj::muestra(){
  if(hora<10){
    cout << "0" << hora << ":";
  } else {
    cout << hora << ":";
  }
  if(minuto<10){
    cout << "0" << minuto;
  } else {
    cout << minuto;
  }
  cout << "\n";
}

Reloj::~Reloj(){
}
