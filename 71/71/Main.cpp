#include <iostream>
using namespace std;
#include "Lista70.h"

bool resuelveCaso()
{
	int tam;
	cin >> tam;
	if (tam == 0)return false;
	else {
		Lista70<int> l;
		for (int i = 0; i < tam; i++)
		{
			int d;
			cin >> d;
			l.push(d);
		}
		l.intercambios();
		l.print(cout);
		return true;
	}
}
int main()
{
	while (resuelveCaso());
	return 0;
}