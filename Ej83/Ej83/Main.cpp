#include <iostream>
using  namespace std;
#include "Extended.h"
void ej()
{
	arbol<char> tree = readTreeData('.');
	tree.ej(tree);
}
int main()
{
	int numC;
	cin >> numC;
	for (int i = 0; i < numC; i++) ej();
	return 0;
}