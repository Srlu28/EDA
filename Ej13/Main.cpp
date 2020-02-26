#include <iostream>
using namespace std;

#include "Dequeue_eda.h"

bool resuelveCaso()
{
	int tam;
	cin >> tam;
	if (tam)
	{
		//Sabemos que la lista esta ordenada segun valores absolutos, por lo que usamos una cola doble poniendo por delante 
		//Los elementos positivos y por detras los negativos
		deque <int> l;
		int num;
		for (int i = 0; i < tam; i++)
		{
			cin >> num;
			if (num > 0)
				l.push_back(num);
			else l.push_front(num);
		}
		while (!l.empty())
		{
			cout << l.front()<< " ";
			l.pop_front();
		}
		cout << endl;
		return true;
	}
	else return false;
}
int main()
{
	while (resuelveCaso());
	return 0;
}