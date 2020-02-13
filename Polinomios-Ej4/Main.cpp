#include <iostream>
using namespace std;
#include "Polinomio.h"
//Cambios realizados respecto a la versión mala:
//	-Añadida función que me añade los monomios respetando el orden de menor a mayor
//	 y en el caso de que se repita un exponente, este se añade
bool resuelveCaso()
{
	try
	{
		polinomio p;
		int numCasos;
		cin >> numCasos;
		for (int i = 0; i < numCasos; i++)
		{
			int val;
			cin >> val;
			cout << p.calcularValor(val) << endl;
		}
		return true;
	}
	catch (domain_error & e)
	{
		return false;
	}
}
int main()
{
	while (resuelveCaso());
	return 0;
}