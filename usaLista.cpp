#include <iostream>
using namespace std; 

#include "Lista.h"

int main(void)
{
    Lista<int> listaInt; 
    Lista<double> listaDo; 
    Lista<char> listaCh; 

    for(int i = 0; i < 5; i++)
    {
        listaInt.agrega(i);
        listaDo.agrega(i+0.5);
        listaCh.agrega(char(i));
    }

    int lenListaInt = listaInt.getSize();
    int lenListaDo = listaDo.getSize();
    int lenListaCh = listaCh.getSize();

    for(int i = 0; i < 5; i++)
    {
        if(i < lenListaInt)
        {
            cout << listaInt.getElement(i) << " ";
        } 
        if(i < lenListaDo)
        {
            cout << listaDo.getElement(i) << " ";
        } 
        if(i < lenListaCh)
        {
            cout << listaCh.getElement(i) << " ";
        } 
    }

    return 0; 
}