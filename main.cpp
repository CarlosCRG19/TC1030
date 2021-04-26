#include "Sucursal.h"

int main() {
    
    
    Cliente cliente1("Luis David", "Const 5", 3411358179, "24/01/2002", 'M', "Lomlo");
    Cliente cliente2("Brandon Josue", "Pipila 8", 341345446, "12/08/2002", 'M', "LMLM");
    Empleado empleado1("Luis David", "Const 5", 3411358179, "24/01/2002", 'M', "CEO");
    Empleado empleado2("Brandon Josue", "Pipila 8", 341345446, "12/08/2002", 'M', "MVP");
    Empleado empleados[2] = {empleado1, empleado2};
    Cliente clientes[2] = {cliente1, cliente2};
    Producto prod1("41234", "Leche", 27,  3, 1, 2000);
    Producto prods[1] = {prod1};
    Sucursal casaRuiz(1, 2, 2, prods, empleados, clientes);

}