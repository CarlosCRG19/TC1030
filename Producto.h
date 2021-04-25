#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
using namespace std;

class Producto{
    private:
        string Codigo;
        string Nombre;
        double Precio;
        int Cantidad;
        double Peso;
        double Size;

    public:
        Producto();
        Producto(string,string,double,int,double,double);
        void borrarProd(string);
        void inventario(int);
        void print();
};

#endif