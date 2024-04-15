#include "Figura.h"

class Cuadrado : public Figura{

    public: 
        void dibuja()
        {
            cout << "********" << endl;
            cout << "********" << endl;
            cout << "********" << endl;
            cout << "********" << endl;
            cout << "Coord: (" << x << ", " << y << ")\n\n"; 
        }

}; 