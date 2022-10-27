#include <iostream>
#include <stdlib.h> //para srand()
#include <time.h> //para time()
#include <string>
#include <Pila.h>
#include <Cola.h>
#include <NodoCola.h>
#include <Paquete.h>

using namespace std;

#define N1 100
#define N2 10
#define N3 5 // son los numeros del tamanno de las colas y pilas del programa

#define TRUE 1
#define FALSE 0
#define PILA_TAM 5 // estos 3 parametros son para la creacion y manipulacion de pilas

bool isEnterPressed()
{
	string str;
	getline(cin, str);
	if (str == "") {
		return true;
	}
	return false;
}

int main(int argc, char** argv)
{
    srand(time(NULL)); //para que los numeros random dependan del tiempo en el que se ejecuta

    /* Prueba de creacion de paquete, asi como sus datos identificadores
    Paquete p1;
    string dni = generarDni();
    p1.dni = dni;
    string id = generarId(2);
    p1.id = id;
    int c[6];
    crearCoordenada(c);
    p1.coordenada.gradosLa = c[0];
    p1.coordenada.gradosLa = c[1];
    p1.coordenada.gradosLa = c[2];
    p1.coordenada.gradosLa = c[3];
    p1.coordenada.gradosLa = c[4];
    p1.coordenada.gradosLa = c[5];

    cout<< "El ID del paquete es: " + p1.id <<endl;
    cout<< "El DNI del cliente es: " + p1.dni <<endl;
    cout<< "Aqui se debe mostrar el id de los paquetes de la cola:" <<endl;
    //cout<< "Las coordenadas del paquete son: " + p1.coordenada.gradosLa + " " + p1.coordenada.minutosLa + " "+ p1.coordenada.segundosLa + " "+ p1.coordenada.gradosLon + " "+ p1.coordenada.minutosLon + " "+ p1.coordenada.segundosLon << endl;
    string z = zonaReparto(c);
    cout<< "La zona en la que reparte es: " + z << endl;
    */

    /* Prueba de creacion de cola, asi como sus metodos y procedimientos
    Cola cola;
    Paquete p1;
    p1.id = "IdDelPaquete1";

    cola.insertar(p1);
    cola.mostrar();
    Paquete p2 = cola.eliminar();
    cout<< p2.id;
    */


    /*Prueba de creacion de una pila
    Paquete p;
    p.id = "IdDelPaquete";

    Pila pila;
    IniciaPila(&pila);
    Push(&pila, p);
    ImprimePila(&pila);
    */

    // Creacion aleatoria de N1 paquetes
    cout<< "Creando paquetes aleatorios..." <<endl;
    Cola cola;
    for(int i = 0; i < N1; i++){
        Paquete p;
        p.generarCoordenada();
        p.generarDNI();
        p.generarID(i + 1);

        cola.insertar(p);
    }
    cout<< "Creacion de paquetes terminada." <<endl;
    cout<<endl;

    Cola colaNO;
    Cola colaNE;
    Cola colaSO;
    Cola colaSE;

    int contador = 0;
    while(contador < 10){
        cout<< "Pulse ENTER para mandar 10 paquetes a sus respectivas zonas de reparto."<<endl;
        if(isEnterPressed()){
            for(int i = 0; i < N2; i++){
                Paquete p = cola.eliminar();

                if(p.zonaReparto() == 1){
                    colaNO.insertar(p);
                }
                else{
                    if(p.zonaReparto() == 2){
                        colaNE.insertar(p);
                    }
                    else{
                        if(p.zonaReparto() == 3){
                            colaSO.insertar(p);
                        }
                        else{
                            colaSE.insertar(p);
                        }
                    }
                }
            }

            cout<< "Si se ha pulsado ENTER." <<endl;
            contador++;
        }
        else{
            cout<< "No se ha pulsado ENTER." <<endl;
        }
    }
    cout<< "Todos los paquetes procesados." <<endl;
    cout<<endl;

    //Ahora se van a ver todos los ID de los paquetes de cada zona de reparto
    cout<< "Se va a mostrar la cola NE." <<endl;
    colaNE.mostrar();

    /*Esto es una prueba para comprobar que el programa funciona bien hasta aqui
    Paquete pSE = colaSE.eliminar();
    cout<< pSE.id<<endl;
    cout<< pSE.dni<<endl;
    int cSE[6];
    cSE[0] = pSE.coordenada.gradosLa;
    cSE[1] = pSE.coordenada.minutosLa;
    cSE[2] = pSE.coordenada.segundosLa;
    cSE[3] = pSE.coordenada.gradosLon;
    cSE[4] = pSE.coordenada.minutosLon;
    cSE[5] = pSE.coordenada.segundosLon;
    cout<< cSE[0] << " " << cSE[1] << " " << cSE[2] << ", " << cSE[3] << " " << cSE[4] << " " << cSE[5] <<endl;*/


    cout<<endl;
    return 0;
}
