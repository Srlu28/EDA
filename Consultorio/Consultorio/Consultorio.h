#pragma once
#include <iostream>
using namespace std;
#include <set>
#include<map>
#include<iterator>
#include<unordered_map>
#include<algorithm>
#include "Fecha.h"
#include <list>
#include <stdexcept>
using medico = string;
using paciente = string;

class Consultorio
{
	unordered_map<medico, map<Fecha, paciente>> infoMedicos;
	unordered_map<medico, map<int, map<Fecha,paciente>::iterator>> mapPrimerPaciente;

public :
	void nuevoMedico(medico m)
	{
		if (infoMedicos.count(m) == 0)
		{
			infoMedicos.insert({ m,{} });
			mapPrimerPaciente.insert({ m,{} });
		}
	}
	void pideConsulta(paciente p, medico m, Fecha f)
	{
		if (infoMedicos.count(m) == 0) {
			throw domain_error("Medico no existente");
		}
		else if (infoMedicos[m].count(f))
		{
			throw domain_error("Fecha ocupada");
		}
		else
		{
			//Si el paciente que acabamos de registrar esta primero en la agenda:
			infoMedicos[m][f] = p;
			if (mapPrimerPaciente[m].count(f.getDia()) == 0 || f < mapPrimerPaciente[m][f.getDia()]->first)
				mapPrimerPaciente[m][f.getDia()]=infoMedicos[m].find(f);
		}
	}
	paciente siguientePaciente(medico m)
	{
		if (infoMedicos.count(m) == 0) {
			throw domain_error("Medico no existente");
		}
		else if (infoMedicos[m].empty())
		{
			throw domain_error("No hay pacientes");
		}
		else return infoMedicos[m].begin()->second;
	}

	void atiendeConsulta(medico m)
	{
		if (infoMedicos.count(m) == 0) {
			throw domain_error("Medico no existente");
		}
		else if (infoMedicos[m].empty())
		{
			throw domain_error("No hay pacientes");
		}
		//Al pasar consulta tendremos que actualizar el primer paciente.
		int dia = infoMedicos[m].begin()->first.getDia();
		auto it = infoMedicos[m].begin();
		it++;
		if (it == infoMedicos[m].end() || dia != it->first.getDia())
			mapPrimerPaciente[m].erase(dia);
		else if(it != infoMedicos[m].end() && dia == it->first.getDia())
		{
			mapPrimerPaciente[m][dia] = it;
		}
		infoMedicos[m].erase(infoMedicos[m].begin());
	}

	list<string> listaPacientes(medico m, int d)
	{
		if (infoMedicos.count(m) == 0) {
			throw domain_error("Medico no existente");
		}
		list<string> ret;
		if (mapPrimerPaciente[m].count(d) != 0)
		{
			auto it = mapPrimerPaciente[m][d];
			while (it != infoMedicos[m].end() && it->first.getDia() == d)
			{
				ret.push_back(it->second);
				it++;
			}
		}
		return ret;
	}
};