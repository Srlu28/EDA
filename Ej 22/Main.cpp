#include <iostream>
using namespace std;
#include "arbol.h"
#include <algorithm>

typedef struct
{
	int height, diameter;
}tInformacion;

template <class T>
tInformacion recurS(bintree<T> const& arbol)
{
	if (arbol.empty()) return{ 0,0 };
	else {
		tInformacion l = recurS(arbol.left()), r = recurS(arbol.right());
		int height = max(l.height, r.height) + 1;
		int diam = max(max(l.diameter, r.diameter), l.height + r.height + 1);
		return { height,diam };
	}
}
void resuelveCaso()
{
	bintree<char> arbol = leerArbol('.');
	tInformacion inf = recurS(arbol);
	cout << inf.diameter<<endl;
}

int main()
{
	int numC;
	cin >> numC;
	for (int i = 0; i < numC; i++)
	{
		resuelveCaso();
	}
}