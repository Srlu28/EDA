#include <iostream>
using namespace std;
#include <set>
#include <map>


bool resuelveCaso()
{
	string name;
	cin >> name;
	if (cin.fail())return false;
	else {

		string depAct;
		map<string, set<string>> mapaDep;
		map<string, string> mapaAL;
		while (name != "_FIN_")
		{
			if (name[0] >= 'A' && name[0] <= 'Z') {
				depAct = name;
				mapaDep[depAct] = set<string>();
			}
			else {
				if (mapaAL.count(name) && depAct != mapaAL[name]) mapaDep[mapaAL[name]].erase(name);
				else {
					mapaDep[depAct].insert(name);
					mapaAL[name] = depAct;
				}
			}
			cin >> name;
		}
		map<int, set<string>, greater<int>> mapOrd;
		for (auto it = mapaDep.begin(); it != mapaDep.end(); ++it)
			mapOrd[it->second.size()].insert(it->first);
		for (pair<int, set<string>> par : mapOrd)
		{
			for (string el : par.second)
				cout << el << " " << par.first << endl;
		}
		cout << "---\n";
		return true;
	}
}
int main()
{
	while (resuelveCaso());
	return 0;
}
