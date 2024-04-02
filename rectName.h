#include "Rectangulo.h"

class rectName : public Rectangulo{

    private: 
        string name; 

    public: 
        rectName();
        rectName(int, int, string);
        void dibuja();

};

rectName::rectName():Rectangulo(){
    name = " ";
}

rectName::rectName(int la, int an, string nom):Rectangulo(la, an){
    name = nom; 
}

void rectName::dibuja(){
    for (int r = 1; r <= ancho; r++) { // dibujo completo el primero y el ultimo renglon
        if (r == 1 || r == ancho) { 
          for (int c = 1; c <= largo; c++)
            cout<<"*";
          cout<<endl;
        } else {
        // dibujo solo los caracteres de los extremos en los renglones del medio
          cout<<"*";
          if(r==ancho/2)
            cout << name; 
          for (int c = 2; c < largo; c++)
            cout<<" ";
          cout<<"*"<<endl;
        }
      }
}