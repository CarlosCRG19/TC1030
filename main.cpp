#include "Sucursal.h"
#include "Cliente.h"
#include "Empleado.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

//Crea el Almacen a partir de un archivo .txt
Producto *crearInventario()
{
    ifstream lector("productos.txt");
    string linea, codigo, nombre, aux;
    int cantidad, size = 0;
    float precio, tam, peso;
    static Producto inventario[20];
    while (getline(lector, linea))
    {
        stringstream ss(linea);
        getline(ss, codigo, ',');
        getline(ss, nombre, ',');
        getline(ss, aux, ',');
        precio = stof(aux);
        getline(ss, aux, ',');
        cantidad = stoi(aux);
        getline(ss, aux, ',');
        peso = stof(aux);
        getline(ss, aux, ',');
        tam = stof(aux);
        Producto nuevo(codigo, nombre, precio, cantidad, peso, tam);
        inventario[size] = nuevo;
        size++;
    }
    lector.close();
    return inventario;
}

int main()
{
    Producto *inventario = crearInventario();
    Producto x("asda", "lol", 121, 12, 12, 12);
    Cliente cliente1("Luis David", "Const 5", "3411358179", "24/01/2002", 'M', "Lomlo");
    Cliente cliente2("Brandon Josue", "Pipila 8", "341345446", "12/08/2002", 'M', "LMLM");
    Cliente cliente3("Frida Khalo", "Saturno 3", "331794452", "25/02/1986", 'F', "AOKDOG");
    Empleado empleado1("Luis David", "Const 5", "3411358179", "24/01/2002", 'M', "vendedor");
    Empleado empleado2("Brandon Josue", "Pipila 8", "341345446", "12/08/2002", 'M', "vendedor");
    Empleado empleados[2] = {empleado1, empleado2};
    //Cliente clientes[3] = {cliente1, cliente2, cliente3};
    Sucursal casaRuiz(20, 2, inventario, empleados);
    casaRuiz.muestraProductos();
    casaRuiz.agregarProducto(x);
    casaRuiz.muestraProductos();
    casaRuiz.eliminarProducto(20);
    casaRuiz.muestraProductos();
    int arr[2] = {1, 2};
    int arr2[2] = {4, 4};
    casaRuiz.realizarOrden(1, 2, arr, arr2, "cuerpo");
    casaRuiz.muestraProductos();
    //Sucursal casaPerez(1, 2, 2, inventario, empleados, clientes);
    //casaRuiz.empleados[1].borrarEmpleado();
    //casaRuiz.empleados[0].print();
    //casaRuiz.empleados[1].print();
    //casaRuiz.clientes[2].print();
    //casaRuiz.clientes[2].modificarInfo("telefono", "66677722");
    //casaRuiz.clientes[2].print();
}
