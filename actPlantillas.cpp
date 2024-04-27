#include <iostream> 
using namespace std; 

template <class T>
void muestraCol(T matriz[10][10], int size, int col)
{
    for(int i = 0; i < size; i++)
        cout << matriz[i][col] << endl; 
}

template <class T>
void muestraMatriz(T matriz[10][10], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl; 
    }
}

template <class T>
T datoMayor(T matriz[10][10], int size)
{
    T mayor = matriz[0][0]; 
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(matriz[i][j] > mayor)
                mayor = matriz[i][j];
        }
    }
    return mayor; 
}

int main(void)
{

    double dMatNum[10][10]  = { {2.5, 3.8, 4.7},

                                {2.2, 4.4, 6.6},

                                {2.5, 3.7, 5.9}};

    string sMatLet[10][10]  = {{"a1", "b2", "c3"},

                            {"dado", "lente", "tren"},

                             {"gato", "iguana", "canario"}};

    int iSize = 3;

    int iColumna;

    double dMayor;

    string sMayor;

    cout << endl << "Cual columna quieres copiar ";

    cin >> iColumna;

    cout << "primera matriz "<< endl;

    muestraMatriz(dMatNum, iSize);

    cout << "Columna de la primera matriz son " << endl;

    muestraCol(dMatNum, iSize, iColumna);

    cout << "el dato mayor de la matriz es " << endl;

    dMayor = datoMayor(dMatNum, iSize);

    cout << dMayor << endl;

    cout << "segunda matriz "<< endl;

    muestraMatriz(sMatLet, iSize);

    cout << "Columna de la segunda matriz son " << endl;

    muestraCol(sMatLet, iSize, iColumna);

    cout << "el dato mayor de la matriz es " << endl;

    sMayor = datoMayor(sMatLet, iSize);

    cout << sMayor << endl;         

    return 0; 
}