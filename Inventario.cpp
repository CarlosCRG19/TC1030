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
        cout << i + 1 << ".";
        productos[i].print();
    }
    cout << endl;
}

void Inventario::borrarProducto(int indice)
{
    if (indice - 1 < numProductos)
    {
        for (int i = indice - 1; i < numProductos; i++)
        {
            productos[i] = productos[i + 1];
        }
        numProductos = numProductos - 1;
    }
}

void Inventario::agregarProducto(Producto nuevoProducto)
{
    Producto *inventarioAuxiliar = new Producto[numProductos + 1];
    for (int i = 0; i < numProductos; i++)
    {
        inventarioAuxiliar[i] = productos[i];
    }
    inventarioAuxiliar[numProductos] = nuevoProducto;
    productos = inventarioAuxiliar;
    numProductos += 1;
}
// void Inventario::agregarProducto(Producto new_prod)
// {
//     Inventario aux(numProductos + 1);
//     for (int i = 0; i < numProductos; i++)
//     {
//         aux.productos[i] = productos[i];
//     }
//     aux.productos[numProductos] = new_prod;
//     productos = aux.productos;
//     numProductos += 1;
// }