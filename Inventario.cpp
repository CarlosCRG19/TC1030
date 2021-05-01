#include "Inventario.h"

Inventario::Inventario()
{
    numProductos = 1;
    productos = new Producto[1];
}

Inventario::Inventario(int _numProductos)
{
    numProductos = _numProductos;
    productos = new Producto[numProductos];
}

Inventario::Inventario(int _numProductos, Producto *_productos)
{
    numProductos = _numProductos;
    productos = _productos;
}

void Inventario::muestraProductos()
{
    cout << "\nLista de Productos" << endl;
    cout << "------------------" << endl;
    for (int i = 0; i < numProductos; i++)
    {
        cout << i << ".";
        productos[i].print();
        cout << endl;
    }
}

void Inventario::borrarProducto(int indice)
{
    if (indice < numProductos)
    {
        numProductos = numProductos - 1;
        for (int i = 0; i < numProductos; i++)
        {
            productos[i] = productos[i + 1];
        }
        numProductos = numProductos - 1;
    }
}