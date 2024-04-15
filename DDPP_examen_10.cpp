#include<iostream>
using namespace std;
int main(){
float contH = 0.0, contM = 0.0, altura, promAltHom = 0.0, promAltMuj = 0.0, altMayHom, altMayMuj, promTotal = 0.0;
int numAtletas; 
char genero; 

do{
cout<<"\nDigite el número de atletas: "; cin>>numAtletas; 
if(numAtletas<=0){
    cout<<"Digite un número mayor a cero.\n"; 
}
}while(numAtletas<=0);

for(int i = 1; i <= numAtletas; i++){

    do{
        cout<<"Seleccione el género (h/m): "; cin>>genero; 
        if((genero!='h')&&(genero!='m')){
            cout<<"Seleccione 'h' o 'm'.\n"; 
        }
    }while((genero!='h')&&(genero!='m'));

    do{
    cout<<"\nDigite la altura: "; cin>>altura; 
    if((altura<1.5)||(altura>2.0)){
        cout<<"Digite una altura entre 1.5 y 2.0.\n"; 
    }
    }while((altura<1.5)||(altura>2.0));

    if(genero == 'h'){
        contH += 1.0; 
        if(i==1){
            altMayHom = altura; 
        }else if(altMayHom<altura){
            altMayHom = altura; 
        }
        promAltHom += altura; 
    }

    if(genero == 'm'){
        contM += 1.0; 
        if(i==1){
            altMayMuj = altura; 
        }else if(altMayMuj<altura){
            altMayMuj = altura; 
        }
        promAltMuj += altura; 
    }

}
promAltHom = promAltHom/(contH*1.0);
promAltMuj = promAltMuj/(contM*1.0);
promTotal = (promAltHom+promAltMuj)/numAtletas;

cout<<"\nPromedio total de alturas: "<<promTotal<<endl;
cout<<"\nPromedio de Hombres: "<<promAltHom<<endl;
cout<<"\nPromedio de Mujeres: "<<promAltMuj<<endl; 
cout<<"\nNúmero de hombres: "<<contH<<endl;
cout<<"\nNúmero de mujeres: "<<contM<<endl;
cout<<"\nAltura mayor de hombres: "<<altMayHom;
cout<<"\nAltura mayor de mujeres: "<<altMayMuj;



    return 0; 
}