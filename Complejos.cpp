#include <iostream>
using namespace std;
#include "Complejo.h"

int main(void){

  Complejo a;
  int real, imaginario;
  cout << "Dame la parte real de tu nUmero complejo: "; cin >> real;
  cout << "Dame la parte imaginaria de tu nUmero complejo: "; cin >> imaginario;

  Complejo b, c;
  b.setComplejo(real, imaginario);
  int d[2], e[2];

  int real2, imaginario2;
  cout << "Dame la parte real de tu otro nUmero complejo: "; cin >> real2;
  cout << "Dame la parte imaginaria de tu otro nUmero complejo: "; cin >> imaginario2;

  d = b.suma(real2, imaginario2);
  e = b.resta(real2, imaginario2);

  for(int i = 0; i < 2; i++)
    cout << d[i] << endl;

  getchar();
  return 0;
}
