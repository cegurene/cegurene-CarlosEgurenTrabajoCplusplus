#include <Paquete.h>

#define N3 5
class Pila
{
    public:
        Pila();
        void meter(Paquete* p);
        Paquete* sacar();
        void cantidadPila();
        void imprimirPila();
        int pilaVacia();
        int pilaLlena();
        ~Pila();

    private:

        Paquete* valores[N3];
        int tope;
};
