/*
EQUIPO 5
Sección: D19
Calendario: 2022A
Nombres:
 - LAURENO VAZQUEZ ANGENLICA PAULINA.
 - MARAVILLA ESTRADA RAUL ALFREDO.
 - MARTINEZ SEPULVEDA ALAN JAHIR.
 - MENDEZ ORTIZ OSCAR DONETH.
*/

#ifndef PASAJEROS_H_INCLUDED
#define PASAJEROS_H_INCLUDED
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
char Ene = 164, Ray = 205, CRay = 206, RayD = 204, RayEIS = 201,
     RayT = 203;
char L = 186, RayEDS = 187, RayI = 185, RayEDB = 200, RayEIB = 188,
     RayTV = 202;

class Pasajero
{
private:
    int nPasajero;
    char NombrePasajero[64];
    char origen[64];
    int fecha_salida;
    int hora_entrada;
    char destino[64];
    int fecha_llegada;
    int hora_llegada;

public:
    Pasajero();
    Pasajero(int, string);
    void establecerNombre(string);
    string RegresaNombre();
    void establecernPasajero(int);
    int RegresanPasajero();

    void establecerOrigen(string);
    string RegresaOrigen();
    void establecerFechaSalida(int);
    int RegresaFechaSalida();
    void establecerHoraEntrada(int);
    int RegresaHoraEntrada();
    void establecerDestino(string);
    string RegresaDestino();
    void establecerFechaLlegada(int);
    int RegresaFechaLlegada();
    void establecerHoraLlegada(int);
    int RegresaHoraLlegada();

    int operator==(Pasajero);
    int operator!=(Pasajero);
    int operator>(Pasajero);
    int operator<(Pasajero);
    friend ostream &operator<<(ostream &, Pasajero &);
};
// Constructor por omision
Pasajero::Pasajero()
{
}
// Constructor por parametros
Pasajero::Pasajero(int NumS, string NomS)
{
    establecernPasajero(NumS);
    establecerNombre(NomS);
}
void Pasajero::establecernPasajero(int valorNumPasajero)
{
    nPasajero = valorNumPasajero;
}
int Pasajero::RegresanPasajero()
{
    return nPasajero;
}
void Pasajero::establecerNombre(string valorNomPasajero)
{
    const char *nomb = valorNomPasajero.data();
    int longitud = valorNomPasajero.size();
    longitud = (longitud < 64 ? longitud : 63);
    strncpy(NombrePasajero, nomb, longitud);
    NombrePasajero[longitud] = '\0';
}
string Pasajero::RegresaNombre()
{
    return NombrePasajero;
}

void Pasajero::establecerOrigen(string valorPasajero)
{
    const char *ori = valorPasajero.data();
    int longitud = valorPasajero.size();
    longitud = (longitud < 64 ? longitud : 63);
    strncpy(origen, ori , longitud);
    origen[longitud] = '\0';
}
string Pasajero::RegresaOrigen()
{
    return origen;
}
void Pasajero::establecerFechaSalida(int valorFecha)
{
    fecha_salida = valorFecha;
}
int Pasajero::RegresaFechaSalida()
{
    return fecha_salida;
}

void Pasajero::establecerHoraEntrada(int valorHora)
{
    hora_entrada = valorHora;
}
int Pasajero::RegresaHoraEntrada(){
    return hora_entrada;
}
void Pasajero::establecerDestino(string valorPasajero)
{
    const char *des = valorPasajero.data();
    int longitud = valorPasajero.size();
    longitud = (longitud < 64 ? longitud : 63);
    strncpy(destino, des , longitud);
    destino[longitud] = '\0';
}
string Pasajero::RegresaDestino()
{
    return destino;
}
void Pasajero::establecerFechaLlegada(int valorFecha)
{
    fecha_llegada = valorFecha;
}
int Pasajero::RegresaFechaLlegada()
{
    return fecha_llegada;
}
void Pasajero::establecerHoraLlegada(int valorHora)
{
    hora_llegada = valorHora;
}
int Pasajero::RegresaHoraLlegada()
{
    return hora_llegada;
}
int Pasajero::operator==(Pasajero Soc)
{
    int Resp = 0;
    if (nPasajero == Soc.nPasajero)
        Resp = 1;
    return Resp;
}
int Pasajero::operator!=(Pasajero Soc)
{
    int Resp = 0;
    if (nPasajero != Soc.nPasajero)
        Resp = 1;
    return Resp;
}
int Pasajero::operator>(Pasajero Soc)
{
    int Resp = 0;
    if (nPasajero > Soc.nPasajero)
        Resp = 1;
    return Resp;
}
int Pasajero::operator<(Pasajero Soc)
{
    int Resp = 0;
    if (nPasajero < Soc.nPasajero)
        Resp = 1;
    return Resp;
}
// Sobrecarga de operadores >> para permitir la lectura de objetos
// tipo Pasajero de manera directa con el cin.
ostream &operator<<(ostream &Escribe, Pasajero &ObjPasajero)
{
    Escribe << " " << L << setw(9) << left << ObjPasajero.nPasajero
            << L << setw(40) << ObjPasajero.NombrePasajero

            << L;
    return Escribe;
}
#endif // PasajeroS_H_INCLUDED
