#include "Sucursal.h"

Sucursal::Sucursal()
{
    numProductos = 1;
    numEmpleados = 1;
    empleados = new Empleado[1];
    inventario = new Producto[1];
}

Sucursal::Sucursal(int _dimProductos, int _dimEmpleados)
{
    numProductos = _dimProductos;
    numEmpleados = _dimEmpleados;
    empleados = new Empleado[_dimEmpleados];
    inventario = new Producto[_dimProductos];
}

Sucursal::Sucursal(int _dimProductos, int _dimEmpleados, Producto *_productos, Empleado *_empleados)
{
    numProductos = _dimProductos;
    numEmpleados = _dimEmpleados;
    empleados = _empleados;
    inventario = _productos;
}

Sucursal::~Sucursal()
{
}

int Sucursal::getSizeEmpleados()
{
    return numEmpleados;
}

// Métodos
void Sucursal::agregarProducto(Producto nuevoProducto)
{
    Producto *inventarioAuxiliar = new Producto[numProductos + 1];
    for (int i = 0; i < numProductos; i++)
    {
        inventarioAuxiliar[i] = inventario[i];
    }
    inventarioAuxiliar[numProductos] = nuevoProducto;
    inventario = inventarioAuxiliar;
    numProductos += 1;
}

void Sucursal::eliminarProducto(int indice)
{
    if (indice - 1 < numProductos)
    {
        for (int i = indice - 1; i < numProductos-1; i++)
        {
            inventario[i] = inventario[i + 1];
        }
        numProductos = numProductos - 1;
    }
}

void Sucursal::muestraProductos()
{
    cout << "\nLista de Productos" << endl;
    cout << "------------------" << endl;
    for (int i = 0; i < numProductos; i++)
    {
        cout << i + 1 << ".";
        inventario[i].print();
    }
    cout << endl;
}
