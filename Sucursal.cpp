#include "Sucursal.h"

Sucursal::Sucursal() {
    dimProductos = 1;
    dimEmpleados = 1;
    dimClientes = 1;
    
    clientes = new Cliente[1];
    empleados = new Empleado[1];
    productos = new Producto[1];
}

Sucursal::Sucursal(int _dimProductos, int _dimEmpleados, int _dimCilentes) {
    dimProductos = _dimProductos;
    dimEmpleados = _dimEmpleados;
    dimClientes = _dimCilentes;

    clientes = new Cliente[_dimCilentes];
    empleados = new Empleado[_dimEmpleados];
    productos = new Producto[_dimProductos];
}

Sucursal::Sucursal(int _dimProductos, int _dimEmpleados, int _dimCilentes, Producto *_productos, Empleado *_empleados, Cliente *_clientes) {
    dimProductos = _dimProductos;
    dimEmpleados = _dimEmpleados;
    dimClientes = _dimCilentes;

    clientes = _clientes;
    empleados = _empleados;
    productos = _productos;
}

Sucursal::~Sucursal() {
}