#include <iostream>
using namespace std;
#include <algorithm>
#include "Pila.h"
#include <string>
const char arrayOpen[3] = { '(','{','[' };
const char arrayClose[3] = { ')','}',']' };
bool isOpen(char c)
{
	for (int i = 0; i < 3; i++)
		if (c == arrayOpen[i])return true;
	return false;
}
bool isClose(char c)
{
	for (int i = 0; i < 3; i++)
		if (c == arrayClose[i])return true;
	return false;
}
char getOp(char c)
{
	for (int i = 0; i < 3; i++)
	{
		if (arrayOpen[i] == c)return arrayClose[i];
		else if (arrayClose[i] == c)return arrayOpen[i];
	}
	return ' ';
}
bool resuelveCaso()
{
	string caso;
	getline(cin, caso);
	if (caso.empty())return false;
	else
	{
		pila<char> p;
		bool ok = true;
		for (long unsigned int i = 0; i < caso.size(); i++)
		{
			if (isOpen(caso[i]))
				p.push(caso[i]);
			else
			{
				if (isClose(caso[i]))
				{
					if (p.empty())ok = false;
					else if (p.top() != getOp(caso[i])) ok = false;
					else p.pop();
				}
			}
		}
		if (ok)cout << "SI\n";
		else cout << "NO\n";
		return true;
	}
}
int main()
{
	while (resuelveCaso());
	return 0;
}