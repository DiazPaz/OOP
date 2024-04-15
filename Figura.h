#ifndef FIGURA_H
#define FIGURA_H

class Figura{

    public:     
        Figura() { x = 1; y = 1; }
        virtual void dibuja() = 0; 

    protected:
        int x, y; 

}; 

#endif