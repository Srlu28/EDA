#include<iostream>
using namespace std;
#include "Rio.h"

int main()
{
	int numC;
	cin >> numC;
	for (int i = 0; i < numC; i++)
	{
		Rio<int> rio = readTreeData(-1);
		rio.ejercicio(rio);
	}
}