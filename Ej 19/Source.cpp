#include "ClaseExtendida.h"
#include <iostream>
#include "Bin_tree.h"
using namespace std;

void res()
{
	ClaseExtendida<char> arbol = readTreeData('.');

	cout << arbol.nodos() <<" "<< arbol.hojas() <<" "<< arbol.altura() << endl;
}

int main() {

	int numC;
	cin >> numC;
	for (int i = 0; i < numC; i++)res();
	return 0;
}