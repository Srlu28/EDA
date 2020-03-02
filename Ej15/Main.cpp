#include <iostream>
using namespace std;
#include "queue_eda.h"
#include <set>

//He optado en este ejercicio utilizar el multiset con el parametro greater, asi me será facil tener ordenados los elementos mayores

bool resuelveCaso()
{
	int numSobres, picks;
	cin >> numSobres >> picks;
	if (numSobres == 0 && picks == 0)return false;
	else
	{
		multiset<int, greater<int>> conjunto;
		queue<int> lista;
		int elem;
		for (int pos = 0; pos < picks; pos++)
		{
			cin >> elem;
			lista.push(elem);
			conjunto.insert(elem);
		}
		int res = *conjunto.begin();
		cout << res << " ";
		for (int i = 0; i < numSobres - picks; i++)
		{
			cin >> elem;
			auto it = conjunto.find(lista.front());
			conjunto.erase(it);
			lista.pop();
			conjunto.insert(elem);
			lista.push(elem);
			int res = *conjunto.begin();
			cout << res << " ";
		}
		cout << endl;
		return true;
	}
}

int main()
{
	while (resuelveCaso());
	return 0;
}
