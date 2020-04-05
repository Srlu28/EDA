#pragma once

#include <iostream>
#include "treeMap.h"
#include <string>
using namespace std;

using alumno = string;

class notas {
private:
	map<alumno, int>tabla;
public:
	notas() {};

	void evaluar(alumno const& a, bool correcto)
	{
		if (correcto)++tabla[a];
		else --tabla[a];
	}
	void mostrar()
	{
		for (auto const& par : tabla)
			if (par.valor != 0)
				cout << par.clave << ", " << par.valor << "\n";
	}
};