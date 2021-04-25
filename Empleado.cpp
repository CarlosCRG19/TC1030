#include "Empleado.h"
#include <iostream>
using namespace std;

Empleado::Empleado(){
    Cargo = "";
}

Empleado::Empleado(string _Nombre, string _Direccion, int _Telefono, string _FechaNac, char _Sexo, string _Cargo)
                    :Persona (_Nombre, _Direccion, _Telefono, _FechaNac, _Sexo){
    Cargo = _Cargo;

}

void Empleado::print(){
    cout << Nombre << Direccion << Telefono << FechaNac << Sexo << Cargo <<endl;
}