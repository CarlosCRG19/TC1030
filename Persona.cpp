#include "Persona.h"

Persona::Persona(){
    nombre = "NULL";
    direccion = "NULL";
    telefono = "NULL";
    fechaNac = "NULL";
    sexo = 'X';
}

Persona::Persona(string _Nombre, string _Direccion, string _Telefono, string _FechaNac, char _Sexo){
    nombre = _Nombre;
    direccion = _Direccion;
    telefono = _Telefono;
    fechaNac = _FechaNac;
    sexo = _Sexo;
}

