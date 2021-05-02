#ifndef DAXON_H_INCLUDED
#define DAXON_H_INCLUDED

#include "Cliente.h"
#include "Sucursal.h"
class Daxon
{
private:
    Cliente *clientes;
    Sucursal *sucursales;
    int numClientes;
    int numSucursales;
    int encuentraSucursal(string);

public:
    Daxon(Cliente *, int, Sucursal *, int);
    void transferirEmpleado(string, string, string);
    void muestraClientes();
    void muestraSucursales();
    void muestraEmpleados(string);
    void quitaClientes(string);
    int encuentraCliente(string);
    void modificaCliente(string, int, string);
    void modificaCliente(string, int, char);
    void crearOrden(string, string, string, string, int, string);
    void crearOrden(string, string, string, int, string *, int *, string);
};
#endif