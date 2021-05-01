#ifndef CLIENTE_H
#define CLIENTE_H
#include "Persona.h"
#include <iostream>
using namespace std;

class Cliente : public Persona
{
private:
    string RFC;

public:
    Cliente();
    Cliente(string, string, string, string, char, string);
    // método para mostrar atributos
    virtual void muestraAtributos();
    // método para modificar atributos
    void modificarInfo(int, string);
    void modificarInfo(int, char);
};

#endif