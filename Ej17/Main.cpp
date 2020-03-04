#include <iostream>
using namespace std;
#include<algorithm>

int resuelveCaso()
{
	int maxi = 0;
	int son;
	cin >> son;
	if (son == 0)return 1;
	else
	{
		for (int i = 0; i < son; i++)
			maxi = max(maxi, resuelveCaso());
	}
	return 1 + maxi;
}
//Implementamos la busqueda del arbol de forma Recursiva

int main()
{
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
	{
		cout<<resuelveCaso()<<endl;
	}
}