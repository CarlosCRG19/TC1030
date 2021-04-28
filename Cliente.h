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
    virtual void print();
    void modificarInfo(string, string);
};

#endif