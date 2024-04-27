#include <iostream> 
using namespace std; 

template <class T>
void copiaRen(T matriz[10][10], int r, int c, int ren, T arr[], int &arrSize)
{
    for(int c1 = 0; c1 < c; c1++)
        arr[c1] = matriz[ren][c1]; 
    arrSize = c; 
}

template <class T>
void copiaCol(T matriz[10][10], int r, int c, int col, T arr[], int &arrSize)
{
    for(int r1 = 0; r1 < r; r1++)
        arr[r1] = matriz[r1][col]; 
    arrSize = r; 
}

template <class T>
void cargaMatriz(T matriz[10][10], int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << "Dame el valor [" << i << "][" << j << "]: ";
            cin >> matriz[i][j]; 
        }
    }
}

template <class T>
void muestraMatriz(T matriz[10][10], int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << matriz[i][j] << " "; 
        }
        cout << endl; 
    }
}

int main(void)
{
    int mat[10][10], arr[10]; 

    int ren, col; 
    cout << "Cuantos renglones: "; cin >> ren; 
    cout << "Cuantas columnas: "; cin >> col; 
    cargaMatriz(mat, ren, col);
    muestraMatriz(mat, ren, col);

    int r, c, size;
     
    cout << "Cual renglon quieres copiar: "; cin >> r; 
    copiaRen(mat, ren, col, r-1, arr, size); 
    for(int i = 0; i < size; i++)
        cout << arr[i] << endl; 
    cout << endl; 
    
    cout << "Cual columna quieres copiar: "; cin >> c;
    copiaCol(mat, ren, col, c-1, arr, size); 
    for(int i = 0; i < size; i++)
        cout << arr[i] << endl; 
    cout << endl; 

    return 0; 
}