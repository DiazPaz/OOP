#include <iostream>
#include <stdio.h>

int main(void){

  int a = 7; 
  int *aPtr = &a; 

  std::cout << "the address of 'a' is " << &a << "\n"; 
  std::cout << "the value of 'aPtr' is " << aPtr << "\n";

  std::cout << "the value of 'a' is " << a << "\n";
  std::cout << "the value of '*aPtr' is " << *aPtr << "\n"; 
  
  std::cout << "&*aPtr = " << &*aPtr << "\n"; 
  std::cout << "*&aPtr = " << *&aPtr; 

}
