#include <iostream>
using namespace std;
#include<string>
#include "Secret.h"
bool  resuelveCaso()
{
	_0069<char> list;
	string cad;

	getline(cin, cad);
	if (cin.fail()) return false;

	list = list.reorder(cad);
	cout << list;

	return true;
}

int main()
{
	while (resuelveCaso())
	{
		;
	}
	return 0;
}