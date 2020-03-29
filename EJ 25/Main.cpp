#include <iostream>
using namespace std;
#include "Arbol.h"
#include <vector>
#include <climits>
#include <algorithm>
#include <math.h>

typedef struct
{
	int nodo, altura;
}tDevolver;

tDevolver ejercicio(bintree<int> t,int altura,vector<bool> esPrimo)
{
	if (t.empty()) return { 0,INT_MAX };

	tDevolver left;
	tDevolver right;
	left = ejercicio(t.left(), altura + 1, esPrimo);
	right = ejercicio(t.right(), altura + 1, esPrimo);
	if (esPrimo[t.root()])return { 0,INT_MAX };
	if (t.root() % 7==0)return { t.root(),altura };
	else
	{
		if (left.altura <= right.altura)return left;
		else return right;
	}
}

vector<bool> cargarPrimos()
{
	vector<bool> primos(5000, true);
	int l = (int)sqrt(5001);
	for (int i = 2; i < l; i++)
	{
		int j = 2;
		int r = j * i;
		while (r < 5000)
		{
			primos[r] = false;
			r = ++j * i;
		}
	}
	return primos;
}

void resolverCaso()
{
	bintree<int> t = leerArbol(-1);

	tDevolver info = { 0,0 };

	vector<bool> primos = cargarPrimos();
	
	info = ejercicio(t,1,primos);

	if (info.nodo==0)cout << "NO HAY\n";
	else
	{
		cout << info.nodo << " " << info.altura << endl;
	}

}

int main()
{
	int numC;
	cin >> numC;
	for (int i = 0; i < numC; i++)
		resolverCaso();
}