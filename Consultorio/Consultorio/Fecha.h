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

	bool operator<(Fecha const& f)
	{
		return dia < f.dia || dia == f.dia && minuto == f.minuto || dia == f.dia && minuto == f.minuto && hora < f.hora;
	}

	bool operator==(Fecha const& f)
	{
		return dia == f.dia && minuto == f.minuto && hora == f.hora;
	}
};
inline ostream& operator<<(std::ostream& out, Fecha  d) {
	out << setw(2) << setfill(0) << d.getHora() << ":" << setw(2) << setfill(0) << d.getMin() << ":" << setw(2) << setfill(0) << d.getMin();
	return out;
}

inline istream& operator>>(std::istream& in, Fecha& d) {
	char c;
	int h, di, m;
	cin >> di >> c >> h >> c >> m;
	d =  Fecha(di, h, m);
	return in;
}