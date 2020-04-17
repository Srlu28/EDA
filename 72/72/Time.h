#ifndef Time_h
#define Time_h

#include <stdexcept>
#include <iostream>
#include <vector>
#include<fstream>
#include <iomanip>
using namespace std;

class Time {

private:
	int horas;
	int minutos;
	int segundos;
	bool correcta(int HH, int MM, int SS)
	{
		return 00 <= HH && HH <= 23 && 00 <= MM && MM <= 59 && 00 <= SS && SS <= 59;
	}



public:
	Time()
	{

	}
	Time(int HH, int MM, int SS)
	{
		if (correcta(HH, MM, SS))
		{
			horas = HH;
			minutos = MM;
			segundos = SS;
		}
		else throw std::domain_error("Datos inválidos.");
	}
	~Time()
	{

	}
	int pasarSeg()
	{
		return horas * 3600 + minutos * 60 + segundos;
	}
	int hor() const {
		return horas;
	}
	int min() const
	{
		return minutos;
	}
	int seg() const
	{
		return segundos;
	}

	bool operator<(Time time)
	{
		return pasarSeg() < time.pasarSeg();
	}
	bool operator==(Time time)
	{
		return horas == time.horas && minutos == time.minutos && segundos == time.segundos;
	}
	void read(std::istream& input = cin)
	{
		int h, m, s;
		char c;
		input >> h >> c >> m >> c >> s;
		*this = Time(h, m, s);
	}
	void print(ostream& out = cout) const
	{
		char c = ':';
		out << setw(2) << setfill('0') << horas << c << setw(2) << setfill('0') << minutos << c << setw(2) << setfill('0') << segundos ;
	}

};
inline ostream& operator<<(ostream& out, Time const time)
{
	time.print(out);
	return out;
}
inline istream& operator>>(istream& in, Time& time)
{
	time.read(in);
	return in;
}
#endif // !Time_h