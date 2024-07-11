#include<iostream>
#include<string>
#include <stdio.h>
#include <string.h>
#include <conio.h>

using namespace std;
const int MAX_USUARIOS = 10;

void titulo(string title) {
     cout<<"                        #     #  ######  #        ######   ######   ##   ##  ######\n";
     cout<<"                        #     #  #       #       #        #      #  # # # #  #     \n";
     cout<<"                        #  #  #  #####   #       #        #      #  #  #  #  ##### \n";
     cout<<"                        # # # #  #       #       #        #      #  #     #  #     \n";
     cout<<"                        ##   ##  ######  #######  ######   ######   #     #  ######\n";
     cout<<"                                             #######   ######\n";
     cout<<"                                                #     #      #\n";
     cout<<"                                                #     #      #\n";
     cout<<"                                                #     #      #\n";
     cout<<"                                                #      ######\n";
     cout<<"                     ######  #####  ##    #  ######       #####   #      #    #  #####\n";
     cout<<"                    #          #    # #   #  #            #    #  #      #    #  #    \n";
     cout<<"                    #          #    #  #  #  #####        #####   #      #    #  #####\n";
     cout<<"                    #          #    #   # #  #            #       #      #    #      #\n"; 
     cout<<"                     ######  #####  #    ##  ######       #       #####   ####   #####\n";
    }

int main (){

    string arreglo_usuarios[MAX_USUARIOS];
    int arreglo_cuentas[MAX_USUARIOS];
    double arreglo_calificaciones[MAX_USUARIOS];
    int numero_usuarios = 0;
    int opcion_menu;
    int usario;
    int g, k, totalF, subtotal, grantotal, c[100][6], np, precio, cant, r, producto;
    bool terminarpro = false;
    //varables contadoras

    int cuates = 0, pareja = 0, hotdog = 0, plus = 0, plusplus = 0, cinefilo = 0;

    int i, j, n, A[100][6], cantidad;
    char des[100][10] ={"\0"}, descrip[5][10]={"\0"};
   
    system("cls");
    bool bandera1 = false;
    string usuario = "", contraseNa = ""; 
    int intentos = 0, opcionM1;
    
    // Variables para las salas 

    char respuesta, boton,cliente,respuesta2, opcionPelicula = ' ';
    const int renglones = 4;
    const int columnas = 5;
    int totalSala1 =0, totalSala2=0, totalSala3=0, totalSala4=0, totalSala5=0;
    int totalCompra1=0, totalCompra2=0, totalCompra3=0, totalCompra4=0, totalCompra5=0;
    int numero, suma =0;
    int opcion, total, cant2, nboletos, Tboletos, fila, asiento, contandor, opcion2;
    int A1[renglones][columnas] = {0};
    int A2[renglones][columnas] = {0};
    int A3[renglones][columnas] = {0};  
    int A4[renglones][columnas] = {0}; 
    int A5[renglones][columnas] = {0};
    string B[renglones][columnas];
    string B2[renglones][columnas];
    string B3[renglones][columnas];
    string B4[renglones][columnas];
    string B5[renglones][columnas];

    string nombre, peli[5] = {"LOS CABALLEROS", "BATMAN INICIA", "TED", "LA MASCARA", "LOS 3 IDI0TAS"};

    // Variables para funciones 
    const int num_peliculas = 6;
    const int OPC_menuP = 5; 

    cout << "\n\n\nIMPORTANTE: ContarA con un total de 3 Intento para lo siguiente" << endl;

    //Para la contraseNa
    do{
        cout << "Intento numero: " << intentos + 1 << endl;
        cout << "\nFavor de ingresar el usuario: ";
        cin >> usuario;
        cout << "\nFavor de ingresar la contraseNa: ";
        cin >> contraseNa;
        cout << "\n";

        if ((contraseNa == "hernandez" || contraseNa == "perez") && (usuario == "miguel" || usuario == "roberto" )){
            bandera1 = true;
        } else {
            cout << "Usuario o ContraseNa incorrectos" << endl;
            intentos++;
        }

    } while ((bandera1 == false) && (intentos < 3));

    if (intentos >= 3){
        while (bandera1 == false){
            cout << "\n--------------------------------------------------------------" << endl;
            cout <<   "[ Has sobrepasado el limite de intentos, estAs bloqueado     ]" << endl;
            cout <<   "--------------------------------------------------------------" << endl;
            getch ();
            }
    }

    titulo("BIENVENIDOS A CINEPLUS");

    cout<< endl << "\nPRESIONA CUALQUIER TECLA PARA INGRESAR A CINE PLUS"<<endl;
    getch();

    int asientos[5] = {19,19,19,19,19}, op;
    do {
        cout << "------------" << endl;
        cout << "<<<<CINEPLUS>>>> " << endl;
        cout << " Menu principal " << endl;
        cout << " A. Mostrar cartelera " << endl;
        cout << " B. Comprar boletos " << endl;
        cout << " C. Comprar combos "<<endl;
        cout << " D. Cancelar asientos"<<endl;
        cout << " E. TICKETS " << endl;
        cout << " F. TERMINAR PROGRAMA" << endl;
        cout << "Que opciOn quiere?: ";
        cin >> boton;
        cout << endl;

        switch (boton){
            case 'A':
                cout << "--------------" << endl;
                cout << "1. LOS CABALLEROS " << endl;
                cout << "2. BATMAN INICIA " << endl;
                cout << "3. TED " << endl;
                cout << "4. LA MASCARA" << endl;
                cout << "5. LOS 3 IDI0TAS" << endl;
                cout << "Entrada: $100" << endl;
                cout << "Quieres ver horarios de las peliculas(s/n)?";
                cin>>respuesta2;
                if (respuesta2=='s'){
                    cout << "--------------" << endl;
                    cout << "1. LOS CABALLEROS " << endl;
                    cout << "2. BATMAN INICIA " << endl;
                    cout << "3. TED " << endl;
                    cout << "4. LA MASCARA" << endl;
                    cout << "5. LOS 3 IDI0TAS" << endl;
                    cout<<"Para que pelicula quieres ver horario? (responde con numero)";
                    cin>>opcion2;
                    switch(opcion2){
                        case 1:
                        cout<<"\n17:50 hrs"<<endl;
                        cout<<"\n19:45 hrs"<<endl;
                        cout<<"\n21:50 hrs"<<endl;
                        break;
                        case 2:
                        cout<<"\n16:35 hrs"<<endl;
                        cout<<"\n18:30 hrs"<<endl;
                        cout<<"\n20:15 hrs"<<endl;
                        break;
                        case 3:
                        cout<<"\n17:15 hrs"<<endl;
                        cout<<"\n19:10 hrs"<<endl;
                        cout<<"\n22:00 hrs"<<endl;
                        break;
                        case 4:
                        cout<<"\n17:30 hrs"<<endl;
                        cout<<"\n19:30 hrs"<<endl;
                        cout<<"\n21:30 hrs"<<endl;
                        break;
                        case 5:
                        cout<<"\n19:15 hrs"<<endl;
                        cout<<"\n21:35 hrs"<<endl;
                        cout<<"\n23:15 hrs"<<endl;
                        break;
                        default:
                        cout<<"\nERROR: OPCION NO VALIDA";
                    }

                    }while(respuesta2=='n'){
                        cout<<"DE ACUERDO :D"<<endl;
                        system("pause");
                    }
                    cout << "--------------" << endl;
                    system("pause");
            break;
            case 'B':
                // numero = 0;
                do {
                    cout << "--------------" << endl;
                    cout << "1. LOS CABALLEROS " << endl;
                    cout << "2. BATMAN INICIA " << endl;
                    cout << "3. TED" << endl;
                    cout << "4. LA MASCARA" << endl;
                    cout << "5. LOS 3 IDI0TAS" << endl;
                    cout << "Entrada: $100" << endl;
                    cout << "CuAl pelIcula quieres? " << endl;
                    cin >> opcionPelicula;
                } while (opcionPelicula != '1' && opcionPelicula != '2' && opcionPelicula != '3' && opcionPelicula != '4' && opcionPelicula != '5');

                op = opcionPelicula - '0';
                switch(opcionPelicula){
                    case '1'://///////////////////////////////////////////////////////////////////////////////////////////MIGUEL
                    totalCompra1 =0;
                    cout << "------------------- "<< endl;
                    cout << "Quedan " << asientos[op - 1] << " asientos" << endl;
                    cout << " [0] significa disponible y [X] significa ocupado " << endl;
                    cout << "\t";
                    do {
                        cout << "------------------- " << endl;
                        cout << "Quedan " << asientos[op - 1] << " asientos" << endl;
                        cout << " [0] significa disponible y [X] significa ocupado " << endl;
                        cout << "\t";
                        for (int i = 0; i < columnas; i++) {
                            cout << i << "\t";
                        }
                        cout << endl << endl;
                        for (int i = 0; i < renglones; i++) {
                            cout << i << "\t";
                            for (int j = 0; j < columnas; j++) {
                                cout << "[" << (A1[i][j] == 0 ? " " : "X") << "]" << "\t";
                            }
                            cout << endl;
                        }

                        int i, j;
                        do {
                            cout << "Escribe la coordenada del asiento que quieres reservar, FILA: ";
                            cin >> i;
                            cout << "Escribe la coordenada del asiento que quieres reservar, COLUMNA: ";
                            cin >> j;
                            if (i < 0 || i >= renglones || j < 0 || j >= columnas) {
                                cout << "Coordenadas fuera de los límites de la sala. Inténtalo de nuevo." << endl;
                            }
                        } while (i < 0 || i >= renglones || j < 0 || j >= columnas);

                        if (A1[i][j] == 0) {
                            A1[i][j] = 1;
                            cout << "Cómo te llamas? ";
                            cin >> B[i][j];
                            cout << "Tienes el asiento " << i << " " << j << endl;
                            // Actualiza el recuento de asientos disponibles
                            asientos[op - 1]--;
                        } else {
                            cout << "El asiento está ocupado." << endl;
                            continue;
                        }

                        // Preguntar si desea agregar otro asiento
                        cout << "\nDeseas agregar otro asiento? s/n (MÁXIMO 5) ";
                        cin >> respuesta;
                    } while (respuesta == 's' && asientos[op - 1] > 0);

                    cout << "Cuántos boletos compraste? ";
                    cin >> totalCompra1;
                    if (totalCompra1 < 1 || totalCompra1 > 5) {
                        cout << "Número de boletos incorrecto. Debe ser entre 1 y 5." << endl;
                        return 0;
                    } else {
                        totalSala1 +=totalCompra1;
                        cout << "\nTotal a pagar $" << totalCompra1 * 100 << endl;
                        cout << "QUE DISFRUTE LA FUNCIÓN :D" << endl;
                        // Aquí puedes realizar cualquier otra acción necesaria, como imprimir los detalles de los boletos, etc.
                    }
                    break;
                    case '2': 
                    totalCompra2 = 0;
                    cout << "------------------- "<< endl;
                    cout << "Quedan " << asientos[op - 1] << " asientos" << endl;
                    cout << " [0] significa disponible y [X] significa ocupado " << endl;
                    cout << "\t";
                    for (int m2 = 0; m2 < columnas; m2++) {
                        cout << m2 << "\t";
                    }cout << endl << endl;
                    for (int m2 = 0; m2 < renglones; m2++) {
                        cout << m2 << "\t";
                        for (int e2 = 0; e2 < columnas; e2++) {
                        cout << "[" << (A2[m2][e2] == 0 ? " " : "X") << "]" << "\t"; 
                        }
                        cout << endl;
                    }
                    int m2, e2;
                    do {
                        cout << "Escribe la coordenada del asiento que quieres reservar, FILA: ";
                        cin >> m2;
                        cout << "Escribe la coordenada del asiento que quieres reservar, COLUMNA: ";
                        cin >> e2;
                        if (m2 < 0 || m2 >= renglones || e2 < 0 || e2 >= columnas) {
                            cout << "Coordenadas fuera de los lImites de la sala. IntEntalo de nuevo." << endl;
                        }
                    } while (m2 < 0 || m2 >= renglones || e2 < 0 ||e2 >= columnas);
                    if (A2[m2][e2] == 0) {
                        A2[m2][e2] = 1; 
                        cout << "COmo te llamas? ";
                        cin >> B2[m2][e2]; 
                        cout << "Tienes el asiento " << m2 << " " << e2 << endl;
                    }else {
                        cout << "El asiento estA ocupado." << endl;
                        system ("pause");
                    }if (asientos[op - 1] > 0) {
                        asientos[op - 1]--;
                        cout << "Tu boleto " << endl;
                        cout << "PelIcula: " << peli[numero - 1] << endl;
                        cout << "Tu nombre: " << B2[m2][e2] << endl;
                        cout << "Tu asiento es el " << m2 << " " << e2 << endl;
                        cout<<"\nDeseas agregar otro asiento? s/n (MAXIMO 5) ";
                        cin>>respuesta;
                        if  (respuesta=='s'){
                            int contador = 0;
                            do{
                                contador++;
                                cout << "------------------- "<< endl;cout << "Quedan " << asientos[op - 1] << " asientos" << endl;
                                cout << " [0] significa disponible y [X] significa ocupado " << endl;
                                cout << "\t";
                                for (int m2 = 0; m2 < columnas; m2++) {
                                    cout << m2 << "\t";
                                }cout << endl << endl;
                                for (int m2 = 0; m2 < renglones; m2++) {
                                    cout << m2 << "\t";
                                    for (int e2 = 0; e2 < columnas; e2++) {
                                        cout << "[" << (A2[m2][e2] == 0 ? " " : "X") << "]" << "\t"; 
                                    }cout << endl;
                                }do {
                                    cout << "Escribe la coordenada del asiento que quieres reservar, COLUMNA: ";
                                    cin >> m2;
                                    cout << "Escribe la coordenada del asiento que quieres reservar, FILA: ";
                                    cin >> e2;
                                    if (m2 < 0 || m2 >= renglones || e2 < 0 || e2 >= columnas) {
                                        cout << "Coordenadas fuera de los lImites de la sala. IntEntalo de nuevo." << endl;
                                    }
                                }while (m2 < 0 || m2 >= renglones || e2 < 0 || e2 >= columnas);
                                if (A2[m2][e2] == 0) {
                                    A2[m2][e2] = 1; 
                                    cout << "COmo te llamas? ";
                                    cin >> B2[m2][e2]; 
                                    cout << "Tienes el asiento " << m2 << " " << e2 << endl;
                                }else {
                                    cout << "El asiento estA ocupado." << endl;
                                    return 0;
                                }if (asientos[op - 1] > 0 && contador < 5) {
                                    asientos[op - 1]--;
                                    cout << "Tu boleto " << endl;
                                    cout << "PelIcula: " << peli[numero - 1] << endl;
                                    cout << "Tu nombre: " << B2[m2][e2] << endl;
                                    cout << "Tu asiento es el " << m2 << " " << e2 << endl;
                                    cout<<"\nDeseas agregar otro asiento? s/n (MAXIMO 5) ";
                                    cin>>respuesta;
                                    if(respuesta=='n'){
                                        cout << "\nTotal a pagar $" << totalCompra2 * 100 << endl;
                                        totalSala2 =+ totalCompra2;
                                        cout<<" DISFRUTE LA FUNCION :D"<< endl;
                                        }
                                }else {
                                break;}
                            } while(respuesta=='s' && contador < 5);
                        }cout << "CuAntos boletos compraste? ";
                        cin >> totalCompra2;
                        if (totalCompra2 < 1 || totalCompra2 > 5) {
                            cout << "NUmero de boletos incorrecto. Debe ser entre 1 y " << 5 << "." << endl;
                            return 0;
                        }else { totalSala2+=totalCompra2;
                            cout << "\nTotal a pagar $" << totalCompra2 * 100 << endl;
                            cout << "QUE DISFRUTE LA FUNCION :D" << endl;
                        }
                    }else {
                        cout << "Ya no quedan lugares, lo sentimos." << endl;
                    }
                    break;
                    case '3': 
                    totalCompra3 =0;
                    do {
                        cout << "------------------- " << endl;
                        cout << "Quedan " << asientos[op - 1] << " asientos" << endl;
                        cout << " [0] significa disponible y [X] significa ocupado " << endl;
                        cout << "\t";
                        for (int o3 = 0; o3 < columnas; o3++) {
                            cout << o3 << "\t";
                        }
                        cout << endl << endl;
                        for (int o3 = 0; o3 < renglones; o3++) {
                            cout << o3 << "\t";
                            for (int p3 = 0; p3 < columnas; p3++) {
                                cout << "[" << (A3[o3][p3] == 0 ? " " : "X") << "]" << "\t"; 
                            }
                            cout << endl;
                        }

                        int o3, p3;
                        do {
                            cout << "Escribe la coordenada del asiento que quieres reservar, FILA: ";
                            cin >> o3;
                            cout << "Escribe la coordenada del asiento que quieres reservar, COLUMNA: ";
                            cin >> p3;
                            if (o3 < 0 || o3 >= renglones || p3 < 0 || p3 >= columnas) {
                                cout << "Coordenadas fuera de los límites de la sala. Inténtalo de nuevo." << endl;
                            }
                        } while (o3 < 0 || o3 >= renglones || p3 < 0 || p3 >= columnas);

                        if (A3[o3][p3] == 0) {
                            A3[o3][p3] = 1; 
                            cout << "Cómo te llamas? ";
                            cin >> B3[o3][p3]; 
                            cout << "Tienes el asiento " << o3 << " " << p3 << endl;
                            // Actualiza el recuento de asientos disponibles
                            asientos[numero - 1]--;
                        } else {
                            cout << "El asiento está ocupado." << endl;
                            system("pause");
                            continue; // Continuar con el siguiente ciclo
                        }

                        // Preguntar si desea agregar otro asiento
                        cout << "\nDeseas agregar otro asiento? s/n (MÁXIMO 5) ";
                        cin >> respuesta;
                    } while (respuesta == 's' && asientos[numero - 1] > 0);

                    cout << "Cuántos boletos compraste? ";
                    cin >> totalCompra3;
                    if (totalCompra3 < 1 || totalCompra3 > 5) {
                        cout << "Número de boletos incorrecto. Debe ser entre 1 y 5." << endl;
                        return 0;
                    } else {
                        totalSala3 += totalCompra3;
                        cout << "\nTotal a pagar $" << totalCompra3 * 100 << endl;
                        cout << "QUE DISFRUTE LA FUNCIÓN :D" << endl;
                        // Aquí puedes realizar cualquier otra acción necesaria, como imprimir los detalles de los boletos, etc.
                    }

                    // Desde aqui escribe Miguel, si no jala regresa hasta que esto se borre
                    break;
                    case '4':
                    totalCompra4=0;
                    do {
                        cout << "------------------- " << endl;
                        cout << "Quedan " << asientos[numero - 1] << " asientos" << endl;
                        cout << " [0] significa disponible y [X] significa ocupado " << endl;
                        cout << "\t";
                        for (int u4 = 0; u4 < columnas; u4++) {
                            cout << u4 << "\t";
                        }
                        cout << endl << endl;
                        for (int u4 = 0; u4 < renglones; u4++) {
                            cout << u4 << "\t";
                            for (int v4 = 0; v4 < columnas; v4++) {
                                cout << "[" << (A4[u4][v4] == 0 ? " " : "X") << "]" << "\t"; 
                            }
                            cout << endl;
                        }

                        int u4, v4;
                        do {
                            cout << "Escribe la coordenada del asiento que quieres reservar, FILA: ";
                            cin >> u4;
                            cout << "Escribe la coordenada del asiento que quieres reservar, COLUMNA: ";
                            cin >> v4;
                            if (u4 < 0 || u4 >= renglones || v4 < 0 || v4 >= columnas) {
                                cout << "Coordenadas fuera de los límites de la sala. Inténtalo de nuevo." << endl;
                            }
                        } while (u4 < 0 || u4 >= renglones || v4 < 0 || v4 >= columnas);

                        if (A4[u4][v4] == 0) {
                            A4[u4][v4] = 1; 
                            cout << "Cómo te llamas? ";
                            cin >> B4[u4][v4]; 
                            cout << "Tienes el asiento " << u4 << " " << v4 << endl;
                            // Actualiza el recuento de asientos disponibles
                            asientos[numero - 1]--;
                        } else {
                            cout << "El asiento está ocupado." << endl;
                            system("pause");
                            continue; // Continuar con el siguiente ciclo
                        }

                        // Preguntar si desea agregar otro asiento
                        cout << "\nDeseas agregar otro asiento? s/n (MÁXIMO 5) ";
                        cin >> respuesta;
                    } while (respuesta == 's' && asientos[numero - 1] > 0);

                    cout << "Cuántos boletos compraste? ";
                    cin >> totalCompra4;
                    if (totalCompra4 < 1 || totalCompra4 > 5) {
                        cout << "Número de boletos incorrecto. Debe ser entre 1 y 5." << endl;
                        return 0;
                    } else {
                        totalSala4=+totalCompra4;
                        cout << "\nTotal a pagar $" << totalCompra4 * 100 << endl;
                        cout << "QUE DISFRUTE LA FUNCIÓN :D" << endl;
                        // Aquí puedes realizar cualquier otra acción necesaria, como imprimir los detalles de los boletos, etc.
                    }
                    break;

                    case '5': 
                    totalCompra5=0;
                    cout << "------------------- "<< endl;
                    cout << "Quedan " << asientos[numero - 1] << " asientos" << endl;
                    cout << " [0] significa disponible y [X] significa ocupado " << endl;
                    cout << "\t";
                    for (int a5 = 0; a5 < columnas; a5++) {
                        cout << a5 << "\t";
                        }
                    cout << endl << endl;
                    for (int a5 = 0; a5 < renglones; a5++) {
                        cout << a5 << "\t";
                        for (int f5 = 0; f5 < columnas; f5++) {
                            cout << "[" << (A5[a5][f5] == 0 ? " " : "X") << "]" << "\t"; 
                            }
                        cout << endl;
                        }
                    int a5, f5;
                    do {
                        cout << "Escribe la coordenada del asiento que quieres reservar, FILA: ";
                        cin >> a5;
                        cout << "Escribe la coordenada del asiento que quieres reservar, COLUMNA: ";
                        cin >> f5;
                        if (a5 < 0 || a5 >= renglones || f5 < 0 || f5 >= columnas) {
                            cout << "Coordenadas fuera de los lImites de la sala. IntEntalo de nuevo." << endl;
                            }
                    } while (a5 < 0 || a5 >= renglones || f5 < 0 || f5 >= columnas);
                    if (A5[a5][f5] == 0) {
                        A5[a5][f5] = 1; 
                        cout << "COmo te llamas? ";
                        cin >> B5[a5][f5]; 
                        cout << "Tienes el asiento " << a5 << " " << f5 << endl;
                        }
                    else {
                        cout << "El asiento estA ocupado." << endl;
                        system ("pause");
                        }
                    if (asientos[numero - 1] > 0) {
                        asientos[numero - 1]--;
                        cout << "Tu boleto " << endl;
                        cout << "PelIcula: " << peli[numero - 1] << endl;
                        cout << "Tu nombre: " << B5[a5][f5] << endl;
                        cout << "Tu asiento es el " << a5 << " " << f5 << endl;
                        cout<<"\nDeseas agregar otro asiento? s/n (MAXIMO 5) ";
                        cin>>respuesta;
                        if  (respuesta=='s'){
                            int contador = 0;
                            do{
                                contador++;
                                cout << "------------------- "<< endl;cout << "Quedan " << asientos[numero - 1] << " asientos" << endl;
                                cout << " [0] significa disponible y [X] significa ocupado " << endl;
                                cout << "\t";
                                for (int a5 = 0; a5 < columnas; a5++) {
                                    cout << a5 << "\t";
                                    }
                                cout << endl << endl;
                                for (int a5 = 0; a5 < renglones; a5++) {
                                    cout << a5 << "\t";
                                    for (int f5 = 0; f5 < columnas; f5++) {
                                        cout << "[" << (A5[a5][f5] == 0 ? " " : "X") << "]" << "\t"; 
                                        }
                                    cout << endl;
                                }
                                do {
                                    cout << "Escribe la coordenada del asiento que quieres reservar, FILA: ";
                                    cin >> a5;
                                    cout << "Escribe la coordenada del asiento que quieres reservar, COLUMNA: ";
                                    cin >> f5;
                                    if (a5 < 0 || a5 >= renglones || f5 < 0 || f5 >= columnas) {
                                        cout << "Coordenadas fuera de los lImites de la sala. IntEntalo de nuevo." << endl;
                                        }
                                    }
                                while (a5 < 0 || a5 >= renglones || f5 < 0 || f5 >= columnas);
                                if (A5[a5][f5] == 0) {
                                    A5[a5][f5] = 1; 
                                    cout << "COmo te llamas? ";
                                    cin >> B5[a5][f5]; 
                                    cout << "Tienes el asiento " << a5 << " " << f5 << endl;
                                    }
                                else {
                                    cout << "El asiento estA ocupado." << endl;
                                    return 0;
                                    }
                                if (asientos[numero - 1] > 0 && contador < 5) {
                                    asientos[numero - 1]--;
                                    cout << "Tu boleto " << endl;
                                    cout << "PelIcula: " << peli[numero - 1] << endl;
                                    cout << "Tu nombre: " << B5[a5][f5] << endl;
                                    cout << "Tu asiento es el " << a5 << " " << f5 << endl;
                                    cout<<"\nDeseas agregar otro asiento? s/n (MAXIMO 5) ";
                                    cin>>respuesta;
                                    if(respuesta=='n'){
                                        cout << "\nTotal a pagar $" << totalCompra5 * 100 << endl;
                                        cout<<" DISFRUTE LA FUNCION :D"<< endl;
                                    }
                                    }
                                
                                else {
                                    break;}
                            } while(respuesta=='s' && contador < 5);
                        }cout << "CuAntos boletos compraste? ";
                        cin >> totalCompra5;
                        if (totalCompra5 < 1 || totalCompra5 > 5) {
                            cout << "NUmero de boletos incorrecto. Debe ser entre 1 y " << 5 << "." << endl;
                            return 0;
                            }
                        else {
                            totalSala5+=totalCompra5;
                            cout << "\nTotal a pagar $" << totalCompra5 * 100 << endl;
                            cout << "QUE DISFRUTE LA FUNCION :D" << endl;
                            }
                    } else {
                        cout << "Ya no quedan lugares, lo sentimos." << endl;
                        }
                    break;
                }

            break;

            case 'C': 
                cout << "<<<<<MENU>>>>>";
                cout << "\n-------------";
                cout << "\n1 Combo cuates 2 palomitas y 2 refrescos $229 ";
                cout << "\n2 Combo pareja 1 palomitas y 2 refrescos $175";
                cout << "\n3 Combo hotdog 1 hotdog, 1 palomitas y 2 refresco $229";
                cout << "\n4 Combo plus 2 palomitas, 2 refrescos, 2 hotdogs $349";
                cout << "\n5 Combo plus plus 2 palomitas, 2 refrescos, 2 hotdogs y un helado(150ml) $399 ";
                cout << "\n6 Combo cinefilo 1 refresco y 1 palomitas $150";
                cout << "\n7 sin combo ";
                cout << "\nElija su combo: ";
                cin >> opcion;
                switch(opcion) {
                    case 1:
                    cout << "\nSu eleccion ha sido combo cuates";
                    cout << "\nCuantos combos desea ordenar? ";
                    cin >> cant;
                    total =+ cant * 229;
                    cuates=+cant;
                    cout << "\nSu total a pagar es de: " << total;
                    break;
                    case 2 :
                    cout << "\nSu eleccion ha sido combo pareja";
                    cout << "\nCuantos combos desea ordenar? ";
                    cin >> cant;
                    total =+ cant * 175;
                    pareja=+cant;
                    cout << "\nSu total a pagar es de: " << total;
                    break;
                    case 3:
                    cout << "\nSu eleccion ha sido combo hotdog";
                    cout << "\nCuantos combos desea ordenar? ";
                    cin >> cant;
                    total =+ cant * 229;
                    hotdog=+cant;
                    cout << "\nSu total a pagar es de: " << total;
                    break;
                    case 4:
                    cout << "\nSu eleccion ha sido combo plus";
                    cout << "\nCuantos combos desea ordenar? ";
                    cin >> cant;
                    total =+ cant * 349;
                    plus=+cant;
                    cout << "\nSu total a pagar es de: " << total;
                    break;
                    case 5:
                    cout << "\nSu eleccion ha sido combo plus plus";
                    cout << "\nCuantos combos desea ordenar? ";
                    cin >> cant;
                    total =+ cant * 399;
                    plusplus=+cant;
                    cout << "\nSu total a pagar es de: " << total;
                    break;
                    
                    case 6:
                    cout << "\nSu eleccion ha sido combo cinefilo";
                    cout << "\nCuantos combos desea ordenar? ";cin >> cant;
                    cout << "\nDesea agregar un dulce de $40?:\n\n\n1. Si  2. No";
                    cin >> cant2;
                    if (cant2 == 1) {
                    total =+ (cant * 150) + 40;
                        } else {
                            total =+ cant * 150;
                            }
                            cout << "\nSu total a pagar es de: " << total;
                    
                    cinefilo=+cant;
                    break;
                    case 7:
                    cout<<"DISFRUTE LA FUNCION :D";
                    break;
                    default:
                        cout << "\nOpcion no valida";
                    }
            break;
            case 'D': 
                cout << "Escriba la coordenada del asiento que desea cancelar, renglon: ";
                cin >> fila;
                cout << "Escriba la coordenada del asiento que desea cancelar, columna: ";
                cin >> asiento;
                if (fila < 0 || fila >= renglones || asiento < 0 || asiento >= columnas) {
                cout << "Coordenadas fuera de los limites de la sala." << endl;
                return 0;
                }
                if (A[fila][asiento] == 1) {
                A[fila][asiento] = 0;
                B[fila][asiento] = ""; // Elimina el nombre del ocupante
                cout << "La reserva del asiento en la fila " << fila << " y columna " << asiento << " ha sido cancelada." << endl;
                }
                else {
                cout << "El asiento seleccionado no estA reservado." << endl;
                }
            break;
            system("pause");
            
            case 'E': 
                Tboletos = totalSala1 + totalSala2 + totalSala3 + totalSala4 + totalSala5;
                cout<< "este es su ticket"<<endl;
                cout<<endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                cout<<"Recibo "<<endl;
                cout<<endl;
                cout<<"//////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
                cout<<endl;
                cout<<"Combos                                                                       Cantidad    Precio"<<endl; 
                if(cuates != 0){cout<<"Cuates....................................................................."<<cuates<<"  $"<<cuates* 229<<endl;}else{}
                if(pareja != 0){cout<<"Pareja....................................................................."<<pareja<<"  $"<<pareja* 175<<endl;}else{}
                if(hotdog != 0){cout<<"Hotdog....................................................................."<<hotdog<<"  $"<<hotdog* 229<<endl;}else{}
                if(plus != 0){cout<<"Plus....................................................................."<<plus<<"  $"<<plus* 349<<endl;}else{}
                if(plusplus != 0){cout<<"Plusplus....................................................................."<<plusplus<<"  $"<<plusplus* 399<<endl;}else{}
                if(cinefilo != 0){cout<<"Cinefilo....................................................................."<<cinefilo<<"  $"<<cinefilo* 150<<endl;}else{}

                cout<<"//////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;

                cout<<"Subtotal Dulcería                                                                           "<<total<<endl;
                cout<<"Subtotal Boletos                                                                            "<<Tboletos * 100 <<endl;
                cout<<"Total                                                                                       "<<total+Tboletos<<endl;
            break;
            case 'F': 
            terminarpro = true;
            break;
        }

    } while (terminarpro == false);
        
    return 0;
}