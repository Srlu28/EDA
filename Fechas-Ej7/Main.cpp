#include <iostream>
using namespace std;
#include <algorithm>
#include "Pila.h"
#include <string>
#include <iomanip>
typedef struct  {
	int dia, mes, ano;
}tFecha;
typedef struct
{
	tFecha f;
	int victimas;
}tAccidente;
tAccidente leerAccidente()
{
	tFecha f;
	char c;
	cin >> f.dia;
	cin >> c;
	cin >> f.mes;
	cin >> c;
	cin >> f.ano;
	tAccidente acc;
	acc.f = f;
	cin >> acc.victimas;
	return acc;
}
void mostrarAccidente(tAccidente acc)
{
	cout << setfill('0')<<setw(2)<<acc.f.dia << "/" << setfill('0') << setw(2)<<acc.f.mes << "/" <<setfill('0')<<setw(4)<< acc.f.ano << endl;
}
bool resuelveCaso()
{
	int numCasos;
	cin >> numCasos;
	if (!cin)return false;
	else
	{
		tAccidente acc;
		pila<tAccidente> p;
		for (int i = 0; i < numCasos; i++)
		{
			acc = leerAccidente();
			try
			{
				while (p.top().victimas < acc.victimas)
				{
					p.pop();
				}
				mostrarAccidente(p.top());
				p.push(acc);
			}
			catch (domain_error & e)
			{
				cout << "NO HAY\n";
				p.push(acc);
			}
			
		}
		cout << "---";
		return true;
	}
}
int main()
{
	while (resuelveCaso());
	return 0;
}