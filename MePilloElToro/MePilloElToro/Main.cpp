#include <iostream>
using namespace std;
#include "Ej29.h"
#include <string>

bool resuelveCaso()
{
	int numEj;
	cin >> numEj;

	if (numEj == 0)return false;

	notas n;

	cin.ignore();

	for (int i = 0; i < numEj; i++)
	{
		string name;
		getline(cin, name);

		string eval;
		getline(cin, eval);

		bool mark = (eval == "CORRECTO") ? true : false;

		n.evaluar(name, mark);
	}
	n.mostrar();
	cout << "---\n";
	return true;
}

int main()
{
	while (resuelveCaso());
	return 0;
}