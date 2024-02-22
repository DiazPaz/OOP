#include <iostream> 
#include <fstream>
#include <string>

using namespace std; 

int main(void){

    int iArr[50];

    ifstream fIn("examen.txt");
    int cont = 0, suma = 0, num; 
    string frase; 

    ofstream fOut("examenSalida.txt");
    
    while(!fIn.eof()){
        getline(fIn, frase);
        if(frase[0] == 'c'){
            fOut << (frase[2]-'0') + (frase[4]-'0')<< endl;
        }
    } fIn.close(); fOut.close();

    ifstream fInn("examenSalida.txt");
    while(!fInn.eof()){
        fInn >> num; 
        iArr[cont]=num; 
        cont++;
    }
    for(int i = 0; i < 50; i++){
        cout << iArr[i] << endl; 
    }

    return 0; 
}