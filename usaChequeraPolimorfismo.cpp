#include <iostream>
using namespace std;

#include "Chequera.h"

int main()

{

    CtaBanc *listaCtas[20];

    int sizeCtas;

    char tipoCta;

    int numCta;

    double saldoI, com, dinero;

    char opcion;

   
    do{

        cout << "Cuantas cuentas bancarias hay? ";

        cin >> sizeCtas;
        
    }while(sizeCtas > 20 || sizeCtas < 0);
   

    for (int c = 0; c < sizeCtas; c++)

    {

        cout << "quieres una cuenta bancaria o de cheques? (b o c) ";

        cin >> tipoCta;

       

        cout << "Numero de cuenta? ";

        cin >> numCta;

       

        cout << "Saldo inicial? ";

        cin >> saldoI;

       

        if (tipoCta == 'c')

        {
            cout << "Comision por hacer retiro? ";

            cin >> com;

            listaCtas[c] = new Chequera(numCta, saldoI, com);
        }
        
        if (tipoCta == 'b')

        {

            listaCtas[c] = new CtaBanc(numCta, saldoI);
        }

    }

    do

    {

        cout << "Menu de opciones " << endl;

        cout << endl;

        cout << "a) depositar " << endl;

        cout << "b) retirar " << endl;

        cout << "c) consultar saldo " << endl;

        cout << "d) terminar " << endl;

        cout << "opcion ->";

        cin >> opcion;

       
        int cont = 0; 

        switch (opcion) {

            case 'a':

            {

                cout << "teclea el numero de cuenta ";

                cin >> numCta;

                cout << "cuando vas a depositar? ";

                cin >> dinero;

                int i = 1;
                for(i; i < sizeCtas+1; i++)
                {
                    if(listaCtas[i-1]->getNumCuenta() == numCta)
                    {
                        listaCtas[i-1]->deposita(dinero);
                        break;
                    } 
                }

                if(i > sizeCtas)
                    cout << "Cuenta no encontrada.\n";

                break;

            }

               

            case 'b':

            {

                cout << "teclea el numero de cuenta ";

                cin >> numCta;

                cout << "cuando vas a retirar? ";

                cin >> dinero;

                int i = 1;
                for(i; i < sizeCtas+1; i++)
                {
                    if(listaCtas[i-1]->getNumCuenta() == numCta)
                    {
                        if(listaCtas[i-1]->retira(dinero))
                        {
                            break;
                        } else {
                            cout << "Fondos insuficientes. \n";
                        }
                    } 
                }

                if(i > sizeCtas)
                    cout << "Cuenta no encontrada.\n";

                break;

            }

               

            case 'c':

            {

                cout << "teclea el numero de cuenta ";

                cin >> numCta;

                int i = 1;
                for(i; i < sizeCtas+1; i++)
                {
                    if(listaCtas[i-1]->getNumCuenta() == numCta)
                    {
                        listaCtas[i-1]->mostrar();
                        break;
                    } 
                }

                if(i > sizeCtas)
                    cout << "Cuenta no encontrada.\n";

                break;

            }

        }

       

    } while (opcion != 'd');

   

    return 0;

}