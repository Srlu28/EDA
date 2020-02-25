#include <iostream>
using namespace std;
#include "HerenciaCola.h"
bool resuelveCaso()
{
	int frecDesc, tam;
	cin >> tam >> frecDesc;
	if (tam == 0 && frecDesc == 0)
		return false;
	else
	{
		Herencia<int> Lista;
		for (int i = 1; i <= tam; i++)
		{
			Lista.push(i);
		}
		Lista.resuelveCaso(frecDesc);
		Lista.print();
		return true;
	}
}
int main()
{
	while (resuelveCaso());
	return 0;
}