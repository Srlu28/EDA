#include "CarnetPuntos.h"
#include <iostream>
#include <stdexcept>
using namespace std;

bool r()
{
	string instr;
	cin >> instr;
	if (cin.fail())return false;
	else
	{
		CarnetPuntos ej;
		while (instr != "FIN")
		{
			if (instr == "nuevo")
			{
				string dni;
				cin >> dni;
				try
				{
					ej.nuevo(dni);
				}
				catch (exception & e)
				{
					cout << "ERROR: " << e.what()<<endl;
				}
				
			}
			else if (instr == "cuantos_con_puntos")
			{
				int puntos;
				cin >> puntos;
				try
				{
					int num = ej.cuantos_con_puntos(puntos);
					cout << "Con " << puntos << " puntos hay " << num << endl;
				}
				catch (exception & e)
				{
					cout << "ERROR: " << e.what() << endl;
				}
				
			}
			else if (instr == "consultar")
			{
				string dni;
				cin >> dni;
				try
				{
					int num=ej.consultarDni(dni);
					cout << "Puntos de " << dni << ": " << num<<endl;
				}
				catch (exception & e)
				{
					cout << "ERROR: " << e.what() << endl;
				}
			}
			else if (instr == "quitar")
			{
				string dni;
				int puntos;
				cin >> dni;
				cin >> puntos;
				try
				{
					ej.quitarDni(dni, puntos);
				}
				catch (exception & e)
				{
					cout << "ERROR: " << e.what() << endl;
				}
			}
			cin >> instr;
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