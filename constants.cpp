#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>

using namespace std; 

void printCharacters(const char *sPtr){
  for(; *sPtr != '\0'; ++sPtr){
    cout << *sPtr; 
  }
}

int main(void){
  system("clear");  
  char string[10]; 
  cout << "Input a string: "; cin >> string; 
  printCharacters(string);
  getchar();
}

