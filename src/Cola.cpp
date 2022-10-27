#include "Cola.h"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
}

Cola::~Cola()
{
    while(primero){
    eliminar();
    }
}

void Cola::insertar(Paquete v)
{
    pnodoCola nuevo;
    nuevo = new NodoCola(v);
    if (ultimo){
        ultimo->siguiente = nuevo;
    }
    ultimo = nuevo;

    if (!primero){
        primero = nuevo;
    }
}

Paquete Cola::eliminar()
{
    pnodoCola nodo;
    Paquete v;
    nodo = primero;
    if(nodo){
        primero = nodo->siguiente;
        v = nodo->valor;
        delete nodo;
        if(!primero){
            ultimo = NULL;
        }
        return v;
    }
}

void Cola::mostrar()
{
    pnodoCola aux = primero;
    while(aux){
        aux->valor.mostrarEtiqueta();

        cout<<endl;

        aux = aux->siguiente;
    }
    cout<< endl;
}

Paquete Cola::verPrimero()
{
    return primero->valor;
}
