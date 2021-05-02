#include "Daxon.h"

Daxon::Daxon(Cliente *_clientes, int _numClientes, Sucursal *_sucursales[2], int _numSucursales){
    clientes=_clientes;
    sucursales=_sucursales;
    numClientes=_numClientes;
    numSucursales=_numSucursales;
}

int Daxon::encuentraSucursal(string _sucursal){
    int index=-1;
    for(int i=0; i<numSucursales; i++){
        if(sucursales[i].getNombre()==_sucursal){
            index=i;
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

int Daxon::encuentraCliente(string _cliente) {
    int index;
    for(int i = 0; i < numClientes; i++) {
        if (clientes[i].getNombre() == _cliente) {
            index = i;
        }
    }
    return index;
}

void Daxon::quitaClientes(string _cliente) {
    int indice = encuentraCliente(_cliente);
    if(indice < numClientes) {
        for (int i = indice; i < numClientes - 1; i++)
        {
            clientes[i] = clientes[i + 1];
        }
        numClientes = numClientes - 1;
    }
}

void Daxon::modificaCliente(string _cliente, int _atributo, string _mod) {
    int indice = encuentraCliente(_cliente);
    clientes[indice].modificarInfo(_atributo, _mod);
}


void Daxon::modificaCliente(string _cliente, int _atributo, char _mod) {
    int indice = encuentraCliente(_cliente);
    clientes[indice].modificarInfo(_atributo, _mod);
}


void Daxon::transferirEmpleado(string _nombreEmpleado, Sucursal *_sucursalOrigen, Sucursal *_sucursalDestino){

    Sucursal *aux=new Sucursal[numSucursales];
    
    Sucursal origen = *_sucursalOrigen;
    Sucursal destino = *_sucursalDestino;

    Empleado empleado = origen.getEmpleado(_nombreEmpleado);
    empleado.print();
    destino.agregarEmpleado(empleado);
    destino.imprimirEmpleados();

    origen.eliminarEmpleado(_nombreEmpleado);
    origen.imprimirEmpleados();

    for (int i=0; i<numSucursales;i++){
        if(sucursales[i].getNombre()!=origen.getNombre() && sucursales[i].getNombre()!=destino.getNombre()){
            aux[i]=sucursales[i];
        }else if(sucursales[i].getNombre()==origen.getNombre()){
            aux[i]=origen;
        }else{
            aux[i]=destino;
        }
    }

    sucursales=aux;

}


void Daxon::crearOrden(string _sucursal, string _cliente, string _empleado, string _producto, int _cantidad, string _formaPago) {
    int index_sucursal=encuentraSucursal(_sucursal);
    sucursales[index_sucursal].realizarOrden(_empleado, _producto, _cantidad, _formaPago);
}

void Daxon::crearOrden(string _sucursal, string _cliente, string _empleado, int _numProductos, string *_producto, int *_cantidad, string _formaPago) {
    int index_sucursal=encuentraSucursal(_sucursal);
    sucursales[index_sucursal].realizarOrden(_empleado, _numProductos, _producto, _cantidad, _formaPago);
}