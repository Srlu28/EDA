#include <iostream>
using namespace std;
#include <map>
#include <string>

bool resuelveCaso()
{
	int numEj;
	cin >> numEj;
	if (numEj > 0)
	{
		cin.ignore();
		map<string, int> cal;
		//Orden de nlog(n).
		for (int i = 0; i < numEj; i++)
		{
			string name;
			getline(cin, name);
			string nota;
			getline(cin, nota);
			if (nota == "INCORRECTO")cal[name]--;
			else cal[name]++;
		}
		for (auto& it : cal)
		{
			if (it.second != 0)
				cout << it.first << ", "<<it.second<<endl;
		}
		cout << "---\n";

		return true;
	}
	return false;
}

int main()
{
	while (resuelveCaso());
	return 0;
}