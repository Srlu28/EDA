#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

struct tTeam
{
	string name;
	int numProb=0;
	int totalTime=0;
	set<string> problemas;

	bool operator<(const tTeam & t)const
	{
		bool x, y, z;
		x = numProb > t.numProb;
		y = totalTime < t.totalTime;
		z = name < t.name;
		return ( x || numProb == t.numProb && y || numProb == t.numProb && totalTime == t.totalTime && z);
	}
	void setter(string name, int time)
	{
		++numProb;
		totalTime += time;
		problemas.insert(name);
	}
	void mostrar()
	{
		cout << name << " " << problemas.size() << " " << totalTime << " " << endl;
	}
};

void resuelveCaso()
{
	map<string, tTeam> teamMap;
	map<string, map<string, int>>IncorrectMap;

	string name, problem;
	int time;
	string veredict;

	cin >> name;

	while (name != "FIN")
	{
		cin >> problem >> time >> veredict;
		if (teamMap.count(name) == 0)
			teamMap[name].name = name;
		if (veredict != "AC")
			++IncorrectMap[name][problem];
		if (veredict == "AC" && !teamMap[name].problemas.count(problem) > 0) {
			teamMap[name].setter(problem, time);
			int numTries = IncorrectMap[name][problem];
			teamMap[name].totalTime += numTries * 20;
		}
		cin >> name;
	}

	set<tTeam> listaTeams;
	for (pair<string, tTeam> team : teamMap)
		listaTeams.insert(team.second);
	for (auto it : listaTeams)
	{
		it.mostrar();
	}
	cout << "---\n";
}
int main()
{
	int numC;
	cin >> numC;
	for (int i = 0; i < numC; i++)
		resuelveCaso();
	return 0;
}
