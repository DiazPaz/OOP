#include <iostream>
using namespace std; 

int main(void)
{
    int contador = 10;
    int duraciones[contador] = {2,4,6,2,1,5,9,7,1,4};
    int aux; 
    for(int i = 0; i < contador; i++)
    {
        for(int j = 0; j < contador; j++)
        {
            if(duraciones[i] < duraciones[j])
            {
                aux = duraciones[j];
                duraciones[j] = duraciones[i];
                duraciones[i] = aux; 
            }
        }
    }

    for(int i = 0; i < contador; i++)
        cout << duraciones[i] << endl;

    return 0;
}