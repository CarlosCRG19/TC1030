#ifndef DAXON_H_INCLUDED
#define DAXON_H_INCLUDED

#include "Cliente.h"
#include "Sucursal.h"
class Daxon{
    private:
        Cliente *clientes;
        Sucursal * sucursales;
        int numClientes;
        int numSucursales;
        int encuentraSucursal(string);
        void muestraClientes();
    public:
        Daxon(Cliente *,int,Sucursal *, int);
        void transferirEmpleado(string, string, string);


};
#endif;