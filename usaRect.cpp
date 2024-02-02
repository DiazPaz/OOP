#include <iostream>
using namespace std;

#include "Rectangulo.h"

int main(void){

  Rectangulo rec1;
  Rectangulo rec2(5, 6);
  double area1, area2;

  rec1.setAncho(20);
  rec1.setLargo(10);

  area1 = rec1.calculaArea();
  cout << "Largo 1: " << rec1.getLargo() << "\n";
  cout << "Ancho 1: " << rec1.getAncho() << "\n";
  cout << "Area 1: " << area1 << "\n";

  area2 = rec2.calculaArea();
  cout << "Largo 2: " << rec2.getLargo() << "\n";
  cout << "Ancho 2: " << rec2.getAncho() << "\n";
  cout << "Area 2: " << area2 << "\n";

  getchar();
  return 0;
}
