#include "Persona.h"

Persona::Persona()
{
    nombre = "NULL";
    direccion = "NULL";
    telefono = "NULL";
    fechaNac = "NULL";
    sexo = 'X';
}

Persona::Persona(string _Nombre, string _Direccion, string _Telefono, string _FechaNac, char _Sexo)
{
    nombre = _Nombre;
    direccion = _Direccion;
    telefono = _Telefono;
    fechaNac = _FechaNac;
    sexo = _Sexo;
}

// Getters y Setters

string Persona::getNombre() const { return nombre; }
string Persona::getDireccion() const { return direccion; }
string Persona::getTelefono() const { return telefono; }
string Persona::getFechaNac() const { return fechaNac; }
char Persona::getSexo() const { return sexo; }
void Persona::setNombre(string _nombre) { nombre = _nombre; }
void Persona::setDireccion(string _direccion) { direccion = _direccion; }
void Persona::setFechaNac(string _fechaNac) { fechaNac = _fechaNac; }
void Persona::setSexo(char _sexo) { sexo = _sexo; }

// Método para modificar atributos
