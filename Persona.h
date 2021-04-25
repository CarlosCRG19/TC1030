#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using namespace std;

class Persona{
    protected: 
        string Nombre;
        string Direccion;
        int Telefono;
        string FechaNac;
        char Sexo;

    public:
        Persona();
        Persona(string, string, int , string, char);
        virtual void print()=0;
};

#endif
