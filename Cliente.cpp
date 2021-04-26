#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente(){
    RFC = "X";
}

Cliente::Cliente(string _Nombre, string _Direccion, string _Telefono, string _FechaNac, char _Sexo, string _RFC)
                    :Persona (_Nombre, _Direccion, _Telefono, _FechaNac, _Sexo){
    RFC = _RFC;

}

void Cliente::print(){
    cout << nombre <<" "<< direccion<<" " << telefono<<" " << fechaNac<<" " << sexo<<" " << RFC << endl;
}