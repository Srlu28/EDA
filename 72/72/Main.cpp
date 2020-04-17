#include <iostream>
using namespace std;
#include "Lista71.h"
#include "Time.h"

bool resuelveCaso()
{
	int tam;
	cin >> tam;
	if (tam == 0)return false;
	else {
		Lista71<Time> lista;
		for (int i = 0; i < tam; i++)
		{
			Time time;
			cin >> time;
			lista.push(time);
		}
		lista.eliminarPares();
		lista.print();
		return true;
	}

}
int main()
{
	while (resuelveCaso());
	return 0;
}