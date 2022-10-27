#include "Pila.h"
#include <iostream>

Pila::Pila()
{
    this->tope = -1;

}

int Pila::pilaVacia()
{
    if(this->tope==-1) return 1;
    else return 0;
}

void Pila::meter(Paquete* p)
{
    if(this->pilaLlena() != 1){
        this->valores[++this->tope]=p;
    } else{
        cout<< "No es posible meter un paquete. LLENO" << endl;
    }
}

Paquete* Pila::sacar()
{
    if(this->pilaVacia() != 1){
        return (this->valores[tope--]);
    } else{
        cout<<"No hay ningun paquete a extraer."<<endl;
    }
}

void Pila::cantidadPila()
{
  cout<< "La pila tiene" << this->tope << " elementos.";
}

void Pila::imprimirPila()
{
  if(this->pilaVacia() == 0){
    cout<< "La pila esta vacia" <<endl;
  }else{
    for(int i = this->tope; i >= 0; i--){
      cout<< " -> " << this->valores[i]->e.id;
    }
    cout<<endl;
  }
}

int Pila::pilaLlena()
{
    if(this->tope==N3-1) return 1;
    else return 0;
}

Pila::~Pila()
{
    //dtor
}
