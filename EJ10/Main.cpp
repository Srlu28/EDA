#include <iostream>
using namespace std;
#include "Herencia.h"

bool resuelveCaso()
{
	int elemPrinc;
	ListaEnlazada <int> l,l2;
	cin >> elemPrinc;
	if (!cin)return false;
	else {
		int elem;
		for (int i = 0; i < elemPrinc; i++)
		{
			cin >> elem;
			l.push(elem);
		}
		int pos,elem2;
		cin >> elem2 >> pos;
		int n;
		for (int i = 0; i < elem2; i++) {
			cin >> n;
			l2.push(n);
		}
		l.inserta(l2,pos);
		l.print();
		return true;
	}
}

int main()
{
	while (resuelveCaso());
	return 0;
}