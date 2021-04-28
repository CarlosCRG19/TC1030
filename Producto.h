#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
using namespace std;

class Producto
{
private:
    string codigo;
    string nombre;
    float precio;
    int cantidad;
    float peso;
    float size;

public:
    Producto();
    Producto(string, string, float, int, float, float);
    void inventario(int);
    void print();
    string getNombre();
    void modificiarInfo(string, float);
    void cambioCantidad(int);
};

#endif