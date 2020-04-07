#include <iostream>
#include <sstream>
using namespace std;
#include <map>
#include <vector>
#include <string>
#include <set>

map<string, int> readDic() { // O(n log(k))
	map<string, int> map;
	string clave, s;
	int valor;
	getline(cin, s);
	stringstream ss(s);

	while (ss >> clave >> valor)
		map[clave] = valor;

	return map;
}

multiset<string> calcularAdic(map<string, int> map1, map<string, int> map2)
{
	multiset< string> ret;
	for (pair<string, int> p1 : map1)
	{
		string n = p1.first;
		int valor = p1.second;
		if (map2[n] == 0) ret.insert(n);
	}
	return ret;
}
multiset<string> calcularMod(map<string, int> map1, map<string, int> map2)
{
	multiset<string> ret;
	for (pair<string, int> p1 : map1)
	{
		string n = p1.first;
		int valor = p1.second;
		if (map2[n] != 0 && valor != map2[n])ret.insert(n);
	}
	return ret;
}
void mostrar(multiset<string> v1,char el)
{
	cout << el << " ";
	for (const auto& e : v1)
		cout << e <<" ";
	cout << endl;
}

void resolverCaso()
{
	char ast = '*', res = '-', sum = '+';
	map<string, int > map1, map2;

	map1 = readDic();
	map2 = readDic();

	multiset<string> adicion;
	multiset<string>sustraer;
	multiset<string> modificados;

	adicion = calcularAdic(map2, map1);
	sustraer = calcularAdic(map1, map2);
	modificados = calcularMod(map1, map2);

	if (adicion.empty() && sustraer.empty() && modificados.empty())cout << "Sin cambios\n";
	else {
		if (!adicion.empty()) mostrar(adicion,sum);
		if (!sustraer.empty())mostrar(sustraer,res);
		if (!modificados.empty())mostrar(modificados,ast);
	}

}
int main()
{
	int numC;
	cin >> numC;
	cin.get();
	for (int i = 0; i < numC; i++)
	{
		resolverCaso();
		cout << "---\n";
	}
}