#include <iostream>
using namespace std;
#include "Bin_tree_eda.h"


int calcularEquiposRescate(bintree<int> arbol)
{
	if (arbol.empty())return 0;
	else {

		int ret = 0;
		int iz = calcularEquiposRescate(arbol.left());
		int der = calcularEquiposRescate(arbol.right());
		ret = iz + der;
		
		if (ret == 0 && arbol.root())ret++;

		return ret;
	}
}
int calcularMayorEquipo(bintree <int> arbol)
{
	if (arbol.empty())return 0;
	else {

		int ret = 0;
		int iz = calcularMayorEquipo(arbol.left());
		int der = calcularMayorEquipo(arbol.right());
		ret = max(iz , der)+ arbol.root();

		return ret;
	}
}

void resolverCaso()
{
	bintree<int> arbol = leerArbol(-1);
	
	cout << calcularEquiposRescate(arbol)<<" "<<calcularMayorEquipo(arbol)<<endl;
}

int main()
{
	int numC;
	cin >> numC;
	for (int i = 0; i < numC; i++)
	{
		resolverCaso();
	}
}