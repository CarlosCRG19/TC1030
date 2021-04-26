#ifndef SUCURSAL_H
#define SUCURSAL_H

#include "Empleado.h"
#include "Cliente.h"
#include "Producto.h"


class Sucursal {
    public:
        Sucursal();
        Sucursal(int, int, int, Producto *, Empleado *, Cliente *);
        Sucursal(int, int, int);
        ~Sucursal();
        Empleado *empleados;
    private:
        int dimProductos;
        int dimEmpleados;
        int dimClientes;

        Producto *productos;
        Cliente *clientes;
};

#endif