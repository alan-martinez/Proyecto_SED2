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

#ifndef LISTADOLIGADA_H_INCLUDED
#define LISTADOLIGADA_H_INCLUDED
#include <iostream>
using namespace std;

template <class T>
class ListaDoLiga;
template <class T>
class NodoDobleLiga
{
private:
    NodoDobleLiga<T> *LigaIzq;
    NodoDobleLiga<T> *LigaDer;
    T Info;

public:
    NodoDobleLiga();
    T RegresarInfo();
    NodoDobleLiga<T> *enlaceNodo() const
    {
        return LigaDer;
    }
    friend class ListaDoLiga<T>;
};
template <class T>
NodoDobleLiga<T>::NodoDobleLiga()
{
    LigaIzq = nullptr;
    LigaDer = nullptr;
}
template <class T>
T NodoDobleLiga<T>::RegresarInfo()
{
    return Info;
}
template <class T>
class ListaDoLiga
{
private:
    NodoDobleLiga<T> *Primero;
    NodoDobleLiga<T> *Ultimo;

public:
    ListaDoLiga();
    void ImprimeIzq_Der(NodoDobleLiga<T> *);
    void ImprimeDer_Izq(NodoDobleLiga<T> *);
    void ImprimeNodo(NodoDobleLiga<T> *);
    void InsertaInicio(T);
    void InsertaFinal(T);
    void InsertaOrdenado(T);
    int InsertaAntes(T, T);
    int EliminaPrimero();
    int EliminaUltimo();
    int EliminaUnNodo(T);
    int EliminaAnterior(T);
    NodoDobleLiga<T> *Busca(T, NodoDobleLiga<T> *);
    NodoDobleLiga<T> *RegresaPrimero();
    NodoDobleLiga<T> *RegresaUltimo();
    NodoDobleLiga<T> *RegresaVecinoDer(NodoDobleLiga<T> *);
    NodoDobleLiga<T> *RegresaVecinoIzq(NodoDobleLiga<T> *);
};
template <class T>
ListaDoLiga<T>::ListaDoLiga()
{
    Primero = nullptr;
    Ultimo = nullptr;
}
template <class T>
void ListaDoLiga<T>::ImprimeIzq_Der(NodoDobleLiga<T> *Apunt)
{
    if (Apunt)
    {
        cout << Apunt->Info << '\n';
        ImprimeIzq_Der(Apunt->LigaDer);
    }
}
template <class T>
void ListaDoLiga<T>::ImprimeDer_Izq(NodoDobleLiga<T> *Apunt)
{
    if (Apunt)
    {
        cout << Apunt->Info << '\n';
        ImprimeDer_Izq(Apunt->LigaIzq);
    }
}
template <class T>
void ListaDoLiga<T>::ImprimeNodo(NodoDobleLiga<T> *Apunt)
{
    cout << Apunt->Info << '\n';
}
template <class T>
void ListaDoLiga<T>::InsertaInicio(T Dato)
{
    NodoDobleLiga<T> *Apunt;
    Apunt = new NodoDobleLiga<T>();
    Apunt->Info = Dato;
    Apunt->LigaDer = Primero;
    if (Primero)
        Primero->LigaIzq = Apunt;
    else
        Ultimo = Apunt;
    Primero = Apunt;
}
template <class T>
void ListaDoLiga<T>::InsertaFinal(T Dato)
{
    NodoDobleLiga<T> *Apunt;
    Apunt = new NodoDobleLiga<T>;
    Apunt->Info = Dato;
    Apunt->LigaIzq = Ultimo;
    if (Ultimo)
        Ultimo->LigaDer = Apunt;
    else
        Primero = Apunt;
    Ultimo = Apunt;
}
template <class T>
void ListaDoLiga<T>::InsertaOrdenado(T Dato)
{
    NodoDobleLiga<T> *Apun1, *Apun2, *Apun3;
    if (!Primero || Dato < Primero->Info)
        InsertaInicio(Dato);
    else if (Dato > Ultimo->Info)
        InsertaFinal(Dato);
    else
    {
        Apun1 = new NodoDobleLiga<T>;
        Apun1->Info = Dato;
        Apun2 = Primero;
        while (Apun2->Info < Apun1->Info)
            Apun2 = Apun2->LigaDer;
        Apun3 = Apun2->LigaIzq;
        Apun3->LigaDer = Apun1;
        Apun1->LigaDer = Apun2;
        Apun1->LigaIzq = Apun3;
        Apun2->LigaIzq = Apun1;
    }
}
template <class T>
int ListaDoLiga<T>::InsertaAntes(T Dato, T Ref)
{
    NodoDobleLiga<T> *Apun1, *Apun2, *Apun3;
    int Resp = 1;
    if (Primero)
    {
        Apun1 = Primero;
        while ((Apun1 != nullptr) && (Apun1->Info != Ref))
            Apun1 = Apun1->LigaDer;
        if (Apun1 != nullptr)
        {
            Apun3 = new NodoDobleLiga<T>();
            Apun3->Info = Dato;
            Apun3->LigaDer = Apun1;
            Apun2 = Apun1->LigaIzq;
            Apun1->LigaIzq = Apun3;
            Apun3->LigaIzq = Apun2;
            if (Primero == Apun1)
                Primero = Apun3;
            else
                Apun2->LigaDer = Apun3;
        }
        else
            Resp = 0;
    }
    else
        Resp = -1;
    return Resp;
}
template <class T>
int ListaDoLiga<T>::EliminaPrimero()
{
    NodoDobleLiga<T> *Apunt;
    int Resp = 1;
    if (Primero)
    {
        Apunt = Primero;
        if (Apunt->LigaDer)
        {
            Primero = Apunt->LigaDer;
            Primero->LigaIzq = nullptr;
        }
        else
        {
            Primero = nullptr;
            Ultimo = nullptr;
        }
        delete (Apunt);
    }
    else
        Resp = 0;
    return Resp;
}
template <class T>
int ListaDoLiga<T>::EliminaUltimo()
{
    NodoDobleLiga<T> *Apunt;
    int Resp = 1;
    if (Ultimo)
    {
        Apunt = Ultimo;
        if (Apunt->LigaIzq)
        {
            Ultimo = Apunt->LigaIzq;
            Ultimo->LigaDer = nullptr;
        }
        else
        {
            Primero = nullptr;
            Ultimo = nullptr;
        }
        delete (Apunt);
    }
    else
        Resp = 0;
    return Resp;
}
template <class T>
int ListaDoLiga<T>::EliminaUnNodo(T Dato)
{
    NodoDobleLiga<T> *Apun1, *Apun2, *Apun3;
    int Resp = 1;
    if (Primero)
    {
        Apun1 = Primero;
        while ((Apun1 != nullptr) && (Apun1->Info != Dato))
            Apun1 = Apun1->LigaDer;
        if (Apun1 == nullptr)
            Resp = 0;
        else
        {
            if (Primero == Ultimo)
            {
                Primero = nullptr;
                Ultimo = nullptr;
            }
            else if (Apun1 == Primero)
            {
                Primero = Apun1->LigaDer;
                Primero->LigaIzq = nullptr;
            }
            else if (Apun1 == Ultimo)
            {
                Ultimo = Apun1->LigaIzq;
                Ultimo->LigaDer = nullptr;
            }
            else
            {
                Apun2 = Apun1->LigaIzq;
                Apun3 = Apun1->LigaDer;
                Apun2->LigaDer = Apun3;
                Apun3->LigaIzq = Apun2;
            }
            delete (Apun1);
        }
    }
    else
        Resp = -1;
    return Resp;
}
template <class T>
int ListaDoLiga<T>::EliminaAnterior(T Dato)
{
    NodoDobleLiga<T> *Apun1, *Apun2, *Apun3;
    int Resp = 1;
    if (Primero)
    {
        Apun1 = Primero;
        while ((Apun1 != nullptr) && (Apun1->Info != Dato))
            Apun1 = Apun1->LigaDer;
        if (Apun1 == nullptr)
            Resp = 0;
        else if (Primero == Apun1)
            Resp = -1;
        else
        {
            if (Primero == Apun1->LigaIzq)
            {
                Apun2 = Primero;
                Primero = Apun1;
                Primero->LigaIzq = nullptr;
            }
            else
            {
                Apun2 = Apun1->LigaIzq;
                Apun3 = Apun2->LigaIzq;
                Apun3->LigaDer = Apun1;
                Apun1->LigaIzq = Apun3;
            }
            delete (Apun2);
        }
    }
    else
        Resp = -2;
    return Resp;
}
template <class T>
NodoDobleLiga<T> *ListaDoLiga<T>::Busca(T Dato, NodoDobleLiga<T>*Apunt)
{
    if (Apunt)
        if (Apunt->Info == Dato)
            return Apunt;
        else
            return Busca(Dato, Apunt->LigaDer);
    else
        return nullptr;
}
template <class T>
NodoDobleLiga<T> *ListaDoLiga<T>::RegresaPrimero()
{
    return Primero;
}
template <class T>
NodoDobleLiga<T> *ListaDoLiga<T>::RegresaUltimo()
{
    return Ultimo;
}
template <class T>
NodoDobleLiga<T> *ListaDoLiga<T>::RegresaVecinoDer(NodoDobleLiga<T>
                                                       *Apunt)
{
    return Apunt->LigaDer;
}
template <class T>
NodoDobleLiga<T> *ListaDoLiga<T>::RegresaVecinoIzq(NodoDobleLiga<T>
                                                       *Apunt)
{
    return Apunt->LigaIzq;
}
#endif // LISTADOLIGADA_H_INCLUDED
