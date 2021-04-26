#include "Sucursal.h"
#include <fstream>
#include <sstream>
#include <string>

#include <iostream>
using namespace std;



//Crea el Almacen a partir de un archivo .txt
Producto * crearInventario(){
    ifstream lector("productos.txt");
    string linea,codigo, nombre, aux;
    int cantidad,size=0;
    float precio,tam,peso;
    static Producto inventario[20];
    while(getline(lector,linea)){
        stringstream ss(linea);
        getline(ss,codigo,',');
        getline(ss,nombre, ',');
        getline(ss,aux,',');
        precio=stof(aux);
        getline(ss,aux,',');
        cantidad=stoi(aux);
        getline(ss,aux,',');
        peso=stof(aux);
        getline(ss,aux,',');
        tam=stof(aux);
        Producto nuevo(codigo,nombre,precio,cantidad,peso,tam);
        inventario[size]=nuevo;
        size++;
    }
    lector.close();
    return inventario;
}

int main() {
    
    Producto *inventario=crearInventario();
    Cliente cliente1("Luis David", "Const 5", 3411358179, "24/01/2002", 'M', "Lomlo");
    Cliente cliente2("Brandon Josue", "Pipila 8", 341345446, "12/08/2002", 'M', "LMLM");
    Empleado empleado1("Luis David", "Const 5", 3411358179, "24/01/2002", 'M', "CEO");
    Empleado empleado2("Brandon Josue", "Pipila 8", 341345446, "12/08/2002", 'M', "MVP");
    Empleado empleados[2] = {empleado1, empleado2};
    Cliente clientes[2] = {cliente1, cliente2};
    Sucursal casaRuiz(1, 2, 2, inventario, empleados, clientes);
    for(int i=0; i<20; i++){
        inventario[i].print();
    }
}