#include "Producto.h"

Producto::Producto(){
    Codigo = "";
    Nombre = "";
    Precio = 0.0;
    Cantidad = 0;
    Peso = 0.0;
    Size = 0.0;
}

Producto::Producto(string _Codigo, string _Nombre, double _Precio, int _Cantidad, double _Peso, double _Size){
    Codigo = _Codigo;
    Nombre = _Nombre;
    Precio = _Precio;
    Cantidad = _Cantidad;
    Peso = _Peso;
    Size = _Size;
}

void Producto::print(){
    cout << Codigo << Nombre << Precio << Cantidad << Peso << Size << endl;
}