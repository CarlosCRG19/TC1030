#ifndef SUCURSAL_H
#define SUCURSAL_H

#include "Empleado.h"
#include "Cliente.h"
#include "Producto.h"

class Sucursal
{
public:
    Sucursal();
    Sucursal(string, int, int, Producto *, Empleado *);
    Sucursal(int, int);
    ~Sucursal();
    int getSizeEmpleados();
    // Métodos
    void imprimirEmpleados(); // imprime los nombres de los empleados
    void eliminarEmpleado();  // elimina empleado del array
    void agregarProducto(Producto);
    void eliminarProducto(int);
    void muestraProductos();
    void modificarProducto(int, int, string);
    void modificarProducto(int, int, float);
    void muestraAtributosProductos();
    void muestraAtributosEmpleado();
    void realizarOrden(string, string, int, string);
    void realizarOrden(string, int, string *, int *, string);
    void reduceCantidadProducto(string, int);
    void aumentaCantidadProducto(string, int);
    string getNombre();
    Empleado getEmpleado(string);
    void agregarEmpleado(Empleado);
    void eliminarEmpleado(string);
    int encuentraProducto(string);
    int encuentraEmpleado(string);
    void setNombre(string);

private:
    // Atributos
    string nombre;
    int numProductos;
    int numEmpleados;
    Producto *inventario;
    Empleado *empleados;
    
};

#endif