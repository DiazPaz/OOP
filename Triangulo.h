#include "Figura.h"

class Triangulo : public Figura{

    public: 
        void dibuja()
        {
            cout << "   *   " << endl;
            cout << "  ***  " << endl;
            cout << " ***** " << endl;
            cout << "*******" << endl;
            cout << "Coord: (" << x << ", " << y << ")\n\n"; 
        }

}; 