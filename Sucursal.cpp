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
    if (indice < numProductos)
    {
        for (int i = indice; i < numProductos - 1; i++)
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

void Sucursal::modificarProducto(int producto, int atributo, string valor)
{
    if (producto > numProductos)
    {
        cout << "Excediste el tamaño del inventario. Ese producto no existe" << endl;
    }
    else
    {
        inventario[producto - 1].modificarInfo(atributo, valor);
    }
}

void Sucursal::modificarProducto(int producto, int atributo, float valor)
{
    if (producto > numProductos)
    {
        cout << "Excediste el tamaño del inventario. Ese producto no existe" << endl;
    }
    else
    {
        inventario[producto - 1].modificarInfo(atributo, valor);
    }
}

void Sucursal::muestraAtributosProductos()
{
    inventario[0].muestraAtributos();
}

void Sucursal::realizarOrden(int _empleado, int _producto, int _cantidad, string _formaPago)
{
    Empleado empleado = empleados[_empleado - 1];
    Producto producto = inventario[_producto - 1];
    if (empleado.getCargo() == "Gerente" || empleado.getCargo() == "Vendedor" || empleado.getCargo() == "gerente" || empleado.getCargo() == "vendedor")
    {
        cout << _cantidad << " X " << producto.getNombre() << " - $" << producto.getPrecio() << endl;
        cout << endl;
        cout << "TOTAL: $" << _cantidad * producto.getPrecio() << endl;
        cout << "FORMA DE PAGO: " << _formaPago << endl;
        cout << "------------------------------------" << endl;
    }
    else
    {
        cout << "ESTA ORDEN NO SE PUDO REALIZAR: contacte con un Gerente o Vendedor e intente nuevamente." << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
    }
}

void Sucursal::realizarOrden(int _empleado, int _numProductos, int *_producto, int *_cantidad, string _formaPago)
{
    Empleado empleado = empleados[_empleado - 1];
    if (empleado.getCargo() == "Gerente" || empleado.getCargo() == "Vendedor" || empleado.getCargo() == "gerente" || empleado.getCargo() == "vendedor")
    {
        int total = 0;
        for (int i = 0; i < _numProductos; i++)
        {
            Producto producto = inventario[_producto[i] - 1];
            cout << _cantidad[i] << " X " << producto.getNombre() << " - $" << producto.getPrecio() << endl;
            total += _cantidad[i] * producto.getPrecio();
            producto.modificaCantidad(_cantidad[i]);
            inventario[_producto[i] - 1]=producto;
        }
        cout << endl;
        cout << "TOTAL: $" << total << endl;
        cout << "FORMA DE PAGO: " << _formaPago << endl;
        cout << "------------------------------------" << endl;
    }
    else
    {
        cout << "ESTA ORDEN NO SE PUDO REALIZAR:  contacte con un Gerente o Vendedor e intente nuevamente." << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
    }
}

void Sucursal::reduceCantidadProducto(int _producto, int cantidad)
{
    Producto producto = inventario[_producto - 1];
    int nuevaCantidad = producto.getCantidad() - cantidad;
    producto.modificarInfo(4, nuevaCantidad);
}