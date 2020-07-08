#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Fecha {
	int dia, hora, minuto;

public:
	Fecha(int d, int h, int m)
	{
		dia = d;
		hora = h;
		minuto = m;
	}
	Fecha() {}

	int getDia() const
	{
		return dia;
	}
	int getHora()
	{
		return hora;
	}
	int getMin()
	{
		return minuto;
	}

	bool operator<(Fecha const& f)const
	{
		return dia < f.dia || dia == f.dia && hora < f.hora || dia == f.dia && hora == f.hora&& minuto < f.minuto ;
	}

	bool operator==(Fecha const& f)const
	{
		return dia == f.dia && minuto == f.minuto && hora == f.hora;
	}
	void print(std::ostream& out = std::cout) const {
		char c = ':';
		out << std::setw(2) << std::setfill('0') << hora << c << std::setw(2) << std::setfill('0') << minuto;
	}
};
inline ostream& operator<<(std::ostream& out, Fecha  const d) {
	d.print(out);
	return out;
}

inline istream& operator>>(std::istream& in, Fecha& d) {
	char c;
	int h, di, m;
	cin >> di  >> h >> c >> m;
	d = Fecha(di, h, m);
	return in;
}