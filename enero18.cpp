#include <iostream>
#include <string>
using namespace std; 

int main(){
  
  string s1, s2, s3; 
  cout << "dame s1 "; 
  getline(cin, s1); 
  cout << "dame s2 "; 
  getline(cin, s2); 
  s3 = s1 + " " + s2; 
  cout << s3; 
  
  /*string str{"Hyper Text Markup Language"}; // s1 = "Hyper Text Markup Language" 

  for(int i = 0; i < str.length(); i++){
    if(i == 0){
      cout << str[i];
    }
    if(str[i]==' '){
      cout << str[i+1];
    }
  }*/

  return 0; 
}
