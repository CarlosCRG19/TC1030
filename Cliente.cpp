#include "Cliente.h"
#include <iostream>
using namespace std;

// Constructor por default
Cliente::Cliente()
{
    RFC = "X";
}

// Constructor parametrizado
Cliente::Cliente(string _Nombre, string _Direccion, string _Telefono, string _FechaNac, char _Sexo, string _RFC)
    : Persona(_Nombre, _Direccion, _Telefono, _FechaNac, _Sexo)
{
    RFC = _RFC;
}

void Cliente::muestraAtributos()
{
    cout << "\nAtributos del Cliente" << endl;
    cout << "---------------------" << endl;
    cout << "1. Nombre (string)" << endl;
    cout << "2. Dirección (string)" << endl;
    cout << "3. Teléfono (string)" << endl;
    cout << "4. Fecha de Nacimiento (string)" << endl;
    cout << "5. Sexo (char)" << endl;
    cout << "6. RFC(string)" << endl;
    cout << "Si quiere modificar un atributo, recuerda utilizar el número del mismo y el tipo de dato que le corresponde.\n"
         << endl;
}

void Cliente::modificarInfo(int atributo, string valor)
{
    switch (atributo)
    {
    case 1:
        nombre = valor;
        break;

    case 2:
        direccion = valor;
        break;

    case 3:
        telefono = valor;
        break;

    case 4:
        fechaNac = valor;
        break;

    case 6:
        RFC = valor;
        break;

    default:
        cout << "Lo sentimos, ese atributo no existe. Revisa que estés utilizando el índice y tipo de dato correcto" << endl;
        break;
    }
}

void Cliente::modificarInfo(int atributo, char valor)
{
    switch (atributo)
    {
    case 5:
        sexo = valor;
        break;

    default:
        cout << "Lo sentimos, ese atributo no existe. Revisa que estés utilizando el índice y tipo de dato correcto" << endl;
        break;
    }
}

void Cliente::print()
{
    cout << "Cliente -> "
         << "Nombre: " << nombre << "; Dirección: " << direccion << "; Teléfono: " << telefono << "; Fecha Nacimiento: " << fechaNac << "; RFC: " << RFC << "." << endl;
}