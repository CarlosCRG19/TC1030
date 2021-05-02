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
    Empleado empleadosRuiz[3] = {empleado1, empleado2, empleado3};
    Sucursal casaRuiz = Sucursal();
    casaRuiz.setNombre("Ruiz");
    casaRuiz.agregarEmpleado(empleado1);
    casaRuiz.agregarEmpleado(empleado2);
    casaRuiz.agregarEmpleado(empleado3);
    casaRuiz.agregarProducto(inventario[0]);
    casaRuiz.agregarProducto(inventario[1]);
    casaRuiz.agregarProducto(inventario[2]);
    casaRuiz.agregarProducto(inventario[3]);

    //Creación de Sucursal2 Perez
    Sucursal casaPerez = Sucursal();
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
    Empleado empleadosPerez[3] = {empleado4, empleado5, empleado6};

    //Clientes
    Cliente cliente1("Carlos", "Obregon 40", "3411561729", "24/03/2002", 'M', "Lomlo");
    Cliente cliente2("Haziel", "Insurgentes 8", "341345446", "12/10/2002", 'M', "LMLM");

    Cliente clientes[2] = {cliente1, cliente2};

    Sucursal sucursales[2] = {casaPerez, casaRuiz};
    Daxon daxon(clientes, 2, sucursales, 2);

    //test agregar Producto
    Producto prueba("A5", "Chookis", 45.0, 0, 0.06, 1000);
    daxon.agregaProducto(prueba);
    daxon.muestraProductosSucursal("Perez");

    //agregar cantidad de productos a todas las sucursales

    daxon.agregaCantidadProductos("A1", 7);
    daxon.agregaCantidadProductos("A2", 7);
    daxon.agregaCantidadProductos("A3", 7);
    daxon.agregaCantidadProductos("A4", 7);
    daxon.agregaCantidadProductos("A5", 7);

    daxon.muestraProductosSucursal("Perez");

    // e) Agregar 3 clientes, modificar 1 cliente y quitar 1 cliente
    daxon.muestraClientes();
    Cliente nuevoCliente("Emilio Mendoza", "Unknown", "33244255", "26/01/2001", 'M', "MP0101");
    Cliente nuevoCliente2("Pablo Ortega", "Pedro Cervantes Vazquez", "3135335", "12/12/2001", 'M', "PABLO0101");
    Cliente nuevoCliente3("Noah Loud", "Beverly Hills", "3121206124", "23/04/2002", 'M', "NOAH2304202");
    daxon.agregarClientes(nuevoCliente);
    daxon.agregarClientes(nuevoCliente2);
    daxon.agregarClientes(nuevoCliente3);
    daxon.muestraClientes();

    // e.1) Modificar Cliente
    daxon.modificaCliente("Pablo Ortega", 5, 'F');
    daxon.muestraClientes();

    // e.2) Quitar Cliente
    daxon.quitaClientes("Emilio Mendoza");
    daxon.muestraClientes();

    // f) Orden con administrador (mensaje de error)
    daxon.crearOrden("Ruiz", "Carlos", "David", "A1", 7, "Tarjeta");

    // g) Orden con vendedor (debe realizar la orden)
    daxon.crearOrden("Ruiz", "Carlos", "Jaime", "A1", 7, "Tarjeta");

    // i) Mostrar datos de clientes
    cout << "Cliente de la compra " << endl;
    daxon.imprimeCliente("Carlos");
}
