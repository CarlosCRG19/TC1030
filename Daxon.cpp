#include "Daxon.h"

Daxon::Daxon(Cliente *_clientes, int _numClientes, Sucursal *_sucursales, int _numSucursales){
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

void Daxon::transferirEmpleado(string _nombreEmpleado, string _sucursalOrigen, string _sucursalDestino){
    
}