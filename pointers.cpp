#include <iostream>
#include <stdio.h>
#include <cstdlib>

int main(void){
  
  system("clear"); 

  int a = 7; 
  int *aPtr = &a; 

  std::cout << "the address of 'a' is " << &a << "\n"; 
  std::cout << "the value of 'aPtr' is " << aPtr << "\n";

  std::cout << "the value of 'a' is " << a << "\n";
  std::cout << "the value of '*aPtr' is " << *aPtr << "\n"; 
  
  std::cout << "&*aPtr = " << &*aPtr << "\n"; 
  std::cout << "*&aPtr = " << *&aPtr; 

  getchar(); 

}
