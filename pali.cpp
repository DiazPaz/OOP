#include <iostream>
#include <string>

using namespace std;

int main(){

  string s1;
  cout << "Dame el string: "; 
  getline(cin, s1);

  for(int i = 0; i < s1.length(); i++){
    if(s1[i] == ' '){
      s1.erase(i,1); 
    }
  }

  cout << s1 << "\n";

  for(char &c: s1){
    c = toupper(c); 
  }
  cout << s1 << "\n";
  int i = 0, longitud = s1.length()-1; 
  bool found = true; 

  for(int i = 0; i < longitud/2; i++){
    if(found){
      if(s1[longitud] == s1[i]){
        i++;
        longitud--;
      } else {
        found = false;
      }
    }
  }

  if(found){
    cout << s1 << " es palindromo."; 
  } else {
    cout << s1 << " no es palindromo."; 
  }
    
  return 0; 
}
