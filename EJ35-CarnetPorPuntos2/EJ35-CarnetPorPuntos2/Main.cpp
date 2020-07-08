#include <iostream>
using namespace std;
#include<string>
#include "CarnetPorPuntos2.h"

bool r()
{
	string orden;
	cin >> orden;
	if (cin.fail())return false;
	else
	{
		autoescuela aut;
		while (orden != "FIN")
		{
			try {

				if (orden == "nuevo")
				{
					string dni;
					cin >> dni;
					aut.nuevo(dni);
				}
				else if (orden == "consultar")
				{
					string dni;
					cin >> dni;
					int p= aut.consultar(dni);
					cout << "Puntos de " << dni << ": " << p << endl;
				}
				else if (orden == "cuantos_con_puntos")
				{
					int p;
					cin >> p;
					int a=aut.cuantos_con_puntos(p);
					cout << "Con " << p << " puntos hay " << a << endl;
				}
				else if (orden == "lista_por_puntos")
				{
					int p;
					cin >> p;
					list<string> lista = aut.lista_por_puntos(p);
					cout << "Tienen " << p << " puntos: ";
					for (string dni : lista)
					{
						cout << dni << " ";
					}
					cout << endl;
				}
				else if (orden == "quitar")
				{
					string dni;
					int p;
					cin >> dni;
					cin >> p;
					aut.quitar(dni, p);
				}
				else if (orden == "recuperar")
				{
					string dni;
					int p;
					cin >> dni;
					cin >> p;
					aut.recuperar(dni, p);
				}
			}
			catch (exception & e)
			{
				cout << "ERROR: " << e.what() << endl;
			}
			cin >> orden;
		}
		cout << "---\n";
		return true;
	}
}

int main()
{
	while (r());
	return 0;
}