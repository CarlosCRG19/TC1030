#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente(){
    RFC = "alo";
}

Cliente::Cliente(string _Nombre, string _Direccion, int _Telefono, string _FechaNac, char _Sexo, string _RFC)
                    :Persona (_Nombre, _Direccion, _Telefono, _FechaNac, _Sexo){
    RFC = _RFC;

}

void Cliente::print(){
    cout << Nombre << Direccion << Telefono << FechaNac << Sexo << RFC << endl;
}