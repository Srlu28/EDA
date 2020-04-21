#include <iostream>
using namespace std;
#include "Extended.h"


void resolverCaso()
{
	extended<char> tree = readTree('.');
	tree.res(tree);
}

int main()
{
	int numC;
	cin >> numC;
	for (int i = 0; i < numC; i++)
		resolverCaso();
	return 0;
}