#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"
#include <iostream>
using namespace std;

class Empleado: public Persona {
    private:
        string Cargo;
    
    public:
        Empleado();
        Empleado(string,string,int,string,char,string);
        void borrarEmpleado(int);
        virtual void print();

};

#endif