#include <iostream>
#include <vector>
using namespace std;
#include "Complejo.h"

int main(void){

  Complejo a;

  int real, imaginario;
  cout << "Dame la parte real de tu nUmero complejo: "; cin >> real;
  cout << "Dame la parte imaginaria de tu nUmero complejo: "; cin >> imaginario;

  Complejo b(real, imaginario);

  int real2, imaginario2;
  cout << "Dame la parte real de tu otro nUmero complejo: "; cin >> real2;
  cout << "Dame la parte imaginaria de tu otro nUmero complejo: "; cin >> imaginario2;

  Complejo c(real2, imaginario2);

  Complejo d(b.suma(c.getComplejo())[0], b.suma(c.getComplejo())[1]);
  Complejo e(b.resta(c.getComplejo())[0], b.resta(c.getComplejo())[1]);

  cout << "(" << a.getComplejo()[0] << "," << a.getComplejo()[1] << ")\n";
  cout << "(" << b.getComplejo()[0] << "," << b.getComplejo()[1] << ")\n";
  cout << "(" << c.getComplejo()[0] << "," << c.getComplejo()[1] << ")\n";
  cout << "(" << d.getComplejo()[0] << "," << d.getComplejo()[1] << ")\n";
  cout << "(" << e.getComplejo()[0] << "," << e.getComplejo()[1] << ")\n";

  return 0;
}