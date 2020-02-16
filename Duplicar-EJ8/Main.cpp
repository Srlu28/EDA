#include <iostream>
using namespace std;
#include "Queue.h"
#include"Herencia.h"
//Cambios realizados respecto a la anterior entrega:
//->Se ha extendido la clase cola mediante herencia para hacer el metodo mostrar  y el metodo duplicar cola
//->Se conservan las colas al hacer los metodos
bool resuleveCaso()
{
	ListaDuplica<int> c;
	int num;
	cin >> num;
	if (!cin)return false;
	else
	{
		while (num != 0)
		{
			c.push(num);
			cin >> num;
		}
		c.duplica();
		c.print(cout);
		return true;
	}
}
int main()
{
	while (resuleveCaso());
	return 0;
}