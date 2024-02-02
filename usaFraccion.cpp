#include <iostream>
using namespace std;

#include "Fraccion.h"

int main(void){

  Fraccion frac1, frac2(3,4);

  cout << "El valor de la fraccion 1 ";
  cout << frac1.getNum() << "/" << frac1.getDen() << " es ";
  cout << frac1.calcValorReal() << "\n";

  cout << "El valor de la fraccion 2 ";
  cout << frac2.getNum() << "/" << frac2.getDen() << " es ";
  cout << frac2.calcValorReal() << "\n";

  getchar();
  return 0;
}
