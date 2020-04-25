#include <iostream>
using namespace std;
#include<map>
#include <vector>
bool resuelveCaso()
{
	int numC;
	cin >> numC;
	if (!cin.fail())
	{
		map<int,int> mapa;
		vector<int> orden;
		for (int i = 0; i < numC; i++)
		{
			int num;
			cin >> num;
			if (mapa[num] == 0)orden.push_back(num);//Indicamos el orden en el que mostramos los elementos
			mapa[num]++;
		}
		for (auto it : orden)//Mostramos basándonos en el vector orden.
			cout << it << " " << mapa[it]<<"\n";
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
