#include <iostream>
using namespace std; 

int main(void)
{

    int arr[10], num1, num2, i;

    try
    {
        cout << "cantidad de numeros: ";
        cin >> num2; 
        for(i = 0; i < num2; i++)
        {
            if(i<11)
            {
                cin >> num1; 
                arr[i] = num1; 
            }
            else 
                throw i; 
        }
    }
    catch(int e)
    {
        cout << "\nException occurred. Index out of bounds.\n";
    }
    
    cout << endl; 

    system("pause");    

    cout << endl;

    try
    {
        for(i = 0; i < num2; i++)
        {
            if(i<10)
            {
                cout << arr[i] << endl;
            }
            else 
                throw i; 
        }
    }
    catch(int e)
    {
        cout << "Exception occurred. Index out of bounds." << '\n';
    }
    cout << endl; 

    system("pause");    

    return 0; 
}