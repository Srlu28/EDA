#include <iostream>
#include <string>
using namespace std;
#include <map>
#include <set>
#include <vector>
#include <sstream>


map<string, int> leerDic()
{
	map<string, int> res;
	string clave, s;
	int valor;
	getline(cin, s);
	stringstream ss(s);

	while(ss>>clave>>valor) res[clave]=valor;

	return res;

}

void resolverCaso()
{
	map<string, int> map1 = leerDic();
	map<string, int> map2 = leerDic();
	map<char, set<string>> mapaCambios;

	for (pair<string, int > p : map1)
	{
		if (map2.count(p.first) && map2[p.first] != p.second)
			mapaCambios['*'].insert(p.first);
		if (map2.count(p.first) == 0)
			mapaCambios['-'].insert(p.first);
	}
	for (pair<string, int> p : map2)
	{
		if (map1.count(p.first) == 0)
			mapaCambios['+'].insert(p.first);
	}

	if (mapaCambios.empty())cout << "Sin cambios\n";
	
	//Orden de log(n)*k
	vector<char> v = { '+','-','*' };
	for (char c : v)
	{
		if (mapaCambios.count(c))
		{
			cout << c;
			for (auto it : mapaCambios[c])
				cout << " " << it;
			cout << endl;
		}
	}
	cout << "---\n";
}

int main()
{
	int num;
	cin >> num;
	cin.get();
	for (int i = 0; i < num; i++)resolverCaso();
	return 0;
}