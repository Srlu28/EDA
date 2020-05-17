#include <iostream>
using namespace std;
#include <map>
#include <set>
#include<sstream>
#include<string>
#include <vector>
#include<iterator>

string minuscula(string& palabra)
{
	for (char& c : palabra)
	{
		c = tolower(c);
	}
	return palabra;
}
bool resuelveCaso()
{
	int numL;
	cin >> numL;
	cin.get();
	if (numL == 0)return false;
	else {
		map<string, set<int>> mapa;
		string name;

		for (int i = 0; i < numL; i++)
		{
			string pal;
			getline(cin, name);
			stringstream ss(name);
			while (ss >> pal)
			{
				if (pal.size() > 2) {
					pal = minuscula(pal);
					int a = i+1;
					mapa[pal].insert(a);
				}
			}
		}

		for (auto& it : mapa)
		{
			//O k*log(n)
			cout << it.first << " ";
			for (auto& a : it.second)
			{
				cout << a<<" ";
			}
			cout << endl;
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