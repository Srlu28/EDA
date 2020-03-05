#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <list>

using namespace std;



void resolver(vector<char>& caracteres)
{
    list<char> lista;
    auto cursor = lista.begin();
    for (char i : caracteres)
    {
        if (i== '-')
        {
            cursor = lista.begin();
        }
        else if (i == '+')
        {
            cursor = lista.end();
        }
        else if (i == '*')
        {
            cursor++;
        }
        else if (i == '3')
        {
            cursor=lista.erase(cursor);
        }
        else
        {
            lista.insert(cursor,i);
        }
    }
    for (char c : lista)
    {
        cout << c;
    }
    cout << endl;
}

bool resuelveCaso()
{
    //using Iterador = typename list<char>::iterator;
    string in;
    cin >> in;
    if (!std::cin)
        return false;
    vector<char> caracteres(in.begin(), in.end());
    resolver(caracteres);
    return true;
}

int main()
{
    while (resuelveCaso());
    return 0;
}