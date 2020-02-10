#include <iostream>
using namespace std;
#include "Complejo.h"

float MandelBrot(Complejo & numAnterior, Complejo  c)
{
	Complejo numActual = numAnterior * numAnterior + c;
	numAnterior = numActual;
	return numActual.modulo();
}

void resuelveCaso()
{
	int i = 0;
	Complejo numAnterior (0,0);
	float numReal, numIm;
	cin >> numReal>>numIm;
	Complejo c(numReal, numIm);
	int numIter;
	cin >> numIter;
	bool notMandel=false;
	while (i < numIter && !notMandel)
	{
		float mod = MandelBrot(numAnterior, c);
		if ( mod> 2) 
			notMandel = true;
		else i++;
	}
	if (notMandel)cout << "NO\n";
	else
	{
		cout << "SI\n";
	}
}


int main()
{
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
	{
		resuelveCaso();
	}
}