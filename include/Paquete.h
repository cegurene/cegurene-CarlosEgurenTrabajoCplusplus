#ifndef PAQUETE_H_
#define PAQUETE_H_

#include <iostream>

using namespace std;

struct Paquete
{
        Paquete(); //Declarar paquetes
        void mostrarEtiqueta();
        string getID();
        ~Paquete();

         typedef struct
        {
            int gradosLa;
            int minutosLa;
            int segundosLa;
            int gradosLon;
            int minutosLon;
            int segundosLon;
        } Coordenadas;

         typedef struct
        {
            string id;
            string dni;
            Coordenadas coordenada;
        } Etiqueta;

        Etiqueta e; //Se introducen valores aqui
        void generarDNI();
        void generarID(int n);
        void generarCoordenada();
        int zonaReparto();
};

#endif PAQUETE_H_
