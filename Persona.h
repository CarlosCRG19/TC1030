#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using namespace std;

class Persona
{
protected:
    string nombre;
    string direccion;
    string telefono;
    string fechaNac;
    char sexo;

public:
    Persona();
    Persona(string, string, string, string, char);
    // getters
    string getNombre() const;
    string getDireccion() const;
    string getTelefono() const;
    string getFechaNac() const;
    char getSexo() const;
    // setters
    void setNombre(string);
    void setDireccion(string);
    void setTelefono(string);
    void setFechaNac(string);
    void setSexo(char);
    // método para mostrar atributos
    virtual void muestraAtributos() = 0;
    // método para modificar atributos
    void modificarInfo(int, string);
    void modificarInfo(int, char);
};

#endif
