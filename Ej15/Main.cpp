#include <iostream>
using namespace std;

#include "stack_eda.h"
#include "queue_eda.h"
#include "Herencia.h"
template <class T>
using Nodo = typename queue<T>::Nodo;

bool resuelveCaso()
{
	int numSobres, picks;
	cin >> numSobres >> picks;
	if (numSobres == 0 && picks == 0)
	{
		return false;
	}
	else
	{
		Herencia<int> sobres;
		for (int i = 0; i < numSobres; i++)
		{
			int n;
			cin >> n;
			sobres.push(n);
		}
		int posibilidades=numSobres-picks+1;
		stack<int>res = sobres.ej(posibilidades,picks);
		res.mostrar();
		return true;
	}
}
int main()
{
	while (resuelveCaso());
	return 0;
}