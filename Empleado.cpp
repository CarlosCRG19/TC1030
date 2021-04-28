#include "Empleado.h"
#include <iostream>
using namespace std;

Empleado::Empleado()
{
    cargo = "NULL";
}

Empleado::Empleado(string _Nombre, string _Direccion, string _Telefono, string _FechaNac, char _Sexo, string _Cargo)
    : Persona(_Nombre, _Direccion, _Telefono, _FechaNac, _Sexo)
{
    cargo = _Cargo;
}

void Empleado::print()
{
    cout << nombre << " " << direccion << " " << telefono << " " << fechaNac << " " << sexo << " " << cargo << endl;
}

void Empleado::modificarInfo(string atributo, string valor)
{
    if (atributo == "cargo")
    {
        cargo = valor;
    }
    else
    {
        Persona::modificarInfo(atributo, valor);
    }
}