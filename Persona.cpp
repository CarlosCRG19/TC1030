#include "Persona.h"

Persona::Persona(){
    Nombre = "";
    Direccion = "";
    Telefono = 0;
    FechaNac = "";
    Sexo = ' ';
}

Persona::Persona(string _Nombre, string _Direccion, int _Telefono, string _FechaNac, char _Sexo){
    Nombre = _Nombre;
    Direccion = _Direccion;
    Telefono = _Telefono;
    FechaNac = _FechaNac;
    Sexo = _Sexo;
}

void Persona::print(){
    cout<<"33"<<endl;
} 

