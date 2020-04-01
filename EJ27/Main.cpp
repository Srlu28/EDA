#include <iostream>
#include "Arbol.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bintree<int> generarArbol(queue <int> cola)
{
	if (cola.size() == 1)return cola.front();

	else
	{
		int raiz = cola.front();
		cola.pop();
		queue<int> colaIzq;

		while (cola.size() && raiz > cola.front())
		{
			colaIzq.push(cola.front());
			cola.pop();
		}
		bintree<int > left = {}, right = {};

		if (colaIzq.size()) left = generarArbol(colaIzq);
		if (cola.size())right = generarArbol(cola);

		return{ left,raiz,right };
	}
	
}

queue<int> leer()
{
	queue<int> ret;
	int tmp;
	string s;

	getline(cin, s);
	stringstream str(s);

	while (str >> tmp)
		ret.push(tmp);
	return ret;
}
bool resuelveCaso()
{
	queue<int> cola;
	bintree<int> arbol;

	cola = leer();
	if (cola.size() == 0) return false;
	else
	{
		arbol = generarArbol(cola);
		for (int it : arbol.postorder())cout << it << ' ';
		cout << endl;
		return true;
	}
}

int main()
{
	while (resuelveCaso()); return 0;
}