#include "Sucursal.h"
#include "Cliente.h"
#include <fstream>
#include <sstream>
#include <string>
#include "Inventario.h"
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
    Inventario mi_inventario(20, inventario);
    mi_inventario.muestraProductos();
    Producto x("asda", "lol", 121, 12, 12, 12);
    mi_inventario.agregarProducto(x);
    mi_inventario.muestraProductos();
    //Cliente cliente1("Luis David", "Const 5", "3411358179", "24/01/2002", 'M', "Lomlo");
    //Cliente cliente2("Brandon Josue", "Pipila 8", "341345446", "12/08/2002", 'M', "LMLM");
    //Cliente cliente3("Frida Khalo", "Saturno 3", "331794452", "25/02/1986", 'F', "AOKDOG");
    //Empleado empleado1("Luis David", "Const 5", "3411358179", "24/01/2002", 'M', "gerente");
    //Empleado empleado2("Brandon Josue", "Pipila 8", "341345446", "12/08/2002", 'M', "vendedor");
    //Empleado empleados[3] = {empleado1, empleado2, empleado3};
    //Cliente clientes[3] = {cliente1, cliente2, cliente3};
    //Sucursal casaRuiz(1, 3, 3, inventario, empleados, clientes);
    //Sucursal casaPerez(1, 2, 2, inventario, empleados, clientes);
    //casaRuiz.empleados[1].borrarEmpleado();
    //casaRuiz.empleados[0].print();
    //casaRuiz.empleados[1].print();
    //casaRuiz.clientes[2].print();
    //casaRuiz.clientes[2].modificarInfo("telefono", "66677722");
    //casaRuiz.clientes[2].print();
}
