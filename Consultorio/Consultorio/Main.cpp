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
				else if (orden == "listaPacientes ")
				{
					string name;
					int num;
					cin >> name >> num;
					list<string> names=c.listaPacientes(name, num);
					cout << "Doctor " << name << " dia " << num << endl;
					for(string n:)
				}
				else if (orden == "siguientePaciente")
				{

				}
				else if (orden == "atiendeConsulta")
				{

				}
			}
			catch (exception& e)
			{
				cout << e.what() << endl;
			}
			
		}
	}
}

int main()
{
	while (r());
	return 0;
}