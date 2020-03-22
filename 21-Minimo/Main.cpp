#include <iostream>
using namespace std;
#include<string>

#include "bintree_eda.h"
#include "MinimoElem.h"

bool resuelveCaso()
{
	char Car;
	cin >> Car;
	
	if (cin.fail())return false;

	else {
		if (Car == 'N')
		{
			minim<int> arbol = readTree(-1);
			arbol.minimElem();
		}
		else {
			string hast = "#";
			minim<string> arbol = readTree(hast);
			arbol.minimElem();
		}
		return true;
	}
}

int main()
{
	while (resuelveCaso());
	return 0;
}