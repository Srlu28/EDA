#include <iostream>
using namespace std;
#include "ArbolGenealogico.h"

void resolverCaso()
{
	ArbolGenealogico<int> tree= readTree(-1);
	tree.esGenealogico(tree);
	
}
int main()
{
	int numC;
	cin >> numC;
	for (int i = 0; i < numC; i++)
		resolverCaso();
	return 0;
}