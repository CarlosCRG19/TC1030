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
    // getters
    string getCodigo();
    string getNombre();
    float getPrecio();
    float getCantidad();
    float getPeso();
    float getSize();
    // métodos para mostar atributos
    void muestraAtributos();
    // métodos para modificar información
    void modificarInfo(int, float);
    void modificarInfo(int, string);
    void cambioCantidad(int);
    // método para imprimir datos del producto actual
    void print();
};

#endif