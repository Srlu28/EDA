#pragma once

#include <stdexcept>
#include <iostream>
#include <unordered_map>
#include<algorithm>
#include<map>
#include <list>
using namespace std;


using Libro = string;

class Libreria {
private:
	unordered_map<Libro, int> libEjem;
	unordered_map<Libro, int> numVendidos;
	map<int, list<Libro>> ventasLibro;
	unordered_map<Libro, list<Libro>::iterator> mapaIt;

public:
	void nuevoLibro(int const n, Libro const& l) {
		libEjem[l] += n;
	}
	void comprar(Libro const& l) { 
		if (libEjem.count(l) == 0) throw invalid_argument("Libro no existente");
		if (libEjem[l] == 0) throw out_of_range("No hay ejemplares");
		--libEjem[l];

		if (numVendidos[l] != 0)
			ventasLibro[numVendidos[l]].erase(mapaIt[l]);
		++numVendidos[l];
		ventasLibro[numVendidos[l]].push_front(l);
		mapaIt[l] = ventasLibro[numVendidos[l]].begin();
	}
	bool estaLibro(Libro const& l) { 
		return libEjem.count(l) > 0;
	}
	void elimLibro(Libro const& l) { 
		if (libEjem.count(l) > 0) {
			libEjem.erase(l);

			if (numVendidos.count(l) != 0) {
				ventasLibro[numVendidos[l]].erase(mapaIt[l]);
				mapaIt.erase(l);
				numVendidos.erase(l);
			}
		}
	}
	int numEjemplares(Libro const& l) { 
		if (libEjem.count(l) > 0) return libEjem[l];
		else throw invalid_argument("No existe el libro " + l + " en el sistema");
		
	}
	list<Libro> top10() { 
		int i = 0;
		auto it1 = ventasLibro.rbegin();
		list<Libro> dev;

		while (it1 != ventasLibro.rend() && i != 10) {
			auto it2 = it1->second.begin();
			while (it2 != it1->second.end() && i != 10) {
				dev.push_back(*it2);
				++it2;
				++i;
			}
			++it1;
		}
		return dev;
	}
};