#include "Producto.h"

Producto::Producto()
{
    codigo = "";
    nombre = "";
    precio = 0.0;
    cantidad = 0;
    peso = 0.0;
    size = 0.0;
}

Producto::Producto(string _Codigo, string _Nombre, float _Precio, int _Cantidad, float _Peso, float _Size)
{
    codigo = _Codigo;
    nombre = _Nombre;
    precio = _Precio;
    cantidad = _Cantidad;
    peso = _Peso;
    size = _Size;
}

string Producto::getCodigo() { return codigo; }
string Producto::getNombre() { return nombre; }
float Producto::getPrecio() { return precio; }
float Producto::getCantidad() { return cantidad; }
float Producto::getPeso() { return peso; }
float Producto::getSize() { return size; }

void Producto::muestraAtributos()
{
    cout << "\nAtributos del Producto" << endl;
    cout << "---------------------" << endl;
    cout << "1. Codigo (string)" << endl;
    cout << "2. Nombre (string)" << endl;
    cout << "3. Precio (float)" << endl;
    cout << "4. Cantidad (float)" << endl;
    cout << "5. Peso (float)" << endl;
    cout << "6. Size (float)" << endl;
    cout << endl;
    cout << "Si quiere modificar un atributo, recuerda utilizar el número del mismo y el tipo de dato que le corresponde.\n"
         << endl;
}

void Producto::modificarInfo(int atributo, string valor)
{
    switch (atributo)
    {
    case 1:
        codigo = valor;
        break;

    case 2:
        nombre = valor;
        break;

    default:
        cout << "Lo sentimos, ese atributo no existe. Revisa que estés utilizando el índice y tipo de dato correcto" << endl;
        break;
    }
}

void Producto::modificarInfo(int atributo, float valor)
{
    switch (atributo)
    {
    case 3:
        precio = valor;
        break;

    case 4:
        cantidad = valor;
        break;

    case 5:
        peso = valor;
        break;

    case 6:
        size = valor;
        break;

    default:
        cout << "Lo sentimos, ese atributo no existe. Revisa que estés utilizando el índice y tipo de dato correcto" << endl;
        break;
    }
}

void Producto::print()
{
    cout << "Producto -> "
         << "Código: " << codigo << "; Nombre: " << nombre << "; Precio: " << precio << "; Cantidad: " << cantidad << "; Peso: " << peso << "; Size: " << size << "." << endl;
}

void Producto::modificaCantidad(int _cantidadComprada)
{
    cout<<cantidad<<endl;
    cout<<_cantidadComprada<<endl;
    cantidad = cantidad - _cantidadComprada;
    cout<<cantidad;
}