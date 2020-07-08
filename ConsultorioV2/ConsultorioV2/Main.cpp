#include <iostream>
using namespace std;
#include "Consultorio.h"

bool r()
{
	int num;
	cin >> num;
	if (cin.fail())return false;
	else
	{
		Consultorio c;
		for (int i = 0; i < num; i++)
		{
			string orden;
			cin >> orden;
			try
			{
				if (orden == "nuevoMedico")
				{
					string name;
					cin >> name;
					c.nuevoMedico(name);
				}
				else if (orden == "pideConsulta")
				{
					string pac, med;
					Fecha f;
					cin >> pac >> med >> f;
					c.pideConsulta(pac, med, f);
				}
				else if (orden == "listaPacientes")
				{
					string name;
					int num;
					cin >> name >> num;
					list<pair<string, Fecha>> names = c.listaPacientes(name, num);
					cout << "Doctor " << name << " dia " << num << endl;
					for (pair<string, Fecha> n : names)
						cout << n.first << " " << n.second << endl;
				}
				else if (orden == "siguientePaciente")
				{
					string name;
					cin >> name;
					string a = c.siguientePaciente(name);
					cout << "Siguiente paciente doctor " << name;
					cout << endl << a << endl;
				}
				else if (orden == "atiendeConsulta")
				{
					string name;
					cin >> name;
					c.atiendeConsulta(name);
				}
			}
			catch (exception& e)
			{
				cout << e.what() << endl;
			}

		}cout << "---\n";
	}
}

int main()
{
	while (r());
	return 0;
}