#ifndef pelicula_h
#define pelicula_h

#include <stdexcept>
#include <iostream>
#include <vector>
#include<fstream>
#include <iomanip>
#include "Time.h"

using namespace std;

class pelicula
{
private :
	Time hora_ini;
	Time duracion;
	Time hora_fin;
	string titulo;
public :
	pelicula()
	{

	}
	pelicula(Time hi, Time dur, string id)
	{
		hora_ini = hi;
		duracion = dur;
		hora_fin = hi+dur;
		titulo = id;
	}
	~pelicula()
	{

	}
	bool operator<(pelicula p)
	{
		if (hora_fin.pasarSeg() == p.hora_fin.pasarSeg()) return titulo < p.titulo;
		else return hora_fin.pasarSeg() < p.hora_fin.pasarSeg();
	}
	void read(std::istream& input = cin)
	{
		Time hi, dur;
		string id;
		input >> hi >> dur;
		getline(input, id);
		
		*this = pelicula(hi, dur, id);
	}
	void print(ostream& out = cout) const
	{
		out << hora_fin << " " << titulo << endl;
	}
};

inline ostream& operator<<(ostream& out, pelicula const p)
{
	p.print(out);
	return out;
}
inline istream& operator>>(istream& in, pelicula& p)
{
	p.read(in);
	return in;
}
#endif // !Time_h