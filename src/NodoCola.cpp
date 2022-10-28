#include "NodoCola.h"

NodoCola::NodoCola(Paquete* v, NodoCola* sig)
{
    valor = v;
    siguiente = sig;
}

NodoCola::~NodoCola()
{
    //dtor
}
