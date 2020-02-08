#include <iostream>
using namespace std;

#include <vector>
#include "Time.h"
#include <algorithm>
#include <fstream>
bool resolverCaso()
{
	int numTrenes,  numHoras;
	cin >> numTrenes >> numHoras;
	if (numTrenes == 0 && numHoras == 0)
		return false;
	vector<Time> trenes(numTrenes);
	int i = 0;
	for (Time& h : trenes)
	{
		cin >> h;
		trenes.at(i) = h;
		i++;
	}
	for (int i = 0; i < numHoras; i++)
	{
		Time h;
		try {
			cin >> h;
			Time res=trenes[0];
			bool colocado = false;
			unsigned int pos=0;
			if (h < trenes[0]) colocado = true;
			while (!colocado && pos<trenes.size()-1)
			{
				if (trenes[pos] < h && h < trenes[pos + 1])
				{
					colocado = true;
					res = trenes[++pos];
				}
				else if (trenes[pos] == h)
				{
					colocado = true;
					res = trenes[pos];
				}
				else if (h == trenes[pos + 1])
				{
					colocado = true;
					res = trenes[++pos];
				}
				else pos++;
			}
			if (colocado) cout << res;
			else cout << "NO\n";
		}
		catch(domain_error & e)
		{
			cout << "ERROR\n";
		}
	}
	cout<<"---\n";
	return true;
}

int main()
{ 
	while (resolverCaso());
	return 0;
}