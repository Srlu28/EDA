#include <iostream>
using namespace std;
#include "ListaHeredada.h"
#include "TAD_PERSONA.h"

bool cumpleReq(Persona p, int edadMin, int edadMax)
{
	return edadMin <= p.edad() && p.edad() <= edadMax;
}
bool resuelveCaso()
{
	int numPer,edadMin,edadMax;
	cin >> numPer>>edadMin>>edadMax;
	if (numPer == 0 && edadMin == 0 && edadMax == 0)return false;
	else
	{
		Herencia<Persona> l;
		for (int i = 0; i < numPer; i++)
		{
			Persona p;
			cin >> p;
			l.push_back(p);
			l.remove_if([edadMin, edadMax](Persona p) {return !cumpleReq(p, edadMin, edadMax); });
		}
		l.mostrar();
		cout << "---\n";
		return true;
	}
}
int main()
{
	while (resuelveCaso());
	return 0;
}