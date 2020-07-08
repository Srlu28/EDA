#pragma once
#include <map>
#include<unordered_map>
#include <list>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

#include <stdexcept>

using cancion = string;
using artista = string;
using duracion = int;

class iPud {
	unordered_map<cancion, duracion> mapaCanciones;
	list<cancion> playList;
	list<cancion> recent;
	unordered_map<cancion, list<cancion>::iterator> mapSongPlayL;
	unordered_map < cancion, list<string>::iterator> mapSongRecent;
public:
	iPud(){}


	void addSong(cancion c, artista a, duracion d)
	{
		if (mapaCanciones.count(c))//Constante
		{
			throw domain_error("");
		}
		else
		{
			mapaCanciones.insert({ c,d });//Constante 
		}
	}

	void addToPlayList(cancion c)
	{
		if (mapaCanciones.count(c)==0)
		{
			throw domain_error("");
		}
		else
		{
			if (!mapSongPlayL.count(c))
			{
				playList.push_back(c);
				mapSongPlayL.insert({ c,playList.end() });
			}
		}
	}

	cancion current() const 
	{
		if(playList.empty())throw domain_error("");
		else
		{
			return playList.front();
		}
	}

	void play()
	{
		try {
			cancion c = current();
			
			if (mapSongRecent.count(c) > 0)
				recent.erase(mapSongRecent[c]);
			playList.pop_front();
			mapSongPlayL.erase(c);
			recent.push_front(c);
			mapSongRecent.insert({ c,recent.begin() });
		}
		catch (exception& e)
		{
			throw domain_error("");
		}
	}

	int totalTime() const
	{
		int dev = 0;

		for (cancion s : playList)
		{
			int time = mapaCanciones.at(s);
			dev += time;
		}

		return dev;
	}

	list<cancion> recents(int n) const 
	{
		if (recent.size() == 0) throw std::domain_error("");

		return recent;
	}

	void deleteSong(cancion c)
	{
		
		if (mapaCanciones.count(c)>0)
		{
			mapaCanciones.erase(c);

			if (mapSongPlayL.count(c)>0)
			{
				playList.erase(mapSongPlayL[c]);
				mapSongPlayL.erase(c);
			}
			if (mapSongRecent.count(c)>0)
			{
				recent.erase(mapSongRecent[c]);
				mapSongRecent.erase(c);
			}
		}
	}
};