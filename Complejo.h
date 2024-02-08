class Complejo{

  public:
    Complejo();
    Complejo(int, int);
    int suma(int, int);
    int resta(int, int);
    void setComplejo(int);
    int getCompSum(int);
    int getCompRes(int);

  private:
    int real;
    int imaginario;
    int comSum[2];
    int comRes[2];

};

Complejo::Complejo(){
  real = 0;
  imaginario = 0;
}

Complejo::Complejo(int r, int i){
  real = r;
  imaginario = i;
}

void Complejo::setComplejo(int r, int i){
  real = r;
  imaginario = i;
}

int Complejo::suma(int a, int b){
  int comA = real + a;
  int comB = imaginario + b;
  comSum = {comA, comB};
  //cout << "(" << comA << "," << comB << ")\n";
}

int Complejo::resta(int a, int b){
  int comA = real - a;
  int comB = imaginario - b;
  //cout << "(" << comA << "," << comB << ")\n";
  comRes = {comA, comB};
}

int Complejo::getCompSum(int){
}
