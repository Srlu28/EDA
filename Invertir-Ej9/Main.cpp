#include <iostream>
#include "Herencia.h"
using namespace std;
bool resuleveCaso()
{
	ListaInvierte<int> l, l2;
	int num;
	cin >> num;
	if (!cin)return false;
	else
	{
		while (num != 0)
		{
			l.push(num);
			cin >> num;
		}
		l.invierte(l2);
		l2.print();
		return true;
	}
}
int main()
{
	while (resuleveCaso());
	return 0;
}