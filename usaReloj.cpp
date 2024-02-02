#include <iostream>
using namespace std;

#include "Reloj.h"

int main(void){

  Reloj horaInicial, horaFinal;
  int horaI, horaF, minI, minF;

  cout << "Dame la hora inicial: ";
  cin >> horaI;
  cout << "Dame los minutos iniciales: ";
  cin >> minI;
  cout << "Dame la hora final: ";
  cin >> horaF;
  cout << "Dame los minutos finales: ";
  cin >> minF;

  horaInicial.setHora(horaI);
  horaInicial.setMinu(minI);

  horaFinal.setHora(horaF);
  horaFinal.setMinu(horaF);

  cout << "La hora inicial es: ";
  horaInicial.muestra();
  cout << "\n" << "La hora final es: ";
  horaFinal.muestra();

  cout << "La hora inicial es ";
  cout << horaInicial.getHora() << ":" << horaInicial.getMinu();

}
