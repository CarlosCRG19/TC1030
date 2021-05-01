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

void Sucursal::realizarOrden(int _empleado, string _producto, int _cantidad, string _formaPago)
{
    Empleado empleado = empleados[_empleado - 1];
    int indice = this->encuentraProducto(_producto);
    Producto producto = inventario[indice];
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

void Sucursal::realizarOrden(int _empleado, int _numProductos, string *_productos, int *_cantidad, string _formaPago)
{
    Empleado empleado = empleados[_empleado - 1];
    if (empleado.getCargo() == "Gerente" || empleado.getCargo() == "Vendedor" || empleado.getCargo() == "gerente" || empleado.getCargo() == "vendedor")
    {
        int total = 0;
        for (int i = 0; i < _numProductos; i++)
        {
            int indice = this->encuentraProducto(_productos[i]);
            Producto producto = inventario[indice];
            cout << _cantidad[i] << " X " << producto.getNombre() << " - $" << producto.getPrecio() << endl;
            total += _cantidad[i] * producto.getPrecio();
<<<<<<< HEAD
            producto.modificaCantidad(_cantidad[i]);
            inventario[_producto[i] - 1]=producto;
=======
            this->reduceCantidadProducto(_productos[i], _cantidad[i]);
>>>>>>> f86ef50061a61cd04f1f311f35dd886c7bd0170f
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

void Sucursal::reduceCantidadProducto(string id, int cantidad)
{
    int indice = this->encuentraProducto(id);
    int nuevaCantidad = inventario[indice].getCantidad() - cantidad;
    inventario[indice].modificarInfo(4, nuevaCantidad);
}

void Sucursal::aumentaCantidadProducto(string id, int cantidad)
{
    int indice = this->encuentraProducto(id);
    int nuevaCantidad = inventario[indice].getCantidad() + cantidad;
    inventario[indice].modificarInfo(4, nuevaCantidad);
}

int Sucursal::encuentraProducto(string id)
{
    for (int i = 0; i < numProductos; i++)
    {
        if (inventario[i].getCodigo() == id)
        {
            return i;
        }
    }
    return -1;
}