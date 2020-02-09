#include <iostream>
using namespace std;
#include "Time.h"
#include <vector>
#include <algorithm>
#include "pelicula.h"
bool resuelveCaso()
{
	int numPelis;
	cin >> numPelis;
	if (numPelis)
	{
		vector<pelicula> vector;
		for (int i = 0; i < numPelis; i++)
		{
			pelicula p;
			cin >> p;
			vector.push_back(p);
		}
		sort(vector.begin(), vector.end());
		for (int i = 0; i < numPelis; i++)
		{
			cout << vector.at(i);
		}
		cout << "---\n";
		return true;
	}
	else return false;
}
int main()
{
	while (resuelveCaso());
	return 0;
}