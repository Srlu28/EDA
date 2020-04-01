#include "Arbol.h"
#include <iostream>
#include "ClaseExtendida.h"
using namespace std;



void resolverCaso()
{
	ArbolBusqueda<int> t = readTree(-1);
	t.esBusqueda();
}

int main()
{
	int numC;
	cin >> numC;
	for (int i = 0; i < numC; i++)
		resolverCaso();
}