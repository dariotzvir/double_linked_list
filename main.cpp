#include <iostream>
#include <vector>
#include <string>

#include "Lista.hpp"
#include "Nodo.hpp"

using namespace std;
using ListaInt = Lista<int>;
using NodoStr  = Nodo<string>;

void print_lista(const ListaInt &lista)
{
    for(uint i=0;i<lista.size();i++) cout << lista[i] << " ";
    cout << endl;
}

int main()
{
    ListaInt lista;
    lista.insertar(1);
    lista.insertar(2);
    lista.insertar(3);
    lista.insertar(5, 0);
    lista.insertar(123, 1);
    lista.insertar(43, -2);
    print_lista(lista);
    lista.eliminar(1);
    lista.eliminar(-2);
    print_lista(lista);
    return 0;
}
