#include <iostream>
#include <string>

using namespace std;

// #include "Reloj.h"
#include "Eventos.h"

/* Escribe la clase Evento que tenga como atributos
Hora de inicio (de tipo Reloj)
Duración (de tipo int, representa los minutos que dura)
Asunto (de tipo string)
Agrega un constructor default y método de acceso y modificación para cada atributo.
Escribe ahora una aplicación que permita dar de alta varios eventos (en un arreglo de objetos) 
y luego los muestre en la pantalla.
NOTA: No debes usar un print para la clase Evento. */

int main(void){

    Eventos arrEventos[3];
    int hora, minutos, duracion, i = 0; string asunto; 

    for(; i < 3; i++){
        cout << "Dame la hora del evento: "; cin >> hora;
        cout << "Dame los minutos del evento: "; cin >> minutos;
        Reloj reloj(hora, minutos); // añadir setHora setMinu
        cout << "Dame la duración del evento: "; cin >> duracion; 
        cout << "Dame el asunto: "; cin.ignore(); getline(cin, asunto);
        Eventos e(reloj, duracion, asunto);
        arrEventos[i] = e;
    }

    i = 0;

    for(Eventos &eventos: arrEventos){
        cout << "Para el evento " << i+1 << ": \n" << "La hora de inicio es: " << arrEventos[i].getHoraInicio().getHora() << ":" << arrEventos[i].getHoraInicio().getMinu() << endl; 
        cout << "La duracion es: " << arrEventos[i].getDuracion() << endl; 
        cout << "El asunto es: " << arrEventos[i].getAsunto() << endl; 
        i++;
    }

    return 0; 
}