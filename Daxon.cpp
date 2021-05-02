#include "Daxon.h"

Daxon::Daxon(Cliente *_clientes, int _numClientes, Sucursal *_sucursales, int _numSucursales)
{
    clientes = _clientes;
    sucursales = _sucursales;
    numClientes = _numClientes;
    numSucursales = _numSucursales;
}

int Daxon::encuentraSucursal(string _sucursal)
{
    int index = -1;
    for (int i = 0; i < numSucursales; i++)
    {
        if (sucursales[i].getNombre() == _sucursal)
        {
            index = i;
        }
    }
    return index;
}

void Daxon::muestraClientes()
{
    cout << "\nLista de Clientes" << endl;
    cout << "------------------" << endl;
    for (int i = 0; i < numClientes; i++)
    {
        cout << i + 1 << ".";
        clientes[i].print();
    }
    cout << endl;
}

int Daxon::encuentraCliente(string _cliente)
{
    int index;
    for (int i = 0; i < numClientes; i++)
    {
        if (clientes[i].getNombre() == _cliente)
        {
            index = i;
        }
    }
    return index;
}

void Daxon::quitaClientes(string _cliente)
{
    int indice = encuentraCliente(_cliente);
    if (indice < numClientes)
    {
        for (int i = indice; i < numClientes - 1; i++)
        {
            clientes[i] = clientes[i + 1];
        }
        numClientes = numClientes - 1;
    }
}

void Daxon::modificaCliente(string _cliente, int _atributo, string _mod)
{
    int indice = encuentraCliente(_cliente);
    clientes[indice].modificarInfo(_atributo, _mod);
}

void Daxon::modificaCliente(string _cliente, int _atributo, char _mod)
{
    int indice = encuentraCliente(_cliente);
    clientes[indice].modificarInfo(_atributo, _mod);
}

void Daxon::transferirEmpleado(string nombreEmpleado, string _sucursalOrigen, string _sucursalDestino)
{
    int indiceOrigen = encuentraSucursal(_sucursalOrigen);
    int indiceDestino = encuentraSucursal(_sucursalDestino);
    Empleado auxiliarEmpleado = sucursales[indiceOrigen].getEmpleado(nombreEmpleado);

    sucursales[indiceOrigen].eliminarEmpleado(nombreEmpleado);
    sucursales[indiceDestino].agregarEmpleado(auxiliarEmpleado);
}

void Daxon::crearOrden(string _sucursal, string _cliente, string _empleado, string _producto, int _cantidad, string _formaPago)
{
    int index_sucursal = encuentraSucursal(_sucursal);
    sucursales[index_sucursal].realizarOrden(_empleado, _producto, _cantidad, _formaPago);
}

void Daxon::crearOrden(string _sucursal, string _cliente, string _empleado, int _numProductos, string *_producto, int *_cantidad, string _formaPago)
{
    int index_sucursal = encuentraSucursal(_sucursal);
    sucursales[index_sucursal].realizarOrden(_empleado, _numProductos, _producto, _cantidad, _formaPago);
}

void Daxon::muestraSucursales()
{
    cout << "\nLista de Sucursales" << endl;
    cout << "------------------" << endl;
    for (int i = 0; i < numSucursales; i++)
    {
        cout << i + 1 << ". " << sucursales[i].getNombre() << endl;
    }
    cout << endl;
}
void Daxon::muestraEmpleados(string nombreSucursal)
{
    int indice = encuentraSucursal(nombreSucursal);
    sucursales[indice].imprimirEmpleados();
}

void Daxon::eliminarProductos(string _nombre){
    for(int i=0; i<numSucursales;i++){
        int indice=sucursales[i].encuentraProducto(_nombre);
        sucursales[i].eliminarProducto(indice);
    }
}

void Daxon::muestraProductosSucursal(string _nombre){
    int indice=encuentraSucursal(_nombre);
    sucursales[indice].muestraProductos();
}

void Daxon::agregaProducto(Producto nuevo_producto){
    for(int i=0; i<numSucursales;i++){
        sucursales[i].agregarProducto(nuevo_producto);
    }
}