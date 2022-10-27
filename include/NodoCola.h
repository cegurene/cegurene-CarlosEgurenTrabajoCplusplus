#ifndef NODOCOLA_H_
#define NODOCOLA_H_

#include <Paquete.h>

class NodoCola
{
    public:
        NodoCola(Paquete v, NodoCola* sig = NULL);
        ~NodoCola();

    private:
        Paquete valor;
        NodoCola* siguiente;

        friend class Cola;
};
typedef NodoCola* pnodoCola;

#endif NODOCOLA_H_
