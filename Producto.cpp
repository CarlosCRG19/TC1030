#include "Producto.h"

Producto::Producto(){
    codigo = "";
    nombre = "";
    precio = 0.0;
    cantidad = 0;
    peso = 0.0;
    size = 0.0;
}

Producto::Producto(string _Codigo, string _Nombre, float _Precio, int _Cantidad, float _Peso, float _Size){
    codigo = _Codigo;
    nombre = _Nombre;
    precio = _Precio;
    cantidad = _Cantidad;
    peso = _Peso;
    size = _Size;
}

void Producto::print(){
    cout << codigo <<" "<<nombre<<" " << precio<<" " << cantidad<<" " << peso<<" " << size << endl;
}

string Producto::getNombre(){
    return nombre;
}

void Producto::borrarProd(string codigo){
    codigo = "NULL";
    nombre = "NULL";
    precio = 0.0;
    cantidad = 0;
    peso = 0.0;
    size = 0.0;
}

void Producto::modificiarInfo(string dato, float cambio){
    if (dato == "precio"){
        precio = cambio;
    }else if (dato == "peso"){
        peso = cambio;
    }else if (dato == "peso"){
        peso = cambio;
    }
}