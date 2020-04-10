#include <iostream>
using namespace std;
#include <map>
#include <set>
#include <string>

using alumno = string;

void mostrar(map<int, set<string>, greater<int>>mapAl)
{
	for (pair<int, set<string>> par : mapAl)
	{
		for (string el : par.second)
			cout << el << " " << par.first << endl;
	}
	cout << "---\n";
}

bool resuelveCaso()
{
	alumno al,lect;
	map<string, set<string>>mapAl;
	map<string, string>prefAl;

	cin >> lect;
	if (cin.fail())return false;
	string depAct;
	while (lect != "_FIN_")
	{
		if (lect[0] >= 'A' && lect[0] <= 'Z')
		{
			depAct = lect;
			mapAl[depAct] = set<string>();
		}
		else
		{
			if (prefAl.count(lect) && prefAl[lect] != depAct)
			{
				mapAl[prefAl[lect]].erase(lect);
			}
			else {
				mapAl[depAct].insert(lect);
				prefAl[lect] = depAct;
			}
		}
		cin >> lect;
	}

	map<int, set<string>, greater<int>> mapOrd;
	for (auto it = mapAl.begin(); it != mapAl.end(); ++it)
		mapOrd[it->second.size()].insert(it->first);
	mostrar(mapOrd);

	return true;
}

int main()
{
	while (resuelveCaso());
	return 0;
}