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

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include "ListaDoLigada.h"
#include "Pasajeros.h"
using namespace std;
char Menu()
{

        char Opcion;
        do {
        system("cls");
        cout << endl
             << "\t\t\tMenu lista de pasajeros" << endl;
        cout << "\t\t\t\tOpciones: " << endl
             << "\t ";
        for (int i = 1; i < 71; i++)
        {
            cout << Ray;
        }
        cout << endl
             << "\t A) Registrar un nuevo pasajero";
        cout << endl
             << "\t B) Dar de baja un pasajero.";
        cout << endl
            //  << "\t C) Generar un reporte de los Pasajeros con un cierto rango de antiguedad.";
             << "\t C) Visualizar un pasajero. (nombre del pasajero)";
        cout << endl
            //  << "\t E) Generar un reporte de los datos de todos los Pasajeros.";
             << "\t D) Visualizar toda la lista";
        cout << endl
             << "\t S) Salir." << endl
             << "\t ";
        for (int i = 1; i < 71; i++)
        {
            cout << Ray;
        }
        cout << "\n\t Seleccione una opcion: ";
        //Opcion.towupper(Opcion);
        cin >> Opcion;
    }
    while (Opcion!= 'A' && Opcion!='B' && Opcion!= 'C' && Opcion!= 'D' && Opcion!= 'E' && Opcion!='F' && Opcion!='S');
    return Opcion;
}
void ReportePasajeros(ListaDoLiga<Pasajero> Registro)
{
    NodoDobleLiga<Pasajero> *Apunt;
    int YearMI, YearActual, Ant;
    cout << "\n\t Ingrese el rango de antiguedad que le interesa.\n";
    cout << "\t A" << Ene << "o actual: ";
    cin >> YearActual;
    cout << "\t A" << Ene << "os de antiguedad: ";
    cin >> YearMI;
    Ant = YearActual - YearMI;
    Apunt = Registro.RegresaPrimero();
    cout << "\n\t Lista de Pasajeros cuya antiguedad es >="<<YearMI<<endl;
    for (int i = 1; i < 90; i++)
    {
        if (i == 1)
        {
            cout << RayEIS;
        }
        else if (i == 11 || i == 52 || i == 83)
        {
            cout << RayT;
        }
        else if (i == 89)
        {
            cout << RayEDS;
        }
        else
        {
            cout << Ray;
        }
    }
    cout << "\n " << L << "Num" << L << left << setw(40) << " Nombre del Pasajero "<<L<<setw(30)<<" Domicilio "<<L<<" A "<<Ene<<" o "<<L<<endl;
        cout
         << " ";
    for (int j = 1; j < 90; j++)
    {
        if (j == 1)
        {
            cout << RayD;
        }
        else if (j == 11 || j == 52 || j == 83)
        {
            cout << CRay;
        }
        else if (j == 89)
        {
            cout << RayI;
        }
        else
        {
            cout << Ray;
        }
    }
    cout << endl;
    while (Apunt)
    {
        // if (Apunt->RegresarInfo().RegresaYearIngreso() <= Ant)
            Registro.ImprimeNodo(Apunt);
        Apunt = Registro.RegresaVecinoDer(Apunt);
    }
    cout << " ";
    for (int i = 1; i < 90; i++)
    {
        if (i == 1)
        {
            cout << RayEDB;
        }
        else if (i == 11 || i == 52 || i == 83)
        {
            cout << RayTV;
        }
        else if (i == 89)
        {
            cout << RayEIB;
        }
        else
        {
            cout << Ray;
        }
    }
}
int BusquedaAgregar(ListaDoLiga<Pasajero> Registro, int valorBusqueda)
{
    NodoDobleLiga<Pasajero> *Apunt;
    int cont = 0;
    Apunt = Registro.RegresaPrimero();
    while (Apunt)
    {
        if (Apunt->RegresarInfo().RegresanPasajero() ==
            valorBusqueda)
            cont = 1;
        Apunt = Registro.RegresaVecinoDer(Apunt);
    }
    return cont;
}
int CalculaTotal(ListaDoLiga<Pasajero> Registro)
{
    NodoDobleLiga<Pasajero> *Apunt;
    Apunt = Registro.RegresaPrimero();
    int Cant = 0;
    while (Apunt)
    {
        Apunt = Registro.RegresaVecinoDer(Apunt);
        Cant = Cant + 1;
    }
    return Cant;
}
void mostrarPasajeros(ListaDoLiga<Pasajero> Registro)
{
    NodoDobleLiga<Pasajero> *Apunt;
    Apunt = Registro.RegresaPrimero();
    cout << endl
         << " Lista de pasajeros\n con su informacion : "<<endl<<endl;
                         if (!Apunt)
    {
        cout << endl
             << "\t Lista vacia..." << endl;
    }
    else
    {
        cout << " ";
        for (int i = 1; i < 54; i++)
        {
            if (i == 1)
            {
                cout << RayEIS;
            }
            else if (i == 11 || i == 52 || i == 83)
            {
                cout << RayT;
            }
            else if (i == 89)
            {
                cout << RayEDS;
            }
            else
            {
                cout << Ray;
            }
        }
        cout << "\n " << L << "N.Pasajero" << L << left << setw(40) << " Nombre del Pasajero "<<L<<endl;
            cout
             << " ";
        for (int j = 1; j < 54; j++)
        {
            if (j == 1)
            {
                cout << RayD;
            }
            else if (j == 11 || j == 52 || j == 83)
            {
                cout << CRay;
            }
            else if (j == 89)
            {
                cout << RayI;
            }
            else
            {
                cout << Ray;
            }
        }
        cout << endl;
        while (Apunt)
        {
            Registro.ImprimeNodo(Apunt);
            Apunt = Registro.RegresaVecinoDer(Apunt);
        }
        cout << " ";
        for (int i = 1; i < 54; i++)
        {
            if (i == 1)
            {
                cout << RayEDB;
            }
            else if (i == 11 || i == 52 || i == 83)
            {
                cout << RayTV;
            }
            else if (i == 89)
            {
                cout << RayEIB;
            }
            else
            {
                cout << Ray;
            }
        }
    }
}
int main()
{
    ListaDoLiga<Pasajero> Registro;
    Pasajero Soc;
    char Opcion;
    int NumPasajero, Resp;
    system("Color 0F");
    fstream
        archivoLista("pasajeros.dat", ios::binary | ios::in | ios::out);
    if (!archivoLista)
    {
        cerr << "\n\t No se pudo abrir el archivo" << endl;
        exit(1);
    }
    if (archivoLista.is_open())
    {
        while (!archivoLista.eof())
        {

            archivoLista.read(reinterpret_cast<char *>(&Soc), sizeof(Pasajero));
            if (Registro.RegresaPrimero() == nullptr)
            {
                Registro.InsertaInicio(Soc);
            }
            else
            {
                Registro.InsertaFinal(Soc);
            }
        }
    }
    ofstream archivoListaS("pasajeros.dat", ios::binary);
    Registro.EliminaUnNodo(Soc);
    do
    {
        Opcion = Menu();
        switch (Opcion)
        {
        case 'A':
        {
            system("cls");
            int NumeroPasajero, YearIngreso, opcB;
            char NombrePasajero[64];
            char Domicilio[64];
            cout << "\n\t\t Ingrese datos del Pasajero a registrar.";
            cout<< endl<< "\t\t\t Registrar un nuevo Pasajero "<<endl;
            cout<< "\t\t____________________________________________________" << endl;
            cout << "\t\t Ingrese el numero de Pasajero: ";
            cin >> NumeroPasajero;
            Soc.establecernPasajero(NumeroPasajero);
            opcB = BusquedaAgregar(Registro, NumeroPasajero);
            if (opcB == 0)
            {
                cin.ignore();
                cout << "\t\t Ingrese nombre del Pasajero: ";
                cin.getline(NombrePasajero, 64, '\n');
                Soc.establecerNombre(NombrePasajero);
                // cout << "\t\t Ingrese el domicilio: ";
                // cin.getline(Domicilio, 64, '\n');
                // Soc.establecerDomicilio(Domicilio);
                // cout << "\t\t Ingrese el a" << Ene << "o de ingreso: ";
                // cin >>YearIngreso;
                // Soc.establecerYearIngreso(YearIngreso);
                Registro.InsertaOrdenado(Soc);
            }
            else if (opcB == 1)
            {
                cout << endl
                     << "\t\t El numero de Pasajero ya existe... "<<endl<<endl;
            }
            cout << "\t\t ";
            system("pause");
            break;
        }
        case 'B':
        {
            system("cls");
            cout << endl
                 << "\t Dar de baja un Pasajero";
            cout << "\n\t Ingrese el numero de Pasajero a eliminar: ";
            cin >> NumPasajero;
            // Pasajero So(NumPasajero, "", "", 0);
            Pasajero So(NumPasajero, "");
            Resp = Registro.EliminaUnNodo(So);
            if (Resp == 1)
                cout << "\n\t Baja registrada.\n";
            else if (Resp == -1)
                cout << "\n\t No hay Pasajeros registrados en inventario.\n ";
            else cout<< "\n\t No hay Pasajero registrado con el numero de Pasajero dado.\n ";
                cout<< "\t ";
            system("pause");
            break;
        }
        case 'C':
        {
            system("cls");
            ReportePasajeros(Registro);
            cout << "\n ";
            system("pause");
            break;
        }
        case 'D':
            system("cls");
            mostrarPasajeros(Registro);
            cout << "\n ";
            system("pause");
            break;
        case 'E':
            system("cls");
            cout << endl
                 << "\n\t Total de Pasajeros registrados: "<<CalculaTotal(Registro)<<endl;
                cout << "\n\t ";
            system("pause");
            break;
        case 'S':
            cout << endl
                 << "\t Saliendo del sistema..." << endl;
            break;
        }
    } while (Opcion == 'A' || Opcion == 'B' || Opcion == 'C' || Opcion == 'D' || Opcion == 'E' || Opcion == 'F');
    NodoDobleLiga<Pasajero> *Apunt2;
    Apunt2 = Registro.RegresaPrimero();
    while (Apunt2 != nullptr)
    {
        Soc = Apunt2->RegresarInfo();

        archivoListaS.write(reinterpret_cast<char *>(&Soc), sizeof(Pasajero));
        Apunt2 = Apunt2->enlaceNodo();
    }
}
