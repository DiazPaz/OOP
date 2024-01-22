#include <iostream> 
#include <string>

using namespace std; 

int main(){

  string lastName, primer, segundo; 
  
  cout << "Apellido: \n"; 
  getline(cin, lastName); 
  
  int pos = lastName.find(" ");
  primer = lastName.substr(0, pos);
  string aux = lastName.substr(pos+1, lastName.length()); 
  
  int pos2 = aux.find(" "); 
  segundo = aux.substr(0, pos2);

  cout << primer+segundo << "\n";

  lastName.erase(0, pos+pos2+1); 
  cout << lastName << "\n";

  return 0;
}
