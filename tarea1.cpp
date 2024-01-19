
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fun(int** a, int b, int c){
  int emp = 0, exa = 0, aux; 
  for(int i = 0; i < b; i++){
    aux = a[i][0];
    for(int j = 0; j < c; j++){
      if(aux <= a[i][j]){
        aux = a[i][j];
        emp = j+1;
        exa = i+1; 
      }
    }
    cout << "El empleado " << emp << " tuvo la calificacion mas alta del examen " << exa << ".\n";
    cout << "Calif: " << aux << "\n";
  }
}


int main(){
  int n, m;                    
  srand(time(NULL)); 
  
  do{
    cout << "\nEscriba el nUmero de examenes:"; cin >> n;
  }while((n<=0)||(n>10));
   do{
    cout << "Escriba el nUmero de clientes:"; cin >> m;
  }while((m<=0)||(m>10));  
  
  int** arr = new int*[n];
  for (int i = 0; i < n; i++) {
      arr[i] = new int[m];
  } 

  cout << "\n";
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      arr[i][j] = 1+rand()%100; 
    }
  } 
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout<<arr[i][j]<<"\t";
    }
    cout << "\n";
  }
  
  fun(arr, n, m); 

  for (int i = 0; i < n; i++) {
    delete[] arr[i];
  }
  delete[] arr;

  return 0;
}
