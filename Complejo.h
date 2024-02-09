class Complejo{

  public:
    Complejo();
    Complejo(double, double);
    vector<int> suma(vector<int>);
    vector<int> resta(vector<int>);
    void setComplejo(double, double);
    vector<int> getComplejo();

  private:
    double real;
    double imaginario;    

};

Complejo::Complejo(){
  real = 0;
  imaginario = 0;
}

Complejo::Complejo(double r, double i){
  real = r;
  imaginario = i;
}

void Complejo::setComplejo(double r, double i){
  real = r;
  imaginario = i;
}

vector<int> Complejo::getComplejo(){
  vector<int> complejo;
  complejo.push_back(real);
  complejo.push_back(imaginario);
  return complejo;
}

vector<int> Complejo::suma(vector<int> a){
  vector<int> comSum;
  int comA = real + a[0];
  comSum.push_back(comA);
  int comB = imaginario + a[1];
  comSum.push_back(comB);
  return comSum; 
}

vector<int> Complejo::resta(vector<int> a){
  vector<int> comRes;
  int comA = real - a[0];
  comRes.push_back(comA);
  int comB = imaginario - a[1];
  comRes.push_back(comB);
  return comRes;
}