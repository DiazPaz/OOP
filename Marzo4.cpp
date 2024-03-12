#include <iostream>
using namespace std;
int main()
{
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

  cout << z;

  char st[] = "ABCD";
  for(int i = 0; st[i] != NULL; i++) {
     cout << st[i] << *(st)+i << *(i+st) << i[st];
  }

  return 0;
}