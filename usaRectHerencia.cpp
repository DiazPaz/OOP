#include <iostream>
#include <string>
using namespace std;

#include "RectName.h"

int main()
{ Rectangulo r1, r2(10,4);
  rectName r3(9, 7, "roberto"), r4(12, 5, "ana"); 


cout<<"Este es el rectangulo 1"<<endl;
r1.dibuja();
cout<<"Este es el rectangulo 2"<<endl;
r2.dibuja();
cout<<"Este es el rectangulo 3"<<endl;
r3.dibuja();
cout<<"Este es el rectangulo 4"<<endl;
r4.dibuja();


 return 0;
}