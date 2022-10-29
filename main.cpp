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

    // Creacion aleatoria de N1 paquetes
    cout<< "Creando paquetes aleatorios..." <<endl;
    Cola cola;
    for(int i = 1; i <= N1; i++){
        Paquete* p = new Paquete(i);
        cola.insertar(p);
    }
    cola.mostrar();
    cout<< "Creacion de paquetes terminada." <<endl;
    cout<<endl;

    Pila pilaNO;
    Pila pilaNE;
    Pila pilaSO;
    Pila pilaSE;

    Cola colaNO;
    Cola colaNE;
    Cola colaSO;
    Cola colaSE;

    int numPaquetesNO = 0;
    int numPaquetesNE = 0;
    int numPaquetesSO = 0;
    int numPaquetesSE = 0;

    int numFurgonetasNO = 0;
    int numFurgonetasNE = 0;
    int numFurgonetasSO = 0;
    int numFurgonetasSE = 0;

    int contador = 0;
    while(contador < 10){
        cout<< "Pulse ENTER para mandar 10 paquetes a repartir."<<endl;
        if(isEnterPressed()){
            cout<< "Si se ha pulsado ENTER." <<endl;
            cout<<endl;

            for(int i = 0; i < N2; i++){
                Paquete* p = cola.eliminar();

                if(p->zonaReparto() == 1){
                    if(pilaNO.pilaLlena() != 1){
                        pilaNO.meter(p);
                    }
                    else{
                        cout<< "La furgoneta de la zona NO llena. Contiene los paquetes:" <<endl;
                        pilaNO.imprimirPila();
                        cout<< "Se va a proceder a repartir estos paquetes." <<endl;
                        cout<<endl;

                        for(int j = 0; j < 5; j++){
                            Paquete* paquetePila = pilaNO.sacar();
                            colaNO.insertar(paquetePila);
                        }
                        pilaNO.meter(p);
                        numFurgonetasNO++;
                    }
                    numPaquetesNO++;
                }
                else{
                    if(p->zonaReparto() == 2){
                        if(pilaNE.pilaLlena() != 1){
                            pilaNE.meter(p);
                        }
                        else{
                            cout<< "La furgoneta de la zona NE llena. Contiene los paquetes:" <<endl;
                            pilaNE.imprimirPila();
                            cout<< "Se va a proceder a repartir estos paquetes." <<endl;
                            cout<<endl;

                            for(int j = 0; j < 5; j++){
                                Paquete* paquetePila = pilaNE.sacar();
                                colaNE.insertar(paquetePila);
                            }
                            pilaNE.meter(p);
                            numFurgonetasNE++;
                        }
                        numPaquetesNE++;
                    }
                    else{
                        if(p->zonaReparto() == 3){
                            if(pilaSO.pilaLlena() != 1){
                                pilaSO.meter(p);
                            }
                            else{
                                cout<< "La furgoneta de la zona SO llena. Contiene los paquetes:" <<endl;
                                pilaSO.imprimirPila();
                                cout<< "Se va a proceder a repartir estos paquetes." <<endl;
                                cout<<endl;

                                for(int j = 0; j < 5; j++){
                                    Paquete* paquetePila = pilaSO.sacar();
                                    colaSO.insertar(paquetePila);
                                }
                                pilaSO.meter(p);
                                numFurgonetasSO++;
                            }
                            numPaquetesSO++;
                        }
                        else{
                            if(pilaSE.pilaLlena() != 1){
                                pilaSE.meter(p);
                            }
                            else{
                                cout<< "La furgoneta de la zona SE llena. Contiene los paquetes:" <<endl;
                                pilaSE.imprimirPila();
                                cout<< "Se va a proceder a repartir estos paquetes." <<endl;
                                cout<<endl;

                                for(int j = 0; j < 5; j++){
                                    Paquete* paquetePila = pilaSE.sacar();
                                    colaSE.insertar(paquetePila);
                                }
                                pilaSE.meter(p);
                                numFurgonetasSE++;
                            }
                            numPaquetesSE++;
                        }
                    }
                }
            }
            contador++;
        }
        else{
            cout<< "No se ha pulsado ENTER." <<endl;
        }
    }

    // Comprobamos que las pilas estan vacias. Si no lo estan, las vaciamos
    if(pilaNO.pilaVacia() != 1){
        while(pilaNO.pilaVacia() != 1){
            Paquete* p = pilaNO.sacar();
            colaNO.insertar(p);
        }
        numFurgonetasNO++;
    }
    if(pilaNE.pilaVacia() != 1){
        while(pilaNE.pilaVacia() != 1){
            Paquete* p = pilaNE.sacar();
            colaNE.insertar(p);
        }
        numFurgonetasNE++;
    }
    if(pilaSO.pilaVacia() != 1){
        while(pilaSO.pilaVacia() != 1){
            Paquete* p = pilaSO.sacar();
            colaSO.insertar(p);
        }
        numFurgonetasSO++;
    }
    if(pilaSE.pilaVacia() != 1){
        while(pilaSE.pilaVacia() != 1){
            Paquete* p = pilaSE.sacar();
            colaSE.insertar(p);
        }
        numFurgonetasSE++;
    }

    cout<< "Todos los paquetes procesados." <<endl;
    cout<<endl;

    //Ahora se van a ver todos los ID de los paquetes de cada zona de reparto
    cout<< "Se va a mostrar la cola NO." <<endl;
    colaNO.mostrar();
    cout<<endl;

    cout<< "Se va a mostrar la cola NE." <<endl;
    colaNE.mostrar();
    cout<<endl;

    cout<< "Se va a mostrar la cola SO." <<endl;
    colaSO.mostrar();
    cout<<endl;

    cout<< "Se va a mostrar la cola SE." <<endl;
    colaSE.mostrar();
    cout<<endl;

    cout<< "La zona NO ha recibido " << numPaquetesNO << " paquetes y se han utilizado " << numFurgonetasNO << " furgonetas." <<endl;
    cout<< "La zona NE ha recibido " << numPaquetesNE << " paquetes y se han utilizado " << numFurgonetasNE << " furgonetas." <<endl;
    cout<< "La zona SO ha recibido " << numPaquetesSO << " paquetes y se han utilizado " << numFurgonetasSO << " furgonetas." <<endl;
    cout<< "La zona SE ha recibido " << numPaquetesSE << " paquetes y se han utilizado " << numFurgonetasSE << " furgonetas." <<endl;

    if( (numPaquetesNO >= numPaquetesNE) && (numPaquetesNO >= numPaquetesSE) && (numPaquetesNO >= numPaquetesSO) ){
        cout<< "La zona que mas paquetes ha recibido es la zona NO." <<endl;
    }
    else{
        if( (numPaquetesNE >= numPaquetesNO) && (numPaquetesNE >= numPaquetesSE) && (numPaquetesNE >= numPaquetesSO) ){
            cout<< "La zona que mas paquetes ha recibido es la zona NE." <<endl;
        }
        else{
            if( (numPaquetesSE >= numPaquetesNO) && (numPaquetesSE >= numPaquetesNE) && (numPaquetesSE >= numPaquetesSO) ){
                cout<< "La zona que mas paquetes ha recibido es la zona SE." <<endl;
            }
            else{
                cout<< "La zona que mas paquetes ha recibido es la zona SO." <<endl;
            }
        }
    }

    cout<<endl;
    return 0;
}
