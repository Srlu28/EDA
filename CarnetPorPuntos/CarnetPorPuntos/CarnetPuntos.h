#pragma once
#include <iostream>
using namespace std;
#include <map>
#include <string>
#include <stdexcept>
#include <algorithm>
#include<list>
#include <vector>
class CarnetPuntos {
	//using Dni =typename string;

	map<string, int> mapaPuntos;
	vector<int> contPuntos = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

public:

	CarnetPuntos(){}
	
	void nuevo(string dni)
	{
		if (mapaPuntos.count(dni) > 0)
		{
			throw domain_error("Conductor duplicado");
		}
		else
		{
			mapaPuntos[dni] = 15;
			contPuntos.at(15)++;
		}
	}

	void quitarDni(string dni, int puntos)
	{
		if (mapaPuntos.count(dni) > 0)
		{
			contPuntos.at(mapaPuntos[dni])--;
			mapaPuntos[dni] = std::max(mapaPuntos[dni]-puntos,0);
			contPuntos.at(mapaPuntos[dni])++;
		}
		else
		{
			throw domain_error("Conductor inexistente");
		}
	}

	int consultarDni(string dni)
	{
		if (mapaPuntos.count(dni) > 0)
		{
			return mapaPuntos[dni];
		}
		else
		{
			throw domain_error("Conductor inexistente");
		}
	}

	int cuantos_con_puntos(int puntos)
	{
		if (puntos < 0 || puntos >15)
		{
			throw domain_error("Puntos no validos");
		}
		else
		{
			return contPuntos.at(puntos);
		}
	}
	
};