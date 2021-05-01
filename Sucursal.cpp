#include "Sucursal.h"

Sucursal::Sucursal()
{
    nombre = "";
    numProductos = 1;
    numEmpleados = 1;
    empleados = new Empleado[1];
    inventario = new Producto[1];
}

Sucursal::Sucursal(int _dimProductos, int _dimEmpleados)
{
    nombre = "";
    numProductos = _dimProductos;
    numEmpleados = _dimEmpleados;
    empleados = new Empleado[_dimEmpleados];
    inventario = new Producto[_dimProductos];
}

Sucursal::Sucursal(int _dimProductos, int _dimEmpleados, Producto *_productos, Empleado *_empleados)
{
    nombre = "";
    numProductos = _dimProductos;
    numEmpleados = _dimEmpleados;
    empleados = _empleados;
    inventario = _productos;
}

Sucursal::~Sucursal()
{
}

void Sucursal::imprimirEmpleados()
{
    cout << "\nLista de Empleados" << endl;
    cout << "------------------" << endl;
    for (int i = 0; i < numEmpleados; i++)
    {
        cout << i + 1 << ".";
        empleados[i].print();
    }
    cout << endl;
}

Empleado Sucursal::getEmpleado(string _nombre)
{
    int indice = this->encuentraEmpleado(_nombre);
    return empleados[indice];
}

int Sucursal::getSizeEmpleados()
{
    return numEmpleados;
}

// Métodos
void Sucursal::agregarEmpleado(Empleado empleado)
{
    Empleado *empleadosAuxiliar = new Empleado[numEmpleados + 1];
    for (int i = 0; i < numEmpleados; i++)
    {
        empleadosAuxiliar[i] = empleados[i];
    }
    empleadosAuxiliar[numEmpleados] = empleado;
    empleados = empleadosAuxiliar;
    numEmpleados += 1;
}

void Sucursal::eliminarEmpleado(string nombre)
{
    int indice = this->encuentraEmpleado(nombre);
    if (indice < numEmpleados)
    {
        for (int i = indice; i < numEmpleados - 1; i++)
        {
            empleados[i] = empleados[i + 1];
        }
        numEmpleados = numEmpleados - 1;
    }
}

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

void Sucursal::realizarOrden(string _empleado, string _producto, int _cantidad, string _formaPago)
{
    int indiceEmpleado = this->encuentraEmpleado(_empleado);
    Empleado empleado = empleados[indiceEmpleado];
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

void Sucursal::realizarOrden(string _empleado, int _numProductos, string *_productos, int *_cantidad, string _formaPago)
{
    int indiceEmpleado = this->encuentraEmpleado(_empleado);
    Empleado empleado = empleados[indiceEmpleado];
    if (empleado.getCargo() == "Gerente" || empleado.getCargo() == "Vendedor" || empleado.getCargo() == "gerente" || empleado.getCargo() == "vendedor")
    {
        int total = 0;
        for (int i = 0; i < _numProductos; i++)
        {
            int indice = this->encuentraProducto(_productos[i]);
            Producto producto = inventario[indice];
            cout << _cantidad[i] << " X " << producto.getNombre() << " - $" << producto.getPrecio() << endl;
            total += _cantidad[i] * producto.getPrecio();
            producto.modificaCantidad(_cantidad[i]);
            inventario[indice] = producto;
            this->reduceCantidadProducto(_productos[i], _cantidad[i]);
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

int Sucursal::encuentraEmpleado(string nombre)
{
    for (int i = 0; i < numEmpleados; i++)
    {
        if (empleados[i].getNombre() == nombre)
        {
            return i;
        }
    }
    return -1;
}
