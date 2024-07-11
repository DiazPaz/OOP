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

    int n = 0, m = 0; 

    string cveServicio, descripcion, costoX15min, costoXHr, clave, idClienteStr;
    int tiempoMax, cantMaxPersonas, reservas = 0, duracionAux, contador;
    char TipoServ, conInstructor;
    bool conInstructorBool, bandera = false, bandera2 = false;
    double cost;

    ifstream inServicios("Servicios.txt");
    ifstream inReservas("Reserva.txt");

    ofstream outReservas;

    if (!inServicios || !inReservas) {
        cout << "No se pudo abrir el archivo.\n";
        return 1;
    }
    while(inServicios >> cveServicio >> tiempoMax >> TipoServ)
    {
        if ( TipoServ == 'C' || TipoServ == 'E' || TipoServ == 'B' ) 
        {
            inServicios >> costoX15min >> conInstructor;
            getline(inServicios, descripcion);
            cost = stod(costoX15min); 
            if(conInstructor == 'T')
                conInstructorBool = true; 
            else if(conInstructor == 'F')
                conInstructorBool = false;
            servicios[n] = new Aparato(cveServicio, tiempoMax, TipoServ, cost, conInstructorBool, descripcion);
            n++; 
        } 
        else if ( TipoServ == 'T' || TipoServ == 'F' || cveServicio[0] == 'V' ) 
        {
            inServicios >> costoXHr >> cantMaxPersonas;
            getline(inServicios, descripcion);
            cost = stod(costoXHr); 
            servicios[n] = new Cancha(cveServicio, tiempoMax, TipoServ, cost, cantMaxPersonas, descripcion);
            n++;
        }
    }
    int idCliente, hora, minutos, duracionMinutos;
    while(inReservas >> cveServicio >> hora >> minutos >> duracionMinutos >> idCliente)
    {
        Hora horaInicio(hora, minutos);
        reservaciones[m] = new Reserva(cveServicio, idCliente, horaInicio, duracionMinutos);
        m++;
        reservas++;
    }
    char opcion; 
    do
    {
        Hora horaAux;
        cout << "\nELIGA UNA OPCION:\n";
        cout << "a. Consultar la lista de Servicios\nb. Consultar la lista de reservaciones\nc. Consultar las reservaciones de una servicio dado\nd. Consulta las reservaciones de una hora especifica\ne. Hacer una reservacion\nf. Terminar\n";
        cin >> opcion; 
        switch(opcion)
        {
            case 'a':
                cout << endl; 
                for(int i = 0; i < (sizeof(servicios) / sizeof(servicios[0])); i++)
                {
                    servicios[i]->muestra();
                    cout << ">>-->-->--<--<-<<\n";
                    cout << endl; 
                }
                system("pause && cls");
                break; 
            case 'b':
                cout << endl; 
                for(int i = 0; i < reservas; i++)
                {
                    Hora h = reservaciones[i]->getHoraInicio(); 
                    Hora f = h + reservaciones[i]->getDuracion();
                    cout << "Clave de Servicio: " << reservaciones[i]->getClaveServicio() << "\nID del cliente: " << reservaciones[i]->getIdCliente() << "\nHora de inicio de reservacion: " << h << " || Hora de terminacion: " << f << endl << "Duracion (en minutos): " << reservaciones[i]->getDuracion() << endl;
                    for(int j = 0; j < (sizeof(servicios) / sizeof(servicios[0])); j++)
                    {
                        if(reservaciones[i]->getClaveServicio() == servicios[j]->getClave())
                        {
                            servicios[j]->muestra();
                            cout << "Precio final: $" << servicios[j]->calculaCosto(reservaciones[i]->getDuracion()) << endl;
                            cout << ">>-->-->--<--<-<<\n";
                            cout << endl; 
                        }
                    }
                }
                system("pause && cls");
                break; 
            case 'c':
                do
                {
                    cout << "\nDame la clave del servicio: "; 
                    cin >> clave; cout << endl; 
                    for(int i = 0; i < (sizeof(servicios) / sizeof(servicios[0])); i++)
                    {
                        if(servicios[i]->getClave() == clave)
                        {
                            cout << "Datos del servicio:\n";
                            servicios[i]->muestra();
                            cout << endl << "Reservaciones del servicio:\n"; 
                            
                            for(int j = 0; j < reservas; j++)
                            {
                                if(reservaciones[j]->getClaveServicio() == servicios[i]->getClave())
                                {
                                    Hora h = reservaciones[j]->getHoraInicio();
                                    Hora f = h + reservaciones[j]->getDuracion();
                                    cout << "- Hora de inicio de reservacion: " << h << " || Hora de terminacion: " << f << endl << "Duracion (en minutos): " << reservaciones[j]->getDuracion() << endl << endl; 
                                }
                            }
                            bandera = true; 
                        }
                    }
                    if(bandera == false)
                        cout << "\nClave no existente. Intente otra vez.\n";
                }while(bandera == false);
                bandera = false; 
                system("pause && cls");
                break; 
            case 'd':
                do
                {
                    cout << "\nDame la hora que buscas: ";
                    cin >> horaAux; 
                    for(int i = 0; i < reservas; i++)
                    {
                        Hora h = reservaciones[i]->getHoraInicio();
                        Hora f = h + reservaciones[i]->getDuracion();
                        int d = reservaciones[i]->getDuracion();
                        if((h == horaAux) || ((horaAux >= h) && (horaAux <= (h + d))))
                        {
                            cout << "\nExiste reservacion a la hora seleccionada: \n\n";
                            for(int j = 0; j < (sizeof(servicios) / sizeof(servicios[0])); j++)
                            {
                                if(reservaciones[i]->getClaveServicio() == servicios[j]->getClave())
                                {
                                    servicios[j]->muestra();
                                    cout << "\nHora de inicio de reservacion: " << h << " || Hora de terminacion: " << f << endl << "| Duracion (en minutos): " << reservaciones[i]->getDuracion() << endl;
                                    cout << "------------------------------\n";
                                }
                            }
                            bandera = true; 
                        }
                    }
                    if(bandera == false)
                    {
                        cout << "\nNo existen reservaciones en este horario.\n";
                        bandera = true; 
                    }
                }while(bandera == false);
                bandera = false; 
                system("pause && cls");
                break; 
            case 'e':
            {
                // en esta opción pregunta al usuario el id del cliente y la
                // clave del servicio, así como la hora a la que desea reservar y por cuantos minutos lo
                // desea reservar.
                do
                {
                    cout << "\nDame el ID de cliente: ";
                    cin >> idClienteStr; 
                    bandera = true; 
                    for(char c: idClienteStr)
                        if(!isdigit(c))
                            bandera = false; 
                    if(bandera == false) 
                        cout << "\nID inexistente. Introduce un valor numerico. \n"; 
                }while(bandera == false); 
                
                bandera = false; 
                int idClienteInt = stoi(idClienteStr); 
                do
                {
                    cout << "\nDame la clave del servicio que deseas reservar: "; 
                    cin >> clave; 
                    for(int i = 0; i < (sizeof(servicios) / sizeof(servicios[0])); i++)
                    {
                        if(servicios[i]->getClave() == clave)
                        {
                            cout << "Datos del servicio:\n";
                            servicios[i]->muestra();
                            bandera = true; 
                        }
                    }
                    if(bandera == false)
                        cout << "\nClave no existente. Intente otra vez.\n";
                }while(bandera == false);
                bandera = false;
                Hora horaInicioAux[50];
                bool bandera3, bandera4;
                do  
                {
                    bandera4 = false,
                    bandera3 = false;
                    do
                    { 
                        cout << "\nDame la duracion de tu reservacion en minutos: ";
                        cin >> duracionAux; 
                        int i = 0, aux; 
                        for(i; i < (sizeof(servicios) / sizeof(servicios[0])); i++)
                        {
                            if(clave == servicios[i]->getClave())
                            {
                                aux = i;
                                if(duracionAux <= servicios[i]->getTiempo() && duracionAux > 0)   
                                    bandera3 = true;
                            }
                        }
                        char continuarChar = '\0';
                        if(duracionAux > servicios[aux]->getTiempo())
                        {
                            cout << "\nDuracion excede el tiempo maximo para la reservacion: " << servicios[aux]->getTiempo() << endl;
                            cout << "Desea continuar con la reservacion? (s/n)\n"; 
                            do
                            {
                                cin >> continuarChar; 
                                if(continuarChar == 'n')
                                {
                                    bandera3 = true;
                                    bandera4 = true; 
                                }
                                if(continuarChar != 's' && continuarChar != 'n')
                                    cout << "Opcion no valida. Intente de nuevo. (s/n)\n";
                            }while(continuarChar != 's' && continuarChar != 'n' && bandera3 == false);
                        }
                        if(duracionAux <= 0)
                        {
                            cout << "\nDuracion invalida."<< endl;
                            do
                            {
                                cout << "Desea continuar con la reservacion? (s/n)\n"; 
                                cin >> continuarChar; 
                                if(continuarChar == 'n')
                                {
                                    bandera3 = true;
                                    bandera4 = true; 
                                }
                                if(continuarChar != 's' && continuarChar != 'n')
                                    cout << "Opcion no valida. Intente de nuevo. (s/n)\n";
                            }while(continuarChar != 's' && continuarChar != 'n' && bandera3 == false);
                        }
                    }while(bandera3 == false);
                    if(!bandera4)
                    {
                        contador = 0;
                        cout << "\nDame la hora que buscas: ";
                        cin >> horaAux;  
                        // Almaceno todas las horas del mismo aparato/cancha en un mismo arreglo
                        for(int i = 0; i < reservas; i++)
                        {
                            if(reservaciones[i]->getClaveServicio() == clave)
                            {
                                Hora h = reservaciones[i]->getHoraInicio();
                                horaInicioAux[contador] = h;
                                contador++; 
                            }
                        }
                        // Acomodo todas las horas de menor a mayor
                        Hora aux; 
                        for(int i = 0; i < contador; i++)
                        {
                            for(int j = 0; j < contador; j++)
                            {
                                if(horaInicioAux[i] <= horaInicioAux[j])
                                {
                                    aux = horaInicioAux[j];
                                    horaInicioAux[j] = horaInicioAux[i];
                                    horaInicioAux[i] = aux; 
                                }
                            }
                        } 
                        // La hora de inicio de la reservación nueva tiene que ser mayor a la hora final de la reservación previa 
                        // y la hora de fin de la reservación nueva tiene que ser menor que la hora de inicio de la reservación previa
                        for(int j = 0; j < contador; j++)
                        {
                            for(int i = 0; i < reservas; i++)
                            {
                                Hora h = reservaciones[i]->getHoraInicio();
                                int d = reservaciones[i]->getDuracion();
                                // Esta condicion es para poder relacionar la duracion de la reservacion con el arreglo de horas iniciales el cual ya esta acomodado
                                if((horaInicioAux[j] == h) && (clave == reservaciones[i]->getClaveServicio()))
                                {  
                                    Hora h1 = horaInicioAux[j], h2 = horaInicioAux[j+1];
                                    // Esta condicion es para poder ubicar reserviaciones entre dos reservaciones  
                                    if((horaAux >= (h1 + d)) && ((horaAux + duracionAux) <= h2))
                                    {
                                        reservaciones[reservas] = new Reserva(clave, idClienteInt, horaAux, duracionAux);
                                        cout << "\nHorario disponible. Reservacion creada.\n";
                                        for(int k = 0; k < (sizeof(servicios) / sizeof(servicios[0])); k++)
                                        {
                                            if(reservaciones[i]->getClaveServicio() == servicios[k]->getClave())
                                                cout << "Precio final: $" << servicios[k]->calculaCosto(duracionAux) << endl;
                                        }
                                        reservas++; 
                                        bandera = true; 
                                    }
                                    // Esta condicion es para poder ubicar reservaciones al inicio del arreglo, siendo la mas temprana en la comparacion
                                    else if(((horaAux + duracionAux) <= h1) && (j == 0))
                                    {
                                        reservaciones[reservas] = new Reserva(clave, idClienteInt, horaAux, duracionAux);
                                        cout << "\nHorario disponible. Reservacion creada.\n";
                                        for(int k = 0; k < (sizeof(servicios) / sizeof(servicios[0])); k++)
                                        {
                                            if(reservaciones[i]->getClaveServicio() == servicios[k]->getClave())
                                                cout << "Precio final: $" << servicios[k]->calculaCosto(duracionAux) << endl;
                                        }
                                        reservas++; 
                                        bandera = true;
                                    }
                                    // Esta condicion es para poder ubicar reservaciones al final del arreglo, siendo la mas tarde en la comparacion
                                    else if((horaAux >= (h1 + d)) && (j == (contador - 1)))
                                    {
                                        reservaciones[reservas] = new Reserva(clave, idClienteInt, horaAux, duracionAux);
                                        cout << "\nHorario disponible. Reservacion creada.\n";
                                        for(int k = 0; k < (sizeof(servicios) / sizeof(servicios[0])); k++)
                                        {
                                            if(reservaciones[i]->getClaveServicio() == servicios[k]->getClave())
                                                cout << "Precio final: $" << servicios[k]->calculaCosto(duracionAux) << endl;
                                        }
                                        reservas++; 
                                        bandera = true; 
                                    }
                                }
                            }
                        }
                        // si no existen reservaciones 
                        if(contador == 0)
                        {
                            reservaciones[reservas] = new Reserva(clave, idClienteInt, horaAux, duracionAux);
                            cout << "\nHorario disponible. Reservacion creada.\n";
                            for(int k = 0; k < (sizeof(servicios) / sizeof(servicios[0])); k++)
                                if(clave == servicios[k]->getClave())
                                    cout << "Precio final: $" << servicios[k]->calculaCosto(duracionAux) << endl;
                            reservas++; 
                            bandera = true;    
                        }
                        if(bandera == false)
                            cout << "\nHorario no disponible. Elige un horario distinto.\n";
                    }
                }while(bandera == false && bandera4 == false);
                bandera = false;  
                bandera3 = false; 
                bandera4 = false; 
                system("pause && cls");
                break; 
            }
            case 'f':
                outReservas.open("Reserva.txt");
                for(int i = 0; i < reservas; i++)
                    outReservas << reservaciones[i]->getClaveServicio() << " " << reservaciones[i]->getHoraInicio().getHora() << " " << reservaciones[i]->getHoraInicio().getMin() << " " << reservaciones[i]->getDuracion() << " " << reservaciones[i]->getIdCliente() << "\n";
                break; 
            default: 
                cout << "\nOpcion invalida. Intente de nuevo.\n";
                system("pause && cls");
                break; 
        }
    }while(opcion != 'f');                    
    inServicios.close();
    inReservas.close();
    return 0; 
}