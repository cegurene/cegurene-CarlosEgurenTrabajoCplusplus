#include "NodoCola.h"

class Cola
{
    public:
        Cola();
        ~Cola();
        void insertar(Paquete v);
        Paquete eliminar();
        void mostrar();
        Paquete verPrimero();

    private:
        pnodoCola primero, ultimo;
};
