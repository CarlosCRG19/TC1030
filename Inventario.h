#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Producto.h"

class Inventario
{
public:
    Inventario();
    Inventario(int);
    Inventario(int, Producto *);
    void modificarProducto(int, int, string);
    void modificarProducto(int, int, float);
    void muestraProductos();
    void agregarProducto();
    void borrarProducto(int);

private:
    int numProductos;
    Producto *productos;
};

#endif