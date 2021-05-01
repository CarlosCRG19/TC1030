#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"
#include <iostream>
using namespace std;

class Empleado : public Persona
{
private:
    string cargo;

public:
    Empleado();
    Empleado(string, string, string, string, char, string);
    void muestraAtributos();
    virtual void print();
    void modificarInfo(int, string);
    void modificarInfo(int, char);
    string getCargo();
};

#endif