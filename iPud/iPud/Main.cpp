#include <iostream>
using namespace std;
#include "iPud.h"

bool r()
{
	string name;
	cin >> name;
	if (cin.fail())return false;
	else
	{
		iPud ipod;

		while (name != "FIN")
		{
			if (name == "addSong")
			{
				try
				{
					cancion c;
					duracion d;
					artista a;
					cin >> c >> a >> d;
					ipod.addSong(c, a, d);
				}
				catch (exception& e)
				{
					cout << "ERROR " << name << endl;
				}
			}
			else if (name == "addToPlaylist")
			{
				try
				{
					cancion c;
					cin >> c;
					ipod.addToPlayList(c);
				}
				catch (exception& e)
				{
					cout << "ERROR " << name << endl;
				}
				
			}
			else if (name == "play")
			{
				try
				{
					cancion c = ipod.current();
					cout << "Sonando " << c << endl;
					ipod.play();
				}
				catch (exception& e)
				{
					cout << "No hay canciones en la lista \n";
				}
			}
			else if (name == "current")
			{
				try
				{
					ipod.current();
				}
				catch (exception& e)
				{
					cout << "ERROR " << name << endl;
				}
			}
			else if (name == "recent")
			{
				int n;
				std::cin >> n;
				try {
					std::list<cancion> l = ipod.recents(n);

					std::cout << "Las " << (n > l.size() ? l.size() : n) << " mas recientes\n";

					int i = 0;
					auto it = l.begin();
					while (it != l.end() && i++ < n) {
						std::cout << "    " << *it << '\n';
						++it;
					}
				}
				catch (std::domain_error& e) {
					std::cout << "No hay canciones recientes\n";
				}

			}
			else if (name == "totalTime")
			{
				try
				{
					int a = ipod.totalTime();
					cout << "Tiempo total " << a << endl;
				}
				catch (exception& e)
				{
					cout << "ERROR " << name << endl;
				}
			}
			else if (name == "deleteSong")
			{
				try
				{

					cancion c;
					cin >> c;
					ipod.deleteSong(c);
				}
				catch (exception& e)
				{
					cout << "ERROR " << name << endl;
				}
			}
			
			cin >> name;
		}
		cout << "---\n";
		return true;
	}
}

int main()
{
	while (r());
}