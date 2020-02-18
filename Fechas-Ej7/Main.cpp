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
	if (f.dia > 31 || f.dia < 0)throw domain_error("el dia introducido no es valido");
	cin >> c;
	cin >> f.mes;
	if (f.mes > 12 || f.mes < 0)throw domain_error("el mes introducido no es valido");
	cin >> c;
	cin >> f.ano;
	tAccidente acc;
	acc.f = f;
	cin >> acc.victimas;
	if (acc.victimas < 0)throw domain_error("No puede haber un numero negativo de victimas");
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
			try {
				tAccidente acc;
				acc = leerAccidente();
				while (!p.empty() && p.top().victimas <= acc.victimas) p.pop();
				if (p.empty())cout << "NO HAY" << endl;
				else mostrarAccidente(p.top());
				p.push(acc);
			}
			catch (domain_error e) {

			}
			
		}
		cout << "---"<<endl;
		return true;
	}
}
int main()
{
	while (resuelveCaso());
	return 0;
}