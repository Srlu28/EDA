#pragma once

#include <map>
#include<list>
#include<iostream>
#include<stdexcept>
#include <vector>
#include<unordered_set>
#include <iterator>
#include<algorithm>
using namespace std;

typedef struct {
	list<string> ::iterator it;
	int puntos;
}tInfoCliente;

class autoescuela {

	map<string, tInfoCliente> mapa;
	vector<list<string>> tablaInfo;

	list<string> ::iterator insertarPunto(string dni, int puntos)
	{
		auto & lista = tablaInfo[puntos];
		return lista.insert(lista.begin(), dni);
	}

public:

	autoescuela(): tablaInfo(16){}

	void nuevo(string dni)
	{
		if (mapa.count(dni) > 0)
		{
			throw domain_error("Conductor duplicado");
		}
		else
		{
			auto it = insertarPunto(dni, 15);
			mapa.insert({ dni,{ it ,15 } });
		}
	}
	void quitar(string dni, int puntos)
	{
		if (mapa.count(dni) == 0)
		{
			throw domain_error("Conductor inexistente");
		}
		else
		{
			if (puntos > 0 && mapa[dni].puntos > 0)
			{
				tablaInfo[mapa[dni].puntos].erase(mapa[dni].it);
				int nP = max(0, mapa[dni].puntos - puntos);
				auto  it = insertarPunto(dni, nP);
				mapa[dni].puntos = nP;
				mapa[dni].it = it;
			}
		}
	}

	void recuperar(string dni, int puntos)
	{
		if (mapa.count(dni) == 0)
		{
			throw domain_error("Conductor inexistente");
		}
		else
		{
			if (puntos > 0 && mapa[dni].puntos < 15)
			{
				tablaInfo[mapa[dni].puntos].erase(mapa[dni].it);
				int nP = min(15, mapa[dni].puntos + puntos);
				auto  it = insertarPunto(dni, nP);
				mapa[dni].puntos = nP;
				mapa[dni].it = it;
			}
		}
	}

	int consultar(string dni)
	{
		if (!mapa.count(dni) > 0)
		{
			throw domain_error("Conductor inexistente");
		}
		else return mapa[dni].puntos;
	}

	int cuantos_con_puntos(int puntos)
	{
		if (puntos < 0 || puntos >15)
		{
			throw domain_error("Puntos no validos");
		}
		else
		{
			return tablaInfo[puntos].size();
		}
	}

	list<string> lista_por_puntos(int puntos)
	{
		if (puntos < 0 || puntos >15)
		{
			throw domain_error("Puntos no validos");
		}
		else
		{
			return tablaInfo[puntos];
		}
	}


};