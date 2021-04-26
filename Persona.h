#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using namespace std;

class Persona{
    protected: 
        string nombre;
        string direccion;
        string telefono;
        string fechaNac;
        char sexo;

    public:
        Persona();
        Persona(string, string, string , string, char);
        virtual void print()=0;
};

#endif
