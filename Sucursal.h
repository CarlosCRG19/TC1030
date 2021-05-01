#ifndef SUCURSAL_H
#define SUCURSAL_H

#include "Empleado.h"
#include "Cliente.h"
#include "Producto.h"

class Sucursal
{
public:
    Sucursal();
    Sucursal(int, int, Producto *, Empleado *);
    Sucursal(int, int);
    ~Sucursal();
    Empleado *empleados;
    int getSizeEmpleados();

private:
    // Atributos
    int dimProductos;
    int dimEmpleados;
    Producto *productos;
    // Métodos
    void imprimirEmpleados(); // imprime los nombres de los empleados
    int buscarEmpleado();     // regresa el índice donde se encuentra el empleado dentro del array
    void eliminarEmpleado();  // elimina empleado del array
};

#endif