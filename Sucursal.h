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
    Empleado getEmpleado(string);
    void agregarEmpleado(Empleado);
    void eliminarEmpleado(string);

<<<<<<< HEAD
class Sucursal {
    public:
        Sucursal();
        Sucursal(int, int, int, Producto *, Empleado *, Cliente *);
        Sucursal(int, int, int);
        ~Sucursal();
        Empleado *empleados;
        Cliente *clientes;
        string getNombre();
        int getSizeEmpleados();

    private:
        string nombre;
        int dimProductos;
        int dimEmpleados;
        int dimClientes;

        Producto *productos;
        
=======
private:
    // Atributos
    string nombre;
    int numProductos;
    int numEmpleados;
    Producto *inventario;
    Empleado *empleados;
    int encuentraProducto(string);
    int encuentraEmpleado(string);
>>>>>>> f82a6181734dc2f481a8193bd3c37e32357c7778
};

#endif