#pragma once

#include <map>
#include <unordered_map>
#include <set>
#include<list>
#include<iostream>
#include <exception>

using namespace std;

using profesor = string;
using alumno = string;
typedef struct
{
	int puntos;
	string profesor;
}tInfoAlumno;

class autoescuela {
	map<profesor, set<alumno>> mapaPA;
	map<alumno, tInfoAlumno> mapaAI;
public:
	autoescuela() {}

	void alta(alumno al, profesor p)
	{
		if (mapaAI.count(al) == 0)
		{
			mapaAI.insert({ al,{0,p} });
			mapaPA[p].insert(al);
		}
		else
		{
			profesor antiguo = mapaAI[al].profesor;
			mapaAI[al].profesor = p;
			mapaPA[antiguo].erase(al);
			mapaPA[p].insert(al);
		}
	}

	bool es_alumno(alumno al, profesor p)
	{
		return mapaAI[al].profesor == p;
	}

	int puntuacion(alumno al)
	{
		if (mapaAI.count(al) > 0)
			return mapaAI[al].puntos;
		else
		{
			throw domain_error("El alumno "+al+ " no esta matriculado");
		}
	}
	
	void actualizar(alumno al, int p)
	{
		if (mapaAI.count(al) > 0)
			mapaAI[al].puntos += p;
		else
		{
			throw domain_error("El alumno " + al + " no esta matriculado");
		}
	}

	list<alumno> examen(profesor p, int n)
	{
		list<alumno> res;
		set<alumno> cjt = mapaPA[p];

		//set<alumno>::iterator it = cjt.begin();

		for (alumno a : cjt)
		{
			int pts = mapaAI[a].puntos;
			if (pts >= n)
			{
				res.push_back(a);
			}
		}
		return res;
	}

	void aprobar(alumno a)
	{
		if (mapaAI.count(a))
		{
			profesor p = mapaAI[a].profesor;
			mapaPA[p].erase(a);
			mapaAI.erase(a);
		}
		else
		{
			throw domain_error("El alumno " + a + " no esta matriculado");
		}
	}
};