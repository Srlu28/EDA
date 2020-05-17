#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#include<algorithm>
#include <unordered_map>



//Orden c*n - Orden lineal respecto de n
void resuelveCaso()
{
	int vSize;
	cin >> vSize;
	vector<int> v(vSize);
	for (int i = 0; i < vSize; i++) cin >> v[i];
	
	unordered_map<int, int> mapaPelis ;

	int inicio_periodo = 0;
	int maxLong = 1;
	for( int i = 0;i<(int)v.size();i++){
		if (mapaPelis.count(v[i]) && mapaPelis[v[i]] >= inicio_periodo)inicio_periodo = mapaPelis[v[i]] + 1;
		mapaPelis[v[i]] = i;
		maxLong = max(maxLong, i - inicio_periodo + 1);
	}	
	cout << maxLong<<endl;
}

int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		resuelveCaso();
	}
}