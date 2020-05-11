#include <iostream>
using namespace std;
#include<map>
#include <string>
#include <vector>
#include <algorithm>

using Equipo = string;
typedef struct {
	Equipo local, visitante;
	int setL, setV;
}tPartido;

bool sortByVal(const pair<Equipo, int>& a,
	const pair<Equipo, int>& b)
{
	return (a.second > b.second);
}

bool leerPartido(tPartido & partido) {
	cin >> partido.local;
	if (partido.local != "FIN") {
		cin >> partido.setL >> partido.visitante >> partido.setV;
		return true;
	}
	return false;
}

void evaluarGanador(tPartido partido, map<Equipo, int> & cl) {
	if (partido.setL > partido.setV) {
		cl[partido.local] += 2;
		cl[partido.visitante] += 1;
	}
	else if (partido.setV > partido.setL)
	{
		cl[partido.visitante] += 2;
		cl[partido.local] += 1;
	}
}

bool resuelveCaso() {
	string categoria;
	cin >> categoria;
	if (categoria == "FIN")return false;
	else {
		map<Equipo, int > clasificacion;
		map<Equipo, vector<Equipo>> mapaLocalVis;
		tPartido partido;
		while (leerPartido(partido)) {
			evaluarGanador(partido, clasificacion);
			mapaLocalVis[partido.local].push_back(partido.visitante);
		}
		int partidosAusentes=0;
		for (auto& it : mapaLocalVis) {
			if (it.second.size() < clasificacion.size() - 1)partidosAusentes++;
		}
		vector<pair<Equipo, int>>vec;
		map<Equipo, int> ::iterator it2;
		for (it2 = clasificacion.begin(); it2 != clasificacion.end(); it2++)
		{
			vec.push_back(make_pair(it2->first, it2->second));
		}

		// // sort the vector by increasing order of its pair's second value
		sort(vec.begin(), vec.end(), sortByVal);

		// print the vector
		if (vec[0].second == vec[1].second) cout << "EMPATE ";
		else cout << vec[0].first<<" ";
		cout << partidosAusentes<<endl;
	}
}
int main() {
	while (resuelveCaso());
	return 0;
}