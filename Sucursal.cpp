#include "Sucursal.h"

Sucursal::Sucursal()
{
    dimProductos = 1;
    dimEmpleados = 1;
    empleados = new Empleado[1];
    productos = new Producto[1];
}

Sucursal::Sucursal(int _dimProductos, int _dimEmpleados)
{
    dimProductos = _dimProductos;
    dimEmpleados = _dimEmpleados;
    empleados = new Empleado[_dimEmpleados];
    productos = new Producto[_dimProductos];
}

Sucursal::Sucursal(int _dimProductos, int _dimEmpleados, Producto *_productos, Empleado *_empleados)
{
    dimProductos = _dimProductos;
    dimEmpleados = _dimEmpleados;
    empleados = _empleados;
    productos = _productos;
}

Sucursal::~Sucursal()
{
}

int Sucursal::getSizeEmpleados()
{
    return dimEmpleados;
}