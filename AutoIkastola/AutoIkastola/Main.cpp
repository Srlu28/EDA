#include "AutoIkastolas.h"

bool r()
{
	string orden;
	cin >> orden;
	if (cin.fail())
	{
		return false;
	}
	autoescuela scl;
	while (orden != "FIN")
	{
		try
		{
			if (orden == "alta")
			{
				string a, p;
				cin >> a >> p;
				scl.alta(a, p);
			}
			else if (orden == "es_alumno")
			{
				string a, p;
				cin >> a >> p;
				bool ok = scl.es_alumno(a, p);
				if(ok)
					cout << a << " es alumno de " << p << endl;
				else cout << a << " no es alumno de " << p << endl;
			}
			else if (orden == "puntuacion")
			{
				string a;
				cin >> a;
				int puntos = scl.puntuacion(a);
				cout << "Puntuacion de " << a << ": " << puntos << endl;
			}
			else if (orden == "actualizar")
			{
				string name;
				int punto;
				cin >> name >> punto;
				scl.actualizar(name, punto);
			}
			else if (orden == "examen")
			{
				string name;
				cin >> name;
				int punto;
				cin >> punto;
				list<string> names = scl.examen(name, punto);
				cout << "Alumnos de " << name << " a examen:\n";
				for (string name : names)
				{
					cout << name << endl;
				}
			}
			else if (orden == "aprobar")
			{
				string name;
				cin >> name;
				scl.aprobar(name);
			}
		}
		catch(exception & e){
			cout << "ERROR\n";
		}
		cin >> orden;
	}
	cout << "---\n";
	return true;
}

int main()
{
	while (r());
	return 0;
}