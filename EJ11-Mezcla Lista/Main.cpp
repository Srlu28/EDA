#include <iostream>
using namespace std;
#include "Herencia.h"
void leerLista(ListaOrdenada<int> & l)
{
	int num;
	cin >> num;
	while (num != 0)
	{
		l.push(num);
		cin >> num;
	}
}
void resuelveCaso()
{
	ListaOrdenada<int> l1, l2;
	leerLista(l1);
	leerLista(l2);
	l1.mezclar_orden(l2);
	l1.print();
}
int main()
{
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
	{
		resuelveCaso();
	}
	return 0;
}