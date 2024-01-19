#include <iostream>
#include <math.h>

int main(){
  double x, res; int n, coef[n]; char continuar;
  while(true){
  std::cout<<"Dime el valor de 'x': ";
  std::cin>>x;
  std::cout<<"Dime el número de coeficientes del polinomio: ";
  std::cin>>n; 
  for(int i = 0; i < n; i++){
    std::cout<<"Dime el valor del coeficiente "<<i+1<<": ";
    std::cin>>coef[i];
  }
  std::cout<<coef[0];
  res = coef[0];
  for(int i = 1; i < n; i++){
    std::cout<<"+"<<coef[i]<<"X^"<<i;
    res=res+coef[i]*pow(x,i); 
  }
  std::cout<<"="<<res;
  
  std::cout<<"\nQuieres seguir? y/n\n";
  std::cin>>continuar;
  if(continuar == 'n'){
    return false;
  }

  }
  return 0;
}
