#include "Empleado.h"
#include <iostream>
using namespace std;

Empleado::Empleado(){
    cargo = "NULL";
}

Empleado::Empleado(string _Nombre, string _Direccion,string _Telefono, string _FechaNac, char _Sexo, string _Cargo)
                    :Persona (_Nombre, _Direccion, _Telefono, _FechaNac, _Sexo){
    cargo = _Cargo;

}

void Empleado::print(){
    cout << nombre<<" " << direccion<<" " << telefono<<" " << fechaNac<<" " << sexo<<" " << cargo <<endl;
}

string Empleado::getNombre(){
    return nombre;
}

void Empleado::borrarEmpleado(){
    nombre="NULL";
    direccion="NULL";
    telefono="NULL";
    fechaNac="NULL";
    sexo='X';
    cargo="NULL";

    //Actualizar el puntero de empleados dentro de sucursal
    //getsizeSucursal
    //for(int i; i<size; i++){
        //nombre = sucursal[i].getNombre()
        //if (nombre == "NULL")
        //int j = i
        //for (j; j<size; j++)
        //empleado[j] = empleado[j+1]
        //cambiar dimension de empleados en sucursal
    //}
}