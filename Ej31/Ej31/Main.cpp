#include <iostream>
using namespace std;
#include <map>
#include <vector>
#include <string>
#include <sstream>

string minuscula(string & palabra)
{
	for (char & c : palabra)
	{
		c = tolower(c);
	}
	return palabra;
}
/*bool yaContado(vector<int> lineas, int line)
{
	bool ok = false;
	int it = 0;
	while (!ok && it <lineas.size())
	{
		if (line == lineas[it])ok = true;
		else it++;
	}
	return ok;
}*/
void resuelveLinea(map<string, vector<int>> & FrecPalabra, int line)
{
	string linea,pal;
	getline(cin, linea);
	stringstream ss(linea);
	while(ss>>pal)
		if (pal.size() > 2)
		{
			pal = minuscula(pal);
			//if(!yaContado(FrecPalabra[pal],line))
			FrecPalabra[pal].push_back(line);
		}
}
bool resuelveCaso()
{
	int numLin;
	cin >> numLin;
	cin.get();
	if (numLin == 0)return false;
	else
	{
		map<string, vector<int>> FrecPalabra;
		for (int i = 1; i <= numLin; i++)
		{
			resuelveLinea(FrecPalabra,i);
		}
		for (pair<string, vector<int>>pal : FrecPalabra)
		{
			cout << pal.first << " ";
			int ult=0;
			for (int i = 0; i < pal.second.size(); i++)
			{
				if (ult != pal.second[i])
				{
					cout << pal.second[i] << " ";
					ult = pal.second[i];
				}
				
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
}