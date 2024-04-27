#include <fstream>
#include <iostream>
#include <string>
using namespace std; 

#include "Aparato.h"
#include "Cancha.h"
#include "Reserva.h"

int main(void)
{

    Reserva *reservaciones[50];
    Servicio *servicios[20];

    string cveServicio, descripcion;
    int tiempoMax, aux;
    char TipoServ;
    double costoX15min;
    char conInstructor;

    ifstream inServicios("Servicios.txt");
    ifstream inReservas("Reserva.txt");

    if (!inServicios || !inReservas) {
        cout << "No se pudo abrir el archivo.\n";
        return 1;
    }

    while(inServicios >> cveServicio >> tiempoMax >> TipoServ >> costoX15min >> conInstructor)
    {
        getline(inServicios, descripcion);
        cout << cveServicio << " " << tiempoMax << " " << TipoServ << " " << costoX15min << " " << conInstructor << " " << descripcion.substr(aux+1) << endl;
    }

    cout << endl; 

    string claveServicio, idCliente;
    int hora, minutos, duracionMinutos;
    
    while(inReservas >> claveServicio >> hora >> minutos >> duracionMinutos >> idCliente)
    {
        cout << claveServicio << " " << hora << " " << minutos << " " << duracionMinutos << " " << idCliente << endl;
    }

    inServicios.close();
    inReservas.close();

    return 0; 
}