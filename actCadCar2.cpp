#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char palabra1[50], palabra2[50], palabra3[50];

    cout << "Ingrese la primera palabra: ";
    cin >> palabra1;

    cout << "Ingrese la segunda palabra: ";
    cin >> palabra2;

    cout << "Ingrese la tercera palabra: ";
    cin >> palabra3;

    char temp[50];

    if (strcmp(palabra1, palabra2) > 0) {
        strcpy(temp, palabra1);
        strcpy(palabra1, palabra2);
        strcpy(palabra2, temp);
    }

    if (strcmp(palabra1, palabra3) > 0) {
        strcpy(temp, palabra1);
        strcpy(palabra1, palabra3);
        strcpy(palabra3, temp);
    }

    if (strcmp(palabra2, palabra3) > 0) {
        strcpy(temp, palabra2);
        strcpy(palabra2, palabra3);
        strcpy(palabra3, temp);
    }

    cout << "Palabras en orden alfabético: " << palabra1 << ", " << palabra2 << ", " << palabra3 << endl;

    return 0;
}