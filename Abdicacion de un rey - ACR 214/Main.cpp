#include <iostream>
using namespace std;
#include <map>

bool resuelveCaso() {
	map<string, int> dinastias;
	string name;
	int numR;
	cin >> numR;
	if (numR == 0) return false;
	for (int i = 0; i < numR; i++) {
		cin >> name;
		dinastias[name]++;
	}
	int numS;
	cin >> numS;
	for (int i = 0; i < numS; i++)
	{
		cin >> name;
		cout << ++dinastias[name]<<endl;
	}
	cout << endl;
	return true;
}

int main()
{
	while (resuelveCaso());
	return 0;
}