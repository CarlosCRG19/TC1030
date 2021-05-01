#include "Sucursal.h"

Sucursal::Sucursal()
{
    nombre = "";
    numProductos = 1;
    numEmpleados = 1;
    empleados = new Empleado[1];
    inventario = new Producto[1];
}

Sucursal::Sucursal(string _nombre, int _dimProductos, int _dimEmpleados)
{
    nombre = _nombre;
    numProductos = _dimProductos;
    numEmpleados = _dimEmpleados;
    empleados = new Empleado[_dimEmpleados];
    inventario = new Producto[_dimProductos];
}

Sucursal::Sucursal(string _nombre, int _dimProductos, int _dimEmpleados, Producto *_productos, Empleado *_empleados)
{
    nombre = _nombre;
    numProductos = _dimProductos;
    numEmpleados = _dimEmpleados;
    empleados = _empleados;
    inventario = _productos;
}

Sucursal::~Sucursal() {
}

int Sucursal::getSizeEmpleados(){
    return dimEmpleados;
}

string Sucursal::getNombre() {
    return nombre;
}