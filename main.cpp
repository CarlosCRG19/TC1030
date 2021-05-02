#include "Sucursal.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Daxon.h"
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
    //Metodo para carga el inventario
    Producto *inventario = crearInventario();
    
    //Creación de Sucursal1 Ruiz
    Empleado empleado1("David", "Const 5", "3411358179", "24/01/2002", 'M', "administrador");
    Empleado empleado2("Brandon", "Pipila 8", "3411150662", "12/08/2002", 'M', "vendedor");
    Empleado empleado3("Jaime", "Carranza 15", "3411564872", "12/05/2000", 'M', "gerente");
    Empleado empleadosRuiz[3]={empleado1,empleado2,empleado3};
    Sucursal casaRuiz=Sucursal();
    casaRuiz.setNombre("Ruiz");
    casaRuiz.agregarEmpleado(empleado1);
    casaRuiz.agregarEmpleado(empleado2);
    casaRuiz.agregarEmpleado(empleado3);
    casaRuiz.agregarProducto(inventario[0]);
    casaRuiz.agregarProducto(inventario[1]);
    casaRuiz.agregarProducto(inventario[2]);
    casaRuiz.agregarProducto(inventario[3]);

     //Creación de Sucursal2 Perez
    Sucursal casaPerez=Sucursal();
    casaPerez.setNombre("Perez");
    Empleado empleado4("Alex", "Insurgentes 53", "3412453724", "24/02/2001", 'M', "administrador");
    Empleado empleado5("Haziel", "Ramon Corona 21", "3849513724", "28/08/1995", 'M', "vendedor");
    Empleado empleado6("Adriana", "Iturbide 12", "1472583629", "15/05/1998", 'M', "gerente");
    casaPerez.agregarEmpleado(empleado4);
    casaPerez.agregarEmpleado(empleado5);
    casaPerez.agregarEmpleado(empleado6);
    casaPerez.agregarProducto(inventario[0]);
    casaPerez.agregarProducto(inventario[1]);
    casaPerez.agregarProducto(inventario[2]);
    casaPerez.agregarProducto(inventario[3]);
    casaPerez.imprimirEmpleados();
    casaPerez.muestraProductos();
    Empleado empleadosPerez[3]={empleado4,empleado5,empleado6};
    
    //Clientes
    Cliente cliente1("Carlos", "Obregon 40", "3411561729", "24/03/2002", 'M', "Lomlo");
    Cliente cliente2("Haziel", "Insurgentes 8", "341345446", "12/10/2002", 'M', "LMLM");
    
    Cliente clientes[2] = {cliente1, cliente2};

    Sucursal sucursales[2]={casaPerez,casaRuiz};
    Daxon daxon(clientes,2,sucursales,2);

    //test agregar Producto
    Producto prueba("A5","Chookis",45.0,0,0.06,1000);
    daxon.agregaProducto(prueba);
    daxon.muestraProductosSucursal("Perez");
   
   
   

    /*Empleado empleados[2] = {empleado1, empleado2};
    Empleado empleados2[2] = {empleado3, empleado4};
    //Cliente clientes[3] = {cliente1, cliente2, cliente3};
    Sucursal casaRuiz("Ruiz", 20, 2, inventario, empleados);
    //casaRuiz.muestraProductos();
    //casaRuiz.agregarProducto(x);
    //casaRuiz.muestraProductos();
    //casaRuiz.eliminarProducto(20);
    //casaRuiz.muestraProductos();
    string arr[2] = {"A1", "A2"};
    int arr2[2] = {4, 4};
    //casaRuiz.realizarOrden("Luis David", 2, arr, arr2, "cuerpo");
    //casaRuiz.muestraProductos();
    Sucursal casaPerez("Perez", 20, 2, inventario, empleados2);
    Sucursal sucursales[2] = {casaPerez, casaRuiz};
    Daxon daxon(clientes, 2, sucursales, 2);
    daxon.muestraEmpleados("Perez");
    daxon.muestraEmpleados("Ruiz");
    daxon.transferirEmpleado("Jorge", "Perez", "Ruiz");
    daxon.muestraEmpleados("Perez");
    daxon.muestraEmpleados("Ruiz");
    // daxon.transferirEmpleado("Jorge", &casaPerez, &casaRuiz);
    // casaRuiz.imprimirEmpleados();
    // casaPerez.imprimirEmpleados();

    //daxon.crearOrden("Perez", "Panfilo", "Pedro", 2, arr, arr2, "Tarjeta");
    //casaPerez.muestraProductos();

    //daxon.modificaCliente("Haziel", 2, "Ramon corona");
    //daxon.quitaClientes("Carlos");
    //daxon.muestraClientes();

    //casaRuiz.empleados[1].borrarEmpleado();
    //casaRuiz.empleados[0].print();
    //casaRuiz.empleados[1].print();
    //casaRuiz.clientes[2].print();
    //casaRuiz.clientes[2].modificarInfo("telefono", "66677722");
    //casaRuiz.clientes[2].print();*/
}
