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
    int getSizeEmpleados();
    // Métodos
    void imprimirEmpleados(); // imprime los nombres de los empleados
    int buscarEmpleado();     // regresa el índice donde se encuentra el empleado dentro del array
    void eliminarEmpleado();  // elimina empleado del array
    void agregarProducto(Producto);
    void eliminarProducto(int);
    void muestraProductos();
    void modificarProducto(int, int, string);
    void modificarProducto(int, int, float);
    void muestraAtributosProductos();
    void muestraAtributosEmpleado();
    void realizarOrden(int, int, int, string);
    void realizarOrden(int, int, int *, int *, string);
    void reduceCantidadProducto(int, int);

private:
    // Atributos
    int numProductos;
    int numEmpleados;
    Producto *inventario;
    Empleado *empleados;
};

#endif