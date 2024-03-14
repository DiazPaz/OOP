#include <iostream>
#include <stdlib.h>

using namespace std;
int main()
{
  system("cls"); 
  // char arr[20];
  int arr[10] = {1,2,3};
  int z = 0;
  for(int i = 0; i < 10; i++){
      if(arr[i] != '\0')
        z++;
  }
  /* for(i = 0; i < 10; i++) {
    *(arr + i) = 65 + i;
    // arr[i] = 65 + i;  ES LO MISMO
  }
  *(arr + i) = '\0';0x5ffe98
  cout << arr; */

  cout << z << endl;

  char st[] = "ABCD";
  for(int i = 0; st[i] != '\0'; i++) {
    // letra del arreglo, se imprime el valor hexadecimal de la letra correspondiente del arreglo + i, se imprime la posición del caracter + i, st[i] == i[st]
     cout << st[i] << *(st)+i << *(i+st) << i[st];
  }

  return 0;
}