#include <Paquete.h>
#include <string>

using namespace std;



Paquete::Paquete(int n)
{
    this->generarDNI();
    this->generarCoordenada();
    this->generarID(n);
}

void Paquete::generarID(int n)
{
    int numero1 = 10 + rand() % (100 - 10);
    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    int posLetra = 0 + rand() % (23 - 0);
    char letra = letras[posLetra];

    string numero3;
    if(n < 10 && n >= 0){
        numero3 = "000";
    }
    else{
        if(n < 100 && n >= 10){
            numero3 = "00";
        }
        else{
            numero3 = "0";
        }
    }

    string idFinal = to_string(numero1)+ letra + numero3 + to_string(n);
    this->e.id = idFinal;
}

void Paquete::generarDNI()
{
    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    int aux = 10000000;
    int dni = 9088570;

    for(int i = 0; i < 8; i++){
        int num = 0 + rand() % (10 - 1);
        dni += num * aux;
        aux /= 10;
    }
    char letraDni = letras[dni % 23];
    string auxDNI = to_string(dni) + letraDni;

    this->e.dni = auxDNI ;
}

void Paquete::generarCoordenada()
{
    int segundoLa;
    int minutoLa = 46 + rand() % (52 - 46);
    if(minutoLa == 46){
        segundoLa = 5 + rand() % (61 - 5);
    }
    else{
        if(minutoLa == 51){
            segundoLa = 0 + rand() % (7 - 0);
        }
        else{
            segundoLa = 0 + rand() % (61 - 0);
        }
    }

    int segundoLon;
    int minutoLon = 32 + rand() % (42 - 32);
    if(minutoLon == 32){
        segundoLon = 2 + rand() % (61 - 2);
    }
    else{
        if(minutoLon == 41){
            segundoLon = 0 + rand() % (2 - 0);
        }
        else{
            segundoLon = 0 + rand() % (61 - 0);
        }
    }

    int gradosLa = 40;
    int gradosLon = -3;
    this->e.coordenada.gradosLa = gradosLa;
    this->e.coordenada.minutosLa = minutoLa;
    this->e.coordenada.segundosLa = segundoLa;
    this->e.coordenada.gradosLon = gradosLon;
    this->e.coordenada.minutosLon = minutoLon;
    this->e.coordenada.segundosLon = segundoLon;
}

void Paquete::mostrarEtiqueta()
{
    cout<< "Paquete:" <<endl;
    cout<< "ID: " << this->e.id <<endl;
    cout<< "Con latitud: "  << this->e.coordenada.gradosLa << " grados " << this->e.coordenada.minutosLa << "' " << this->e.coordenada.segundosLa << "\" " <<endl;
    cout<< "Con longitud: " << this->e.coordenada.gradosLon << " grados " << this->e.coordenada.minutosLon << "' " << this->e.coordenada.segundosLon<< "\" " <<endl;
    cout<< "DNI: " << this->e.dni << endl;
}

int Paquete::zonaReparto()
{
    int fila;
    int columna;
    if( (this->e.coordenada.minutosLa > 48) || ( (this->e.coordenada.minutosLa == 48) && (this->e.coordenada.segundosLa >= 36) ) ){
        fila = 1;
    }
    else{
        fila = 2;
    }
    if ( (this->e.coordenada.minutosLon > 37) || ( (this->e.coordenada.minutosLon == 37) && (this->e.coordenada.segundosLon >= 3) ) ){
        columna = 1;
    }
    else{
        columna = 2;
    }

    if((fila == 1) && (columna == 1)){
        return 1;
    }
    else{
        if((fila == 1) && (columna == 2)){
            return 2;
        }
        else{
            if((fila == 2) && (columna == 1)){
                return 3;
            }
            else{
                return 4;
            }
        }
    }
}

Paquete::~Paquete()
{
}
